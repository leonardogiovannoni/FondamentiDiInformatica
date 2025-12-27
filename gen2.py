import subprocess
import tempfile
import os
import sys
import shutil

TEMPLATE = r"""
#set page(
  width: %dcm,
  margin: 1cm,
)

// Usa FreeMono come font monospaziato (se installato nel sistema)
#show raw: set text(font: "FreeMono")

#raw(
  read("%s"),
  block: true,
  lang: "cpp",
)
"""

def count_arrow(file_path):
    with open(file_path, "r", encoding="utf-8") as f:
        return f.read().count("→")

def count_arrow_pdf(pdf_path):
    # Estrae il testo dal pdf con pdftotext
    txt_path = pdf_path + ".txt"
    subprocess.run(["pdftotext", pdf_path, txt_path], check=True)
    with open(txt_path, "r", encoding="utf-8") as f:
        return f.read().count("→")

def compile_pdf(typ_path, workdir):
    # Compila il file Typst in PDF
    subprocess.run(
        ["typst", "compile", typ_path],
        cwd=workdir,
        check=True,
    )

def generate_pdf(cpp_file):
    if not os.path.exists(cpp_file):
        print("Errore: file .cpp non trovato:", cpp_file)
        sys.exit(1)

    cpp_abs = os.path.abspath(cpp_file)

    base_name = os.path.splitext(os.path.basename(cpp_file))[0]
    final_pdf_name = base_name + ".pdf"

    arrow_cpp = count_arrow(cpp_file)
    print(f"Occorrenze → nel file .cpp: {arrow_cpp}")

    page_width = 19  # larghezza pagina iniziale in cm

    with tempfile.TemporaryDirectory() as tempdir:
        typ_path = os.path.join(tempdir, "output.typ")
        pdf_path = os.path.join(tempdir, "output.pdf")

        # Copia il sorgente C++ nella cartella temporanea
        cpp_name = os.path.basename(cpp_abs)
        cpp_temp_path = os.path.join(tempdir, cpp_name)
        shutil.copyfile(cpp_abs, cpp_temp_path)

        # Path che Typst vedrà (relativo alla root del progetto = tempdir)
        cpp_rel = cpp_name

        while True:
            # Genera il .typ con larghezza aggiornata
            with open(typ_path, "w", encoding="utf-8") as f:
                f.write(TEMPLATE % (page_width, cpp_rel))

            print(f"Compilo con larghezza pagina = {page_width} cm ...")

            # Compila con Typst
            compile_pdf(typ_path, tempdir)

            # Typst genera automaticamente output.pdf accanto a output.typ
            # (stesso basename, estensione .pdf)
            if not os.path.exists(pdf_path):
                print("ERRORE: PDF non generato da Typst")
                break

            # Conta le frecce nel PDF
            arrow_pdf = count_arrow_pdf(pdf_path)
            print(f"Occorrenze → nel PDF: {arrow_pdf}")

            if arrow_pdf == arrow_cpp:
                print("Match ottenuto! Nessuna espansione aggiuntiva.")
                break

            if arrow_pdf > arrow_cpp:
                print("Il PDF contiene più → del .cpp → aumento larghezza di 1 cm")
                page_width += 1
            else:
                print("ERRORE: Il PDF contiene meno → del cpp (non dovrebbe accadere)")
                break

        # Copia il PDF finale nella working directory
        final_path = os.path.join(os.getcwd(), final_pdf_name)
        shutil.copyfile(pdf_path, final_path)

        print(f"\nPDF finale generato: {final_path}")


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Utilizzo: python script.py file.cpp")
        sys.exit(1)

    generate_pdf(sys.argv[1])


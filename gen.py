import subprocess
import tempfile
import os
import sys
import shutil

TEMPLATE = r"""
#set page(height: auto, width: auto)

#raw(
  read("%s"),
  lang: "cpp",
)
"""

def compile_pdf(typ_path, workdir):
    # Compila il file Typst in PDF
    # read all at typ_path and print
    with open(typ_path, "r", encoding="utf-8") as f:
        print("Contenuto del file .typ da compilare:")
        print(f.read())
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


    with tempfile.TemporaryDirectory() as tempdir:
        typ_path = os.path.join(tempdir, "output.typ")
        pdf_path = os.path.join(tempdir, "output.pdf")

        # Copia il sorgente C++ nella cartella temporanea
        cpp_name = os.path.basename(cpp_abs)
        cpp_temp_path = os.path.join(tempdir, cpp_name)
        shutil.copyfile(cpp_abs, cpp_temp_path)

        # Path che Typst vedrà (relativo alla root del progetto = tempdir)
        cpp_rel = cpp_name

        # Genera il .typ con larghezza aggiornata
        with open(typ_path, "w", encoding="utf-8") as f:
            f.write(TEMPLATE % (cpp_rel))

        # Compila con Typst
        compile_pdf(typ_path, tempdir)

        # Typst genera automaticamente output.pdf accanto a output.typ
        # (stesso basename, estensione .pdf)
        if not os.path.exists(pdf_path):
            print("ERRORE: PDF non generato da Typst")
            return

        # Copia il PDF finale nella working directory
        final_path = os.path.join(os.getcwd(), final_pdf_name)
        shutil.copyfile(pdf_path, final_path)

        print(f"\nPDF finale generato: {final_path}")


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Utilizzo: python script.py file.cpp")
        sys.exit(1)

    generate_pdf(sys.argv[1])



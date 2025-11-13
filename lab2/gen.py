import subprocess
import tempfile
import os
import sys
import shutil

TEMPLATE = r"""
\documentclass[border=1cm]{standalone}

\usepackage{fontspec}
\setmonofont{FreeMono}

\usepackage{minted}
\usemintedstyle{perldoc}

\begin{document}

\begin{minipage}{%dcm}
\inputminted[encoding=utf8,breaklines]{cpp}{%s}
\end{minipage}

\end{document}
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

def compile_pdf(tex_path, workdir):
    subprocess.run([
        "xelatex", "-shell-escape",
        "-interaction=nonstopmode",
        tex_path
    ], cwd=workdir, check=True)

def generate_pdf(cpp_file):
    if not os.path.exists(cpp_file):
        print("Errore: file .cpp non trovato:", cpp_file)
        sys.exit(1)

    cpp_abs = os.path.abspath(cpp_file)

    base_name = os.path.splitext(os.path.basename(cpp_file))[0]
    final_pdf_name = base_name + ".pdf"

    arrow_cpp = count_arrow(cpp_file)
    print(f"Occorrenze → nel file .cpp: {arrow_cpp}")

    minipage_width = 19  # cm iniziale

    with tempfile.TemporaryDirectory() as tempdir:
        tex_path = os.path.join(tempdir, "output.tex")
        pdf_path = os.path.join(tempdir, "output.pdf")

        while True:
            # Genera .tex con minipage aggiornata
            with open(tex_path, "w", encoding="utf-8") as f:
                f.write(TEMPLATE % (minipage_width, cpp_abs))

            print(f"Compilo con minipage = {minipage_width} cm ...")

            # Compila
            compile_pdf(tex_path, tempdir)

            # Conta le frecce nel pdf
            arrow_pdf = count_arrow_pdf(pdf_path)
            print(f"Occorrenze → nel PDF: {arrow_pdf}")

            if arrow_pdf == arrow_cpp:
                print("Match ottenuto! Nessuna espansione aggiuntiva.")
                break

            if arrow_pdf > arrow_cpp:
                print("Il PDF contiene più → del .cpp → aumento minipage di 1 cm")
                minipage_width += 1
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


#!/bin/bash

# Script per processare tutte le cartelle lab* e pila

# Ottieni il percorso dello script
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# Vai alla directory dello script
cd "$SCRIPT_DIR"

# Trova tutte le cartelle che iniziano con "lab" o "pila"
for dir in lab* pila; do
    # Controlla se la directory esiste
    if [ -d "$dir" ]; then
        echo "==========================================="
        echo "Processando cartella: $dir"
        echo "==========================================="
        
        cd "$dir"
        
        # 1. Chiama gen.py per ogni file *_commented.cpp
        if [ -f "gen.py" ]; then
            echo "Trovato gen.py nella cartella $dir"
            for commented_file in *_commented.cpp; do
                if [ -f "$commented_file" ]; then
                    echo "Eseguendo gen.py su $commented_file"
                    python3 gen.py "$commented_file"
                    
                    # Rinomina il PDF generato rimuovendo _commented
                    base_name="${commented_file%.cpp}"  # es1_commented
                    pdf_name="${base_name}.pdf"         # es1_commented.pdf
                    if [ -f "$pdf_name" ]; then
                        new_name="${base_name/_commented/}.pdf"  # es1.pdf
                        echo "Rinominando $pdf_name in $new_name"
                        mv "$pdf_name" "$new_name"
                    fi
                fi
            done
        fi
        
        # 2. Chiama xelatex -shell-escape su ogni file testo*.tex
        for tex_file in testo*.tex; do
            if [ -f "$tex_file" ]; then
                echo "Compilando $tex_file con xelatex"
                xelatex -shell-escape "$tex_file"
            fi
        done
        
        # 3. Entra dentro altri_esercizi se esiste
        if [ -d "altri_esercizi" ]; then
            echo "Entrando in altri_esercizi..."
            cd altri_esercizi
            
            # Chiama xelatex -shell-escape su esercizi.tex
            if [ -f "esercizi.tex" ]; then
                echo "Compilando esercizi.tex con xelatex"
                xelatex -shell-escape esercizi.tex
            fi
            
            # Torna alla cartella parent (lab*/pila)
            cd ..
        fi
        
        # Torna alla cartella principale
        cd "$SCRIPT_DIR"
        
        echo ""
    fi
done

echo "==========================================="
echo "Processamento completato!"
echo "==========================================="

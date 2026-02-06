#!/bin/bash

# Script per compilare tutti i file .typ e i file es*_commented.cpp in PDFs
# Crea una struttura pdf/ che replica le cartelle lab* ricorsivamente

set -e  # Esce in caso di errore

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PDF_DIR="$SCRIPT_DIR/pdf"

# Funzione ricorsiva per processare una directory
process_directory() {
    local source_dir="$1"
    local dest_dir="$2"
    local indent="$3"
    
    # Crea la directory di destinazione
    mkdir -p "$dest_dir"
    
    cd "$source_dir"
    
    # Compila tutti i file .typ
    for typ_file in *.typ; do
        if [ -f "$typ_file" ]; then
            echo "${indent}Compilazione $typ_file..."
            typst compile "$typ_file" "$dest_dir/${typ_file%.typ}.pdf"
        fi
    done
    
    # Compila tutti i file es*_commented.cpp e *_commented.cpp con gen.py
    for cpp_file in *_commented.cpp; do
        if [ -f "$cpp_file" ]; then
            echo "${indent}Compilazione $cpp_file con gen.py..."
            # gen.py genera il PDF nella directory corrente
            python3 "$SCRIPT_DIR/gen.py" "$cpp_file"
            
            # Il PDF generato ha lo stesso nome del cpp ma con estensione .pdf
            generated_pdf="${cpp_file%.cpp}.pdf"
            
            # Lo rinominiamo rimuovendo "_commented" e lo spostiamo in pdf/
            base_name="${cpp_file%_commented.cpp}"
            final_pdf="$base_name.pdf"
            
            if [ -f "$generated_pdf" ]; then
                mv "$generated_pdf" "$dest_dir/$final_pdf"
                echo "${indent}  → $final_pdf creato"
            else
                echo "${indent}  ERRORE: $generated_pdf non trovato"
            fi
        fi
    done
    
    # Processa ricorsivamente tutte le sottocartelle
    for subdir in */; do
        if [ -d "$subdir" ]; then
            subdir_name=$(basename "$subdir")
            echo "${indent}--- Elaborazione sottocartella $subdir_name ---"
            process_directory "$source_dir/$subdir_name" "$dest_dir/$subdir_name" "${indent}  "
        fi
    done
}

# Crea la cartella pdf se non esiste
mkdir -p "$PDF_DIR"

echo "=== Compilazione PDFs ==="
echo "Directory di lavoro: $SCRIPT_DIR"
echo "Directory output: $PDF_DIR"
echo ""

# Trova tutte le cartelle lab*
for lab_dir in "$SCRIPT_DIR"/lab*/; do
    if [ ! -d "$lab_dir" ]; then
        continue
    fi
    
    lab_name=$(basename "$lab_dir")
    echo "--- Elaborazione $lab_name ---"
    
    # Crea la corrispondente cartella in pdf/
    pdf_lab_dir="$PDF_DIR/$lab_name"
    
    # Processa la directory lab e tutte le sue sottocartelle ricorsivamente
    process_directory "$lab_dir" "$pdf_lab_dir" "  "
    
    echo ""
done

cd "$SCRIPT_DIR"
echo "=== Compilazione completata ==="
echo "I PDF sono stati salvati in: $PDF_DIR"

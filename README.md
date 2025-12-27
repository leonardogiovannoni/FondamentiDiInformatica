# Fondamenti di Informatica 💻

Collezione completa di esercizi di laboratorio per il corso di Fondamenti di Informatica, con codice C++ commentato e documentazione in formato PDF.

## 📁 Struttura del Repository

Il repository è organizzato in laboratori (`lab1` - `lab9`), ciascuno contenente:

- **Esercizi principali**: file `.cpp` con codice pulito e versioni `_commented.cpp` con commenti dettagliati
- **Testi degli esercizi**: file `.typ` (Typst) con le specifiche degli esercizi
- **Esercizi aggiuntivi**: cartella `altri_esercizi/` con materiale supplementare

```
FondamentiDiInformatica/
├── lab1/           # Introduzione alla programmazione
├── lab2/           # Cicli e iterazioni
├── lab3/           # Strutture di controllo
├── lab4/           # Array e puntatori
├── lab5/           # Funzioni e modularità
├── lab6/           # Stringhe e gestione memoria
├── lab7/           # Strutture dati
├── lab8/           # File e I/O
├── lab9/           # Progetti avanzati
└── pdf/            # PDF generati automaticamente
```

## 🛠️ Strumenti

### `gen.py`
Script Python per generare PDF da file C++ commentati usando Typst come motore di rendering.

**Utilizzo:**
```bash
python gen.py path/to/file_commented.cpp
```

### `compile_pdfs`
Script bash automatico per compilare tutti i file del repository in PDF.

**Funzionalità:**
- Crea la struttura `pdf/lab*/` rispecchiando l'organizzazione del repository
- Compila tutti i file `.typ` (testi degli esercizi)
- Converte i file `es*_commented.cpp` in PDF usando `gen.py`
- Rinomina automaticamente i PDF da `es*_commented.pdf` a `es*.pdf`

**Utilizzo:**
```bash
./compile_pdfs
```

I PDF generati saranno disponibili nella cartella `pdf/` con la stessa struttura dei laboratori.

## 📋 Requisiti

- **Compilatore C++**: GCC o Clang (C++11 o superiore)
- **Python 3**: per eseguire `gen.py`
- **Typst**: per la compilazione dei documenti
  ```bash
  # Installazione Typst
  curl -fsSL https://typst.app/install.sh | sh
  ```

## 🚀 Quick Start

1. **Clona il repository:**
   ```bash
   git clone https://github.com/leonardogiovannoni/FondamentiDiInformatica.git
   cd FondamentiDiInformatica
   ```

2. **Compila tutti i PDF:**
   ```bash
   chmod +x compile_pdfs
   ./compile_pdfs
   ```

3. **Compila ed esegui un singolo esercizio:**
   ```bash
   g++ -o esercizio lab1/es1.cpp
   ./esercizio
   ```

## 📝 Contenuto dei Laboratori

| Lab | Argomento | Esercizi |
|-----|-----------|----------|
| Lab 1 | Introduzione al C++ | Variabili, tipi di dato, I/O |
| Lab 2 | Cicli | `for`, `while`, `do-while` |
| Lab 3 | Controllo di flusso | `if-else`, `switch`, operatori logici |
| Lab 4 | Array e puntatori | Array, gestione memoria, aritmetica puntatori |
| Lab 5 | Funzioni | Definizione, passaggio parametri, ricorsione |
| Lab 6 | Stringhe | `char[]`, `string`, manipolazione testo |
| Lab 7 | Strutture dati | `struct`, liste, gestione dati |
| Lab 8 | File I/O | Lettura/scrittura file, stream |
| Lab 9 | Progetti | Centro stampe, liste colorate |

## 🤝 Contribuire

Contributi sono benvenuti! Per aggiungere esercizi o migliorare la documentazione:

1. Fork il repository
2. Crea un branch per le modifiche (`git checkout -b feature/nuova-funzionalita`)
3. Commit delle modifiche (`git commit -m 'Aggiunge nuova funzionalità'`)
4. Push al branch (`git push origin feature/nuova-funzionalita`)
5. Apri una Pull Request

## 📄 Licenza

Questo progetto è distribuito per scopi didattici.

## 👤 Autore

**Leonardo Giovannoni**
- GitHub: [@leonardogiovannoni](https://github.com/leonardogiovannoni)

---

_Ultimo aggiornamento: Dicembre 2025_

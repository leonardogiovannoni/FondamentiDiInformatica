#set page(
  width: 21cm,
  height: 29.7cm,
  margin: (top: 0.24cm, bottom: 0.54cm, left: 0.44cm, right: 0.44cm),
)
#set text(size: 12pt, font: "New Computer Modern")
#set par(leading: 0.65em, spacing: 0.65em)
#set block(spacing: 0.65em)
#show list: set block(above: 1.2em, below: 1.2em)
#set list(spacing: 1.2em)
#show title: set block(above: 1.4em, below: 1em)
#show title: it => [
  #v(1em)
  #align(center)[
    #set text(size: 23pt, weight: "regular")
    #it.body
  ]
]

#title[Esercizio: Centro Stampe]
= Prova scritta 09-09-2025
Un centro stampe dispone di `p` stampanti identiche (`1 ≤ p ≤ 10`). Ogni stampante può eseguire una
sola coda di lavori (jobs) e stampa una pagina al minuto (i minuti trascorsi corrispondono alle pagine
stampate). Le stampanti sono numerate a partire da 1. Il numero di lavori in coda ad una stampante è
potenzialmente illimitato. Un lavoro consiste in un identificatore e nel numero di pagine. L'identificatore è
una stringa di al massimo 20 caratteri, solo lettere minuscole e maiuscole dell'alfabeto e identifica
univocamente un lavoro. Implementare le seguenti operazioni che possono essere effettuate su un
centro stampe:
- `inizializza(c, ncode)`: funzione che inizializza un centro stampe `c`, con `ncode` code vuote.
- `inserisci(c, j, idx, pages)`: funzione che inserisce nella coda `j` un nuovo lavoro con identificatore `idx` e numero di pagine `pages`. La funzione restituisce `true`, se l'operazione ha successo; altrimenti restituisce `false`.
- `meno_carica(c)`: funzione che restituisce il numero della stampante del centro stampa `c` con meno numero di pagine totali in attesa. Se più stampanti condividono lo stesso numero minimo, viene restituita la stampante con numero più basso.
- `avanza_tempo(c, min)`: funzione che simula il passare di `min` minuti. Ogni stampante stampa al più `min` pagine; i lavori completati vengono rimossi. Restituisce il numero totale di lavori completati.
- `accoda(c, idx, pag)`: funzione che inserisce in coda alla stampante meno carica un nuovo lavoro con identificatore `idx` e numero di pagine `pag`. La funzione restituisce true, se l'operazione ha successo; altrimenti restituisce `false`.
- `stampa(c)`: funzione che per ogni coda stampa la stringa "printer", il numero della stampante e il carattere ':', seguito la lista dei lavori in coda. Per un lavoro sono mostrati l'identificatore e il numero di pagine separati dal carattere ',' e racchiusi fra parentesi quadre. I lavori in coda sono stampati dal meno recente al più recente; se una coda è vuota si mostra `[]`. ``` printer 1:[id1,pg1][[id2,pg2]
  printer 2:[]```

#grid(
  columns: (1fr, 1fr),
  column-gutter: 2em,
  [
    == Main di esempio
    ```cpp
    int main() {
        CentroStampe c;
        inizializza(c, 2);
        stampa(c);
        
        inserisci(c, 1, "dd", 10);
        inserisci(c, 1, "fff", 15);
        stampa(c);
        
        int n = meno_carica(c);
        cout << n << endl;
        accoda(c, "e", 30);
        stampa(c);
       
        int finiti = avanza_tempo(c, 12);
        cout << finiti << endl;
     
        stampa(c);
        
        return 0;
    }
    ```
  ],
  [
    == Output
    ```



    printer1:[]
    printer2:[]


    printer1:[dd,10][fff,15]
    printer2:[]
    
    2

    printer1:[dd,10][fff,15]
    printer2:[e,30] 

    1
    
    printer1:[fff,13]
    printer2:[e,18]
    ```
  ],
)

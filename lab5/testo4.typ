#set page(
  width: 21cm, 
  height: 29.7cm,
  margin: (top: 2.24cm, bottom: 2.24cm, left: 2.24cm, right: 2.24cm)
)
#set text(size: 12pt, font: "New Computer Modern")
#set par(leading: 0.65em, spacing: 0.65em)
#set block(spacing: 0.65em)

// Configuration for bullet lists
#show list: set block(above: 1.2em, below: 1.2em)
#set list(spacing: 1.2em)

// Configuration for numbered lists
#show enum: set block(above: 1.2em, below: 1.2em)
#set enum(spacing: 1.2em)

#show title: set block(above: 1.4em, below: 1em)
#show title: it => [
  #v(1em)
  #align(center)[
    #set text(size: 23pt, weight: "regular")
    #it.body
  ]
]

#title[Esercizio: Menù]

#v(4em)

Scrivi un programma in linguaggio *C++* che mostri un *menù di funzioni* e permetta all'utente di scegliere tra diverse operazioni:

- *s*: stampa un rettangolo di asterischi di dimensione $N times M$;
- *r*: calcola la radice quadrata di un numero;
- *e*: termina l'esecuzione del programma.

Il programma deve:
+ visualizzare un menù all'inizio di ogni iterazione;
+ leggere il comando scelto dall'utente;
+ eseguire l'operazione corrispondente;
+ terminare solo quando l'utente inserisce il comando di uscita `e`.

#v(10pt)
== Esempi

#grid(
  columns: (1fr, 1fr),
  column-gutter: 2em,
  [
    *Esempio 1: stampa rettangolo*

    `MENU fondamenti funzioni` \
    `s: Stampa rettangolo NxM di asterischi` \
    `r: Radice quadrata` \
    `e: esci` \
    `inserisci il comando..` \
    #text(fill: orange)[`s`] \
    `inserisci altezza e larghezza..` \
    #text(fill: orange)[`3 5`] \
    `* * * * *` \
    `* * * * *` \
    `* * * * *` \
    `MENU fondamenti funzioni` \
    `s: Stampa rettangolo NxM di asterischi` \
    `r: Radice quadrata` \
    `e: esci` \
    `inserisci il comando..` \
    #text(fill: orange)[`e`] \
    `Terminazione`
  ],
  [
    *Esempio 2: radice quadrata*

    `MENU fondamenti funzioni` \
    `s: Stampa rettangolo NxM di asterischi` \
    `r: Radice quadrata` \
    `e: esci` \
    `inserisci il comando..` \
    #text(fill: orange)[`r`] \
    `inserisci un numero..` \
    #text(fill: orange)[`9`] \
    `la radice quadrata di 9 e': 3` \
    `MENU fondamenti funzioni` \
    `s: Stampa rettangolo NxM di asterischi` \
    `r: Radice quadrata` \
    `e: esci` \
    `inserisci il comando..` \
    #text(fill: orange)[`e`] \
    `Terminazione`
  ]
)
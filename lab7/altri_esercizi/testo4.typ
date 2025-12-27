#set page(
  width: 21cm, 
  height: 29.7cm,
  margin: (top: 2.54cm, bottom: 2.54cm, left: 2.54cm, right: 2.54cm)
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

#show heading: set block(above: 1.4em, below: 1em)
#show heading.where(level: 1): it => [
  #v(1em)
  #align(center)[
    #set text(size: 21pt, weight: "regular")
    #it.body
  ]
]

= Esercizio: Frequenza lettere in una stringa

#v(1em)

Scrivi un programma in linguaggio *C++* che calcoli la frequenza di ogni lettera dell'alfabeto presente in una stringa inserita dall'utente.

Si richiede di:

- implementare una funzione `conta_caratteri` che:
  - riceva in ingresso la stringa e un array di interi per le frequenze;
  - scorra la stringa e incrementi il contatore corrispondente alla lettera trovata;
  - gestisca le lettere in modo _case-insensitive_ (es. 'A' e 'a' incrementano lo stesso indice);
  - ignori qualsiasi carattere non alfabetico (numeri, simboli, ecc.);
- stampare l'array nel formato mostrato nell'esempio.

== Esempi

*Esempio 1:*

`Inserisci una parola..` #text(fill: orange)[`Ciao!`]

`{a: 1, b: 0, c: 1, d: 0, e: 0, f: 0, g: 0, h: 0, i: 1, j: 0, k: 0, l: 0, m: 0, n: 0, o: 1, p: 0, q: 0, r: 0, s: 0, t: 0, u: 0, v: 0, w: 0, x: 0, y: 0, z: 0}`

#v(1em)

*Esempio 2:*

`Inserisci una parola..` #text(fill: orange)[`Thequickbrownfoxjumpsoverthelazydog`]

`{a: 1, b: 1, c: 1, d: 1, e: 3, f: 1, g: 1, h: 2, i: 1, j: 1, k: 1, l: 1, m: 1, n: 1, o: 4, p: 1, q: 1, r: 2, s: 1, t: 2, u: 2, v: 1, w: 1, x: 1, y: 1, z: 1}`

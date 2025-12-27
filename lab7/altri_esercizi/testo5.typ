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

= Esercizio: Word Count

#v(1em)

Scrivi un programma in linguaggio *C++* che conti le occorrenze di parole all'interno di una frase formattata.

Nel `main`:

- Leggere una stringa dove le parole sono separate dal carattere underscore `_` (es. `ciao_mondo_ciao`);
- Contare il numero di occorrenze di ciascuna parola all'interno della frase;
- Stampare il risultato.

*Suggerimento:* _Utilizzare la funzione di libreria `strtok` per ottenere le parole a partire dalla frase._

== Esempi

*Esempio 1:*

`Inserisci una frase intervallata da _:` #text(fill: orange)[`ciao_mondo_ciao_prova_mondo`]

`{"ciao": 2, "mondo": 2, "prova": 1}`

#v(1em)

*Esempio 2:*

`Inserisci una frase intervallata da _:` #text(fill: orange)[`a_b_a_b_c`]

`{"a": 2, "b": 2, "c": 1}`

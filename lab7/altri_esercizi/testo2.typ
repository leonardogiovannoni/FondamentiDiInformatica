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

= Esercizio: Gestione Dinamica Studenti

#v(1em)

In linguaggio *C++*, gestisci un elenco di studenti utilizzando l'allocazione dinamica della memoria.

Si richiede di:

- Chiedere all'utente il numero $N$ di studenti da inserire.
- Salvare in memoria l'elenco di studenti inserito.
- Stampare l'elenco degli studenti.

Ogni studente possiede un nome (stringa di caratteri), un'età (intero) e una media voti (numero in virgola mobile).

== Esempio

`Quanti studenti vuoi inserire?` #text(fill: orange)[`2`]

#v(0.5em)

`Inserisci nome, eta' e media dello studente n.1`

#text(fill: orange)[`Mario 21 27.5`]

#v(0.5em)

`Inserisci nome, eta' e media dello studente n.2`

#text(fill: orange)[`Luigi 22 29`]

#v(0.5em)

`Elenco Studenti:`

`1. Nome: Mario | Eta': 21 | Media: 27.5`

`2. Nome: Luigi | Eta': 22 | Media: 29`

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

= Esercizio: Filtro Temperature

#v(1em)

In linguaggio *C++*, realizza un programma per l'analisi di dati ambientali utilizzando l'allocazione dinamica.

Si richiede di:

- Definire una struttura `TempLog` contenente un array dinamico di valori decimali (`float`) e la relativa dimensione.
- Chiedere all'utente il numero $N$ di temperature da registrare e popolare la struttura.
- Chiedere all'utente una *soglia di allarme* (valore decimale).
- Creare e restituire una *nuova* struttura `TempLog` contenente solo le temperature strettamente superiori alla soglia inserita.
- Stampare a video sia il log completo che quello filtrato.
- Gestire correttamente la deallocazione della memoria per entrambe le strutture (originale e filtrata).

== Esempio

`Quante temperature vuoi inserire?` #text(fill: orange)[`5`]

#v(0.5em)

`Temp 0:` #text(fill: orange)[`22.5`]

`Temp 1:` #text(fill: orange)[`18.0`]

`Temp 2:` #text(fill: orange)[`35.2`]

`Temp 3:` #text(fill: orange)[`41.0`]

`Temp 4:` #text(fill: orange)[`29.9`]

`Tutte le temperature: [ 22.5, 18, 35.2, 41, 29.9 ]`

`Inserisci soglia di allarme:` #text(fill: orange)[`30.0`]

`Temperature CRITICHE: [ 35.2, 41 ]`

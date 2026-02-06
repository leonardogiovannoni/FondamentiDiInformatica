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

#show title: set block(above: 1.4em, below: 1em)
#show title: it => [
  #v(1em)
  #align(center)[
    #set text(size: 23pt, weight: "regular")
    #it.body
  ]
]
#title[Esercizio: Puntatore al valore maggiore]

#v(7em)

Scrivi un programma in linguaggio *C++* che:

- legga da tastiera due numeri interi;
- crei un puntatore che punti al numero maggiore tra i due;
- visualizzi a schermo il valore del numero maggiore tramite il puntatore;
- modifichi, sempre attraverso il puntatore, il valore del numero maggiore portandolo a zero;
- mostri infine i valori aggiornati di entrambi i numeri.

#v(10pt)
== Esempio

=== Input:
```text
5 10
```

=== Output:

```text
Il numero maggiore e': 10
Dopo l'azzeramento, i valori sono: a = 5, b = 0
```
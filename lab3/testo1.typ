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
  #v(4em)
  #align(center)[
    #set text(size: 21pt, weight: "regular")
    #it.body
  ]
]

= Esercizio: Quadrato cavo con diagonale principale

#v(7em)

Scrivi un programma in linguaggio *C++* che:

+ *Legga* da tastiera un numero intero positivo `n`, rappresentante la dimensione del lato di un quadrato.
+ *Disegni* un quadrato di lato `n` utilizzando il carattere `*`, in modo tale che:
  - siano visibili i quattro bordi del quadrato;
  - sia visibile anche la *diagonale principale* (da sinistra in alto a destra in basso);
  - le altre posizioni interne siano vuote (spazi);
  - ogni `*` sia intervallato da uno spazio.
+ Se l'utente inserisce un valore minore di 1, il programma deve visualizzare un messaggio di errore.

Utilizzare una funzione per disegnare il quadrato.

#v(10pt)
== Esempio

=== Input:
```text
5
```

=== Output:

```text
* * * * *
* *     *
*   *   *
*     * *
* * * * *
```


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

= Esercizio 2: Stampa triangolo di asterischi

#v(7em)

Scrivi un programma in linguaggio *C++* che:

+ *Legga* da tastiera un numero intero positivo `n`.
+ *Stampi* a video un *triangolo rettangolo di asterischi* con `n` righe, dove:
  - la prima riga contiene 1 asterisco (`*`),
  - la seconda riga contiene 2 asterischi,
  - la terza riga 3 asterischi,
  - e così via, fino alla riga `n`, che contiene `n` asterischi.

#v(10pt)
== Esempio

=== Input:
```text
4
```

=== Output:

```text
*
**
***
****
```

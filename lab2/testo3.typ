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

= Esercizio 3: Calcolo del Massimo Comune Divisore (MCD)

#v(7em)

Scrivi un programma in linguaggio *C++* che:

+ *Legga* da tastiera due numeri interi positivi `a` e `b`.
+ *Calcoli* il loro *massimo comune divisore (MCD)* utilizzando l'*algoritmo di Euclide*.
+ *Stampi* a video il risultato.

L'algoritmo di Euclide per il calcolo del MCD funziona nel seguente modo:

- Finché `b` è diverso da 0:
  + si calcola `a % b` (il resto della divisione di `a` per `b`)
  + si assegna alle variabili `a` e `b` rispettivamente i valori di `b` e del resto calcolato al passo precedente.
- Quando `b` diventa 0, il valore di `a` è il *massimo comune divisore*.

#v(10pt)
== Esempio

=== Input:
```text
36 24
```

=== Output:

```text
Il massimo comune divisore è: 12
```


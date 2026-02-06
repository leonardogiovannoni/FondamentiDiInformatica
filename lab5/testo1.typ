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
#title[Esercizio: Somma dei numeri da 0 a n (ricorsione)]

#v(7em)

Scrivi un programma in linguaggio *C++* che:

- chieda all'utente di inserire un numero intero positivo $n$;
- calcoli, utilizzando una *funzione ricorsiva*, la somma dei numeri da $0$ a $n$, estremi inclusi;
- stampi a video il risultato ottenuto.

#v(10pt)
== Esempio

=== Input:
```text
Inserisci un numero intero positivo: 5
```

=== Output:

```text
La somma dei numeri da 0 a 5 è: 15
```

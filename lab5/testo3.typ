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

= Esercizio: Verifica ricorsiva di numeri pari in un array

#v(7em)

Scrivi un programma in linguaggio *C++* che:

- legga da tastiera $N = 10$ numeri interi e li memorizzi nell'array;
- stampi a video il contenuto dell'array;
- utilizzi una *funzione ricorsiva* per verificare se tutti gli elementi dell'array sono numeri pari;
- stampi un messaggio che indichi se tutti gli elementi sono pari oppure no.

La funzione ricorsiva avrà una firma simile alla seguente:
#v(1em)
```cpp
bool tutti_pari(int arr[], int n);
```

#v(10pt)
== Esempi

#grid(
columns: (1fr, 1fr),
column-gutter: 2em,
[
=== Input:
```text 
4 8 10
```

=== Output:
```text
Array: 4 8 10 
Gli elementi sono tutti pari
```
],
[
=== Input:
```text
3 6 9
```

=== Output:
```text
Array: 3 6 9 
Non tutti gli elementi sono pari
```

]
)
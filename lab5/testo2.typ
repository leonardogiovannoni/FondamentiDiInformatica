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
#title[Esercizio: Inversione di un array]

#v(7em)

Scrivi un programma in linguaggio *C++* che:

- dichiari un array di dimensione fissa $N = 5$;
- legga da tastiera $N$ numeri interi e li memorizzi nell'array;
- stampi a video il contenuto originale dell'array;
- inverta l'ordine degli elementi dell'array;
- stampi a video l'array invertito.

La funzione avrà una firma simile alla seguente:
#v(1em)
```cpp
void inverti(int arr[], int n);
```

#v(10pt)
== Esempio

=== Input:

```text
Inserisci 5 numeri interi:
1 2 3 4 5
```

=== Output:

```text
Array: 1 2 3 4 5 
Array invertito: 5 4 3 2 1
```

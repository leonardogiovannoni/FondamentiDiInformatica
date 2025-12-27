#set page(
  width: 21cm, 
  height: 29.7cm,
  margin: (top: 1.24cm, bottom: 1.24cm, left: 1.24cm, right: 1.24cm)
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

= Esercizio: Lettura, stampa e manipolazione di matrici

#v(1em)

== Parte A: Lettura e stampa di una matrice

Scrivi un programma in linguaggio *C++* che:

- dichiari una matrice di dimensione fissa $2 times 3$;
- legga tutti gli elementi della matrice da tastiera, riempiendola riga per riga;
- stampi la matrice a video, mantenendo la struttura a righe e colonne.

Le funzioni da utilizzare saranno le seguenti:
#v(1em)
```cpp
void leggi_matrice(int *m, int rows, int cols);
void stampa_matrice(int *m, int rows, int cols);
```

#v(10pt)
=== Esempio

=== Input:

```text
1 2 3 4 5 6
```

=== Output:

```text
1 2 3
4 5 6
```

#v(0em)

== Parte B: Inversione delle colonne di una matrice

Estendi il programma precedente aggiungendo una funzione che *inverta l'ordine delle colonne* della matrice, per ogni riga.

  - Dopo aver letto e stampato la matrice, il programma deve invertire le colonne della matrice.
  - Successivamente deve stamparla nuovamente.

La funzione da utilizzare sarà:
#v(1em)

```cpp
void inverti_colonne(int *m, int rows, int cols);
```

#v(10pt)
=== Esempio

=== Input:

```text
1 2 3 4 5 6
```

=== Output:

```text
1 2 3
4 5 6
Matrice dopo inversione colonne:
3 2 1
6 5 4
```

#set page(
  width: 21cm,
  height: 29.7cm,
  margin: (top: 1.24cm, bottom: 1.24cm, left: 1.24cm, right: 1.24cm),
)

#set text(size: 12pt, font: "New Computer Modern")
#set par(leading: 0.65em, spacing: 0.65em)
#set block(spacing: 0.65em)

// Configuration for bullet lists
#show list: set block(above: 1.2em, below: 1.2em)
#set list(marker: ([•], [--]), spacing: 0.8em, indent: 1em)

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

#set heading(numbering: none)

#set par(
  justify: true,
  first-line-indent: 0pt,
  leading: 0.65em,
)


#show heading.where(level: 1): set heading(numbering: "1.")
#title[Esercizi di Programmazione (C++) - Ricorsione]
#v(1em)

= Calcolo del fattoriale

*Testo. * Scrivi una funzione ricorsiva che calcola il *fattoriale* di un numero intero non negativo `n`.
Per definizione:
$
f(n) = cases(
  1 & "se " n = 0,
  n dot f(n - 1) & "se " n > 0
)
$
Il programma deve leggere un numero intero positivo e stampare il suo fattoriale.

#v(10pt)

== Esempio

=== Input
```text
5
```

#v(10pt)
=== Output
```text
Il fattoriale di 5 e': 120
```

= Conta dei numeri positivi

*Testo. * Leggi 8 numeri interi in un array e scrivi una funzione ricorsiva che conta quanti elementi sono *strettamente positivi*.

#v(10pt)

== Esempio

=== Input
```text
3 -1 7 0 4 -5 2 8
```

#v(10pt)
=== Output
```text
Ci sono 5 numeri positivi.
```

= Massimo elemento di un array

*Testo. * Scrivi una funzione ricorsiva che calcola il *valore massimo* all'interno di un array di interi positivi.

#v(10pt)

== Esempio

=== Input
```text
4 9 2 7 1 5
```

#v(10pt)
=== Output
```text
Il valore massimo e': 9
```

= Ricerca di un valore nell'array

*Testo. * Scrivi una funzione ricorsiva che stabilisce se un dato valore `x` è *presente* in un array di interi.

#v(10pt)

== Esempio

=== Input
```text
3 7 1 9 2 6 4
9
```

#v(10pt)
=== Output
```text
9 e' presente nell'array.
```

= Inversione di un array

*Testo. * Scrivi un programma che inverte un array usando una funzione ricorsiva.

#v(10pt)

== Esempio

=== Input
```text
1 2 3 4 5 6 7 8
```

#v(10pt)
=== Output
```text
Array invertito: 8 7 6 5 4 3 2 1
```

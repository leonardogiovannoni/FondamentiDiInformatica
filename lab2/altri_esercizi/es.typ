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
#title[Esercizi di Programmazione (C++)]
#v(1em)

= Somma dei primi n numeri naturali a partire da 0

*Testo. * Leggi un intero `n` e calcola la somma dei primi `n` numeri naturali a partire da `0`, cioe' $0 + 1 + 2 + dots + (n - 1)$. Stampa la somma. Se $n <= 0$, la somma vale 0.

#v(10pt)

== Esempio

=== Input
```text
5
```

#v(10pt)
=== Output
```text
La somma fa: 10
```

= Fattoriale di n

*Testo. * Leggi un intero $n >= 0$ e calcola il *fattoriale* $n! = 1 * 2 * dots * n$.

#v(10pt)

== Esempio

=== Input
```text
5
```

#v(10pt)
=== Output
```text
Il fattoriale e' 120
```

= Numeri pari in [0, n) con conteggio e somma

*Testo. * Leggi un intero `n` e stampa tutti i numeri pari compresi tra 0 e $n - 1$. Al termine stampa quante occorrenze sono state stampate e la loro somma complessiva.

#v(10pt)

== Esempio

=== Input
```text
10
```

#v(10pt)
=== Output
```text
0
2
4
6
8
Pari stampati: 5
Somma dei pari: 20
```

= Tabellina di un numero

*Testo. * Leggi un intero `n` e stampa la *tabellina di n* dalla moltiplicazione per 1 alla moltiplicazione per 10, nel formato `n x i = risultato`.

#v(10pt)

== Esempio

=== Input
```text
7
```

#v(10pt)
=== Output
```text
7 x 1 = 7
7 x 2 = 14
7 x 3 = 21
7 x 4 = 28
7 x 5 = 35
7 x 6 = 42
7 x 7 = 49
7 x 8 = 56
7 x 9 = 63
7 x 10 = 70
```

= Minimo, massimo e media intera di N numeri

*Testo. * Leggi un intero $N > 0$ e poi leggi $N$ interi. Stampa il *minimo*, il *massimo* e la *media intera*.

#v(10pt)

== Esempio

=== Input
```text
5
3 10 -2 7 7
```

#v(10pt)
=== Output
```text
Minimo: -2
Massimo: 10
Media intera: 5
```

= I primi n numeri della sequenza di Fibonacci

*Testo. * Leggi un intero `n` e stampa i primi `n` numeri della sequenza di Fibonacci, a partire da 0 e 1. Se $n <= 0$, non stampare nulla; se $n = 1$, stampa solo 0.

#v(10pt)

== Esempio

=== Input
```text
7
```

#v(10pt)
=== Output
```text
0
1
1
2
3
5
8
```

= Numero di cifre, somma delle cifre e numero invertito

*Testo. * Leggi un intero non negativo `n`. Stampa: (1) quante cifre ha, (2) la somma delle cifre, (3) il numero ottenuto invertendo l'ordine delle cifre. Gestisci correttamente il caso `n = 0`.

#v(10pt)

== Esempio

=== Input
```text
12345
```

#v(10pt)
=== Output
```text
Cifre: 5
Somma cifre: 15
Invertito: 54321
```

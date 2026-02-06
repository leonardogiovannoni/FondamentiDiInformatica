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

= Somma degli elementi di un array

*Testo. * Leggi 5 numeri interi e memorizzali in un array. Calcola e stampa la *somma* di tutti gli elementi.

#v(10pt)

== Esempio

=== Input
```text
5 7 2 -1 4
```

#v(10pt)
=== Output
```text
Somma = 17
```

= Valore massimo e minimo

*Testo. * Leggi 6 numeri interi in un array. Trova e stampa il *valore massimo* e il *valore minimo* tra essi.

#v(10pt)

== Esempio

=== Input
```text
4 9 -2 7 1 5
```

#v(10pt)
=== Output
```text
Massimo = 9
Minimo = -2
```

= Conta i numeri negativi

*Testo. * Leggi 10 numeri interi e conta quanti di essi sono *negativi*. Stampa il conteggio finale.

#v(10pt)

== Esempio

=== Input
```text
5 -3 0 -7 12 9 -1 -4 6 8
```

#v(10pt)
=== Output
```text
Numeri negativi: 4
```

= Scambio con puntatori

*Testo. * Scrivi una funzione che scambia due valori interi utilizzando i *puntatori*.
La funzione deve avere la seguente firma:
#v(1em)
```cpp
void scambia(int *a, int *b);
```
#v(1em)
Nel programma principale, leggi due interi, scambiali usando la funzione e stampa i nuovi valori.

#v(10pt)

== Esempio

=== Input
```text
3 10
```

#v(10pt)
=== Output
```text
Dopo scambio: a = 10 b = 3
```

= Media intera degli elementi

*Testo. * Scrivi un programma che calcola la *media intera* dei valori contenuti in un array di numeri interi.

#v(10pt)

== Esempio

=== Input
```text
4 6 8 2 10
```

#v(10pt)
=== Output
```text
Media intera = 6
```

= Verificare se un array è palindromo
*Testo.* Leggi un array di numeri interi e verifica se è _palindromo_, cioè se il primo e l'ultimo elemento coincidono, il secondo e il penultimo, e così via.

Più rigorosamente, un vettore $v = (v_0, v_1, dots, v_(n - 1))$ è palindromo se e solo se:
$ v_i = v_(n - 1 - i) quad forall i, 0 <= i <= floor(n / 2) - 1. $
Se la condizione e' vera per tutte le coppie, stampa `si`, altrimenti `no`.

#v(10pt)

== Esempio

=== Input
```text
1 2 3 2 1
```

#v(10pt)
=== Output
```text
palindromo? si
```

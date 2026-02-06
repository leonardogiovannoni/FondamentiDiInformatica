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

= Triangolo rettangolo cavo di altezza n

*Testo. * Leggi un intero $n >= 1$ e stampa un *triangolo rettangolo cavo* di altezza `n` usando gli asterischi `*`. Devono essere disegnati il cateto sinistro, l'ipotenusa e la base; gli spazi interni restano vuoti. Usa uno spazio doppio per gli spazi vuoti cosi' da mantenere l'allineamento (ad esempio `"* "` e `"  "`).

#v(10pt)

== Esempio

=== Input
```text
5
```

#v(10pt)
=== Output
```text
* 
* *
*   *
*     *
* * * * *
```

= Croce centrale in matrice n x n (con n dispari)

*Testo. * Leggi un intero $n >= 1$ *dispari* e stampa una *croce* in una griglia $n x n$ composta da asterischi `*`: una riga orizzontale e una colonna verticale passano entrambe per l'indice centrale $floor(n / 2)$. Le altre celle sono vuote (usa due spazi per mantenere l'allineamento). Se `n` e' pari o `n < 1`, segnala un errore.

#v(10pt)

== Esempio

=== Input
```text
5
```

#v(10pt)
=== Output
```text
    *     
    *     
* * * * * 
    *     
    *   
```

= Segno di x e valore assoluto
*Testo.* Leggi un intero `x` e stampa due risultati:

- $op("segno")(x)$, definito come:
  $ op("segno")(x) = cases(
    1 & "se " x > 0,
    0 & "se " x = 0,
    -1 & "se " x < 0
  ) $
- $|x|$, il _valore assoluto_ di `x`.

#v(10pt)

== Esempio

=== Input
```text
-17
```

#v(10pt)
=== Output
```text
segno(x) = -1
|x| = 17
```

= Primalita' di n e prossimo primo >= n

*Testo. * Leggi un intero `n` e:
- determina se `n` e' *primo* (stampa `si` oppure `no`);
- stampa il *minimo numero primo* maggiore o uguale a `n`. Se $n <= 2$, il risultato e' 2.

L'algoritmo per il test di primalita' puo' interrompersi a $floor(sqrt(n))$ controllando solo i divisori dispari dopo il 2.

#v(10pt)

== Esempio

=== Input
```text
30
```

#v(10pt)
=== Output
```text
primo(n)? no
prossimo primo >= n: 31
```

= Scambio di due interi e clamp su un intervallo

*Testo. * Leggi due interi `a` e `b`, scambiali (swap) e stampa i nuovi valori. Poi leggi tre interi `x`, `lo`, `hi` con $l o <= h i$ e applica l'operazione di *clamp* a `x`:

$ x arrow.l cases(
  l o & "se " x < l o,
  h i & "se " x > h i,
  x & "altrimenti"
) $

Infine stampa il nuovo valore di `x`.

#v(10pt)

== Esempio

=== Input
```text
3 10
-2 0 7
```

#v(10pt)
=== Output
```text
Dopo swap: a=10 b=3
Clamp(x): 0
```

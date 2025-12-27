#set page(
  width: 21cm, 
  height: 29.7cm,
  margin: (top: 0.5cm, bottom: 0.5cm, left: 0.5cm, right: 0.5cm)
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

= Esercizio: Derivata di un polinomio

#v(1em)

In linguaggio *C++*, implementa una semplice struttura dati per rappresentare un polinomio.

Si richiede di:

- definire una struttura `Polynomial` contenente:
  - un puntatore `int *coeffs`, che rappresenta un vettore dinamico di coefficienti;
  - un intero `len`, contenente la lunghezza del vettore.

- scrivere una funzione `polynomial_init` che inizializzi correttamente la struttura,

- definire una funzione `polynomial_print` che stampi il polinomio nella forma
  $ a_n x^n + a_(n-1) x^(n-1) + dots.h + a_1 x + a_0 $

- definire una funzione `polynomial_derivative` che, dato un polinomio
  $ P(x) = a_0 + a_1 x + dots.h + a_n x^n, $
  costruisca e restituisca un nuovo oggetto `Polynomial` corrispondente alla derivata
  $ P'(x) = a_1 + 2a_2 x + dots.h + n a_n x^(n-1), $
  allocando un nuovo vettore dinamico e inizializzandolo tramite `polynomial_init`.

- definire la funzione `polynomial_destroy`, responsabile della *corretta deallocazione* della memoria posseduta dal polinomio.

== Esempio

`How many coefficients?` #text(fill: orange)[`4`]

`Enter coefficients (from degree 0 to degree 3):`

`Coefficient of x^0:` #text(fill: orange)[`2`]

`Coefficient of x^1:` #text(fill: orange)[`-1`]

`Coefficient of x^2:` #text(fill: orange)[`0`]

`Coefficient of x^3:` #text(fill: orange)[`5`]

#v(0.5em)

`Polynomial: 5*x^3       +       0*x^2   +       -1*x    +       2`

`Derivative:`

`Polynomial: 15*x^2      +       0*x     +       -1`


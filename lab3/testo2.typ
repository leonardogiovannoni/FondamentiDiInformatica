#set page(
  width: 21cm,
  height: 29.7cm,
  margin: (top: 2.54cm, bottom: 2.54cm, left: 2.54cm, right: 2.54cm),
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

= Esercizio: Passaggio per valore e per riferimento

#v(7em)

Scrivi un programma in linguaggio *C++* che permetta di comprendere la differenza tra:

- il *passaggio per valore*;
- il *passaggio per riferimento*.

Ogni funzione deve raddoppiare il valore del parametro ricevuto.
Il programma deve eseguire questo main:
#v(1em)
#grid(
  columns: (2.675fr, 1fr),
  column-gutter: 0em,
  [
    ```cpp
    void f1(int x) {
        // Passaggio per valore
        // ..
    }

    int f2(int x) {
        // Passaggio per valore, con riassegnamento
        // ..
        return ...;
    }

    void f3(int &x) {
        // Passaggio per riferimento
        // ..
    }

    int main() {
      int a = 0;
      cout << "Inserisci un numero intero: ";
      cin >> a;
      cout << "\nValore iniziale: " << a << endl;
      f1(a); // Passaggio per valore
      cout << "Dopo f1(x): " << a << endl;
      a = f2(a); // Passaggio per valore, con riassegnamento
      cout << "Dopo x = f2(x): " << a << endl;
      f3(a); // Passaggio per riferimento
      cout << "Dopo f3(x): " << a << endl;
      return 0;
    }
    ```
  ],
  [
    == Esempio

    === Input:


    ```text
    10
    ```

    === Output:

    ```text
    Valore iniziale: 10
    Dopo f1(x): 10
    Dopo x = f2(x): 20
    Dopo f3(x): 40
    ```
  ],
)

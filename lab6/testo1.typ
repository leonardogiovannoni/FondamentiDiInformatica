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

#show title: set block(above: 1.4em, below: 1em)
#show title: it => [
  #v(1em)
  #align(center)[
    #set text(size: 23pt, weight: "regular")
    #it.body
  ]
]

#title[Esercizio: Manipolazione di stringhe in C++]

#v(1em)

= Parte A: Implementazione `my_strcpy`

Scrivi un programma in linguaggio *C++* che:

- dichiari due array di caratteri di lunghezza prefissata 51;
- legga da tastiera una stringa e la memorizzi nel primo array;
- visualizzi la stringa;
- utilizzi una funzione `my_strcpy` per copiare il contenuto della stringa nel secondo array;
- stampi la stringa contenuta nel secondo array sia prima che dopo la copia.

La funzione da implementare è la seguente, dove il valore ritornato è `dst`:
#v(1em)
```cpp
char *my_strcpy(char dst[], const char src[]);
```

#v(10pt)
== Esempio

=== Input: 
```text
abc
```
=== Output:

```text
str1: abc 
str2 PRIMA: 
str2 DOPO: abc 
```

#v(1em)

= Parte B: Verifica di stringa composta da solo lettere maiuscole o cifre

Estendi il programma precedente introducendo una funzione che verifichi se una stringa è composta esclusivamente da:

  - lettere dell'alfabeto inglese in *maiuscolo* (da `'A'` a `'Z'`);
  - cifre numeriche decimali (da `'0'` a `'9'`).

La funzione deve restituire `true` se tutti i caratteri della stringa rispettano tali condizioni, `false` altrimenti.
La funzione da implementare è:
#v(1em)
```cpp
bool is_alpha_maiusc_or_numeric(const char str[]);
```

#v(10pt)
== Esempi

#grid(
columns: (1fr, 1fr),
column-gutter: 2em,
[
=== Input:  
```text
ABC123
```

=== Output:
```text
str1: ABC123
str2 PRIMA: 
str2 DOPO: ABC123
OK
```

],
[
=== Input:  
```text
AbC!12
```

=== Output:
```text
str1: AbC!12 
str2 PRIMA: 
str2 DOPO: AbC!12
NO
```

]
)

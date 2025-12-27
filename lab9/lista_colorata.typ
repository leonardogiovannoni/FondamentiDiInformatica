#set page(
  width: 21cm,
  height: 29.7cm,
  margin: (top: 0.24cm, bottom: 0.54cm, left: 0.44cm, right: 0.44cm),
)
#set text(size: 12pt, font: "New Computer Modern")
#set par(leading: 0.65em, spacing: 0.65em)
#set block(spacing: 0.65em)
#show list: set block(above: 1.2em, below: 1.2em)
#set list(spacing: 1.2em)
#show heading: set block(above: 1.4em, below: 1em)
#show heading.where(level: 1): it => [
  #v(1em)
  #align(center)[
    #set text(size: 21pt, weight: "regular")
    #it.body
  ]
]

= Esercizio: Lista Colorata
== Prova scritta 14-02-2024

Una `ListaColorata` ha un nome e contiene elementi aventi come informazione un colore. Il nome è una
stringa di caratteri di dimensione inferiore o uguale a 30. I possibili colori sono verde, azzurro e giallo. Le
operazioni che possono eseguite su una lista colorata sono le seguenti:

- `inizializza(l, s)`: funzione che inizializza una lista colorata `l` con il nome `s`. La lista colorata non ha elementi.


- `add(l, c)`: funzione che aggiunge un elemento di colore `c` alla lista colorata `l`.

- `stampa_colore(l)`: funzione che stampa il nome del colore che è presente il maggior numero di volte nella lista colorata. Se più colori sono presenti lo stesso numero massimo di volte, ne viene stampato uno.
- `elimina(l, n)`: funzione che elimina gli `n` elementi inseriti meno di recente dalla lista `l`. La funzione restituisce il numero di elementi effettivamente eliminati.
- `elimina_colore(l, c)`: funzione che elimina dalla lista colorata `l` tutti gli elementi di colore `c`.

- `stampa(l)`: L'uscita ha il seguente formato: viene prima visualizzato il nome della lista colorata. Poi su una riga separata, vengono visualizzati gli elementi della lista, in ordine di inserimento dal meno recente al più recente, separati da una virgola. Nel caso seguente la lista colorata `l` ha nome: Arcobaleno. Inoltre, verde è il colore dell'elemento inserito più di recente.```
Arcobaleno
Giallo, Giallo, Azzurro, Giallo, Verde
```
// Il contenuto dello stream d'output standard è rappresentato racchiuso tra i simboli di
// commento /**/

#grid(
  columns: (1fr, 1fr),
  column-gutter: 2em,
  [
== Main di esempio
```cpp
int main() {
    ListaColorata l;
    inizializza(l, "Arcobaleno");
    stampa(l);
    
    add(l, VERDE);
    add(l, GIALLO);
    stampa(l);
    
    add(l, AZZURRO);
    add(l, AZZURRO);
    stampa(l);
    

    stampa_colore(l);
    
    int quanti = elimina(l, 2);
    cout << quanti << endl;
    
    add(l, GIALLO);
    add(l, VERDE);
    add(l, GIALLO);
    add(l, VERDE);
    stampa(l);
    
    elimina_colore(l, GIALLO);
    stampa(l);

    return 0;
}
```
  ],
  [
    == Output
    ```



    Arcobaleno



    Arcobaleno
    Verde, Giallo


    Arcobaleno
    Verde, Giallo, Azzurro, Azzurro

    Azzurro


    2





    Arcobaleno
    Azzurro, Azzurro, Giallo, Verde, Giallo, Verde

    Arcobaleno
    Azzurro, Azzurro, Verde, Verde
    ```
  ]
)
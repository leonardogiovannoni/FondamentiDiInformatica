#include <cstring>
#include <iostream>
using namespace std;

enum Colore { VERDE, AZZURRO, GIALLO };
const int MAX_COLORI = 3;

const char *colore_to_string(Colore c) {
    switch (c) {
        case VERDE: {
            return "Verde";
        }
        case AZZURRO: {
            return "Azzurro";
        }
        case GIALLO: {
            return "Giallo";
        }
        default: {
            // unreachable
            return "";
        }
    }
}

struct Elem {
    Colore colore;
    Elem *next;
};

const int MAX_LEN = 30;

struct ListaColorata {
    char nome[MAX_LEN + 1];
    Elem *phead;
};

bool inizializza(ListaColorata &l, const char s[]) {
    int len = strlen(s);
    if (len == 0 || len > MAX_LEN) {
        return false;
    }
    strcpy(l.nome, s);
    l.phead = nullptr;
    return true;
}

void add(ListaColorata &l, Colore c) {
    Elem *new_elem = new Elem;
    new_elem->colore = c;
    new_elem->next = nullptr;

    Elem *curr = l.phead;
    Elem *prev = nullptr;

    while (curr != nullptr) {
        prev = curr;
        curr = curr->next;
    }

    if (prev == nullptr) {
        l.phead = new_elem;
    } else {
        prev->next = new_elem;
    }
}

// È utile per fare questa funzione assumere che l'enum
// sia mappabile (come è effettivamente) in una sequenza
// contigua di interi a partire da 0
void stampa_colore(const ListaColorata &l) {
    if (l.phead == nullptr) {
        return;
    }
    int counts[MAX_COLORI] = {};
    for (Elem *scan = l.phead; scan != nullptr; scan = scan->next) {
        int idx = (int)scan->colore;
        counts[idx]++;
    }
    int max_count = counts[0];
    int max_idx = 0;
    for (int i = 1; i < MAX_COLORI; i++) {
        if (counts[i] > max_count) {
            max_count = counts[i];
            max_idx = i;
        }
    }

    Colore max_colore = (Colore)max_idx;
    cout << colore_to_string(max_colore) << endl;
}

// Versione dove non assumiamo la contiguità dell'enum:
//
// void stampa_colore(const ListaColorata &l) {
//     if (l.phead == nullptr) {
//         return;
//     }
//     struct ColorCount {
//         Colore colore;
//         int count;
//     };
//
//     ColorCount counts[MAX_COLORI] = {};
//     int next = 0;
//     for (Elem *scan = l.phead; scan != nullptr; scan = scan->next) {
//         int idx = next;
//         for (int i = 0; i < next; i++) {
//             if (counts[i].colore == scan->colore) {
//                 idx = i;
//                 break;
//             }
//         }
//         if (idx == next) {
//             next++;
//             counts[idx].colore = scan->colore;
//             counts[idx].count = 1;
//         } else {
//             counts[idx].count++;
//         }
//     }
//
//     bool b = false;
//     int max_idx = 0;
//     for (int i = 0; i < next; i++) {
//         if (!b || counts[i].count > counts[max_idx].count) {
//             b = true;
//             max_idx = i;
//         }
//     }
//
//     if (!b) {
//         return;
//     }
//     cout << colore_to_string(counts[max_idx].colore) << endl;
// }

Elem *pop_front(ListaColorata &l) {
    if (l.phead == nullptr) {
        return nullptr;
    }
    Elem *rv = l.phead;
    l.phead = l.phead->next;
    return rv;
}

int elimina(ListaColorata &l, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        Elem *removed = pop_front(l);
        if (removed == nullptr) {
            break;
        }
        delete removed;
        count++;
    }
    return count;
}

void elimina_colore(ListaColorata &l, Colore c) {
    Elem *curr = l.phead;
    Elem *prev = nullptr;

    while (curr != nullptr) {
        if (curr->colore == c) {
            if (prev == nullptr) {
                l.phead = curr->next;
                delete curr;
                curr = l.phead;
            } else {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
}

void stampa(const ListaColorata &l) {
    cout << l.nome << endl;
    for (Elem *scan = l.phead; scan != nullptr; scan = scan->next) {
        cout << colore_to_string(scan->colore);
        bool is_last = (scan->next == nullptr);
        if (!is_last) {
            cout << ", ";
        }
    }
    cout << endl;
}

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
}
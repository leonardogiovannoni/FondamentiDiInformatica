#include <cstring>
#include <iostream>

using namespace std;

// Stabiliamo delle regole per le copie delle struct:
// - se una struct contiene puntatori a memoria dinamica, può essere copiata (a meno di costruttori di copia, 
//   di cui non parleremo), solo se facciamo la promessa che il proprietario originale non userà più la struct originale
//   ```
//   MyStruct a = ...;
//   MyStruct b = a; // OK solo se non userò più `a`
//   ```
// - se volessi accedere ad `a`, devo cambiare pattern:
//   ```
//   MyStruct a = ...;
//   MyStruct b = {};
//   mystruct_copy(b, a); // ora posso usare sia `a` che `b`
//   ```
// Dentro la `mystruct_copy`, devo copiare i dati, allocando nuova memoria per i puntatori dinamici.
// In questo modo, evitiamo problemi di doppia deallocazione della memoria, perché `a` e `b` deallocheranno 
// due blocchi di memoria distinti.
// Come risulta quindi evidente, dobbiamo creare queste regole rigide perché la gestione della memoria in C++ è manuale,
// se non dovessimo chiamare la `delete` per la memoria allocata con `new`, il problema non si porrebbe.

struct Entry {
    int count;
    char *word;
};

void entry_init(Entry &e, int count, const char word[]) {
    e.count = count;
    int len = strlen(word);
    e.word = new char[len + 1];
    strcpy(e.word, word);
}

void entry_destroy(Entry &e) {
    e.count = 0;
    delete[] e.word;
    e.word = nullptr;
}

struct Map {
    // INVARIANTE: gli elementi in [0, len) sono inizializzati,
    //             quelli da [len, capacity) contengono memoria sporca 
    //             e non devono essere distrutti.
    Entry *entries;
    int len;
    int capacity;
};

void map_init(Map &map, int capacity) {
    map.entries = new Entry[capacity];
    map.len = 0;
    map.capacity = capacity;
}

void map_destroy(Map &map) {
    for (int i = 0; i < map.len; i++) {
        entry_destroy(map.entries[i]);
    }
    delete[] map.entries;
    map.entries = nullptr;
    map.len = 0;
    map.capacity = 0;
}

Entry *map_entry(Map &map, const char word[]) {
    for (int i = 0; i < map.len; i++) {
        if (strcmp(map.entries[i].word, word) == 0) {
            return &map.entries[i];
        }
    }
    return nullptr;
}

int *map_get(Map &map, const char word[]) {
    Entry *entry = map_entry(map, word);
    if (entry != nullptr) {
        return &entry->count;
    }
    return nullptr;
}

bool map_insert(Map &map, const char word[], int initial_count) {
    Entry *old = map_entry(map, word);
    if (old != nullptr) {
        old->count = initial_count;
    } else {
        if (map.len == map.capacity) {
            return false;
        }
        entry_init(map.entries[map.len], initial_count, word);
        map.len++;
    }
    return true;
}

bool map_remove(Map &map, const char word[]) {
    Entry *entry = map_entry(map, word);
    if (entry == nullptr) {
        return false;
    }
    if (map.len == 1) {
        entry_destroy(*entry);
        map.len--;
        return true;
    }
    Entry &last = map.entries[map.len - 1];
    entry_destroy(*entry);
    *entry = last;
    map.len--;
    return true;
}

void map_print(const Map &map) {
    cout << "{";
    for (int i = 0; i < map.len; i++) {
        cout << '"' << map.entries[i].word << "\": " << map.entries[i].count;
        if (i != map.len - 1) {
            cout << ", ";
        }
    }
    cout << "}" << endl;
}

int main() {
    const int MAX_LEN = 100;
    char buffer[MAX_LEN + 1] = {};
    cout << "Inserisci una frase intervallata da _: ";
    cin >> buffer;

    int number_of_words = 1;
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '_') {
            number_of_words++;
        }
    }

    Map map = {};
    map_init(map, number_of_words);

    const char *word = strtok(buffer, "_");
    while (word != nullptr) {
        int *count_ptr = map_get(map, word);
        if (count_ptr == nullptr) {
            map_insert(map, word, 1);
        } else {
            (*count_ptr)++;
        }
        word = strtok(nullptr, "_");
    }

    map_print(map);
    map_destroy(map);
}

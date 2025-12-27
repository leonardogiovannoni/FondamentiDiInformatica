#include <iostream>
#include <cstring>

using namespace std;

const int ALPHABET_SIZE = 26;

bool conta_caratteri(const char *str, int freqs[], int size) {
    if (size != ALPHABET_SIZE) {
        return false;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        int idx = 0;
        char c = str[i];
        if (c >= 'a' && c <= 'z') {
            idx = c - 'a';
        } else if (c >= 'A' && c <= 'Z') {
            idx = c - 'A';
        } else {
            continue;
        }
        freqs[idx]++;
    }
    return true;
}


void print_frequencies(const int freqs[], int size) {
    if (size != ALPHABET_SIZE) {
        cout << "Dimensione frequenze non valida!" << endl;
        return;
    }
    cout << "{";
    for (int i = 0; i < size; i++) {
        char c = 'a' + i;
        cout << c << ": " << freqs[i];
        if (i != size - 1) {
            cout << ", ";
        }
    }
    cout << "}" << endl;
}

int main() {
    char buffer[100] = {};
    cout << "Inserisci una parola.. ";
    cin >> buffer;

    int freqs[ALPHABET_SIZE] = {};

    if (!conta_caratteri(buffer, freqs, ALPHABET_SIZE)) {
        cout << "Errore nel conteggio delle frequenze!" << endl;
        return 1;
    }
    print_frequencies(freqs, ALPHABET_SIZE);
    return 0;
}
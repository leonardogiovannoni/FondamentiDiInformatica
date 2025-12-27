#include <cstring>
#include <iostream>

using namespace std;

const int MAX_LEN = 50;

struct Studente {
    char nome[MAX_LEN + 1];
    int eta;
    float media;
};

bool studente_init(Studente &s, const char nome[], int eta, float media) {
    int len = strlen(nome);
    if (len > MAX_LEN || eta < 0 || media < 0.0f || media > 30.0f) {
        return false;
    }
    strcpy(s.nome, nome);
    s.eta = eta;
    s.media = media;
    return true;
}

void studente_print(const Studente &s) {
    cout << "Nome: " << s.nome << " | Eta': " << s.eta << " | Media: " << s.media << endl;
}

struct ElencoStudenti {
    Studente *studenti;
    int len;
    int capacity;
};

void elenco_studenti_init(ElencoStudenti &elenco, int capacity) {
    elenco.studenti = new Studente[capacity];
    elenco.len = 0;
    elenco.capacity = capacity;
}

bool elenco_studenti_is_full(const ElencoStudenti &elenco) {
    return elenco.len == elenco.capacity;
}

bool elenco_studenti_push_back(ElencoStudenti &elenco, const Studente &s) {
    if (elenco_studenti_is_full(elenco)) {
        return false;
    }
    elenco.studenti[elenco.len] = s;
    elenco.len++;
    return true;
}

void elenco_studenti_print(const ElencoStudenti &elenco) {
    cout << "\nElenco Studenti:\n";
    for (int i = 0; i < elenco.len; i++) {
        cout << (i + 1) << ". ";
        studente_print(elenco.studenti[i]);
    }
    cout << endl;
}

void elenco_studenti_destroy(ElencoStudenti &elenco) {
    delete[] elenco.studenti;
    elenco.studenti = nullptr;
    elenco.len = 0;
    elenco.capacity = 0;
}

int main() {
    int n = 0;

    cout << "Quanti studenti vuoi inserire? ";
    cin >> n;

    if (n <= 0) {
        cout << "Numero non valido." << endl;
        return 0;
    }

    ElencoStudenti elenco = {};
    elenco_studenti_init(elenco, n);
    while (!elenco_studenti_is_full(elenco)) {
        Studente s = {};
        cout << "\nInserisci nome, eta' e media dello studente n." << (elenco.len + 1) << endl;
        char name[MAX_LEN + 1] = {};
        int age = 0;
        float avg = 0.0f;
        cin >> name >> age >> avg;
        if (!studente_init(s, name, age, avg)) {
            cout << "Dati studente non validi." << endl;
            elenco_studenti_destroy(elenco);
            return 1;
        }
        elenco_studenti_push_back(elenco, s);
    }

    elenco_studenti_print(elenco);

    elenco_studenti_destroy(elenco);

    return 0;
}

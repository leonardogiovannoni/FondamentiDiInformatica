#include <iostream>
using namespace std;

struct Elem {
    int val;
    Elem *next;
};

void print(Elem *phead) {
    cout << "[";

    for (Elem *scan = phead; scan != nullptr; scan = scan->next) {
        cout << scan->val;
        bool is_last = (scan->next == nullptr);
        if (!is_last) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

Elem *pop_front(Elem *&rphead) {
    if (rphead == nullptr) {
        return nullptr;
    }

    Elem *tmp = rphead;
    rphead = rphead->next;
    tmp->next = nullptr;

    return tmp;
}

void push_front(Elem **pphead, int n) {
    Elem *new_elem = new Elem;
    new_elem->val = n;
    new_elem->next = *pphead;

    *pphead = new_elem;
}

int main() {
    Elem *phead = nullptr;
    cout << "Inserisci una sequenza di numeri interi positivi:" << endl;
    int n = 0;
    while (cin >> n) {
        push_front(&phead, n);
    }
    cout << "Lista inserita: ";
    print(phead);

    cin.clear();
    cin.ignore(10000, '\n');
    int m = 0;
    cout << "Elementi da estrarre: ";
    cin >> m;

    Elem *extracted = nullptr;
    for (int i = 0; i < m; i++) {
        Elem *elem = pop_front(phead);
        if (elem == nullptr) {
            break;
        }
        delete elem;
    }
    cout << "Lista dopo l'estrazione: ";
    print(phead);
    return 0;
}

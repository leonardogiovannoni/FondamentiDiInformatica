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

void push_front(Elem **pphead, int n) {
    Elem *new_elem = new Elem;
    new_elem->val = n;
    new_elem->next = *pphead;

    *pphead = new_elem;
}

int main() {
    Elem *phead = nullptr;
    cout << "Inserisci una sequenza di numeri interi positivi:" << endl;
    bool b = true;
    while (b) {
        int n = 0;
        cin >> n;
        if (n < 0) {
            b = false;
        } else {
            push_front(&phead, n);
        }
    }

    print(phead);

    return 0;
}

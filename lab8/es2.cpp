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
        if (!is_last)
            cout << ", ";
    }

    cout << "]" << endl;
}

void insert_ordered(Elem *&rphead, int val) {
    Elem *new_elem = new Elem;
    new_elem->val = val;
    new_elem->next = nullptr;

    Elem *scan = rphead;
    Elem *prev = nullptr;

    while (scan != nullptr && val > scan->val) {
        prev = scan;
        scan = scan->next;
    }

    new_elem->next = scan;

    if (prev == nullptr) {
        rphead = new_elem;
    } else {
        prev->next = new_elem;
    }
}

int main() {
    Elem *phead = nullptr;

    int n = 0;

    cout << "Inserisci una sequenza di numeri interi ";

    while (cin >> n) {
        insert_ordered(phead, n);
    }

    print(phead);

    return 0;
}

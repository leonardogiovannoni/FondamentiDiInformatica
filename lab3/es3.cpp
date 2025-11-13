#include <iostream>
using namespace std;

int main() {
    int a = 0;
    int b = 0; 
    cin >> a >> b;
   
    int *max_ptr = nullptr;

    if (a > b) {
        max_ptr = &a;
    } else {
        max_ptr = &b;
    }
    cout << "Il numero maggiore è: " << *max_ptr << endl;
    *max_ptr = 0;
    cout << "Dopo l'azzeramento, i valori sono: a = " 
         << a << ", b = " << b << endl;
    return 0;
}
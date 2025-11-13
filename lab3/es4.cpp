#include <iostream>
using namespace std;

void clamp(int *value_ptr, int low, int high) {
    if (*value_ptr < low) {
        *value_ptr = low;
    } else if (*value_ptr > high) {
        *value_ptr = high;
    }
}

int main() {
    int a = 0;
    int low = 0;
    int high = 0;
    cin >> a >> low >> high;
    int *a_ptr = &a;
    clamp(a_ptr, low, high);
    cout << "Il valore clamped è: " << *a_ptr << endl;
    return 0;
}
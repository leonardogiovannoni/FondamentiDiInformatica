#include <iostream>
using namespace std;

void filtra_alfabetici(char dst[], int dst_capacity, const char src[]) {
    if (dst_capacity <= 0) {
        return;
    }

    int j = 0;
    for (int i = 0; src[i] != '\0'; i++) {
        if (j >= dst_capacity - 1) {
            break;
        }
        char c = src[i];
        bool is_uppercase = (c >= 'A' && c <= 'Z');
        bool is_lowercase = (c >= 'a' && c <= 'z');
        bool is_alpha = is_uppercase || is_lowercase;
        if (is_alpha) {
            dst[j] = c;
            j++;
        }
    }
    dst[j] = '\0';
}

int main() {
    char str1[10] = {};
    char str2[100] = {};

    cin >> str1;

    filtra_alfabetici(str2, 10, str1);
    cout << str2 << endl;

    return 0;
}


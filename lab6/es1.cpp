#include <cstring>
#include <iostream>
using namespace std;

char *my_strcpy(char dst[], const char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return dst;
}

bool is_alpha_maiusc_or_numeric(const char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        bool is_maiusc = (c >= 'A' && c <= 'Z');
        bool is_digit  = (c >= '0' && c <= '9');
        bool is_valid  = (is_maiusc || is_digit);
        if (!is_valid) {
            return false;
        }
    }
    return true;
}

int main() {
    const int MAX_LEN = 50;
    const int CAPACITY = MAX_LEN + 1;

    char str1[CAPACITY] = {};
    char str2[CAPACITY] = {};

    cin >> str1;

    cout << "str1: " << str1 << endl;

    cout << "str2 PRIMA: " << str2 << endl;

    my_strcpy(str2, str1);

    cout << "str2 DOPO: " << str2 << endl;

    if (is_alpha_maiusc_or_numeric(str1)) {
        cout << "OK" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}

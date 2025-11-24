#include <iostream>
using namespace std;


const char *ITALIAN_LOWERCASE = "abcdefghilmnopqrstuvz";
const char *ITALIAN_UPPERCASE = "ABCDEFGHILMNOPQRSTUVZ";

bool is_contained(char c, const char s[]) {
    for (int i = 0; i < s[i] != '\0'; i++) {
        if (c == s[i]) {
            return true;
        }
    }
    return false;
}

bool is_alfabeto_italiano_21(const char s[]) {
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        bool is_italian_lowercase = is_contained(c, ITALIAN_LOWERCASE);
        bool is_italian_uppercase = is_contained(c, ITALIAN_UPPERCASE);
        bool is_valid = is_italian_lowercase || is_italian_uppercase;
        if (!is_valid) {
            return false;
        }
    }
    return true;
}

int main() {
    char s[51];
    cin >> s;

    if (is_alfabeto_italiano_21(s)) {
        cout << "OK" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}


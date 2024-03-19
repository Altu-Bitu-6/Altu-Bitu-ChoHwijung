#include <iostream>
#include <cstring>

using namespace std;

bool similar(const int* a, const int* b) {
    int s = 0, f = -1;
    for (int i = 0; i < 26; ++i) {
        if (a[i] != b[i]) {
            if (f == -1) f = i;
            if (++s > 2 || a[i] - b[i] > 1 || a[i] - b[i] < -1 || (s == 2 && (a[f] + a[i]) != (b[f] + b[i]))) return false;
        }
    }
    return true;
}

int cnt(int n, const char* stand) {
    int c = 0;
    int alphabets[26] = {0};

    for (int i = 0; stand[i]; ++i) {
        ++alphabets[stand[i] - 'A'];
    }

    for (int j = 1; j < n; ++j) {
        char input[15];
        int cf[26] = {0};
        cin >> input;
        for (int i = 0; input[i]; ++i) {
            ++cf[input[i] - 'A'];
        }
        c += similar(alphabets, cf);
    }

    return c;
}

int main() {
    int n;
    cin >> n;

    char stand[15];
    cin >> stand;

    int c = cnt(n, stand);

    cout << c << endl;

    return 0;
}

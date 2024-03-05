#include <iostream>
#include <algorithm>

using namespace std;

int getGcdRecur(int a, int b) {
    if (b == 0) {
        return a;
    }
    return getGcdRecur(b, a % b);
}

void getIrreducible(int& deno, int& nume) {
    int gcd = getGcdRecur(deno, nume);
    deno /= gcd;
    nume /= gcd;
}

pair<int, int> getFraction(int nume_1, int deno_1, int nume_2, int deno_2) {
    int deno = deno_1 * deno_2;
    int nume = deno_1 * nume_2 + deno_2 * nume_1;

    return make_pair(nume, deno);
}

int main() {
    int nume_1, deno_1, nume_2, deno_2;

    cin >> nume_1 >> deno_1;
    cin >> nume_2 >> deno_2;

    pair<int, int> fraction = getFraction(nume_1, deno_1, nume_2, deno_2);
    int nume = fraction.first;
    int deno = fraction.second;

    getIrreducible(deno, nume);

    cout << nume << " " << deno;

    return 0;
}

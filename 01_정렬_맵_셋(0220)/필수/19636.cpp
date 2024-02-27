#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int W, Dur, T, A, L0, LC;

    cin >> W >> L0 >> T;
    cin >> Dur >> LC >> A;

    int Wb = W;
    int Wc = W;

    int L0c = L0;

    for (int i = 0; i < Dur; i++) {
        Wb += LC - (L0 + A);
        Wc += LC - (L0c + A);

        if (abs(LC - (L0c + A)) > T) {
            L0c += floor((LC - (L0c + A)) / 2.0);
        }
    }


    if (Wb <= 0) {
        cout << "Danger Diet\n";
    }
    else {
        cout << Wb << " " << L0 << "\n";
    }
    if (Wc <= 0 || L0c <= 0) {
        cout << "Danger Diet\n";
    }
    else {
        if ((L0 - L0c) > 0) {
            cout << Wc << " " << L0c << " " << "YOYO";
        }
        else {
            cout << Wc << " " << L0c << " " << "NO";
        }

    }

    return 0;
}
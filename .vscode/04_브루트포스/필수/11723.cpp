#include <iostream>
#include <string>

using namespace std;
typedef long long ll;
const long long ONES = 2097150;

ll set = 0;

void printExistence(int num) {
    if (set & ((ll)1 << num)) {
        cout << 1 << '\n';
    }
    else {
        cout << 0 << '\n';
    }
}

void changeSet(string cmd) {
    if (cmd == "all") {
        set = ONES;
    }
    else if (cmd == "empty") {
        set = (ll)0;
    }
}

void findSet(string cmd, int n) {
    if (cmd == "add") {
        set |= ((ll)1 << n);
    }
    else if (cmd == "remove") {
        set &= ~((ll)1 << n);
    }
    else if (cmd == "toggle") {
        set ^= ((ll)1 << n);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, num;
    string cmd;

    cin >> n;

    while (n--) {
        cin >> cmd;
        if (cmd == "all" || cmd =="empty") changeSet(cmd);
        else {
            cin >> num;
            if (cmd == "check") printExistence(num);
            else findSet(cmd, num);
        }

    }

}
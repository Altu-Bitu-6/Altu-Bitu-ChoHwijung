#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    int index = 0;
    bool is_circle = true;
    
    cin >> n >> k;

    vector<string> circle(n);

    for (int i = 0; i < n; i++)
        circle[i] = "?";

    for (int i = 0; i < k; i++) {
        int s;
        string letter;
        cin >> s >> letter;

        index = (index + s ) % n; 

        if (circle[index] != "?") {
            if (circle[index] == letter) continue;
            is_circle = false;
        }
        else circle[index] = letter;
    }

    for (int i = 0; i < n; i++) {
        if (circle[i] == "?") continue;
        for (int j = i + 1; j < n; j++) {
            if (circle[i] == circle[j]) {
                is_circle = false;
                break;
            }
        }
    }
    
    int times = n;

    if (is_circle) {
        while (n--) {
            if (index >= 0) {
                cout << circle[index];
                index--;
            }
            else {
                index += times;
                n++;
            }
       }
    }
    else cout << "!";
    
    return 0;
}

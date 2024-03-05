#include <iostream>
#include <vector>

using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    bool is_circle = true;

    cin >> n >> k;

    vector<string> circle(n);

    for (int i; i<n; i++) circle[i] = "?";

    for (int i; i<k; i++) {
        int s;
        string letter;
        cin >> s >> letter;

        if (circle[i] != "?") {
            if (circle[i] == letter) continue;
            is_circle = false;
        }
        else circle[i] = letter;
    }

    for (int i; i<n; i++) {
        if(circle[i] == "?") continue;
        for (int j; j<n; j++) {
            if (circle[i] == circle[j]){
                is_circle = false;
            }
        }
    }

    if(is_circle) for (int i=0; i<n; i++) cout << circle[i];


}
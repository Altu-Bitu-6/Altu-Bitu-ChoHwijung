#include <iostream>
#include <queue>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    int num = 0;
    cin >> n >> k;

    vector<int> save(n);
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    
    while (q.size() > 1) {
        for (int i = 1; i < k; i++) {
            int cnt = q.front();
            q.pop();
            q.push(cnt);
        }
        save[num] = q.front();
        num++;
        q.pop();
    }

    cout << "<";
    for (int i = 0; i < n-1; i++) {
        cout << save[i] << ", ";
    }
    cout << q.front() << ">\n";

}
#include <iostream>
#include <queue>

using namespace std;

struct cmp {
    bool operator() (const int& x1, const int& x2) {
        if (abs(x1) != abs(x2)) {
            return abs(x1) > abs(x2);
        }
        return x1 > x2;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, x;
    priority_queue<int, vector<int>, cmp> pq;

    cin >> n;

    while (n--) {
        cin >> x;

        //힙에서 가장 큰 수 출력 
        if (x==0) {
            if (pq.empty()) {
                cout << "0\n";
            }
             else {
                cout << pq.top() << "\n";
                pq.pop();
             }
        }
        else {
            pq.push(x);
        }
       
    }
}

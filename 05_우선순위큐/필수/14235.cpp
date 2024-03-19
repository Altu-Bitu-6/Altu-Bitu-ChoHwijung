#include <iostream>
#include <queue>

using namespace std;

// 선물 주기
int give(priority_queue<int>& pq) {
    if (pq.empty()) {
        return -1;
    }
    else {
        int maxGift = pq.top();
        pq.pop();
        return maxGift;
    }
}

// 선물 충전
void reload(priority_queue<int>& pq, int num) {
    for (int i = 0; i < num; i++) {
        int gift;
        cin >> gift;
        pq.push(gift);
    }
}

int main() {
    int n;
    cin >> n;

    priority_queue<int> pq;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        
        //a == 0 일때 선물 출력
        if (a == 0) {
            cout << give(pq) << "\n";
        }
        // 0이 아니라면 선물 충전하기
        else {
            reload(pq, a);
        }
    }

    return 0;
}

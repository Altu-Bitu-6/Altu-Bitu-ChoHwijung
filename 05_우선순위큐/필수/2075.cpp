#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, num;
    // 우선순위 큐를 최소힙으로 선언
    priority_queue<int, vector<int>, greater<int>> pq;

    cin >> n;

    // n * n 개의 수를 받아 우선순위 큐에 넣고 최소힙 유지
    for (int i = 0; i < n * n; i++) {
        cin >> num;
        pq.push(num);

        // 우선순위 큐의 크기가 n보다 크다면 가장 작은 값 제거하여 메모리 초과 방지
        if (pq.size() > n) {
            pq.pop(); // 우선순위 큐에서 가장 작은 값 제거
        }
    }

    // 우선순위 큐에서 top 값이 n번째로 큰 수 출력
    cout << pq.top();

    return 0;
}

#include <iostream>

using namespace std;

int bruteforce(int n) {
    for (int i=1; i<n; i++) {
        //분해합에 생성자 본인 추가
        int tmp = i; //현재의 생성자
        int sum = i; // 분해합 더해주기
        //자릿수 구하기
        while (tmp) { //??
            sum += tmp % 10;
            tmp /= 10;
        }

        if (sum == n) {
            return i;
        }
    }
    return 0;
}

int main() {
    int n;
    cin >> n;

    cout << bruteforce(n);

    return 0;
}
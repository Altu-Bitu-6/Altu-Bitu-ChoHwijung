#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 에라토스테네스의 체 이용하여 소수인지를 반환
vector<bool> getPrimes(int n) {
    // n까지의 수가 소수인지 여부를 저장하는 벡터 생성
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false; // 0과 1은 소수가 아님
    for (int i = 2; i * i <= n; i++) {
        if (!is_prime[i]) { // 이미 소수가 아니라고 판별된 경우 건너뜀
            continue;
        }
        // i의 배수들을 소수가 아니라고 표시
        for (int j = i * i; j <= n; j += i) {
            is_prime[j] = false;
        }
    }
    return is_prime;
}

// n = a + b를 만족시키는 a
int goldbach(int n, vector<bool> &is_prime) {
    for (int a = 3; a <= n / 2; a += 2) { // 2보다 큰 짝수 소수는 존재하지 않으므로, 홀수만 고려
        if (is_prime[a] && is_prime[n - a]) { // a와 n-a가 모두 소수인 경우
            return a; // a 반환
        }
    }
    // n = a + b를 만족시키는 홀수 소수 a, b가 없으면 0
    return 0;
}

int main() {
    // 입력
    vector<int> arr;
    int input;
    while (true) {
        cin >> input;
        if (input == 0) { // 입력이 0이면 종료
            break;
        }
        arr.push_back(input); // 입력값을 벡터에 저장
    }

    // 연산
    int max_num = *max_element(arr.begin(), arr.end()); // 입력값 중 최대값 찾기
    vector<bool> is_prime = getPrimes(max_num); // 최대값까지의 소수 여부 계산

    // 입력값에 대한 출력
    for (int i = 0; i < arr.size(); i++) {
        int a = goldbach(arr[i], is_prime); // 골드바흐의 추측 적용

        // 출력
        if (a != 0) { // n = a + b를 만족하는 a, b가 존재하면
            cout << arr[i] << " = " << a << " + " << arr[i] - a << "\n"; 
        } else {      // 존재하지 않으면
            cout << "Goldbach's conjecture is wrong.\n"; // 골드바흐의 추측이 틀렸음
        }
    }
    return 0;
}

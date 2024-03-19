#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef pair<char, char> cc; // 좌표

cc move(string input, char x, char y) {
    for (char how : input) {
        if (how == 'R') {
            x++; // 오른쪽으로 이동
        } else if (how == 'L') {
            x--; // 왼쪽으로 이동
        } else if (how == 'B') {
            y--; // 아래로 이동
        } else {  // (how == 'T')
            y++; // 위로 이동
        }
    }
    return {x, y}; // 이동 후의 좌표를 반환
}

bool isSame(cc k, cc s) {
    return (k.first == s.first && k.second == s.second); // 두 좌표가 일치하는지 여부를 반환
}


bool checkRange (cc pos) {
    if (pos.first < 'A' || pos.first > 'H' || pos.second < '1' || pos.second > '8') {
        return false; // 좌표가 체스판 범위를 벗어나면 false 반환
    }
    return true; // 좌표가 체스판 범위 안에 있으면 true 반환
}

int main() {
    cc k, s; // 킹(K)과 돌(S)의 위치를 나타내는 좌표
    int n; // 이동 명령의 수
    string input; // 이동 방향을 담은 문자열

    // 입력 받기
    cin >> k.first >> k.second >> s.first >> s.second >> n; // 킹과 돌의 초기 위치 및 이동 명령의 수 입력 받음

    // 연산
    while (n--) { // 이동 명령의 수만큼 반복
        cin >> input; // 이동 방향 입력 받음

        cc next_k, next_s; // 이동 후의 킹과 돌의 좌표를 저장할 변수

        // 킹 이동
        next_k = move(input, k.first, k.second);

        // 돌 이동
        if (isSame(next_k, s)) { // 이동한 킹의 위치가 돌의 위치와 일치하는지 확인
            // 일치하면 돌도 같은 방향으로 이동
            next_s = move(input, s.first, s.second);
        }
        else {
            next_s = s; // 일치하지 않으면 돌의 위치는 변경되지 않음
        }

        // 체스판 범위 내에서만 이동
        if (checkRange(next_k) && checkRange(next_s)) { // 이동 후의 킹과 돌의 위치가 체스판 범위 안에 있는지 확인
            k = next_k; // 범위 안에 있다면 킹의 위치 갱신
            s = next_s; // 범위 안에 있다면 돌의 위치 갱신
        }
    }

    // 출력
    cout << k.first << k.second << '\n' << s.first << s.second; // 킹과 돌의 최종 위치 출력

    return 0;
}

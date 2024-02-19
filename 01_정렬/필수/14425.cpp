#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	int cnt = 0;
	string input;
	map<string, int> S;
	map<int, string> strs;

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> input;
		S[input] = i;
	}

	for (int i = 1; i <= m; i++) {
		cin >> input;
		strs[i] = input;
	}

	for (int i = 1; i <= m; i++) {
		if (S[strs[i]] > 0) {
			cnt++;
		}
	}
	
	cout << cnt;

	return 0;
}
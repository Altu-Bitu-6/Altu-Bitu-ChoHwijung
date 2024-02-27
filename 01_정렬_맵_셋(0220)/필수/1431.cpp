#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmpFunc(const string str1, const string str2) {
	int sum1 = 0;
	int sum2 = 0;

	if (str1.size() != str2.size()) {
		return str1.size() < str2.size();
	}
	if (str1.size() == str2.size()) {
		for (int i = 0; i < str1.size(); i++) {
			if (str1[i] >= '0' && str1[i] <= '9') {
				sum1 += str1[i] - 48;
			}
			if (str2[i] >= '0' && str2[i] <= '9') {
				sum2 += str2[i] - 48;
			}
		}

		if (sum1 != sum2) {
			return sum1 < sum2;
		}

		return str1 < str2;
	}
}

int main() {
	int n;
	cin >> n;
	vector<string> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end(), cmpFunc);


	for (int i = 0; i < n; i++) {
		cout << arr[i] << '\n';
	}

	return 0;
}
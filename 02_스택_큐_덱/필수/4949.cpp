#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string input;
    while (getline(cin, input)) {
        if (input == ".") break; // End of input
        
        stack<char> st;
        bool balanced = true;
        for (int i = 0; i < input.length(); i++) {
            char ch = input[i];
            if (ch == '(' || ch == '[') {
                st.push(ch);
            } else if (ch == ')' || ch == ']') {
                if (st.empty() || (ch == ')' && st.top() != '(') || (ch == ']' && st.top() != '[')) {
                    balanced = false;
                    break;
                } else {
                    st.pop();
                }
            }
        }
        if (!st.empty()) balanced = false;

        if (balanced) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }

    return 0;
}

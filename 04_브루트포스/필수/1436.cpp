#include <iostream>
#include <string>

using namespace std;

void findNumber(int n) {
    int count = 0;
    int number = 665; 
    while (true) {
        number++;
        string str_number = to_string(number);

        if (str_number.find("666") != string::npos) {
            count++;
        }

        if (count == n) {
            cout << number << endl;
            break;
        }
    }

}

int main() {
    int n;
    cin >> n;
    
    findNumber(n);
    
    return 0;
}

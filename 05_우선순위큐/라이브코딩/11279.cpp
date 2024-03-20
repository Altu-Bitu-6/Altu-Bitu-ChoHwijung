#include <iostream>
#include <vector>

using namespace std;

bool isEmpty(vector<int>& heap) {
    return heap.size() == 1;
}

void push(int x, vector<int>& heap) {
    int idx = heap.size();

    heap.push_back(x);

    while (idx > 1 && heap[idx] > heap[idx/2]) {
        swap(heap[idx], heap[idx/2]);
        idx /= 2;
    }
    return;
}

int pop(vector<int>& heap) {
    int item = heap[1];

    heap[1] = heap[heap.size()-1];
    heap.pop_back();

    int size = heap.size();
    int parent = 1, child = 2;

    while (child < size) {
        if (child +1 <size && heap[child+1] > heap[child]) {
            child++;
        }

        if (heap[parent] < heap[child]) {
            swap(heap[parent], heap[child]);

            parent = child;
            child = parent * 2;
        }
        else {
            break;
        }
    }

    return item;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, x;
    vector<int> heap_vec;
    heap_vec.push_back(0);

    cin >> n;

    while (n--) {
        cin >> x;

        //힙에서 가장 큰 수 출력 
        if (x==0) {
            if (isEmpty(heap_vec)) {
                cout << "0\n";
            }
             else {
            cout << pop(heap_vec) << "\n";
             }
        }
        else {

        }
       
    }
}

/* 다른 풀이(priority queue 이용)

#include <iostream>
#include <queue>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, x;
    priority_queue<int> max_heap;

    cin >> n;

    while (n--) {
        cin >> x;

        //힙에서 가장 큰 수 출력 
        if (x==0) {
            if (max_heap.empty()) {
                cout << "0\n";
            }
             else {
                cout << max_heap.top() << "\n";
                max_heap.pop();
             }
        }
        else {
            max_heap.push(x);
        }
       
    }
}

*/
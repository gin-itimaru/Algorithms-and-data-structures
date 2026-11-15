#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

class MinHeap {
private:
    vector<int> heap;
    void siftUp(int i) {
        while (i > 0) {
            int p = (i - 1) / 2;
            if (heap[i] >= heap[p]) break;
            swap(heap[i], heap[p]);
            i = p;
        }
    }
    void siftDown(int i) {
        while (2 * i + 1 < heap.size()) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int j = left;
            
            if (right < heap.size() && heap[right] < heap[left]) {
                j = right;
            }
            if (heap[i] <= heap[j]) break;
            
            swap(heap[i], heap[j]);
            i = j;
        }
    }

public:
    void clear() {
        heap.clear();
    }

    void add(int x) {
        heap.push_back(x);
        siftUp(heap.size() - 1);
    }

    bool isEmpty() const {
        return heap.empty();
    }

    int extract() {
        int removed = heap[0];
        if (heap.size() > 1) {
            heap[0] = heap.back();
            heap.pop_back();
            siftDown(0);
        } else {
            heap.pop_back();
        }
        return removed;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    MinHeap h;
    string command;

    while (cin >> command) {
        if (command == "CLEAR") {
            h.clear();
        } else if (command == "ADD") {
            int val;
            cin >> val;
            h.add(val);
        } else if (command == "EXTRACT") {
            if (h.isEmpty()) {
                cout << "CANNOT\n";
            } else {
                cout << h.extract() << "\n";
            }
        }
    }

    return 0;
}



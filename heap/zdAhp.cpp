#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    void siftUp(int i) {
        int p = (i - 1) / 2;
        while (heap[i] > heap[p]) { 
            swap(heap[i], heap[p]);
            i = (i - 1) / 2;
            p = (i - 1) / 2;
        }
    }

    void siftDown(int i) {
        while (2 * i + 1 < heap.size()) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int j = left;
            
            if (right < heap.size() && heap[right] > heap[left]) {
                j = right;
            }
            if (heap[i] >= heap[j]) break;
            
            swap(heap[i], heap[j]);
            i = j;
        }
    }

public:
    void insert(int x) {
        heap.push_back(x);
        siftUp(heap.size() - 1);
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

    int n;
    if (!(cin >> n)) return 0;

    MaxHeap h;
    for (int i = 0; i < n; ++i) {
        int command_type;
        cin >> command_type;
        if (command_type == 0) {
            int val;
            cin >> val;
            h.insert(val);
        } else {
            cout << h.extract() << "\n";
        }
    }
    return 0;
}


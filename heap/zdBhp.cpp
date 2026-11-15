#include <iostream>
#include <vector>
#include <utility>

using namespace std;
void siftDown(vector<int>& arr, int i, int heap_size) {
    while (2 * i + 1 < heap_size) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int j = left;
        
        if (right < heap_size && arr[right] > arr[left]) {
            j = right;
        }
        if (arr[i] >= arr[j]) {
            break;
        }
        swap(arr[i], arr[j]);
        i = j;
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; --i) {
        siftDown(arr, i, n);
    }
    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]); 
        siftDown(arr, 0, i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    heapSort(arr);

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}



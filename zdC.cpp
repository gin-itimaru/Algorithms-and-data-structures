#include <iostream>
#include <vector>

using namespace std;

void BubbleSort(vector<int>& A) {
    int n = A.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j] < A[j + 1]) {  
                swap(A[j], A[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; 
    }
}

int main() {
    int x;
    vector<int> arr;
    while (cin >> x) {
        arr.push_back(x);
    }
    
    BubbleSort(arr);
    
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}

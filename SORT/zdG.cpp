#include <iostream>
#include <vector>
using namespace std;

void CountSort(vector<int>& A) {
    const int MAX_VALUE = 100;
    vector<int> count(MAX_VALUE + 1, 0);
    
    for (int i = 0; i < (int)A.size(); ++i) {
        count[A[i]]++;
    }
    
    int index = 0;
    for (int value = 0; value <= MAX_VALUE; ++value) {
        while (count[value] > 0) {
            A[index++] = value;
            count[value]--;
        }
    }
}

int main() {
    vector<int> A;
    int x;
    while (cin >> x) {                   
        A.push_back(x);
    }
    
    CountSort(A);
    
    for (int i = 0; i < (int)A.size(); ++i) {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

vector<int> SelectionSort(vector<int> A) {
    int n = A.size();
    
    for (int i = 0; i < n - 1; ++i) { 
        int maxIndex = i;
        
        for (int j = i + 1; j < n; ++j) {
            if (A[j] > A[maxIndex]) {   
                maxIndex = j;
            }
        }
        
        int temp = A[i];
        A[i] = A[maxIndex];
        A[maxIndex] = temp;
    }
    
    return A;
}

int main() {
    string line;
    getline(cin, line);
    
    stringstream ss(line);
    vector<int> A;
    int x;
    while (ss >> x) {
        A.push_back(x);
    }
    
    vector<int> result = SelectionSort(A);
    
    for (int i = 0; i < (int)result.size(); ++i) {
        cout << result[i] << " ";
    }
    
    return 0;
}

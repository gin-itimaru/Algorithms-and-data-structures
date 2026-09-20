#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;


vector<int> InsertionSort(vector<int> A) {
    int n = A.size();                          
    
    for (int i = 1; i < n; ++i) {              
        int key = A[i];                        
        int j = i - 1;                         
        
        
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];                   
            j--;                               
        }
        
        A[j + 1] = key;                        
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
    
    vector<int> result = InsertionSort(A);
    
    for (int i = 0; i < (int)result.size(); ++i) {
        cout << result[i] << " ";      
    }
    
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

// Override the << operator to print the vector values
template <typename T> 
ostream& operator<<(ostream& os, const vector<T>& v) 
{ 
    os << "["; 
    for (int i = 0; i < v.size(); ++i) { 
        os << v[i]; 
        if (i != v.size() - 1) 
            os << ", "; 
    } 
    os << "]\n"; 
    return os; 
}

template <typename T>
void brickSort(vector<T> &A, int n) {    
    bool stop = false;
    
    while (!stop) { 
        stop = true; 
  
        // Bubble sort odd elements 
        for (int i = 1; i <= n - 2; i = i + 2) { 
            if (A[i] > A[i + 1]) { 
                swap(A[i], A[i + 1]); 
                stop = false; 
            } 
        } 
  
        // Bubble sort even elements
        for (int i = 0; i <= n - 2; i = i + 2) { 
            if (A[i] > A[i + 1]) { 
                swap(A[i], A[i + 1]); 
                stop = false; 
            } 
        } 
    }
}

int main(int, char*[]){
    // Insert the vector for testing
    // vector<int> vec{ 13, 17, 2, 4, 11, 8, 19, 3, 7 };
    vector<double> vec{ 11.3, 17.1, 2.5, 4.4, 13, 8.1, 19.6, 3, 7.03 }; 

    // Calculate the size of the vector
    int n = vec.size();

    // Print the original vector 
    cout << "Original vector: " << vec; 

    brickSort(vec, n);

    // Print the resulting vector 
    cout << "Sorted vector: " << vec; 

    return 0;
}
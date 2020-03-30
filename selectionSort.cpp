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
void smallest(vector<T> &A, int &i, int &n, int &pos){
    // Element to be inserted
    T min = A[i];
    
    // Reposition the selector
    pos = i;

    // Locate position of smallest element
    for (int j = i + 1; j < n; ++j) {
        if (min > A[j]) {
            min = A[j];
            pos = j;
        }  
    }
}

template <typename T> 
void selectionSort(vector<T> &A){ 
    // Calculate the size of the vector
    int n = A.size();

    // Initialize the variables
    int pos = 0;
    T temp = 0;

    // Sort the values of the vector
    for (int i = 0; i < n; ++i) {
        smallest(A, i, n, pos);
        
        // Swap with smallest element
        temp = A[i];
        A[i] = A[pos];
        A[pos] = temp;
    }
}

int main(int, char*[]){
    // Insert the vector for testing
    // vector<int> vec{ 13, 17, 2, 4, 11, 8, 19, 3, 7 };
    vector<double> vec{ 11.3, 17.1, 2.5, 4.4, 13, 8.1, 19.6, 3, 7.03 }; 
    
    // Print the original vector 
    cout << "Original vector: " << vec; 

    selectionSort(vec);

    // Print the resulting vector 
    cout << "Sorted vector: " << vec; 

    return 0;
}
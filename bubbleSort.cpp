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
void bubbleSort(vector<T> &A){ 
    // Calculate the size of the vector
    int n = A.size();

    // Initialize the variables
    T temp = 0;

    // Sort the values of the vector
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (A[j] < A[i]) {
                // Swap elements
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
}

int main(int, char*[]){
    // Insert the vector for testing
    // vector<int> vec{ 7, 11, 9, 1, 3, 18, 5, 21 };
    vector<double> vec{ 11.3, 17.1, 2.5, 4.4, 13, 8.1, 19.6, 3, 7.03 }; 
    
    // Print the original vector 
    cout << "Original vector: " << vec; 

    bubbleSort(vec);

    // Print the resulting vector 
    cout << "Sorted vector: " << vec; 

    return 0;
}
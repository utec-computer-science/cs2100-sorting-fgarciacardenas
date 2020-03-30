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
void swap(vector<T> &A, int &i){
    // Element to be inserted
    T temp = A[i];
    int j = i - 1;

    // Locate position to insert the element
    while (j >= 0 && temp <= A[j]) {
        A[j + 1] = A[j];
        --j;
    }

    // Insert the element
    A[j + 1] = temp;
}

template <typename T>
void insertionSort(vector<T> &A){ 
    // Calculate the size of the vector
    int n = A.size();

    // Sort the values of the vector
    for (int i = 0; i < n; ++i) {
        swap(A, i);
    }
}

int main(int, char*[]){
    // Insert the vector for testing
    // vector<int> vec{ 11, 17, 1, 7, 13, 8, 19, 4, 2 }; 
    vector<double> vec{ 11.3, 17.1, 2.5, 4.4, 13, 8.1, 19.6, 3, 7.03 };

    // Print the original vector 
    cout << "Original vector: " << vec; 

    insertionSort(vec);

    // Print the resulting vector 
    cout << "Sorted vector: " << vec; 

    return 0;
}
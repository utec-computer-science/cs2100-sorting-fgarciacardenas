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
void merge(vector<T> &A, int low, int high, int mid){
    // Initialize the selectors
    int i = low;
    int k = low;
    int j = mid + 1;

    // Copy the original vector
    vector<T> temp = A;

    // Iterate while each half has elements
    while (i <= mid && j <= high) {
        if (A[i] < A[j]) {
            temp[k] = A[i];
            ++k;
            ++i;
        }
        else  {
            temp[k] = A[j];
            ++k;
            ++j;
        }
    }

    // Iterate while first half has elements
    while (i <= mid) {
        temp[k] = A[i];
        ++k;
        ++i;
    }

    // Iterate while second half has elements
    while (j <= high) {
        temp[k] = A[j];
        ++k;
        ++j;
    }

    // Merge the two halfs
    for (i = low; i < k; ++i) {
        A[i] = temp[i];
    }
}

template <typename T> 
void mergeSort(vector<T> &A, int low, int high){ 
    if (low < high) {
        // Divide the vector in the middle and sort each half
        int mid = (low + high)/2;
        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);

        // Merge the sorted vectors
        merge(A, low, high, mid);
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

    mergeSort(vec, 0, n-1);

    // Print the resulting vector 
    cout << "Sorted vector: " << vec; 

    return 0;
}
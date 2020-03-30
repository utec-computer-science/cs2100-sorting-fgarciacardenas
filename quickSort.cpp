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
int pivot(vector<T> &A, int low, int high){
    // Select the last element as pivot
    int p = A[high];

    // Initialize index
    int i = (low - 1);

    // Verify that the sub-vector is sorted
    for (int j = low; j <= high - 1; ++j) {
        if (A[j] <= p) {
            // Swap element smaller than pivot
            ++i;
            swap(A[i], A[j]);
        }
    }
    
    // Swap the pivot and return its index
    swap(A[i + 1], A[high]); 
    return (i + 1);
}

template <typename T>
void quickSort(vector<T> &A, int low, int high){ 
    if (low < high) {
        // Compute the pivot and sort partitions
        int p = pivot(A, low, high);
        quickSort(A, low, p - 1);
        quickSort(A, p + 1, high);
    }
}

int main(int, char*[]){
    // Insert the vector for testing
    // vector<int> vec{ 11, 17, 2, 4, 13, 8, 19, 3, 7 }; 
    vector<double> vec{ 11.3, 17.1, 2.5, 4.4, 13, 8.1, 19.6, 3, 7.03 };

    // Calculate the size of the vector
    int n = vec.size();

    // Print the original vector 
    cout << "Original vector: " << vec; 

    quickSort(vec, 0, n-1);

    // Print the resulting vector 
    cout << "Sorted vector: " << vec; 

    return 0;
}
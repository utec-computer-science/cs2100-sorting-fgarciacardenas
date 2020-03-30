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
void heap(vector<T> &A, int n, int root)
{
    // In a max heap, the root should have the highest value.
    int high = root;

    // The left and right elements are given by:
    int left = 2*root + 1;
    int right = 2*root + 2;
  
    // Determine the root of the heap
    if (left < n && A[left] > A[high]){
        high = left;
    }
    if (right < n && A[right] > A[high]){
        high = right;
    }
  
    // If the highest value is not the root, swap it
    if (high != root) {
        // Swap the elements
        swap(A[root], A[high]);
        
        // Recursively verify the max-heap condition
        heap(A, n, high);
    }
}

template <typename T>
void heapSort(vector<T> &A){ 
    // Calculate the size of the vector
    int n = A.size();

    // Build a max heap
   for (int i = n / 2 - 1; i >= 0; --i) {
       heap(A, n, i);
   }
  
   // Remove the highest element (root) and swap it, then adjust
   for (int i = n - 1; i >= 0; --i) {
      // Swap current root with last element of vector
      swap(A[0], A[i]);
  
      // Adjust the max heap with reduced size
      heap(A, i, 0);
   }
}

int main(int, char*[]){
    // Insert the vector for testing
    // vector<int> vec{ 13, 17, 2, 4, 11, 8, 19, 22, 7 };
    vector<double> vec{ 11.3, 17.1, 2.5, 4.4, 13, 8.1, 19.6, 3, 7.03 }; 
    
    // Print the original vector 
    cout << "Original vector: " << vec; 

    heapSort(vec);

    // Print the resulting vector 
    cout << "Sorted vector: " << vec; 

    return 0;
}
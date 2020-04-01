#include <ostream>
#include <vector>
#include "sorting.h"

// Constructor
template <class T>
Sorting<T>::Sorting(std::vector<T> &v): vec(v) {
	// Calculate the size of the vector
	n = vec.size();
}

template <class T>
void Sorting<T>::insertionSort(){ 
    // Sort the values of the vector
    for (int i = 0; i < n; ++i) {
        swapSort(i);
    }
    std::cout << "Insertion sort executed" << std::endl;
}

template <class T> 
void Sorting<T>::selectionSort(){ 
    // Initialize the variables
    int pos = 0;
    T temp = 0;

    // Sort the values of the vector
    for (int i = 0; i < n; ++i) {
        smallest(i, pos);
        
        // Swap with smallest element
        temp = vec[i];
        vec[i] = vec[pos];
        vec[pos] = temp;
    }
    std::cout << "Selection sort executed" << std::endl;
}

template <class T>
void Sorting<T>::bubbleSort(){ 
    // Initialize the variables
    T temp = 0;

    // Sort the values of the vector
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (vec[j] < vec[i]) {
                // Swap elements
                temp = vec[i];
                vec[i] = vec[j];
                vec[j] = temp;
            }
        }
    }
    std::cout << "Bubble sort executed" << std::endl;
}

template <class T>
void Sorting<T>::heapSort(){ 
    // Build a max heap
   for (int i = n / 2 - 1; i >= 0; --i) {
       heap(n, i);
   }
  
   // Remove the highest element (root) and swap it, then adjust
   for (int i = n - 1; i >= 0; --i) {
      // Swap current root with last element of vector
      std::swap(vec[0], vec[i]);
  
      // Adjust the max heap with reduced size
      heap(i, 0);
   }
   std::cout << "Heap sort executed" << std::endl;
}

template <class T> 
void Sorting<T>::mergeSort(int low, int high){ 
    if (low < high) {
        // Divide the vector in the middle and sort each half
        int mid = (low + high)/2;
        mergeSort(low, mid);
        mergeSort(mid+1, high);

        // Merge the sorted vectors
        merge(low, high, mid);
    }
    std::cout << "Merge sort executed" << std::endl;
}

template <class T>
void Sorting<T>::quickSort(int low, int high){ 
    if (low < high) {
        // Compute the pivot and sort partitions
        int p = pivot(low, high);
        quickSort(low, p - 1);
        quickSort(p + 1, high);
    }
    std::cout << "Quick sort executed" << std::endl;
}

template <class T>
void Sorting<T>::shellSort(){    
    // Begin with a big step and reduce it by half each time
    for(int step = n/2; step > 0; step /= 2) {

        // Gapped insertion sort for the current step
        for(int j = step; j < n; j++) {
            
            // Shift elements until the correct position is found
            for(int k = j - step; k >= 0; k -= step) {
                if(vec[k + step] >= vec[k]) {
                    break;
                }
                else {
                    std::swap(vec[k + step], vec[k]);
                }
            }
        }
    }
    std::cout << "Shell sort executed" << std::endl;
}

template <class T>
void Sorting<T>::brickSort() {    
    bool stop = false;
    
    while (!stop) { 
        stop = true; 
  
        // Bubble sort odd elements 
        for (int i = 1; i <= n - 2; i = i + 2) { 
            if (vec[i] > vec[i + 1]) { 
                std::swap(vec[i], vec[i + 1]); 
                stop = false; 
            } 
        } 
  
        // Bubble sort even elements
        for (int i = 0; i <= n - 2; i = i + 2) { 
            if (vec[i] > vec[i + 1]) { 
                std::swap(vec[i], vec[i + 1]); 
                stop = false; 
            } 
        } 
    }
    std::cout << "Brick sort executed" << std::endl;
}

template <class T>
void Sorting<T>::swapSort(int &i){
    // Element to be inserted
    T temp = vec[i];
    int j = i - 1;

    // Locate position to insert the element
    while (j >= 0 && temp <= vec[j]) {
        vec[j + 1] = vec[j];
        --j;
    }

    // Insert the element
    vec[j + 1] = temp;
}

template <class T> 
void Sorting<T>::smallest(int &i, int &pos){
    // Element to be inserted
    T min = vec[i];
    
    // Reposition the selector
    pos = i;

    // Locate position of smallest element
    for (int j = i + 1; j < n; ++j) {
        if (min > vec[j]) {
            min = vec[j];
            pos = j;
        }  
    }
}

template <class T> 
void Sorting<T>::merge(int low, int high, int mid){
    // Initialize the selectors
    int i = low;
    int k = low;
    int j = mid + 1;

    // Copy the original vector
    std::vector<T> temp = vec;

    // Iterate while each half has elements
    while (i <= mid && j <= high) {
        if (vec[i] < vec[j]) {
            temp[k] = vec[i];
            ++k;
            ++i;
        }
        else  {
            temp[k] = vec[j];
            ++k;
            ++j;
        }
    }

    // Iterate while first half has elements
    while (i <= mid) {
        temp[k] = vec[i];
        ++k;
        ++i;
    }

    // Iterate while second half has elements
    while (j <= high) {
        temp[k] = vec[j];
        ++k;
        ++j;
    }

    // Merge the two halfs
    for (i = low; i < k; ++i) {
        vec[i] = temp[i];
    }
}

template <class T>
void Sorting<T>::heap(int n, int root){
    // In a max heap, the root should have the highest value.
    int high = root;

    // The left and right elements are given by:
    int left = 2*root + 1;
    int right = 2*root + 2;
  
    // Determine the root of the heap
    if (left < n && vec[left] > vec[high]){
        high = left;
    }
    if (right < n && vec[right] > vec[high]){
        high = right;
    }
  
    // If the highest value is not the root, swap it
    if (high != root) {
        // Swap the elements
        std::swap(vec[root], vec[high]);
        
        // Recursively verify the max-heap condition
        heap(n, high);
    }
}

template <class T>
int Sorting<T>::pivot(int low, int high){
    // Select the last element as pivot
    int p = vec[high];

    // Initialize index
    int i = (low - 1);

    // Verify that the sub-vector is sorted
    for (int j = low; j <= high - 1; ++j) {
        if (vec[j] <= p) {
            // Swap element smaller than pivot
            ++i;
            std::swap(vec[i], vec[j]);
        }
    }
    
    // Swap the pivot and return its index
    std::swap(vec[i + 1], vec[high]); 
    return (i + 1);
}

template <class T>
int Sorting<T>::getLength(){
    return n;
}

// Override the << operator to print the vector values
template <class T> 
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) 
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
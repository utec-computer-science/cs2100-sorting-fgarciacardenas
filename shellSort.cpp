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
void shellSort(vector<T> &A, int n){    
    // Begin with a big step and reduce it by half each time
    for(int step = n/2; step > 0; step /= 2) {

        // Gapped insertion sort for the current step
        for(int j = step; j < n; j++) {
            
            // Shift elements until the correct position is found
            for(int k = j - step; k >= 0; k -= step) {
                if(A[k + step] >= A[k]) {
                    break;
                }
                else {
                    swap(A[k + step], A[k]);
                }
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

    shellSort(vec, n);

    // Print the resulting vector 
    cout << "Sorted vector: " << vec; 

    return 0;
}
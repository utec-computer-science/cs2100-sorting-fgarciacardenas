#include <iostream>
#include <vector>
#include "sorting.h"

int main(int, char*[]){
    // Insert the vector for testing
    //std::vector<int> vec{ 13, 17, 2, 4, 11, 8, 19, 3, 7 };
	std::vector<double> vec{ 11.3, 17.1, 2.5, 4.4, 13, 8.1, 19.6, 3, 7.03 }; 

    // Print the original vector 
    std::cout << "Original vector: " << vec; 

	// Create an object Sorting
	Sorting <double> objSort(vec);

	// Test each sorting algorithm
	objSort.insertionSort();
	//objSort.selectionSort();
	//objSort.bubbleSort();
	//objSort.mergeSort(0, objSort.getLength() - 1);
	//objSort.heapSort();
	//objSort.quickSort(0, objSort.getLength() - 1);
	//objSort.shellSort();
	//objSort.brickSort();

    // Print the resulting vector 
    std::cout << "Sorted vector: " << vec; 

    return 0;
}
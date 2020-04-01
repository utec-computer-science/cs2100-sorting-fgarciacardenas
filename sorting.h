#ifndef SORTING_H
#define SORTING_H
#include <ostream>
#include <vector>

template <class T>
class Sorting {
    private:
        std::vector<T> &vec;
        int n;
    public:
        // Constructor
        Sorting(std::vector<T> &v);

        // Sorting algorithms
        void insertionSort();
        void selectionSort();
        void bubbleSort();
        void mergeSort(int low, int high);
        void heapSort();
        void quickSort(int low, int high);
        void shellSort();
        void brickSort();

        // Helper functions
        void swapSort(int &i);
        void smallest(int &i, int &pos);
        void merge(int low, int high, int mid);
        void heap(int n, int root);
        int pivot(int low, int high);
        int getLength();
};

// Override the << operator to print the vector values
template <typename T> 
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v);

#include "sorting.cpp"
#endif

#include <iostream>
#include <vector>
using namespace std;
int main(){
  
  
}

bool isSorted(const vector < int > & L) {
  for (int i = 1; i < L.size(); i++) {
    // If the current value is smaller than the last, then it isn't sorted
    if (L[i] < L[i - 1]) {
      return false;
    }
  }
  return true;
}

void bubbleSort(vector<int>& arr) {
  // This handles the number of passes
  for (int i = 0; i < arr.size() - 1; ++i) {
    // Perform swaps in each pass
    for (int j = 0; j < arr.size() - i - 1; ++j) {
      // If the current element is greater than the next one, then swap them
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}

void insertionSort(vector<int>& arr) {
  // Start from the second element (index 1)
  for (int i = 1; i < arr.size(); ++i) {
    int key = arr[i];  // Element to be placed at the right position
    int j = i - 1;
    // Move elements of arr[0..i-1], that are greater than key, to one position
    // ahead
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];  // Shift element to the right
      --j;
    }
    // Place key in its correct position
    arr[j + 1] = key;
  }
}

void selectionSort(vector<int>& arr) {
  // Loop through the array
  for (size_t i = 0; i < arr.size() - 1; ++i) {
    size_t minIndex = i;  // Assume the current element is the smallest

    // Find the smallest element in the unsorted part
    for (size_t j = i + 1; j < arr.size(); ++j) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;  // Update the minimum index
      }
    }
    // This will swap the smallest found element with the first element of the unsorted values
    swap(arr[i], arr[minIndex]);
  }
}

// Function to partition the array (this is used by quicksort)
int partition(vector<int>& arr, int low, int high) {
  int pivot = arr[high];  // Choose the last element as the pivot
  int i = low - 1;        // Acts as a pointer for the smaller elements

  // This will loop through the array to partition it based on the pivot
  for (int j = low; j < high; ++j) {
    if (arr[j] < pivot) {
      ++i;
      swap(arr[i],
           arr[j]);  // Move element smaller than pivot to the correct position
    }
  }
  // Put the pivot in the correct sort
  swap(arr[i + 1], arr[high]);
  return i + 1;  // Return the index of said sort
}

// Recursive function to implement the Quicksort 
void quicksort(vector<int>& arr, int low, int high) {
  if (low < high) {
    // This will Partition the array and grab the pivot index
    int pi = partition(arr, low, high);

    // Recursively sort the elements before and after saidpivot
    quicksort(arr, low, pi - 1);
    quicksort(arr, pi + 1, high);
  }
}

// Function to make it easier to call the quicksort without specifying what's low and high 

void quicksort(vector<int>& arr) { 
  quicksort(arr, 0, arr.size() - 1);
}

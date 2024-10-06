
#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

vector<int> randomVectorGen(int size, int low, int high) {
	vector<int> v(size); // creates empty vector of size size 
	for( int i = 0; i < size; i++ ) {
		v[i] = rand() % (high - low + 1) + low; // generates random number between low and high then we add low to offset it
	}
	return v;
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
  for (int i = 0; i < arr.size() - 1; ++i) {
    int minIndex = i;  // Assume the current element is the smallest

    // Find the smallest element in the unsorted part
    for (int j = i + 1; j < arr.size(); ++j) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;  // Update the minimum index
      }
    }
    // This will swap the smallest found element with the first element of the unsorted values
    swap(arr[i], arr[minIndex]);
  }
}

// Partition the array using the first element as the pivot
int firstElementPartition(vector<int>& arr, int low, int high) {
  int pivot = arr[low];  // First element as pivot
  int i = low + 1;
  for (int j = low + 1; j <= high; ++j) {
    if (arr[j] < pivot) {
      swap(arr[i], arr[j]);
      ++i;
    }
  }
  swap(arr[low], arr[i - 1]);  // Move pivot to its correct position
  return i - 1;                // Return the index of the pivot
}

// Quicksort that uses the first element as the pivot
void quicksortFirstPivot(vector<int>& arr, int low, int high) {
  if (low < high) {
    int pi = firstElementPartition(
        arr, low, high);  // Partition using first element as pivot
    quicksortFirstPivot(arr, low, pi - 1);   // Recur for the left subarray
    quicksortFirstPivot(arr, pi + 1, high);  // Recur for the right subarray
  }
}

// Wrapper for quicksort with first element as pivot
void quicksortFirstPivot(vector<int>& arr) {
  quicksortFirstPivot(arr, 0, arr.size() - 1);
}

// Runs the experiments for part1
void sortExperiment(void (*sortFunction)(vector<int>&), const vector<vector<int> >&tenVectors) { // Utilize pointer for the function testing
	vector<double> sortTimes; // This will hold all the times of the experiments
	for( int i = 0; i < 2; i++) {
		vector<int> vec = tenVectors[i];
		for (int j = 0; j < vec.size(); j++) {
			cout << vec[j] << ", ";
		}
		cout << endl;
		cout << "================================================================"<< endl; // Looks better
		sortFunction(vec);
		if(!isSorted(vec)) {
			cout << "Failed to sort vector " << endl;
		}
		else {
			for (int c = 0; c < vec.size(); c++) {
			cout << vec[c] << ", ";
		}
		cout << endl;
				cout << "================================================================"<< endl;

		}
	}


}

void partOneExperiment() { 
	vector<vector<int> > tenTestVectors; // Vector of test vectors
		for(int i = 0; i < 10; i++) {
			tenTestVectors.push_back(randomVectorGen(100, 0, 100)); // Generates 10 test vectors of size 100
		}
		//sortExperiment(bubbleSort, tenTestVectors);
		//sortExperiment(insertionSort, tenTestVectors);
		sortExperiment(quicksortFirstPivot, tenTestVectors);

}

void partTwoExperiment() { 

}

int main() {
	srand(time(NULL)); // sets seed for the random number generator

	partOneExperiment();

	partTwoExperiment();

	return 0;
}
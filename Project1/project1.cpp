
#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
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

double timeFunction(void (*sortFunction)(vector<int> &), vector<int> & timedVector) {
  auto start = chrono::high_resolution_clock::now();
  sortFunction(timedVector);
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double> sortDuration = end - start;
  return sortDuration.count();
}

double calculateMean(const vector<double>& sortTimes) {
  double sum = 0;
  for(int i = 0; i < sortTimes.size(); i++) {
    sum += sortTimes[i];
  }
  return sum/sortTimes.size();
}

double calculateSD(const vector<double>& sortTimes, double mean) { 
  double sum = 0;
  for(int i = 0; i < sortTimes.size(); i++) {
    sum += pow(sortTimes[i] - mean, 2);
  }
  return sqrt(sum/(sortTimes.size()-1));
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
void sortExperiment(void (*sortFunction)(vector<int>&), string sortName, const vector<vector<int> >&tenVectors) { // Utilize pointer for the function testing
	vector<double> sortTimes; // This will hold all the times of the experiments

  for(int i = 0; i < tenVectors.size(); i++) {
    vector<int> tempVector = tenVectors[i];
    double testTimes = timeFunction(sortFunction, tempVector);

    if(!isSorted(tempVector)) {
      cout << "Error: " << sortName << " failed to sort vector" << i+1 << endl;
    }

    sortTimes.push_back(testTimes);
  }

  double minTime = *min_element(sortTimes.begin(), sortTimes.end());
  double maxTime = *max_element(sortTimes.begin(), sortTimes.end());
  double mean = calculateMean(sortTimes);
  double sd = calculateSD(sortTimes, mean);

  cout << fixed << setprecision(6);
  cout << "********************************" << endl;
  cout << sortName << " on 10 vectors of length 100" << endl;
  cout << "Sorting Succesfull" << endl;
  cout << "Minimum: " << minTime << " sec;" << endl;
  cout << "Mean: " << mean << " sec;" << endl;
  cout << "Standard Deviation: " << sd << " sec;" << endl;
  cout << "Maximum: " << maxTime << " sec;" << endl;
  cout << "********************************" << endl;
}

void partOneExperiment() { 
	vector<vector<int> > tenTestVectors; // Vector of test vectors
		for(int i = 0; i < 10; i++) {
			tenTestVectors.push_back(randomVectorGen(100, 0, 100)); // Generates 10 test vectors of size 100
		}
		sortExperiment(bubbleSort, "Bubble Sort",tenTestVectors);
		sortExperiment(insertionSort, "Insertion Sort", tenTestVectors);
    sortExperiment(selectionSort, "Selection Sort", tenTestVectors);
		sortExperiment(quicksortFirstPivot, "Quick Sort", tenTestVectors);

}

void partTwoExperiment() { 

}

int main() {
	srand(time(NULL)); // sets seed for the random number generator

	partOneExperiment();

	partTwoExperiment();

	return 0;
}
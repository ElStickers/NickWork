
#include <iostream>
#include <vector>
using namespace std;
int main(){
  
  
}

bool isSorted(const vector<int>& L) {
  for (int i = 1; i < L.size(); i++) {
    if(L[i] < L[i-1]) {
      return false;
    }
  }
  return true;
} 


vector <int> bubbleSort(vector <int>& L) {
  bool sorted = false;

  while (!sorted) {
    sorted = true;
    for (int i = 1; i < L.size(); ++i) {
      if (L[i - 1] > L[i]) {
        // Swap elements
        int temp = L[i - 1];
        L[i - 1] = L[i];
        L[i] = temp;
        sorted = false;
      }
    }
  }

  return L;
}


vector<int> insertionSort(vector<int>& L) {
    int i = 1;

    while (i < L.size()) {
        int j = i;
        while (j > 0 && L[j] < L[j - 1]) {
            // Swap elements
            int temp = L[j - 1];
            L[j - 1] = L[j];
            L[j] = temp;
            j = j - 1;
        }
        i = i + 1;
    }

    return L;
}


vector<int> selectionSort(vector<int>& L) {
    for (int i = 0; i < L.size() - 1; ++i) {
        int uMin = i;  // Assume the current index is the smallest
        for (int j = i + 1; j < L.size(); ++j) {
            if (L[j] < L[uMin]) {
                uMin = j;  // Update the index of the smallest element
            }
        }
        // Swap the smallest element found with the element at index i
        int temp = L[i];
        L[i] = L[uMin];
        L[uMin] = temp;
    }

    return L;
}


vector<int> quicksort(vector<int> L) {
    // Base case: If the list has 1 or fewer elements, it's already sorted
    if (L.size() <= 1) {
        return L;
    }

    // Choose the pivot (in this case, the first element)
    int pivot = L[0];
    vector<int> A;  // Elements less than or equal to pivot
    vector<int> B;  // Elements greater than pivot

    // Partition the list into two sublists A and B
    for (int i = 1; i < L.size(); ++i) {
        if (L[i] <= pivot) {
            A.push_back(L[i]);
        } else {
            B.push_back(L[i]);
        }
    }

    // Recursively sort A and B, then concatenate the results with the pivot
    A = quicksort(A);
    B = quicksort(B);

    // Concatenate A, pivot, and B
    A.push_back(pivot);  // Add pivot in the middle
    A.insert(A.end(), B.begin(), B.end());  // Append B to A

    return A;
}
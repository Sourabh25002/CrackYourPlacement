#include <bits/stdc++.h>
using namespace std;

// Counting Sort function used by Radix Sort
void countingSort(vector<int> &arr, int exp)
{
  int n = arr.size();
  vector<int> output(n);    // Output array
  vector<int> count(10, 0); // Count array for digits 0 to 9

  // Store count of occurrences of each digit in count[]
  for (int i = 0; i < n; ++i)
  {
    count[(arr[i] / exp) % 10]++;
  }

  // Change count[i] so that count[i] now contains actual position of this digit in output[]
  for (int i = 1; i < 10; ++i)
  {
    count[i] += count[i - 1];
  }

  // Build the output array
  for (int i = n - 1; i >= 0; --i)
  {
    output[count[(arr[i] / exp) % 10] - 1] = arr[i];
    count[(arr[i] / exp) % 10]--;
  }

  // Copy the output array to arr[], so that arr[] contains sorted numbers
  for (int i = 0; i < n; ++i)
  {
    arr[i] = output[i];
  }
}

// Main function to implement Radix Sort
void radixSort(vector<int> &arr)
{
  // Find the maximum number to determine the number of digits
  int maxVal = *max_element(arr.begin(), arr.end());

  // Apply counting sort to sort elements based on place value
  for (int exp = 1; maxVal / exp > 0; exp *= 10)
  {
    countingSort(arr, exp);
  }
}

int main()
{
  vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
  radixSort(arr);

  cout << "Sorted array: ";
  for (int num : arr)
  {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}

/*
Time Complexity: O(n * k), where n is the number of elements and k is the number of digits in the maximum number.
Space Complexity: O(n + k), where n is the number of elements and k is the range of digits (0 to 9).
*/

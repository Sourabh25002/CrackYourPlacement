#include <bits/stdc++.h>
using namespace std;

int nthUglyNumber(int n)
{
  // Min-heap to store the current ugly numbers
  priority_queue<long, vector<long>, greater<long>> minHeap;
  unordered_set<long> seen; // To avoid duplicate entries in the heap

  // Initial ugly number
  minHeap.push(1);
  seen.insert(1);

  // Prime factors
  vector<int> primes = {2, 3, 5};
  long ugly = 1;

  // Generate the first n ugly numbers
  for (int i = 0; i < n; i++)
  {
    ugly = minHeap.top(); // Get the smallest ugly number
    minHeap.pop();        // Remove it from the heap

    // Generate the next possible ugly numbers by multiplying with primes
    for (int prime : primes)
    {
      long nextUgly = ugly * prime;
      if (seen.find(nextUgly) == seen.end())
      {
        minHeap.push(nextUgly); // Push the new ugly number to the heap
        seen.insert(nextUgly);  // Mark it as seen
      }
    }
  }

  return ugly; // Return the nth ugly number
}

int main()
{
  int n = 10;
  int result = nthUglyNumber(n);

  // Print the result
  cout << "The " << n << "th ugly number is: " << result << endl;

  return 0;
}

// Time Complexity: O(n * log n)
// Space Complexity: O(n)
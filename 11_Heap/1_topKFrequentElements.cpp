#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
  // Min-heap to store pairs of (frequency, element)
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
  unordered_map<int, int> mpp; // Hashmap to count frequency of elements
  vector<int> ans;             // To store the result

  // Count frequency of each element
  for (auto it : nums)
  {
    mpp[it]++;
  }

  // Insert elements into the min-heap based on their frequency
  for (auto it : mpp)
  {
    minHeap.push({it.second, it.first});

    // Ensure the heap contains at most k elements
    if (minHeap.size() > k)
      minHeap.pop();
  }

  // Extract elements from the heap, which are the k most frequent
  while (!minHeap.empty())
  {
    ans.push_back(minHeap.top().second);
    minHeap.pop();
  }

  return ans;
}

int main()
{
  vector<int> nums = {1, 1, 1, 2, 2, 3};
  int k = 2;

  vector<int> result = topKFrequent(nums, k);

  // Print the result
  for (int num : result)
  {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}

// Time Complexity: O(N * log k)
// Space Complexity: O(N + k)
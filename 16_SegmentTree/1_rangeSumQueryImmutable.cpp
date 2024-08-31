#include <bits/stdc++.h>
using namespace std;

class NumArray
{
private:
  vector<int> prefixSum;

public:
  // Constructor to initialize the prefix sum array
  NumArray(vector<int> &nums)
  {
    int n = nums.size();
    prefixSum.resize(n + 1, 0);
    for (int i = 0; i < n; ++i)
    {
      prefixSum[i + 1] = prefixSum[i] + nums[i];
    }
  }

  // Function to get the sum of elements between indices left and right inclusive
  int sumRange(int left, int right)
  {
    return prefixSum[right + 1] - prefixSum[left];
  }
};

int main()
{
  // Example usage
  vector<int> nums = {-2, 0, 3, -5, 2, -1};
  NumArray numArray(nums);

  cout << numArray.sumRange(0, 2) << endl; // Output: 1
  cout << numArray.sumRange(2, 5) << endl; // Output: -1
  cout << numArray.sumRange(0, 5) << endl; // Output: -3

  return 0;
}

/*
Time Complexity: O(n) for the constructor, where n is the length of the input array. O(1) for each sumRange query.
Space Complexity: O(n) for storing the prefix sum array.
*/

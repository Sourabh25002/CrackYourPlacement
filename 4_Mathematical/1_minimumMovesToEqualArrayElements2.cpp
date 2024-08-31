#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minMoves2(vector<int> &nums)
  {
    // Sort the array
    sort(nums.begin(), nums.end());
    int median = nums[nums.size() / 2];
    int moves = 0;

    // Calculate the total number of moves required to make all elements equal to the median
    for (int num : nums)
    {
      moves += abs(num - median);
    }

    return moves;
  }
};

int main()
{
  Solution sol;

  int n;
  cout << "Input the number of elements in the array: ";
  cin >> n;

  vector<int> nums(n);
  cout << "Input the elements of the array:" << endl;
  for (int i = 0; i < n; ++i)
  {
    cin >> nums[i];
  }

  cout << "Minimum moves to make all elements equal: " << sol.minMoves2(nums) << endl;

  return 0;
}

/*
Time Complexity: O(N log N), where N is the number of elements in the array (due to sorting).
Space Complexity: O(1), as the solution uses constant extra space besides the input array.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> productArray(const vector<int> &nums)
{
  int n = nums.size();
  vector<int> leftProduct(n, 1), rightProduct(n, 1), result(n);

  // Calculate left products
  for (int i = 1; i < n; ++i)
  {
    leftProduct[i] = leftProduct[i - 1] * nums[i - 1];
  }

  // Calculate right products and the result in one pass
  for (int i = n - 2; i >= 0; --i)
  {
    rightProduct[i] = rightProduct[i + 1] * nums[i + 1];
    result[i] = leftProduct[i] * rightProduct[i];
  }

  return result;
}

int main()
{
  vector<int> nums;

  cout << "Enter the number of elements in the array: ";
  int size;
  cin >> size;

  cout << "Enter the elements of the array: ";
  for (int i = 0; i < size; ++i)
  {
    int num;
    cin >> num;
    nums.push_back(num);
  }

  vector<int> result = productArray(nums);

  cout << "Product array: ";
  for (int num : result)
  {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}

/*
Time Complexity: O(n), where n is the number of elements in the array. The algorithm makes a single pass to compute left and right products.
Space Complexity: O(n), due to the use of additional arrays to store left and right products.
*/

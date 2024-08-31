#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k)
  {
    // Create a vector to store the ratio of wage to quality and the respective quality index
    vector<pair<double, int>> ratio;
    int n = quality.size();

    // Populate the ratio vector with wage-to-quality ratio and corresponding index
    for (int i = 0; i < n; ++i)
    {
      ratio.emplace_back(static_cast<double>(wage[i]) / quality[i], i);
    }

    // Sort the ratio vector based on the ratio in ascending order
    sort(ratio.begin(), ratio.end());

    // Max heap to maintain the highest quality workers in the current group
    priority_queue<int> maxHeap;
    int qualitySum = 0;
    double result = DBL_MAX;

    // Loop through the first k workers based on the sorted ratio
    for (int i = 0; i < k; ++i)
    {
      qualitySum += quality[ratio[i].second];
      maxHeap.push(quality[ratio[i].second]);
    }

    // Calculate the initial cost for the first k workers
    result = qualitySum * ratio[k - 1].first;

    // Loop through the remaining workers
    for (int i = k; i < n; ++i)
    {
      // Remove the worker with the highest quality from the group
      qualitySum -= maxHeap.top();
      maxHeap.pop();

      // Add the current worker to the group
      qualitySum += quality[ratio[i].second];
      maxHeap.push(quality[ratio[i].second]);

      // Calculate the minimum cost based on the current worker's ratio
      result = min(result, qualitySum * ratio[i].first);
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<int> quality = {10, 20, 5};
  vector<int> wage = {70, 50, 30};
  int k = 2;
  double result = sol.mincostToHireWorkers(quality, wage, k);

  cout << fixed << setprecision(5) << "Minimum cost to hire " << k << " workers: " << result << endl;
  return 0;
}

/*
Time Complexity:
- The time complexity is O(n log n), where n is the number of workers.
- Sorting the ratio vector takes O(n log n), and processing the heap takes O(n log k).

Space Complexity:
- The space complexity is O(n) for storing the ratio and heap.
*/

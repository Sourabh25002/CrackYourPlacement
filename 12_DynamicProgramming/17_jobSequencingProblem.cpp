#include <bits/stdc++.h>
using namespace std;

// Function to find the number of jobs done and maximum profit
class Solution
{
public:
  // Job structure to hold job details
  struct Job
  {
    int id;
    int deadline;
    int profit;
  };

  // Comparison function to sort jobs by profit in descending order
  static bool compare(Job a, Job b)
  {
    return a.profit > b.profit;
  }

  // Main function to solve the job sequencing problem
  pair<int, int> jobScheduling(vector<Job> &jobs, int n)
  {
    // Sort jobs by profit in descending order
    sort(jobs.begin(), jobs.end(), compare);

    // Find the maximum deadline to determine the size of the slots array
    int maxDeadline = 0;
    for (const auto &job : jobs)
    {
      maxDeadline = max(maxDeadline, job.deadline);
    }

    // Create an array to keep track of free time slots
    vector<bool> slots(maxDeadline + 1, false);

    int jobCount = 0;
    int maxProfit = 0;

    // Schedule jobs
    for (const auto &job : jobs)
    {
      // Find a free slot for this job (starting from its deadline)
      for (int j = job.deadline; j > 0; --j)
      {
        if (!slots[j])
        {
          // Assign job to the found slot
          slots[j] = true;
          maxProfit += job.profit;
          jobCount++;
          break;
        }
      }
    }

    return {jobCount, maxProfit};
  }
};

int main()
{
  Solution sol;

  // Example 1
  vector<Solution::Job> jobs1 = {{1, 4, 20}, {2, 1, 1}, {3, 1, 40}, {4, 1, 30}};
  auto result1 = sol.jobScheduling(jobs1, jobs1.size());
  cout << "Output for Jobs 1: " << result1.first << " " << result1.second << endl; // Output: 2 60

  // Example 2
  vector<Solution::Job> jobs2 = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 1, 15}};
  auto result2 = sol.jobScheduling(jobs2, jobs2.size());
  cout << "Output for Jobs 2: " << result2.first << " " << result2.second << endl; // Output: 2 127

  return 0;
}

/*
Time Complexity: O(n log n) for sorting + O(n * d) where d is the maximum deadline
Space Complexity: O(d) for the slots array, where d is the maximum deadline
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int leastInterval(vector<char> &tasks, int n)
  {
    vector<int> freq(26, 0);
    for (char task : tasks)
    {
      freq[task - 'A']++;
    }

    sort(freq.begin(), freq.end(), greater<int>());

    int maxFreq = freq[0];
    int idleSlots = (maxFreq - 1) * n;

    for (int i = 1; i < 26 && freq[i] > 0; i++)
    {
      idleSlots -= min(maxFreq - 1, freq[i]);
    }

    idleSlots = max(0, idleSlots);

    return tasks.size() + idleSlots;
  }
};

int main()
{
  Solution solution;

  vector<char> tasks1 = {'A', 'A', 'A', 'B', 'B', 'B'};
  int n1 = 2;
  cout << "Example 1 Output: " << solution.leastInterval(tasks1, n1) << endl; // Output: 8

  vector<char> tasks2 = {'A', 'C', 'A', 'B', 'D', 'B'};
  int n2 = 1;
  cout << "Example 2 Output: " << solution.leastInterval(tasks2, n2) << endl; // Output: 6

  vector<char> tasks3 = {'A', 'A', 'A', 'B', 'B', 'B'};
  int n3 = 3;
  cout << "Example 3 Output: " << solution.leastInterval(tasks3, n3) << endl; // Output: 10

  return 0;
}

/*
Time Complexity: O(N + 26log26), where N is the number of tasks (for counting frequency) and 26log26 is for sorting the frequency array.
Space Complexity: O(1) as we use a fixed-size frequency array.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
  {
    // If starting fuel is already greater or equal to the target, no need to refuel
    if (startFuel >= target)
      return 0;

    // Max heap to store the fuel capacities of stations we've passed
    priority_queue<int> max_heap;
    int i = 0, n = stations.size();
    int stops = 0;                // Number of refueling stops made
    int max_distance = startFuel; // Maximum distance the car can travel with the current fuel

    // Loop until the car reaches the target or runs out of fuel
    while (max_distance < target)
    {
      // Add fuel capacities to the heap for all stations within the current range
      while (i < n && stations[i][0] <= max_distance)
      {
        max_heap.push(stations[i][1]);
        i++;
      }

      // If there are no more stations in range and the target is not reachable, return -1
      if (max_heap.empty())
        return -1;

      // Refuel with the largest fuel available from the heap and increment stops
      max_distance += max_heap.top();
      max_heap.pop();
      stops++;
    }

    // Return the number of refueling stops needed to reach the target
    return stops;
  }
};

int main()
{
  Solution sol;
  int target = 100;
  int startFuel = 10;
  vector<vector<int>> stations = {{10, 60}, {20, 30}, {30, 30}, {60, 40}};
  int result = sol.minRefuelStops(target, startFuel, stations);

  cout << "Minimum number of refueling stops to reach the target: " << result << endl;
  return 0;
}

/*
Time Complexity:
- The time complexity is O(n log n), where n is the number of gas stations.
- Inserting an element into the max heap takes O(log n) time, and in the worst case, we insert all stations into the heap.

Space Complexity:
- The space complexity is O(n) because, in the worst case, we might store all stations' fuel in the heap.
*/

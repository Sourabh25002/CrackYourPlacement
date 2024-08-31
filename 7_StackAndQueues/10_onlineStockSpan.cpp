#include <bits/stdc++.h>
using namespace std;

class StockSpanner
{
private:
  stack<pair<int, int>> st; // Stack to store pairs of (price, span)

public:
  StockSpanner()
  {
    // Constructor does nothing special
  }

  int next(int price)
  {
    int span = 1; // The minimum span is 1 (the current day itself)

    // Calculate the span
    while (!st.empty() && st.top().first <= price)
    {
      span += st.top().second; // Accumulate the span of the days with less or equal price
      st.pop();                // Remove those days from the stack
    }

    // Push the current price and its span onto the stack
    st.push({price, span});

    return span;
  }
};

int main()
{
  StockSpanner stockSpanner;

  // Example sequence of stock prices and their spans
  vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
  vector<int> results;

  for (int price : prices)
  {
    results.push_back(stockSpanner.next(price));
  }

  // Output the results
  for (int result : results)
  {
    cout << result << " ";
  }
  cout << endl;

  return 0;
}

/*
Time Complexity: O(1) on average for each call to `next()` due to amortized analysis, though in the worst case, it can be O(n) where n is the number of elements in the stack.

Space Complexity: O(n) where n is the number of elements pushed onto the stack.
*/

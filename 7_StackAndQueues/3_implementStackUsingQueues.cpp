#include <bits/stdc++.h>
using namespace std;

class MyStack
{
public:
  queue<int> q1, q2;

  MyStack()
  {
    // Constructor initializes the stack
  }

  void push(int x)
  {
    // Push element x onto stack
    q2.push(x);

    // Transfer all elements from q1 to q2
    while (!q1.empty())
    {
      q2.push(q1.front());
      q1.pop();
    }

    // Swap the names of q1 and q2
    queue<int> temp = q1;
    q1 = q2;
    q2 = temp;
  }

  int pop()
  {
    // Remove the element on the top of the stack and return it
    if (q1.empty())
    {
      return -1; // Stack is empty
    }

    int front = q1.front();
    q1.pop();
    return front;
  }

  int top()
  {
    // Get the element on the top of the stack without removing it
    if (q1.empty())
    {
      return -1; // Stack is empty
    }

    return q1.front();
  }

  bool empty()
  {
    // Check if the stack is empty
    return q1.empty();
  }
};

int main()
{
  MyStack myStack;

  // Example 1:
  myStack.push(1);
  myStack.push(2);
  cout << "Top element: " << myStack.top() << endl;                           // Outputs: 2
  cout << "Popped element: " << myStack.pop() << endl;                        // Outputs: 2
  cout << "Is stack empty? " << (myStack.empty() ? "true" : "false") << endl; // Outputs: false

  return 0;
}

/*
Time Complexity:
- push(): O(n), where n is the number of elements in the stack. We move all elements from q1 to q2 and then swap them.
- pop(): O(1), since we only remove the front element from q1.
- top(): O(1), since we only access the front element of q1.
- empty(): O(1), since we only check if q1 is empty.

Space Complexity:
- O(n), where n is the number of elements in the stack. We use two queues to store the elements, which requires space proportional to the number of elements.
*/

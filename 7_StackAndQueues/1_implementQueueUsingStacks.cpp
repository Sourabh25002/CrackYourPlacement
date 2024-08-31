#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
public:
  stack<int> s1, s2;

  MyQueue()
  {
    // Constructor: No initialization required as we're using stacks.
  }

  void push(int x)
  {
    // Move all elements from s1 to s2
    while (!s1.empty())
    {
      s2.push(s1.top());
      s1.pop();
    }

    // Push the new element onto s1
    s1.push(x);

    // Move all elements back from s2 to s1
    while (!s2.empty())
    {
      s1.push(s2.top());
      s2.pop();
    }
  }

  int pop()
  {
    if (s1.empty())
    {
      return -1; // or handle the case when the queue is empty
    }

    // Return the top element of s1 which is the front of the queue
    int x = s1.top();
    s1.pop();
    return x;
  }

  int peek()
  {
    if (s1.empty())
    {
      return -1; // or handle the case when the queue is empty
    }

    // Return the top element of s1 which is the front of the queue
    return s1.top();
  }

  bool empty()
  {
    // Check if s1 is empty
    return s1.empty();
  }
};

int main()
{
  MyQueue myQueue;

  // Example from the prompt:
  myQueue.push(1); // Queue is now: [1]
  myQueue.push(2); // Queue is now: [1, 2]

  cout << myQueue.peek() << endl;  // Outputs: 1
  cout << myQueue.pop() << endl;   // Outputs: 1, Queue is now: [2]
  cout << myQueue.empty() << endl; // Outputs: 0 (false)

  return 0;
}

/*
Time Complexities:
- Push: O(n), where n is the number of elements in the queue. This is because each push operation requires us to transfer elements between the two stacks.
- Pop: O(1), as we directly access the top of the stack.
- Peek: O(1), similar to pop, it only checks the top element.
- Empty: O(1), it just checks whether s1 is empty.

Space Complexity: O(n), where n is the number of elements stored in the queue. We use two stacks to store the elements.
*/

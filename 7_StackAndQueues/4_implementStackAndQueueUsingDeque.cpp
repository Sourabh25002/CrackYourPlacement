#include <bits/stdc++.h>
using namespace std;

// Structure for a node of deque
struct DQueNode
{
  int value;
  DQueNode *next;
  DQueNode *prev;
};

// Implementation of deque class
class Deque
{
public:
  DQueNode *head;
  DQueNode *tail;

public:
  // Constructor
  Deque() : head(NULL), tail(NULL) {}

  // Check if deque is empty
  bool isEmpty() const
  {
    return head == NULL;
  }

  // Count the number of nodes in deque
  int size() const
  {
    int len = 0;
    DQueNode *temp = head;
    while (temp != NULL)
    {
      len++;
      temp = temp->next;
    }
    return len;
  }

  // Insert at the first position
  void insert_first(int element)
  {
    DQueNode *temp = new DQueNode();
    temp->value = element;
    temp->next = head;
    temp->prev = NULL;
    if (head != NULL)
    {
      head->prev = temp;
    }
    head = temp;
    if (tail == NULL)
    {
      tail = temp;
    }
  }

  // Insert at the last position of deque
  void insert_last(int element)
  {
    DQueNode *temp = new DQueNode();
    temp->value = element;
    temp->next = NULL;
    temp->prev = tail;
    if (tail != NULL)
    {
      tail->next = temp;
    }
    tail = temp;
    if (head == NULL)
    {
      head = temp;
    }
  }

  // Remove element at the first position
  void remove_first()
  {
    if (!isEmpty())
    {
      DQueNode *temp = head;
      head = head->next;
      if (head != NULL)
      {
        head->prev = NULL;
      }
      else
      {
        tail = NULL;
      }
      delete temp;
    }
    else
    {
      cout << "List is Empty" << endl;
    }
  }

  // Remove element at the last position
  void remove_last()
  {
    if (!isEmpty())
    {
      DQueNode *temp = tail;
      tail = tail->prev;
      if (tail != NULL)
      {
        tail->next = NULL;
      }
      else
      {
        head = NULL;
      }
      delete temp;
    }
    else
    {
      cout << "List is Empty" << endl;
    }
  }

  // Display the elements in deque
  void display() const
  {
    if (!isEmpty())
    {
      DQueNode *temp = head;
      while (temp != NULL)
      {
        cout << temp->value << " ";
        temp = temp->next;
      }
      cout << endl;
    }
    else
    {
      cout << "List is Empty" << endl;
    }
  }
};

// Class to implement stack using Deque
class Stack : public Deque
{
public:
  // Push to push element at the top of stack
  void push(int element)
  {
    insert_last(element);
  }

  // Pop to remove element at the top of stack
  void pop()
  {
    remove_last();
  }

  // Top to get the top element of stack
  int top() const
  {
    if (!isEmpty())
    {
      return tail->value;
    }
    return -1; // Indicates stack is empty
  }
};

// Class to implement queue using Deque
class Queue : public Deque
{
public:
  // Enqueue to insert element at the end
  void enqueue(int element)
  {
    insert_last(element);
  }

  // Dequeue to remove element from the front
  void dequeue()
  {
    remove_first();
  }

  // Front to get the front element of queue
  int front() const
  {
    if (!isEmpty())
    {
      return head->value;
    }
    return -1; // Indicates queue is empty
  }
};

// Driver Code
int main()
{
  // Object of Stack
  Stack stk;

  // Push 7 and 8 at the top of stack
  stk.push(7);
  stk.push(8);
  cout << "Stack: ";
  stk.display();

  // Pop an element
  stk.pop();
  cout << "Stack after pop: ";
  stk.display();

  // Object of Queue
  Queue que;

  // Insert 12 and 13 in queue
  que.enqueue(12);
  que.enqueue(13);
  cout << "Queue: ";
  que.display();

  // Delete an element from queue
  que.dequeue();
  cout << "Queue after dequeue: ";
  que.display();

  // Display the sizes
  cout << "Size of Stack is " << stk.size() << endl;
  cout << "Size of Queue is " << que.size() << endl;

  return 0;
}

/*
Time Complexity:
- insert_first(): O(1) - Insert at the head.
- insert_last(): O(1) - Insert at the tail.
- remove_first(): O(1) - Remove from the head.
- remove_last(): O(1) - Remove from the tail.
- display(): O(n) - Traverse the entire deque.

Space Complexity:
- O(n) - The space used is proportional to the number of elements in the deque, where n is the number of elements.

Note: `top()` and `front()` functions are added to provide better stack and queue functionalities, respectively. They have O(1) time complexity as they access the head or tail directly.
*/

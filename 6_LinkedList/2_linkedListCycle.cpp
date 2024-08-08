#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct Node
{
  int val;
  Node *next;
  Node(int x) : val(x), next(NULL) {}
};

bool hasCycle(Node *head)
{
  if (head == nullptr || head->next == nullptr)
    return false;

  Node *slow = head;
  Node *fast = head->next->next;

  while (slow != fast)
  {
    if (fast == nullptr || fast->next == nullptr)
      return false;
    slow = slow->next;
    fast = fast->next->next;
  }
  return true;
}

// Function to create a cycle in the linked list
void createCycle(Node *head, int pos)
{
  if (pos == -1)
    return;
  Node *cycleNode = head;
  Node *tail = head;
  for (int i = 0; i < pos; ++i)
  {
    cycleNode = cycleNode->next;
  }
  while (tail->next != nullptr)
  {
    tail = tail->next;
  }
  tail->next = cycleNode;
}

// Function to print the result
void printResult(bool hasCycle)
{
  if (hasCycle)
  {
    cout << "The linked list has a cycle." << endl;
  }
  else
  {
    cout << "The linked list does not have a cycle." << endl;
  }
}

int main()
{
  // Creating a linked list: 1->2->3->4->5
  Node *head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  head->next->next->next->next = new Node(5);

  // Create a cycle in the linked list
  createCycle(head, 2); // The cycle starts at node 3 (0-based index)

  bool result = hasCycle(head);

  printResult(result);

  return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(1)
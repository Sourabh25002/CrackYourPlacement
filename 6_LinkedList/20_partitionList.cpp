#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct Node
{
  int val;
  Node *next;
  Node() : val(0), next(nullptr) {}
  Node(int x) : val(x), next(nullptr) {}
  Node(int x, Node *next) : val(x), next(next) {}
};

Node *partition(Node *head, int x)
{
  // Create two dummy nodes to start the less and greater lists
  Node *lessHead = new Node(0);
  Node *greaterHead = new Node(0);

  // Pointers to the current node in less and greater lists
  Node *less = lessHead;
  Node *greater = greaterHead;

  // Traverse the original list and partition the nodes
  while (head != nullptr)
  {
    if (head->val < x)
    {
      less->next = head;
      less = less->next;
    }
    else
    {
      greater->next = head;
      greater = greater->next;
    }
    head = head->next;
  }

  // Connect the less list to the greater list
  less->next = greaterHead->next;
  // End the greater list
  greater->next = nullptr;

  // The new head is the next node of the less dummy node
  Node *newHead = lessHead->next;

  // Clean up the dummy nodes
  delete lessHead;
  delete greaterHead;

  return newHead;
}

// Helper function to create a linked list from a vector of values
Node *createList(const vector<int> &values)
{
  if (values.empty())
    return nullptr;
  Node *head = new Node(values[0]);
  Node *current = head;
  for (size_t i = 1; i < values.size(); ++i)
  {
    current->next = new Node(values[i]);
    current = current->next;
  }
  return head;
}

// Helper function to print a linked list
void printList(Node *head)
{
  while (head != nullptr)
  {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}

int main()
{
  vector<int> values1 = {1, 4, 3, 2, 5, 2};
  int x1 = 3;
  Node *head1 = createList(values1);
  cout << "Original list: ";
  printList(head1);
  Node *partitioned1 = partition(head1, x1);
  cout << "Partitioned list: ";
  printList(partitioned1);

  vector<int> values2 = {2, 1};
  int x2 = 2;
  Node *head2 = createList(values2);
  cout << "Original list: ";
  printList(head2);
  Node *partitioned2 = partition(head2, x2);
  cout << "Partitioned list: ";
  printList(partitioned2);

  return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)

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

Node *deleteDuplicates(Node *head)
{
  if (!head)
    return nullptr;

  // Create a dummy node to handle edge cases
  Node *dummy = new Node(0);
  dummy->next = head;
  Node *prev = dummy;

  while (head)
  {
    // If the current node is a duplicate
    if (head->next && head->val == head->next->val)
    {
      // Skip all nodes with the same value
      while (head->next && head->val == head->next->val)
      {
        head = head->next;
      }
      // Remove all duplicates
      prev->next = head->next;
    }
    else
    {
      // No duplicates, move prev pointer
      prev = prev->next;
    }
    // Move head pointer
    head = head->next;
  }

  // Get the new head and delete dummy node
  Node *newHead = dummy->next;
  delete dummy;
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
  vector<int> values1 = {1, 2, 3, 3, 4, 4, 5};
  Node *head1 = createList(values1);
  cout << "Original list: ";
  printList(head1);
  Node *result1 = deleteDuplicates(head1);
  cout << "List after removing duplicates: ";
  printList(result1);

  vector<int> values2 = {1, 1, 1, 2, 3};
  Node *head2 = createList(values2);
  cout << "Original list: ";
  printList(head2);
  Node *result2 = deleteDuplicates(head2);
  cout << "List after removing duplicates: ";
  printList(result2);

  return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
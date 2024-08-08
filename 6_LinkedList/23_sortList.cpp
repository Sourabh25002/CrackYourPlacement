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

// Function to split the linked list into two halves
Node *getMiddle(Node *head)
{
  if (!head)
    return nullptr;

  Node *slow = head;
  Node *fast = head->next;

  while (fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;
}

// Function to merge two sorted linked lists
Node *merge(Node *left, Node *right)
{
  Node *dummy = new Node();
  Node *current = dummy;

  while (left && right)
  {
    if (left->val < right->val)
    {
      current->next = left;
      left = left->next;
    }
    else
    {
      current->next = right;
      right = right->next;
    }
    current = current->next;
  }

  if (left)
    current->next = left;
  if (right)
    current->next = right;

  Node *head = dummy->next;
  delete dummy;
  return head;
}

// Function to sort the linked list using merge sort
Node *sortList(Node *head)
{
  if (!head || !head->next)
    return head;

  Node *middle = getMiddle(head);
  Node *left = head;
  Node *right = middle->next;
  middle->next = nullptr;

  left = sortList(left);
  right = sortList(right);

  return merge(left, right);
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
  vector<int> values1 = {4, 2, 1, 3};
  Node *head1 = createList(values1);
  cout << "Original list: ";
  printList(head1);
  Node *sorted1 = sortList(head1);
  cout << "Sorted list: ";
  printList(sorted1);

  vector<int> values2 = {-1, 5, 3, 4, 0};
  Node *head2 = createList(values2);
  cout << "Original list: ";
  printList(head2);
  Node *sorted2 = sortList(head2);
  cout << "Sorted list: ";
  printList(sorted2);

  vector<int> values3 = {};
  Node *head3 = createList(values3);
  cout << "Original list: ";
  printList(head3);
  Node *sorted3 = sortList(head3);
  cout << "Sorted list: ";
  printList(sorted3);

  return 0;
}

// Time Complexity: O(n log n)
// Space Complexity: O(1)
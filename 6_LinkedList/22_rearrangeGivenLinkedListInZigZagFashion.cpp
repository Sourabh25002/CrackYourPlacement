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

void rearrangeInZigZag(Node *head)
{
  if (!head)
    return;

  // Start with the '<' relation
  bool flag = true;

  Node *current = head;
  while (current->next)
  {
    if (flag)
    { // '<' relation expected
      if (current->val > current->next->val)
      {
        swap(current->val, current->next->val);
      }
    }
    else
    { // '>' relation expected
      if (current->val < current->next->val)
      {
        swap(current->val, current->next->val);
      }
    }
    flag = !flag; // flip the flag
    current = current->next;
  }
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
  vector<int> values1 = {1, 2, 3, 4};
  Node *head1 = createList(values1);
  cout << "Original list: ";
  printList(head1);
  rearrangeInZigZag(head1);
  cout << "Zig-Zag rearranged list: ";
  printList(head1);

  vector<int> values2 = {11, 15, 20, 5, 10};
  Node *head2 = createList(values2);
  cout << "Original list: ";
  printList(head2);
  rearrangeInZigZag(head2);
  cout << "Zig-Zag rearranged list: ";
  printList(head2);

  return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
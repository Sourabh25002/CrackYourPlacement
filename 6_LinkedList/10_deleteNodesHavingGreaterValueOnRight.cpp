#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct Node
{
  int val;
  Node *next;
  Node(int x) : val(x), next(nullptr) {}
};

// Function to reverse the linked list
Node *reverseList(Node *head)
{
  Node *prev = nullptr;
  Node *current = head;
  Node *next = nullptr;
  while (current != nullptr)
  {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  return prev;
}

// Function to delete nodes having greater value on right
Node *compute(Node *head)
{
  if (!head)
    return nullptr;

  // Reverse the linked list
  head = reverseList(head);

  // Initialize max_node to the head of the reversed list
  Node *max_node = head;
  Node *current = head;

  // Traverse the reversed list
  while (current != nullptr && current->next != nullptr)
  {
    if (current->next->val < max_node->val)
    {
      // Delete the node
      Node *temp = current->next;
      current->next = temp->next;
      delete temp;
    }
    else
    {
      // Update max_node and move to next
      current = current->next;
      max_node = current;
    }
  }

  // Reverse the list again to restore original order
  head = reverseList(head);

  return head;
}

// Function to print the linked list
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
  // Creating a linked list: 12->15->10->11->5->6->2->3
  Node *head = new Node(12);
  head->next = new Node(15);
  head->next->next = new Node(10);
  head->next->next->next = new Node(11);
  head->next->next->next->next = new Node(5);
  head->next->next->next->next->next = new Node(6);
  head->next->next->next->next->next->next = new Node(2);
  head->next->next->next->next->next->next->next = new Node(3);

  head = compute(head);
  printList(head); // Expected output: 15 11 6 3

  return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(1)
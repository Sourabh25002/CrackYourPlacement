#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct Node
{
  int val;
  Node *next;
  Node(int x) : val(x), next(nullptr) {}
};

// Iterative function to reverse the linked list.
Node *reverseList(Node *head)
{
  Node *prev = nullptr; // Initialize previous pointer to nullptr.
  Node *curr = head;    // Initialize current pointer to the head of the list.

  while (curr != nullptr)
  {
    Node *next = curr->next; // Store the next node.
    curr->next = prev;       // Reverse the current node's pointer.
    prev = curr;             // Move prev and curr one step forward.
    curr = next;
  }

  // At the end of the list, prev will be the new head of the reversed list.
  return prev;
}

// Function to print the linked list.
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
  // Creating a linked list: 1->2->3->4->5
  Node *head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  head->next->next->next->next = new Node(5);

  cout << "Original list: ";
  printList(head);

  // Reverse the linked list.
  Node *reversedHead = reverseList(head);

  cout << "Reversed list: ";
  printList(reversedHead);

  return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(1)
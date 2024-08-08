#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct Node
{
  int val;
  Node *next;
  Node(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
  void reorderList(Node *head)
  {
    if (!head || !head->next || !head->next->next)
      return;

    // Step 1: Find the middle of the list
    Node *slow = head;
    Node *fast = head;
    while (fast->next && fast->next->next)
    {
      slow = slow->next;
      fast = fast->next->next;
    }

    // Step 2: Reverse the second half of the list
    Node *prev = nullptr;
    Node *curr = slow->next;
    while (curr)
    {
      Node *nextTemp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = nextTemp;
    }
    slow->next = nullptr; // Split the list into two halves

    // Step 3: Merge the two halves
    Node *first = head;
    Node *second = prev;
    while (second)
    {
      Node *temp1 = first->next;
      Node *temp2 = second->next;
      first->next = second;
      second->next = temp1;
      first = temp1;
      second = temp2;
    }
  }
};

void printList(Node *head)
{
  while (head)
  {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}

int main()
{
  // Example usage
  Solution sol;

  // Create a sample linked list: 1 -> 2 -> 3 -> 4
  Node *head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);

  // Reorder the list
  sol.reorderList(head);

  // Print the result
  printList(head);

  // Clean up allocated memory
  while (head)
  {
    Node *temp = head;
    head = head->next;
    delete temp;
  }

  return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(1)
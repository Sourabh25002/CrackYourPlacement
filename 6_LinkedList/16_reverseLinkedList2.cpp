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
  Node *reverseBetween(Node *head, int left, int right)
  {
    if (!head || left == right)
      return head;

    // Create a dummy node to handle edge cases where reversal includes the head
    Node *dummy = new Node(0);
    dummy->next = head;
    Node *prev = dummy;

    // Move prev to the node just before the left position
    for (int i = 1; i < left; ++i)
    {
      prev = prev->next;
    }

    // Start reversing the segment
    Node *curr = prev->next;
    Node *next = curr->next;

    for (int i = 0; i < right - left; ++i)
    {
      curr->next = next->next;
      next->next = prev->next;
      prev->next = next;
      next = curr->next;
    }

    // Return the new head
    head = dummy->next;
    delete dummy;
    return head;
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
  // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
  Node *head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  head->next->next->next->next = new Node(5);

  Solution sol;
  int left = 2, right = 4;
  head = sol.reverseBetween(head, left, right);

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
#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct Node
{
  int data;
  Node *next;
  Node(int x) : data(x), next(nullptr) {}
};

class Solution
{
public:
  // Function to get the length of the linked list
  int length(Node *n)
  {
    int ret = 0;
    while (n)
    {
      ret++;
      n = n->next;
    }
    return ret;
  }

  // Function to reverse a linked list
  Node *reverse(Node *head)
  {
    Node *prev = NULL;
    Node *current = head;
    Node *next;
    while (current != NULL)
    {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }
    return prev;
  }

  // Function to subtract one linked list from another
  Node *subLinkedList(Node *head1, Node *head2)
  {
    // Remove leading zeros from both linked lists
    while (head1 && head1->data == 0)
      head1 = head1->next;
    while (head2 && head2->data == 0)
      head2 = head2->next;

    // If both lists are empty after removing zeros, return a new node with data 0
    if (!head1 && !head2)
    {
      return new Node(0);
    }

    // Get the lengths of both linked lists
    int n1 = length(head1);
    int n2 = length(head2);

    // Swap head1 and head2 if head2 represents a larger number
    if (n2 > n1)
      swap(head1, head2);

    // If both lists have the same length, determine which list represents the larger number
    if (n1 == n2)
    {
      Node *t1 = head1, *t2 = head2;
      while (t1->data == t2->data)
      {
        t1 = t1->next;
        t2 = t2->next;
        if (!t1)
          return new Node(0);
      }
      if (t2->data > t1->data)
        swap(head1, head2);
    }

    // Reverse both linked lists
    head1 = reverse(head1);
    head2 = reverse(head2);

    Node *res = NULL, *last = NULL;
    Node *t1 = head1, *t2 = head2;

    // Subtract the numbers represented by the linked lists
    while (t1)
    {
      int small = 0;
      if (t2)
        small = t2->data;

      if (t1->data < small)
      {
        t1->next->data = t1->next->data - 1;
        t1->data = t1->data + 10;
      }

      Node *n = new Node(t1->data - small);
      if (res == NULL)
      {
        res = n;
        last = n;
      }
      else
      {
        last->next = n;
        last = last->next;
      }

      t1 = t1->next;
      if (t2)
        t2 = t2->next;
    }

    // Reverse the result list to get the final answer
    res = reverse(res);

    // Remove any leading zeros in the result list
    while (res && res->data == 0)
    {
      res = res->next;
    }

    return res;
  }
};

int main()
{
  // Example usage
  Node *L1 = new Node(1);
  L1->next = new Node(0);
  L1->next->next = new Node(0);

  Node *L2 = new Node(1);
  L2->next = new Node(2);

  Solution sol;
  Node *result = sol.subLinkedList(L1, L2);

  // Print the resulting linked list
  while (result != NULL)
  {
    cout << result->data;
    result = result->next;
  }
  cout << endl;

  return 0;
}

/*
Time Complexity: O(n + m)
- The function traverses the linked lists multiple times (for reversing, length calculation, and subtraction).
- n is the length of the first linked list and m is the length of the second linked list.

Space Complexity: O(n + m)
- Space is used for creating the result linked list and recursion stack (due to the use of the reverse function).
*/

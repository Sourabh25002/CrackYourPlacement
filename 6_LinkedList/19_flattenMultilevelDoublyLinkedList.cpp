#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
struct Node
{
  int val;
  Node *prev;
  Node *next;
  Node *child;
  Node(int x) : val(x), prev(NULL), next(NULL), child(NULL) {}
};

class Solution
{
public:
  Node *flatten(Node *head)
  {
    if (!head)
      return nullptr;

    Node *curr = head;
    while (curr)
    {
      if (curr->child)
      {
        Node *child = curr->child;

        // Find the tail of the child list
        Node *childTail = child;
        while (childTail->next)
        {
          childTail = childTail->next;
        }

        // Connect the child list with the next node
        if (curr->next)
        {
          curr->next->prev = childTail;
        }
        childTail->next = curr->next;

        // Connect the current node with the child list
        curr->next = child;
        child->prev = curr;
        curr->child = nullptr; // Remove the child pointer

        // Move to the next node in the main list
        curr = child;
      }
      else
      {
        curr = curr->next;
      }
    }

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
  // Example usage
  Solution sol;

  // Create nodes for the multilevel doubly linked list
  Node *head = new Node(1);
  head->next = new Node(2);
  head->next->prev = head;
  head->next->next = new Node(3);
  head->next->next->prev = head->next;
  head->next->next->next = new Node(4);
  head->next->next->next->prev = head->next->next;
  head->next->next->next->next = new Node(5);
  head->next->next->next->next->prev = head->next->next->next;
  head->next->next->next->next->next = new Node(6);
  head->next->next->next->next->next->prev = head->next->next->next->next;

  // Create child nodes
  head->next->next->next->child = new Node(7);
  head->next->next->next->child->next = new Node(8);
  head->next->next->next->child->next->prev = head->next->next->next->child;
  head->next->next->next->child->next->next = new Node(9);
  head->next->next->next->child->next->next->prev = head->next->next->next->child->next;
  head->next->next->next->child->next->next->next = new Node(10);
  head->next->next->next->child->next->next->next->prev = head->next->next->next->child->next->next;

  // Flatten the list
  head = sol.flatten(head);

  // Print the flattened list
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
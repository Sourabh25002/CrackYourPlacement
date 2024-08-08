#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct Node
{
  int val;
  Node *next;
  Node(int x) : val(x), next(nullptr) {}
};

Node *removeElements(Node *head, int val)
{
  // Create a dummy node to simplify edge cases
  Node *dummy = new Node(0);
  dummy->next = head;
  Node *current = dummy;

  while (current->next != nullptr)
  {
    if (current->next->val == val)
    {
      // Skip the node with the value `val`
      Node *temp = current->next;
      current->next = current->next->next;
      delete temp; // Free the memory
    }
    else
    {
      current = current->next;
    }
  }

  Node *newHead = dummy->next;
  delete dummy; // Free the memory for the dummy node
  return newHead;
}

// Function to print the linked list
void printList(Node *head)
{
  Node *temp = head;
  while (temp != nullptr)
  {
    cout << temp->val << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main()
{
  // Creating a linked list: 1->2->6->3->4->5->6
  Node *head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(6);
  head->next->next->next = new Node(3);
  head->next->next->next->next = new Node(4);
  head->next->next->next->next->next = new Node(5);
  head->next->next->next->next->next->next = new Node(6);

  cout << "Original list: ";
  printList(head);

  int valToRemove = 6;
  head = removeElements(head, valToRemove);

  cout << "List after removing " << valToRemove << ": ";
  printList(head);

  return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1).
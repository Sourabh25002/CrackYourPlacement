#include <bits/stdc++.h>
using namespace std;

// Linkedlist Node structure
struct Node
{
  int data;
  struct Node *next;
};

// Function to create newNode in a linked list
Node *newNode(int key)
{
  Node *temp = new Node;
  temp->data = key;
  temp->next = NULL;
  return temp;
}

// Function to reverse the linked list
void reverselist(Node **head)
{
  Node *prev = NULL, *curr = *head, *next;

  while (curr)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  *head = prev;
}

// Function to print the linked list
void printlist(Node *head)
{
  while (head != NULL)
  {
    cout << head->data << " ";
    if (head->next)
      cout << "-> ";
    head = head->next;
  }
  cout << endl;
}

// Function to rearrange a linked list
void rearrange(Node **head)
{
  Node *slow = *head, *fast = slow->next;
  while (fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;
  }

  Node *head1 = *head;
  Node *head2 = slow->next;
  slow->next = NULL;

  reverselist(&head2);

  *head = newNode(0);
  Node *curr = *head;
  while (head1 || head2)
  {
    if (head1)
    {
      curr->next = head1;
      curr = curr->next;
      head1 = head1->next;
    }
    if (head2)
    {
      curr->next = head2;
      curr = curr->next;
      head2 = head2->next;
    }
  }

  *head = (*head)->next;
}

// Driver program
int main()
{
  Node *head = newNode(1);
  head->next = newNode(2);
  head->next->next = newNode(3);
  head->next->next->next = newNode(4);
  head->next->next->next->next = newNode(5);

  printlist(head);
  rearrange(&head);
  printlist(head);
  return 0;
}

// Time Complexity: O(n) - The list is traversed a constant number of times.
// Space Complexity: O(1) - No extra space is used apart from a few pointers.

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct Node
{
  int val;
  Node *next;
  Node(int x) : val(x), next(NULL) {}
};

Node *deleteDuplicates(Node *head)
{
  if (head == nullptr)
  {
    return head;
  }

  Node *current = head;
  while (current->next != nullptr)
  {
    if (current->val == current->next->val)
    {
      current->next = current->next->next;
    }
    else
    {
      current = current->next;
    }
  }
  return head;
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
  // Creating a sorted linked list: 1->1->2->3->3
  Node *head = new Node(1);
  head->next = new Node(1);
  head->next->next = new Node(2);
  head->next->next->next = new Node(3);
  head->next->next->next->next = new Node(3);

  cout << "Original list: ";
  printList(head);

  head = deleteDuplicates(head);

  cout << "List after removing duplicates: ";
  printList(head);

  return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1).
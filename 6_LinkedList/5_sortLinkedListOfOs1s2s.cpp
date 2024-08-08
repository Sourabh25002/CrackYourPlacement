#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct Node
{
  int val;
  Node *next;
  Node(int x) : val(x), next(NULL) {}
};

void sortList(Node *head)
{
  if (head == nullptr)
    return;

  // Initialize count of 0s, 1s, and 2s
  int count[3] = {0, 0, 0};
  Node *temp = head;

  // Count the number of 0s, 1s, and 2s in the list
  while (temp != nullptr)
  {
    count[temp->val]++;
    temp = temp->next;
  }

  int i = 0;
  temp = head;

  // Update the list with the counted values
  while (temp != nullptr)
  {
    if (count[i] == 0)
    {
      ++i;
    }
    else
    {
      temp->val = i;
      --count[i];
      temp = temp->next;
    }
  }
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
  // Creating a linked list: 1->2->0->1->2->0->1
  Node *head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(0);
  head->next->next->next = new Node(1);
  head->next->next->next->next = new Node(2);
  head->next->next->next->next->next = new Node(0);
  head->next->next->next->next->next->next = new Node(1);

  cout << "Original list: ";
  printList(head);

  sortList(head);

  cout << "Sorted list: ";
  printList(head);

  return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
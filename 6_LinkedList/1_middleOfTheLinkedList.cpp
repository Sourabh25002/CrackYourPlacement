#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *next;

  Node(int val)
  {
    data = val;
    next = NULL;
  }
};

Node *findMiddle(Node *head)
{
  Node *slow = head;
  Node *fast = head;

  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;
}

// Function to print the linked list
void printList(Node *head)
{
  Node *temp = head;
  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main()
{

  Node *head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  head->next->next->next->next = new Node(5);

  cout << "Original List: ";
  printList(head);

  Node *middle = findMiddle(head);
  if (middle != NULL)
  {
    cout << "Middle of the List: " << middle->data << endl;
  }
  else
  {
    cout << "The list is empty." << endl;
  }

  return 0;
}

// Time Complexity: O(N/2)
// Space Complexity: O(1)
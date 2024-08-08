#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct Node
{
  int val;
  Node *next;
  Node(int x) : val(x), next(nullptr) {}
};

Node *mergeTwoLists(Node *list1, Node *list2)
{
  // Create a dummy node to act as the head of the merged list
  Node *dummy = new Node(0);
  Node *current = dummy;

  // Merge the two lists by splicing together the nodes
  while (list1 != nullptr && list2 != nullptr)
  {
    if (list1->val <= list2->val)
    {
      current->next = list1;
      list1 = list1->next;
    }
    else
    {
      current->next = list2;
      list2 = list2->next;
    }
    current = current->next;
  }

  // Attach the remaining nodes of list1 or list2
  if (list1 != nullptr)
  {
    current->next = list1;
  }
  else
  {
    current->next = list2;
  }

  Node *mergedHead = dummy->next;
  delete dummy; // Free the memory of the dummy node
  return mergedHead;
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
  // Creating first linked list: 1->2->4
  Node *list1 = new Node(1);
  list1->next = new Node(2);
  list1->next->next = new Node(4);

  // Creating second linked list: 1->3->4
  Node *list2 = new Node(1);
  list2->next = new Node(3);
  list2->next->next = new Node(4);

  Node *mergedList = mergeTwoLists(list1, list2);

  cout << "Merged list: ";
  printList(mergedList);

  return 0;
}

// Time Complexity: O(N+M)
// Space Complexity: O(1)
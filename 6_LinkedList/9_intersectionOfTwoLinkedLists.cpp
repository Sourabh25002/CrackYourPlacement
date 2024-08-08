#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct Node
{
  int val;
  Node *next;
  Node(int x) : val(x), next(nullptr) {}
};

int getLength(Node *head)
{
  int length = 0;
  while (head)
  {
    head = head->next;
    length++;
  }
  return length;
}

Node *getIntersectionNode(Node *headA, Node *headB)
{
  if (!headA || !headB)
  {
    return nullptr; // If either list is empty, there's no intersection.
  }

  // Find the lengths of both lists.
  int lenA = getLength(headA);
  int lenB = getLength(headB);

  // Move the head of the longer list to make both lists the same length.
  while (lenA > lenB)
  {
    headA = headA->next;
    lenA--;
  }
  while (lenB > lenA)
  {
    headB = headB->next;
    lenB--;
  }

  // Move both pointers until they meet at the intersection point (or reach the end).
  while (headA != headB)
  {
    headA = headA->next;
    headB = headB->next;
  }

  return headA; // Return the intersection point (or null if there's no intersection).
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
  // Creating first linked list: 4->1->8->4->5
  Node *headA = new Node(4);
  headA->next = new Node(1);
  headA->next->next = new Node(8);
  headA->next->next->next = new Node(4);
  headA->next->next->next->next = new Node(5);

  // Creating second linked list: 5->6->1->8->4->5
  Node *headB = new Node(5);
  headB->next = new Node(6);
  headB->next->next = new Node(1);
  headB->next->next->next = headA->next->next; // Intersection at node with value 8

  Node *intersection = getIntersectionNode(headA, headB);
  if (intersection)
  {
    cout << "Intersection at node with value: " << intersection->val << endl;
  }
  else
  {
    cout << "No intersection." << endl;
  }

  return 0;
}

// Time Complexity: O(n + m)
// Space Complexity: O(1)
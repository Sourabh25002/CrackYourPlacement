#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

// Definition for singly-linked list.
struct Node
{
  int val;
  Node *next;
  Node(int x) : val(x), next(nullptr) {}
};

// Function to convert a linked list to an integer
long long listToNumber(Node *head)
{
  long long num = 0;
  while (head != nullptr)
  {
    num = (num * 10 + head->val) % MOD;
    head = head->next;
  }
  return num;
}

// Function to multiply two linked lists
long long multiplyTwoLists(Node *l1, Node *l2)
{
  long long num1 = listToNumber(l1);
  long long num2 = listToNumber(l2);
  return (num1 * num2) % MOD;
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
  // Creating first linked list: 1->0->0
  Node *list1 = new Node(1);
  list1->next = new Node(0);
  list1->next->next = new Node(0);

  // Creating second linked list: 1->0
  Node *list2 = new Node(1);
  list2->next = new Node(0);

  long long result = multiplyTwoLists(list1, list2);
  cout << "Result: " << result << endl;

  return 0;
}

// Time Complexity: O(N+M)
// Space Complexity: O(1)
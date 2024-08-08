#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct Node
{
  int val;
  Node *next;
  Node(int x) : val(x), next(NULL) {}
};

int getDecimalValue(Node *head)
{
  Node *temp = head;
  int size = 0;
  while (temp != nullptr)
  {
    size++;
    temp = temp->next;
  }

  int i = size - 1;
  temp = head;
  int ans = 0;
  while (temp != nullptr)
  {
    if (temp->val == 1)
    {
      ans += pow(2, i);
    }
    i--;
    temp = temp->next;
  }
  return ans;
}

// Function to print the result
void printResult(int value)
{
  cout << "The decimal value of the binary linked list is: " << value << endl;
}

int main()
{
  // Creating a linked list: 1->0->1
  Node *head = new Node(1);
  head->next = new Node(0);
  head->next->next = new Node(1);

  int result = getDecimalValue(head);

  printResult(result);

  return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1).
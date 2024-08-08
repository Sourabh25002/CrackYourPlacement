#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct Node
{
  int val;
  Node *next;
  Node(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
  bool isPalindrome(Node *head)
  {
    if (!head || !head->next)
    {
      return true; // An empty list or a single-node list is considered a palindrome.
    }

    Node *slow = head;
    Node *fast = head;

    // Use a slow and fast pointer to find the middle of the list.
    while (fast->next && fast->next->next)
    {
      slow = slow->next;
      fast = fast->next->next;
    }

    // Reverse the second half of the list.
    Node *secondHalf = reverseList(slow->next);

    // Compare the first half with the reversed second half.
    Node *firstHalf = head;
    while (secondHalf)
    {
      if (firstHalf->val != secondHalf->val)
      {
        return false;
      }
      firstHalf = firstHalf->next;
      secondHalf = secondHalf->next;
    }

    return true;
  }

private:
  // Function to reverse a linked list.
  Node *reverseList(Node *head)
  {
    Node *prev = nullptr;
    Node *curr = head;

    while (curr)
    {
      Node *next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    return prev;
  }
};

// Function to print the linked list
void printList(Node *head)
{
  while (head != nullptr)
  {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}

int main()
{
  // Creating a linked list: 1->2->2->1
  Node *head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(2);
  head->next->next->next = new Node(1);

  Solution solution;
  bool result = solution.isPalindrome(head);

  if (result)
  {
    cout << "The linked list is a palindrome." << endl;
  }
  else
  {
    cout << "The linked list is not a palindrome." << endl;
  }

  return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(1)
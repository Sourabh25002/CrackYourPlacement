#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    ListNode *dummy = new ListNode(0); // Create a dummy node to handle edge cases.
    dummy->next = head;
    ListNode *first = dummy;
    ListNode *second = dummy;

    // Move the first pointer n+1 steps ahead.
    for (int i = 0; i <= n; i++)
    {
      first = first->next;
    }

    // Move both pointers simultaneously until the first pointer reaches the end.
    while (first != nullptr)
    {
      first = first->next;
      second = second->next;
    }

    // Remove the nth node from the end.
    second->next = second->next->next;

    return dummy->next;
  }
};

void printList(ListNode *head)
{
  while (head)
  {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}

int main()
{
  // Example usage
  Solution sol;

  // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  int n = 2; // Remove the 2nd node from the end

  // Remove the nth node from the end
  head = sol.removeNthFromEnd(head, n);

  // Print the result
  printList(head);

  // Clean up allocated memory
  while (head)
  {
    ListNode *temp = head;
    head = head->next;
    delete temp;
  }

  return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(1)
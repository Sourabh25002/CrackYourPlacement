#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  // Function to reverse the first k nodes of the list
  ListNode *reverse(ListNode *head, int k)
  {
    if (head == NULL)
      return NULL;

    ListNode *next = NULL;
    ListNode *curr = head;
    ListNode *prev = NULL;
    int cnt = 0;

    // Reverse k nodes
    while (curr != NULL && cnt < k)
    {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
      cnt++;
    }

    // Recursively call for the remaining list
    if (next != NULL)
    {
      head->next = reverse(next, k);
    }

    // Return the new head after reversal
    return prev;
  }

  // Function to reverse nodes in k-group
  ListNode *reverseKGroup(ListNode *head, int k)
  {
    return reverse(head, k);
  }
};

int main()
{
  // Example usage
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  int k = 2; // Number of nodes in each group to reverse

  Solution sol;
  ListNode *modifiedHead = sol.reverseKGroup(head, k);

  // Printing the modified linked list
  while (modifiedHead != nullptr)
  {
    cout << modifiedHead->val << " ";
    modifiedHead = modifiedHead->next;
  }
  cout << endl;

  return 0;
}

/*
Time Complexity: O(n)
- The list is traversed and reversed in groups of k nodes, where n is the total number of nodes in the linked list.
- Each node is visited exactly once, making the time complexity O(n).

Space Complexity: O(n/k)
- The recursion stack will hold at most n/k frames, where n is the total number of nodes and k is the group size.
- Thus, the space complexity is O(n/k) due to recursion.
*/

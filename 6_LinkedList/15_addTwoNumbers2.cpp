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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    stack<int> s1, s2;

    // Push all elements of the first list into stack s1
    while (l1)
    {
      s1.push(l1->val);
      l1 = l1->next;
    }

    // Push all elements of the second list into stack s2
    while (l2)
    {
      s2.push(l2->val);
      l2 = l2->next;
    }

    ListNode *head = nullptr;
    int carry = 0;

    // Add numbers from both stacks
    while (!s1.empty() || !s2.empty() || carry)
    {
      int sum = carry;
      if (!s1.empty())
      {
        sum += s1.top();
        s1.pop();
      }
      if (!s2.empty())
      {
        sum += s2.top();
        s2.pop();
      }

      carry = sum / 10;
      sum = sum % 10;

      ListNode *newNode = new ListNode(sum);
      newNode->next = head;
      head = newNode;
    }

    return head;
  }
};

int main()
{
  // Example usage
  Solution sol;

  // Create first linked list: 7 -> 2 -> 4 -> 3
  ListNode *l1 = new ListNode(7);
  l1->next = new ListNode(2);
  l1->next->next = new ListNode(4);
  l1->next->next->next = new ListNode(3);

  // Create second linked list: 5 -> 6 -> 4
  ListNode *l2 = new ListNode(5);
  l2->next = new ListNode(6);
  l2->next->next = new ListNode(4);

  // Add the two numbers
  ListNode *result = sol.addTwoNumbers(l1, l2);

  // Print the result
  while (result)
  {
    cout << result->val << " ";
    result = result->next;
  }
  cout << endl;

  // Clean up allocated memory
  while (l1)
  {
    ListNode *temp = l1;
    l1 = l1->next;
    delete temp;
  }

  while (l2)
  {
    ListNode *temp = l2;
    l2 = l2->next;
    delete temp;
  }

  while (result)
  {
    ListNode *temp = result;
    result = result->next;
    delete temp;
  }

  return 0;
}

// Time Complexity: O(N + M)
// Space Complexity: O(N + M)
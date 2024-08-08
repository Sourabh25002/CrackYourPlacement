#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

// Function to add two numbers represented by linked lists.
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
  ListNode *dummyHead = new ListNode(0); // Dummy node to simplify edge cases
  ListNode *current = dummyHead;         // Pointer to build the result list
  int carry = 0;                         // Initialize carry to 0

  while (l1 || l2 || carry)
  {
    int sum = carry; // Start with carry from the previous digit

    // Add value from l1 if available
    if (l1)
    {
      sum += l1->val;
      l1 = l1->next;
    }

    // Add value from l2 if available
    if (l2)
    {
      sum += l2->val;
      l2 = l2->next;
    }

    // Update carry for next iteration
    carry = sum / 10;

    // Create new node with the digit value
    current->next = new ListNode(sum % 10);
    current = current->next;
  }

  return dummyHead->next; // Return the head of the new list
}

// Function to print the linked list.
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
  // Create two linked lists: 342 (3->4->2) and 465 (5->6->4)
  ListNode *l1 = new ListNode(2);
  l1->next = new ListNode(4);
  l1->next->next = new ListNode(3);

  ListNode *l2 = new ListNode(5);
  l2->next = new ListNode(6);
  l2->next->next = new ListNode(4);

  // Add the two numbers
  ListNode *result = addTwoNumbers(l1, l2);

  // Print the result list (should print 7->0->8)
  cout << "Result: ";
  printList(result);

  return 0;
}

// Time Complexity: O(max(N, M))
// Space Complexity: O(max(N, M))

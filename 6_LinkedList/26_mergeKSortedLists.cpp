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
  ListNode *mergeKLists(vector<ListNode *> &lists)
  {
    if (lists.empty())
    {
      return nullptr;
    }
    return mergeKListsHelper(lists, 0, lists.size() - 1);
  }

private:
  ListNode *mergeKListsHelper(vector<ListNode *> &lists, int start, int end)
  {
    if (start == end)
    {
      return lists[start];
    }
    if (start + 1 == end)
    {
      return merge(lists[start], lists[end]);
    }
    int mid = start + (end - start) / 2;
    ListNode *left = mergeKListsHelper(lists, start, mid);
    ListNode *right = mergeKListsHelper(lists, mid + 1, end);
    return merge(left, right);
  }

  ListNode *merge(ListNode *l1, ListNode *l2)
  {
    ListNode *dummy = new ListNode(0);
    ListNode *curr = dummy;

    while (l1 && l2)
    {
      if (l1->val < l2->val)
      {
        curr->next = l1;
        l1 = l1->next;
      }
      else
      {
        curr->next = l2;
        l2 = l2->next;
      }
      curr = curr->next;
    }

    curr->next = l1 ? l1 : l2;

    ListNode *result = dummy->next;
    delete dummy; // Free the memory of the dummy node
    return result;
  }
};

int main()
{
  // Example usage:
  vector<ListNode *> lists;

  // Creating the first linked list: 1->4->5
  ListNode *list1 = new ListNode(1);
  list1->next = new ListNode(4);
  list1->next->next = new ListNode(5);
  lists.push_back(list1);

  // Creating the second linked list: 1->3->4
  ListNode *list2 = new ListNode(1);
  list2->next = new ListNode(3);
  list2->next->next = new ListNode(4);
  lists.push_back(list2);

  // Creating the third linked list: 2->6
  ListNode *list3 = new ListNode(2);
  list3->next = new ListNode(6);
  lists.push_back(list3);

  Solution sol;
  ListNode *mergedList = sol.mergeKLists(lists);

  // Printing the merged linked list
  while (mergedList != nullptr)
  {
    cout << mergedList->val << " ";
    mergedList = mergedList->next;
  }
  cout << endl;

  return 0;
}

/*
Time Complexity: O(N log k)
- N is the total number of nodes across all k lists.
- Each merge operation (merging two lists) takes O(N) time.
- There are log k levels of merge operations.

Space Complexity: O(log k)
- The space complexity is O(log k) due to the recursive stack used during the merge process.
- No extra space is used apart from the recursion stack.
*/

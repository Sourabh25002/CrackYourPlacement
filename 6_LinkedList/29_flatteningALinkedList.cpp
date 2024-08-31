#include <bits/stdc++.h>
using namespace std;

// Node structure used in the program
struct Node
{
  int data;
  struct Node *next;
  struct Node *bottom;

  Node(int x)
  {
    data = x;
    next = NULL;
    bottom = NULL;
  }
};

class Solution
{
public:
  // Function which returns the root of the flattened linked list.

  Node *merge(Node *l1, Node *l2)
  {
    // This function merges two sorted linked lists
    if (!l1)
      return l2; // If l1 is NULL, return l2
    if (!l2)
      return l1; // If l2 is NULL, return l1

    Node *result = NULL;

    // Choose either l1 or l2, and recursively merge the rest
    if (l1->data < l2->data)
    {
      result = l1;
      result->bottom = merge(l1->bottom, l2);
    }
    else
    {
      result = l2;
      result->bottom = merge(l1, l2->bottom);
    }

    return result;
  }

  // Function to flatten the linked list
  Node *flatten(Node *root)
  {
    // Base case: if the list is empty or there is only one sub-list
    if (!root || !root->next)
      return root;

    // Recur for list on right and merge it with root
    root->next = flatten(root->next);

    // Merge this list with the next list
    root = merge(root, root->next);

    // Return the root
    return root;
  }
};

// Helper function to print the flattened linked list
void printList(Node *root)
{
  while (root != NULL)
  {
    cout << root->data << " ";
    root = root->bottom;
  }
  cout << endl;
}

int main()
{
  // Example usage
  Node *root = new Node(5);
  root->bottom = new Node(7);
  root->bottom->bottom = new Node(8);
  root->bottom->bottom->bottom = new Node(30);

  root->next = new Node(10);
  root->next->bottom = new Node(20);

  root->next->next = new Node(19);
  root->next->next->bottom = new Node(22);
  root->next->next->bottom->bottom = new Node(50);

  root->next->next->next = new Node(28);
  root->next->next->next->bottom = new Node(35);
  root->next->next->next->bottom->bottom = new Node(40);
  root->next->next->next->bottom->bottom->bottom = new Node(45);

  Solution sol;
  Node *flattenedList = sol.flatten(root);

  cout << "Flattened Linked List: ";
  printList(flattenedList);

  return 0;
}

/* Time Complexity:
   - The time complexity of the flatten function is O(N * M), where N is the total number of nodes and M is the average number of nodes in the bottom linked lists. This is because for each node, we are merging two lists.
   - The merge function, which is the core of the operation, works in O(N) time for each merge.
   Overall: O(N * M), where N is the total number of nodes across all sub-lists.

   Space Complexity:
   - The space complexity is O(1) for the iterative parts, but O(N) in the worst case due to recursion stack space.
*/

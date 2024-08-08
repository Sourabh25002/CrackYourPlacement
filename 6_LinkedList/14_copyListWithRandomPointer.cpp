#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node
{
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val)
  {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution
{
public:
  Node *copyRandomList(Node *head)
  {
    if (!head)
      return nullptr;

    // Step 1: Create a mapping of original nodes to their corresponding copied nodes.
    unordered_map<Node *, Node *> nodeMap;
    Node *current = head;
    while (current)
    {
      nodeMap[current] = new Node(current->val);
      current = current->next;
    }

    // Step 2: Link the copied nodes to form the new list.
    current = head;
    while (current)
    {
      Node *copyNode = nodeMap[current];
      copyNode->next = nodeMap[current->next];
      copyNode->random = nodeMap[current->random];
      current = current->next;
    }

    // Step 3: Return the head of the copied list.
    return nodeMap[head];
  }
};

int main()
{
  // Example usage
  // Creating the linked list [[7,null],[13,0],[11,4],[10,2],[1,0]]
  Node *head = new Node(7);
  head->next = new Node(13);
  head->next->next = new Node(11);
  head->next->next->next = new Node(10);
  head->next->next->next->next = new Node(1);

  head->next->random = head;
  head->next->next->next->random = head->next->next;
  head->next->next->next->next->random = head;

  Solution sol;
  Node *copiedList = sol.copyRandomList(head);

  // Print the copied list to verify
  Node *current = copiedList;
  while (current)
  {
    int randomVal = current->random ? current->random->val : -1;
    printf("[%d, %d] -> ", current->val, randomVal);
    current = current->next;
  }
  printf("null\n");

  // Cleanup memory
  current = head;
  while (current)
  {
    Node *next = current->next;
    delete current;
    current = next;
  }
  current = copiedList;
  while (current)
  {
    Node *next = current->next;
    delete current;
    current = next;
  }

  return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(N)
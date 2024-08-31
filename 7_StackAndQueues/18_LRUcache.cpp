#include <bits/stdc++.h>
using namespace std;

// Definition for doubly-linked list node
struct ListNode
{
  int key;
  int value;
  ListNode *prev;
  ListNode *next;
  ListNode(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache
{
private:
  unordered_map<int, ListNode *> cache; // HashMap to store key-node pairs
  ListNode *head;                       // Dummy head of the doubly linked list
  ListNode *tail;                       // Dummy tail of the doubly linked list
  int capacity;                         // Maximum capacity of the cache
  int size;                             // Current size of the cache

  // Add a node right after the head
  void addNode(ListNode *node)
  {
    node->next = head->next;
    node->prev = head;
    head->next->prev = node;
    head->next = node;
  }

  // Remove a node from the doubly linked list
  void removeNode(ListNode *node)
  {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

  // Move a node to the front (right after the head)
  void moveToHead(ListNode *node)
  {
    removeNode(node);
    addNode(node);
  }

  // Pop the last node (right before the tail) from the doubly linked list
  ListNode *popTail()
  {
    ListNode *res = tail->prev;
    removeNode(res);
    return res;
  }

public:
  LRUCache(int capacity) : capacity(capacity), size(0)
  {
    head = new ListNode(0, 0); // Dummy head
    tail = new ListNode(0, 0); // Dummy tail
    head->next = tail;
    tail->prev = head;
  }

  int get(int key)
  {
    if (cache.find(key) == cache.end())
    {
      return -1; // Key not found
    }
    ListNode *node = cache[key];
    moveToHead(node);
    return node->value;
  }

  void put(int key, int value)
  {
    if (cache.find(key) != cache.end())
    {
      ListNode *node = cache[key];
      node->value = value;
      moveToHead(node);
    }
    else
    {
      ListNode *newNode = new ListNode(key, value);
      cache[key] = newNode;
      addNode(newNode);
      size++;
      if (size > capacity)
      {
        ListNode *tail = popTail();
        cache.erase(tail->key);
        delete tail;
        size--;
      }
    }
  }

  ~LRUCache()
  {
    ListNode *curr = head;
    while (curr)
    {
      ListNode *next = curr->next;
      delete curr;
      curr = next;
    }
  }
};

int main()
{
  // Example usage
  LRUCache *lRUCache = new LRUCache(2);
  lRUCache->put(1, 1);              // cache is {1=1}
  lRUCache->put(2, 2);              // cache is {1=1, 2=2}
  cout << lRUCache->get(1) << endl; // return 1
  lRUCache->put(3, 3);              // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
  cout << lRUCache->get(2) << endl; // returns -1 (not found)
  lRUCache->put(4, 4);              // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
  cout << lRUCache->get(1) << endl; // return -1 (not found)
  cout << lRUCache->get(3) << endl; // return 3
  cout << lRUCache->get(4) << endl; // return 4

  // Cleanup
  delete lRUCache;

  return 0;
}

/*
Time Complexity: O(1) for both get and put operations, as the operations involve constant-time hash map lookups and doubly linked list manipulations.

Space Complexity: O(capacity) due to the hash map and doubly linked list nodes.
*/

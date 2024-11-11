/* 146. LRU Cache

Design a data structure that follows the constraints of a Least Recently Used
(LRU) cache. Implement the LRUCache class: LRUCache(int capacity) Initialize the
LRU cache with positive size capacity. int get(int key) Return the value of the
key if the key exists, otherwise return -1. void put(int key, int value) Update
the value of the key if the key exists. Otherwise, add the key-value pair to the
cache. If the number of keys exceeds the capacity from this operation, evict the
least recently used key. The functions get and put must each run in O(1) average
time complexity.



Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4


Constraints:

1 <= capacity <= 3000
0 <= key <= 104
0 <= value <= 105
At most 2 * 105 calls will be made to get and put.*/

/* Fast access to elements by key: The get and put operations must both run in
constant time on average, i.e.,  O(1). This can be achieved using a hash map
(dictionary) to store key-value pairs.

Tracking order of use: We need to track the order in which elements are accessed
to know which element is the least recently used. A doubly linked list is ideal
for this because it allows efficient insertion, removal, and moving of elements
to the front (most recently used) or back (least recently used) in constant
time.*/

// Key Operations:
/* get(key): Retrieve the value of the key if it exists, and mark the key as
most recently used. put(key, value): Insert or update the key-value pair, and
mark the key as most recently used. If the cache exceeds its capacity, evict the
least recently used key.*/

// Data Structure Design:
/*Hash Map (Dictionary): The hash map stores key-value pairs where the key maps
to the corresponding node in the doubly linked list. This allows  O(1) access to
values based on the key.

Doubly Linked List: This is used to maintain the order of elements based on
their usage. When an element is accessed or inserted, it becomes the most
recently used and is moved to the front of the list. When the cache exceeds its
capacity, the element at the tail of the list (least recently used) is
removed.*/

// Algorithm:
/*Initialization: Create a hash map to store key-node pairs and initialize the
doubly linked list. get(key): Check if the key exists in the hash map: If it
exists, move the corresponding node to the front of the linked list and return
its value. If it does not exist, return -1. put(key, value): If the key already
exists, update its value and move the corresponding node to the front of the
list. If the key does not exist, insert a new node at the front of the list. If
the cache exceeds its capacity, remove the node at the tail (least recently
used) and remove its corresponding entry from the hash map.*/

/*
class LRUCache {
public:
    LRUCache(int capacity) {

    }

    int get(int key) {

    }

    void put(int key, int value) {

    }
};*/

#include <list>
#include <unordered_map>

class LRUCache {
public:
  LRUCache(int capacity) { this->capacity = capacity; }

  int get(int key) {
    // Check if key exists in the cache
    if (cacheMap.find(key) != cacheMap.end()) {
      // Move the accessed item to the front (most recently used)
      cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
      return cacheMap[key]->second;
    }
    return -1;
  }

  void put(int key, int value) {
    // Check if key already exists
    if (cacheMap.find(key) != cacheMap.end()) {
      // Key exists, move it to the front and update its value
      cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
      cacheMap[key]->second = value;
    } else {
      // If the cache is at capacity, remove the least recently used item
      if (cacheList.size() == capacity) {
        // Remove the least recently used item from the list and map
        cacheMap.erase(cacheList.back().first);
        cacheList.pop_back();
      }
      // Insert the new key-value pair at the front (most recently used)
      cacheList.emplace_front(key, value);
      cacheMap[key] = cacheList.begin();
    }
  }

private:
  int capacity;
  std::list<std::pair<int, int>>
      cacheList; // Doubly linked list of key-value pairs
  std::unordered_map<int, std::list<std::pair<int, int>>::iterator>
      cacheMap; // Map key to list iterator
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// Explanation:
/* cacheList (doubly linked list): This stores the key-value pairs in order from
most recently used (front) to least recently used (back). When a key is
accessed, it is moved to the front of the list. If the cache exceeds its
capacity, the least recently used item (at the back) is removed.

cacheMap (hash map): This stores mappings from keys to their corresponding
iterator positions in the doubly linked list. This allows  O(1) access to the
list elements by key.

Operations:

get(int key): If the key exists, we move the corresponding element to the front
of the list (most recently used) using splice and return its value. If the key
does not exist, we return -1. put(int key, int value): If the key already
exists, we update its value and move it to the front. If the key does not exist
and the cache has reached its capacity, we remove the least recently used item
(the item at the back of the list). We then insert the new key-value pair at the
front of the list.
*/
/*

Time Complexity:
get(int key):  O(1) average time complexity because both hash map lookup and
linked list operations (insert, erase, splice) take constant time.

put(int key, int value):  O(1) average time complexity as we perform
constant-time operations for insertion and removal in both the hash map and the
doubly linked list.


Optimizations:
C++ STL list::splice(): This is used to move elements within the list in
constant time. It eliminates the need to manually remove and reinsert the node
when moving it to the front. Memory-efficient: Since we use an unordered_map and
list, the memory overhead is minimal compared to maintaining a custom doubly
linked list.*/

using namespace std;

int main() {
  LRUCache lruCache(2);
  lruCache.put(1, 1);                   // cache: {1=1}
  lruCache.put(2, 2);                   // cache: {1=1, 2=2}
  std::cout << lruCache.get(1) << "\n"; // returns 1, cache: {2=2, 1=1}
  lruCache.put(3, 3);                   // evicts key 2, cache: {1=1, 3=3}
  std::cout << lruCache.get(2) << "\n"; // returns -1 (not found)
  lruCache.put(4, 4);                   // evicts key 1, cache: {3=3, 4=4}
  std::cout << lruCache.get(1) << "\n"; // returns -1 (not found)
  std::cout << lruCache.get(3) << "\n"; // returns 3
  std::cout << lruCache.get(4) << "\n"; // returns 4
}
/* # Complexity
- Time complexity:O(1)
   - put-> O(1);get->O(1)
- Space complexity:O(n)*/

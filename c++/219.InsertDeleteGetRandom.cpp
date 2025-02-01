/* https://leetcode.com/problems/insert-delete-getrandom-o1/description/
380. Insert Delete GetRandom O(1)

Implement the RandomizedSet class:

RandomizedSet() Initializes the RandomizedSet object.
bool insert(int val) Inserts an item val into the set if not present. Returns
true if the item was not present, false otherwise. bool remove(int val) Removes
an item val from the set if present. Returns true if the item was present, false
otherwise. int getRandom() Returns a random element from the current set of
elements (it's guaranteed that at least one element exists when this method is
called). Each element must have the same probability of being returned. You must
implement the functions of the class such that each function works in average
O(1) time complexity.



Example 1:
Input
["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert",
"getRandom"]
[[], [1], [2], [2], [], [1], [2], []]
Output
[null, true, false, true, 2, true, false, 2]

Explanation
RandomizedSet randomizedSet = new RandomizedSet();
randomizedSet.insert(1); // Inserts 1 to the set. Returns true as 1 was inserted
successfully. randomizedSet.remove(2); // Returns false as 2 does not exist in
the set. randomizedSet.insert(2); // Inserts 2 to the set, returns true. Set now
contains [1,2]. randomizedSet.getRandom(); // getRandom() should return either 1
or 2 randomly. randomizedSet.remove(1); // Removes 1 from the set, returns true.
Set now contains [2]. randomizedSet.insert(2); // 2 was already in the set, so
return false. randomizedSet.getRandom(); // Since 2 is the only number in the
set, getRandom() will always return 2.


Constraints:
-231 <= val <= 231 - 1
At most 2 * 105 calls will be made to insert, remove, and getRandom.
There will be at least one element in the data structure when getRandom is
called.
*/

/*
class RandomizedSet {
public:
  RandomizedSet() { new RandomizedSet(); }

  bool insert(int val) {
    if (val not in set) {
      set.add(val);
      return true;
    } else {
      return false;
    }
  }

  bool remove(int val) {
    if (val in set) {
      set.remove(val);
      return true;
    } else {
      return false;
    }
  }

  int getRandom() { return set.getRandom(); }
};
*/

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unordered_map>
#include <vector>

class RandomizedSet {
private:
  std::unordered_map<int, int>
      valToIndex;          // Maps value to its index in the vector
  std::vector<int> values; // Stores the actual values

public:
  RandomizedSet() {
    std::srand(std::time(0)); // Seed for random number generation
  }

  bool insert(int val) {
    if (valToIndex.find(val) != valToIndex.end()) {
      return false; // Value already exists
    }
    values.push_back(val);
    valToIndex[val] = values.size() - 1; // Store the index of the value
    return true;
  }

  bool remove(int val) {
    auto it = valToIndex.find(val);
    if (it == valToIndex.end()) {
      return false; // Value doesn't exist
    }

    int index = it->second;
    int lastVal = values.back();

    // Swap the value to remove with the last element
    values[index] = lastVal;
    valToIndex[lastVal] = index;

    // Remove the last element
    values.pop_back();
    valToIndex.erase(it);

    return true;
  }

  int getRandom() {
    int randomIndex = std::rand() % values.size();
    return values[randomIndex];
  }
};

// Your RandomizedSet object will be instantiated and called as such:
int main() {
  RandomizedSet* obj = new RandomizedSet();
  std::cout << "null" << std::endl;                           // Constructor
  std::cout << std::boolalpha << obj->insert(1) << std::endl; // true
  std::cout << obj->remove(2) << std::endl;                   // false
  std::cout << obj->insert(2) << std::endl;                   // true
  std::cout << obj->getRandom() << std::endl;                 // 1 or 2
  std::cout << obj->remove(1) << std::endl;                   // true
  std::cout << obj->insert(2) << std::endl;   // false (2 already inserted)
  std::cout << obj->getRandom() << std::endl; // 2

  delete obj; // Clean up memory
  return 0;
}

// Time: O(1)
// Space: O(n)

// sub:
// https://leetcode.com/problems/insert-delete-getrandom-o1/submissions/1527239471/
// sol:
// https://leetcode.com/problems/insert-delete-getrandom-o1/solutions/6356135/380-insert-delete-getrandom-o1-by-nalind-fzxg/

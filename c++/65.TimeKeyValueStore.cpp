/* 981. Time Based Key-Value Store
Design a time-based key-value data structure that can store multiple values for
the same key at different time stamps and retrieve the key's value at a certain
timestamp. Implement the TimeMap class:
- TimeMap() Initializes the object of the data structure.
- void set(String key, String value, int timestamp) Stores the key key with the
value value at the given time timestamp.
- String get(String key, int timestamp) Returns a value such that set was called
previously, with timestamp_prev <= timestamp. If there are multiple such values,
it returns the value associated with the largest timestamp_prev. If there are no
values, it returns "".


Example 1:
Input
["TimeMap", "set", "get", "get", "set", "get", "get"]
[[], ["foo", "bar", 1], ["foo", 1], ["foo", 3], ["foo", "bar2", 4], ["foo", 4],
["foo", 5]] Output [null, null, "bar", "bar", null, "bar2", "bar2"]

Explanation
TimeMap timeMap = new TimeMap();
timeMap.set("foo", "bar", 1);  // store the key "foo" and value "bar" along with
timestamp = 1. timeMap.get("foo", 1);         // return "bar" timeMap.get("foo",
3);         // return "bar", since there is no value corresponding to foo at
timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar".
timeMap.set("foo", "bar2", 4); // store the key "foo" and value "bar2" along
with timestamp = 4. timeMap.get("foo", 4);         // return "bar2"
timeMap.get("foo", 5);         // return "bar2"


Constraints:

1 <= key.length, value.length <= 100
key and value consist of lowercase English letters and digits.
1 <= timestamp <= 107
All the timestamps timestamp of set are strictly increasing.
At most 2 * 105 calls will be made to set and get.
        */

// Intuition:
/*This problem is essentially about efficiently storing and retrieving values
based on timestamps for a given key. The challenge is to find the latest stored
value at or before a specified timestamp, which suggests using a data structure
that supports both insertion and binary search.

To achieve this, we can store each key's values along with their corresponding
timestamps in a way that allows quick lookup for the most recent timestamp that
is less than or equal to the given one.
*/

// Approach:
/*
Data Structure: A unordered_map (hashmap) to store each key's data as a vector
of pairs, where each pair contains a timestamp and its corresponding value. Set
Operation: Append the timestamp-value pair to the vector associated with the
key.Since the problem guarantees increasing timestamps, appending is efficient.
Get Operation: Use binary search (upper_bound) to find the largest timestamp
less than or equal to the given one.
                                  */

#include <string>
#include <unordered_map>
#include <vector>
class TimeMap {
public:
  // Using an unordered_map to store key -> vector of (timestamp, value) pairs
  std::unordered_map<std::string, std::vector<std::pair<int, std::string>>>
      store;

  TimeMap() {
    // Constructor initializes the map (nothing specific to initialize)
  }

  // Set function to add (timestamp, value) for a key
  void set(std::string key, std::string value, int timestamp) {
    store[key].push_back({timestamp, value});
  }

  // Get function to return the latest value for a key <= timestamp
  std::string get(std::string key, int timestamp) {
    // If key is not found, return empty string
    if (store.find(key) == store.end()) {
      return "";
    }

    // Get the vector of (timestamp, value) pairs for the key
    const auto& values = store[key];

    // Binary search using upper_bound to find the position where timestamp <=
    // given timestamp We compare the first element of the pair (the timestamp)
    auto it = std::upper_bound(
        values.begin(), values.end(), std::make_pair(timestamp, std::string()),
        [](const std::pair<int, std::string>& a,
           const std::pair<int, std::string>& b) { return a.first < b.first; });

    // If it == values.begin(), no timestamp is less than or equal to the given
    // timestamp
    if (it == values.begin()) {
      return "";
    }

    // Otherwise, return the value of the largest timestamp <= given timestamp
    return std::prev(it)->second;
  }
};

/*
Time Complexity:
set Operation: O(1) for appending to the list.
get Operation: O(log N) where N is the number of timestamps stored for a
particular key, due to the binary search. Space Complexity: O(M), where M is the
total number of set operations, as each operation stores a key, value, and
timestamp.

*/

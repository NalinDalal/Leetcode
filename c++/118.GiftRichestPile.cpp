/*POTD: 2558. Take Gifts From the Richest Pile

You are given an integer array gifts denoting the number of gifts in various
piles. Every second, you do the following:

Choose the pile with the maximum number of gifts.
If there is more than one pile with the maximum number of gifts, choose any.
Leave behind the floor of the square root of the number of gifts in the pile.
Take the rest of the gifts. Return the number of gifts remaining after k
seconds.



Example 1:
Input: gifts = [25,64,9,4,100], k = 4
Output: 29
Explanation:
The gifts are taken in the following way:
- In the first second, the last pile is chosen and 10 gifts are left behind.
- Then the second pile is chosen and 8 gifts are left behind.
- After that the first pile is chosen and 5 gifts are left behind.
- Finally, the last pile is chosen again and 3 gifts are left behind.
The final remaining gifts are [5,8,9,4,3], so the total number of gifts
remaining is 29.

Example 2:
Input: gifts = [1,1,1,1], k = 4
Output: 4
Explanation:
In this case, regardless which pile you choose, you have to leave behind 1 gift
in each pile. That is, you can't take any pile with you. So, the total gifts
remaining are 4.


Constraints:
1 <= gifts.length <= 10^3
1 <= gifts[i] <= 10^9
1 <= k <= 10^3
*/

#include <algorithm>
#include <priority_queue>
#include <vector>

using namespace std;

// well what can we do
// just select the pile with max no of gift from array{Used a priority queue
// (priority_queue) instead of manual max element finding}
// then change it with floor of it's own sqrt{use floor(sqrt()) function}
// repeat the process till k seconds, so do it like iterations of k
// return the sum of array{use lon long to avoid integer overflow}

class Solution {
public:
  long long pickGifts(vector<int>& gifts, int k) {
    // Priority queue to efficiently track the maximum gift pile
    priority_queue<int> pq(gifts.begin(), gifts.end());

    while (k--) {
      // Get the pile with the maximum gifts
      int maxGifts = pq.top();
      pq.pop();

      // Replace with floor of square root
      int newGifts = floor(sqrt(maxGifts));

      // Add back to priority queue
      pq.push(newGifts);
    }

    // Calculate total gifts remaining
    long long totalGifts = 0;
    while (!pq.empty()) {
      totalGifts += pq.top();
      pq.pop();
    }

    return totalGifts;
  }
};

// further optimisation(100%):
/* This approach:

Uses standard library heap operations
Modifies the vector in-place
Avoids using additional data structures
Provides similar time complexity O(k log n)

Performance Tips:

The floor(sqrt()) operation is relatively efficient
Early termination reduces unnecessary computations
In-place modifications save memory */
class Solution2 {
public:
  long long pickGifts(vector<int>& gifts, int k) {
    // Make the entire vector a max heap in-place
    make_heap(gifts.begin(), gifts.end());

    for (int i = 0; i < k; i++) {
      // If the top (first) element is 1 or 0, stop
      if (gifts.front() <= 1)
        break;

      // Pop the max element
      pop_heap(gifts.begin(), gifts.end());

      // Transform the last element
      gifts.back() = floor(sqrt(gifts.back()));

      // Restore heap property
      push_heap(gifts.begin(), gifts.end());
    }

    // Sum the total gifts
    return accumulate(gifts.begin(), gifts.end(), 0LL);
  }
};

// Time complexity: $$O(k log n)$$
// Space complexity: $$O(n)$$

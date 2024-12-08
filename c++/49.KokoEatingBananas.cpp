/* 875. Koko Eating Bananas
Koko loves to eat bananas. There are n piles of bananas, the ith pile has
piles[i] bananas. The guards have gone and will come back in h hours. Koko can
decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile
of bananas and eats k bananas from that pile. If the pile has less than k
bananas, she eats all of them instead and will not eat any more bananas during
this hour. Koko likes to eat slowly but still wants to finish eating all the
bananas before the guards return. Return the minimum integer k such that she can
eat all the bananas within h hours.

Example 1:
Input: piles = [3,6,7,11], h = 8
Output: 4

Example 2:
Input: piles = [30,11,23,4,20], h = 5
Output: 30

Example 3:
Input: piles = [30,11,23,4,20], h = 6
Output: 23

Constraints:
1 <= piles.length <= 104
piles.length <= h <= 109
1 <= piles[i] <= 109
*/

// Approach:
/*
n size of piles of banana
h hours
speed=k banana/hr{to find}
pile[i]<k -> eat all
min k such that all banana within h hour
*/

// Complexity:
// Time- O(Nlog(M))
// Space- O(1)

// Run Time Error
/*
class Solution {
public:
  int minEatingSpeed(vector<int> &piles, int h) {
    int left = 1;
    int right = 1000000000;

    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (canEatInTime(piles, mid, h))
        right = mid - 1;
      else
        left = mid + 1;
    }
    return left;
  }
  bool canEatInTime(vector<int> &piles, int k, int h) {
    int hours = 0;
    for (int pile : piles) {
      int div = pile / k;
      hours += div;
      if (pile % k != 0)
        hours++;
    }
    return hours <= h;
  }
};
*/

// use long long instead of int in left, right, hours
// correct code:

#include <vector>
class Solution {
public:
  int minEatingSpeed(vector<int>& piles, int h) {
    long long left = 1;
    long long right = 1000000000; // large number for upper bound

    while (left <= right) {
      long long mid = left + (right - left) / 2;
      if (canEatInTime(piles, mid, h))
        right = mid - 1;
      else
        left = mid + 1;
    }
    return left;
  }

  bool canEatInTime(vector<int>& piles, long long k, int h) {
    long long hours = 0;
    for (int pile : piles) {
      int div = pile / k;
      hours += div;
      if (pile % k != 0)
        hours++;
    }
    return hours <= h;
  }
};

// Algo:
/*
minEatingSpeed:->
initialise low,high, find mid{mid=low+high/2}
binary serach logic-> to return appropriate eatingSpeed

canEatInTime:->
find time by divide piles with k{speed}
add the time{hours} repeatedly for the array
return hours
*/

// Time complexity:O(log n)

// Space complexity:O(n)

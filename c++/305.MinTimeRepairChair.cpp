/* 2594. Minimum Time to Repair Cars
You are given an integer array ranks representing the ranks of some mechanics.
ranksi is the rank of the ith mechanic. A mechanic with a rank r can repair n
cars in r * n2 minutes. You are also given an integer cars representing the
total number of cars waiting in the garage to be repaired. Return the minimum
time taken to repair all the cars. Note: All the mechanics can repair the cars
simultaneously.


Example 1:
Input: ranks = [4,2,3,1], cars = 10
Output: 16
Explanation:
- The first mechanic will repair two cars. The time required is 4 * 2 * 2 = 16
minutes.
- The second mechanic will repair two cars. The time required is 2 * 2 * 2 = 8
minutes.
- The third mechanic will repair two cars. The time required is 3 * 2 * 2 = 12
minutes.
- The fourth mechanic will repair four cars. The time required is 1 * 4 * 4 = 16
minutes. It can be proved that the cars cannot be repaired in less than 16
minutes.​​​​​

Example 2:
Input: ranks = [5,1,8], cars = 6
Output: 16
Explanation:
- The first mechanic will repair one car. The time required is 5 * 1 * 1 = 5
minutes.
- The second mechanic will repair four cars. The time required is 1 * 4 * 4 = 16
minutes.
- The third mechanic will repair one car. The time required is 8 * 1 * 1 = 8
minutes. It can be proved that the cars cannot be repaired in less than 16
minutes.​​​​​


Constraints:
1 <= ranks.length <= 105
1 <= ranks[i] <= 100
1 <= cars <= 106
*/

class Solution {
public:
  long long repairCars(vector<int>& ranks, int cars) {
    // solve using binary search on time
    // min time=1,maxtime=slowest reair time for all cars via slowest
    // mechanic
    // For a given time t, check how many cars can be repaired by all mechanics
    // within t minutes
    long long low = 1,
              high = 1LL * ranks[0] * cars * cars; // Maximum possible time
    long long ans = high;

    while (low <= high) {
      long long mid = low + (high - low) / 2;
      if (canRepairAll(ranks, cars, mid)) {
        ans = mid;      // Update answer with the valid time
        high = mid - 1; // Try a smaller time
      } else {
        low = mid + 1; // Increase time
      }
    }

    return ans;
  }

private:
  bool canRepairAll(vector<int>& ranks, int cars, long long time) {
    long long repaired = 0;

    for (int r : ranks) {
      long long maxCars = sqrt(time / r); // Using the formula n = sqrt(T / r)
      repaired += maxCars;
      if (repaired >= cars)
        return true; // Early stopping
    }

    return repaired >= cars;
  }
};
// Time: O(n)
// Space: O(1)
//  sub:
//  https://leetcode.com/problems/minimum-time-to-repair-cars/submissions/1575414826/?envType=daily-question&envId=2025-03-16
//  sol:
//  https://leetcode.com/problems/minimum-time-to-repair-cars/solutions/6542152/2594-minimum-time-to-repair-cars-by-nali-y13f/

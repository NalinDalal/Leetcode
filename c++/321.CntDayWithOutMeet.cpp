/*3169. Count Days Without Meetings
You are given a positive integer days representing the total number of days an
employee is available for work (starting from day 1). You are also given a 2D
array meetings of size n where, meetings[i] = [start_i, end_i] represents the
starting and ending days of meeting i (inclusive).

Return the count of days when the employee is available for work but no meetings
are scheduled.

Note: The meetings may overlap.


Example 1:
Input: days = 10, meetings = [[5,7],[1,3],[9,10]]
Output: 2
Explanation:There is no meeting scheduled on the 4th and 8th days.

Example 2:
Input: days = 5, meetings = [[2,4],[1,3]]
Output: 1
Explanation:There is no meeting scheduled on the 5th day.

Example 3:
Input: days = 6, meetings = [[1,6]]
Output: 0
Explanation:Meetings are scheduled for all working days.



Constraints:
1 <= days <= 109
1 <= meetings.length <= 105
meetings[i].length == 2
1 <= meetings[i][0] <= meetings[i][1] <= days
*/

// Intuition
/* int meetingDay=0;
        for(int i=0;i<meetings.size();i++){
            for(int j=0;j<meetings[0].size();j++){
                //days=endi-starti+1
            }
        }
        return ans;
        */

// Approach
/* 1. sort meetings
2. merge overlapping intervals
3. calculate free days
4. check for edge cases like no meetings or all meetings
*/
class Solution {
public:
  int countDays(int days, vector<vector<int>>& meetings) {
    if (meetings.empty())
      return days;

    // Sort meetings by start day
    sort(meetings.begin(), meetings.end());

    int occupiedDays = 0, prevEnd = 0;

    for (auto& meeting : meetings) {
      int start = meeting[0], end = meeting[1];

      // If there's a gap between previous meeting and current meeting, count it
      if (start > prevEnd + 1) {
        occupiedDays += (end - start + 1);
      } else {
        // Merge overlapping meetings
        occupiedDays += max(0, end - prevEnd);
      }

      prevEnd = max(prevEnd, end);
    }

    return days - occupiedDays; // Free days
  }
};
// sub:
// https://leetcode.com/problems/count-days-without-meetings/submissions/1583818000/?envType=daily-question&envId=2025-03-24
// sol:
// https://leetcode.com/problems/count-days-without-meetings/solutions/6571831/3169-count-days-without-meetings-by-nali-tjjs/

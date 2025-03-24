//3169. Count Days Without Meetings
function countDays(days: number, meetings: number[][]): number {
  if (meetings.length === 0) return days;

  // Sort meetings by start day
  meetings.sort((a, b) => a[0] - b[0]);

  let occupiedDays = 0,
    prevEnd = 0;

  for (const [start, end] of meetings) {
    if (start > prevEnd + 1) {
      occupiedDays += end - start + 1;
    } else {
      occupiedDays += Math.max(0, end - prevEnd);
    }

    prevEnd = Math.max(prevEnd, end);
  }

  return days - occupiedDays;
}

// Example Usage
console.log(
  countDays(10, [
    [2, 3],
    [5, 6],
    [8, 10],
  ]),
); // Output: Free days
//sub: https://leetcode.com/problems/count-days-without-meetings/submissions/1583818556/?envType=daily-question&envId=2025-03-24
//sol: https://leetcode.com/problems/count-days-without-meetings/solutions/6571831/3169-count-days-without-meetings-by-nali-tjjs/

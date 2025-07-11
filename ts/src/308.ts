//2402. Meeting Rooms III
function mostBooked(n: number, meetings: number[][]): number {
  meetings.sort((a, b) => a[0] - b[0]);

  const availability = new Array<number>(n).fill(0);
  const count = new Array<number>(n).fill(0);

  for (const [start, end] of meetings) {
    const duration = end - start;
    let assigned = false;

    for (let i = 0; i < n; i++) {
      if (availability[i] <= start) {
        availability[i] = end;
        count[i]++;
        assigned = true;
        break;
      }
    }

    if (!assigned) {
      let earliest = 0;
      for (let i = 1; i < n; i++) {
        if (availability[i] < availability[earliest]) earliest = i;
      }
      availability[earliest] += duration;
      count[earliest]++;
    }
  }

  let maxRoom = 0;
  for (let i = 1; i < n; i++) {
    if (count[i] > count[maxRoom]) maxRoom = i;
  }

  return maxRoom;
}

//sub: https://leetcode.com/problems/meeting-rooms-iii/submissions/1694452640/?envType=daily-question&envId=2025-07-11
//sol: https://leetcode.com/problems/meeting-rooms-iii/solutions/6947194/2402-meeting-rooms-iii-by-nalindalal2004-1sc4/

//2071. Maximum Number of Tasks You Can Assign
function maxTaskAssign(
  tasks: number[],
  workers: number[],
  pills: number,
  strength: number,
): number {
  tasks.sort((a, b) => a - b);
  workers.sort((a, b) => a - b);

  let left = 0,
    right = Math.min(tasks.length, workers.length),
    ans = 0;

  while (left <= right) {
    const mid = Math.floor((left + right) / 2);
    if (canAssign(mid, tasks, workers, pills, strength)) {
      ans = mid;
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return ans;
}

function canAssign(
  k: number,
  tasks: number[],
  workers: number[],
  pills: number,
  strength: number,
): boolean {
  const taskSlice = tasks.slice(0, k); // easiest to hardest
  const workerSlice = workers.slice(workers.length - k); // strongest k workers
  workerSlice.sort((a, b) => a - b); // ensure ascending order

  let pillsLeft = pills;
  let deque: number[] = [...workerSlice]; // simulate multiset using sorted array

  for (let j = k - 1; j >= 0; j--) {
    const task = taskSlice[j];

    // Try strongest worker first
    if (deque[deque.length - 1] >= task) {
      deque.pop(); // assign strongest worker
    } else {
      if (pillsLeft === 0) return false;
      // Find weakest worker who can do it with a pill
      let idx = lowerBound(deque, task - strength);
      if (idx === deque.length) return false;
      deque.splice(idx, 1); // use this worker with pill
      pillsLeft--;
    }
  }

  return true;
}

// Binary search for first index in sorted array >= target
function lowerBound(arr: number[], target: number): number {
  let left = 0,
    right = arr.length;
  while (left < right) {
    const mid = Math.floor((left + right) / 2);
    if (arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }
  return left;
}
//sub: https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/submissions/1622415843/?envType=daily-question&envId=2025-05-01

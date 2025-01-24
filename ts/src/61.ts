//621. Task Scheduler
function leastInterval(tasks: string[], n: number): number {
  // Step 1: Initialize a frequency array for the 26 uppercase letters (A-Z)
  let freq: number[] = new Array(26).fill(0);

  // Step 2: Populate the frequency array with task counts
  for (let task of tasks) {
    freq[task.charCodeAt(0) - "A".charCodeAt(0)]++;
  }

  // Step 3: Sort the frequency array in ascending order
  freq.sort((a, b) => a - b);

  // Step 4: Calculate the number of chunks (excluding the most frequent task)
  let chunk = freq[25] - 1; // freq[25] is the max frequency after sorting
  let idle = chunk * n; // Maximum idle slots between chunks

  // Step 5: Fill the idle slots with remaining tasks
  for (let i = 24; i >= 0; i--) {
    // Start from the second highest frequency
    idle -= Math.min(freq[i], chunk); // Reduce idle slots by filling them
  }

  // Step 6: If no idle slots remain, return the task length; otherwise, add idle slots
  return idle < 0 ? tasks.length : tasks.length + idle;
}

//sub: https://leetcode.com/problems/task-scheduler/submissions/1518712283/
//sol: https://leetcode.com/problems/task-scheduler/solutions/6322678/621-task-scheduler100-by-nalindalal2004-j69n/
//100%

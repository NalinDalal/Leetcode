//502. IPO
class MaxHeap {
  private heap: number[];

  constructor() {
    this.heap = [];
  }

  push(value: number) {
    this.heap.push(value);
    this.heapifyUp();
  }

  pop(): number | undefined {
    if (this.heap.length === 0) return undefined;
    if (this.heap.length === 1) return this.heap.pop();
    const max = this.heap[0];
    this.heap[0] = this.heap.pop()!;
    this.heapifyDown();
    return max;
  }

  isEmpty(): boolean {
    return this.heap.length === 0;
  }

  private heapifyUp() {
    let index = this.heap.length - 1;
    while (index > 0) {
      let parentIndex = Math.floor((index - 1) / 2);
      if (this.heap[parentIndex] >= this.heap[index]) break;
      [this.heap[parentIndex], this.heap[index]] = [
        this.heap[index],
        this.heap[parentIndex],
      ];
      index = parentIndex;
    }
  }

  private heapifyDown() {
    let index = 0;
    while (true) {
      let left = 2 * index + 1;
      let right = 2 * index + 2;
      let largest = index;

      if (left < this.heap.length && this.heap[left] > this.heap[largest]) {
        largest = left;
      }
      if (right < this.heap.length && this.heap[right] > this.heap[largest]) {
        largest = right;
      }
      if (largest === index) break;
      [this.heap[index], this.heap[largest]] = [
        this.heap[largest],
        this.heap[index],
      ];
      index = largest;
    }
  }
}

function findMaximizedCapital(
  k: number,
  w: number,
  profits: number[],
  capital: number[],
): number {
  let projects: [number, number][] = [];
  const n = profits.length;

  // Step 1: Sort projects by required capital (ascending order)
  for (let i = 0; i < n; i++) {
    projects.push([capital[i], profits[i]]);
  }
  projects.sort((a, b) => a[0] - b[0]); // Sorting by capital in ascending order

  const maxHeap = new MaxHeap(); // Max-Heap for profits
  let i = 0;

  // Step 2: Pick up to k projects
  while (k--) {
    // Push all projects we can afford into the max-heap
    while (i < n && projects[i][0] <= w) {
      maxHeap.push(projects[i][1]);
      i++;
    }

    // If no projects are available, break early
    if (maxHeap.isEmpty()) break;

    // Pick the most profitable project
    w += maxHeap.pop()!;
  }

  return w;
}

//sub:https://leetcode.com/problems/ipo/submissions/1592769114/?envType=study-plan-v2&envId=top-interview-150
//sol:https://leetcode.com/problems/ipo/solutions/6602383/502-ipo-by-nalindalal2004-wjex/

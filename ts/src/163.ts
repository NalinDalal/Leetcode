//1851. Minimum Interval to Include Each Query

class MinHeap<T> {
  private heap: T[];
  private comparator: (a: T, b: T) => number;

  constructor(comparator: (a: T, b: T) => number) {
    this.heap = [];
    this.comparator = comparator;
  }

  push(value: T): void {
    this.heap.push(value);
    this.heapifyUp();
  }

  pop(): T | undefined {
    if (this.size() === 1) return this.heap.pop();
    const top = this.heap[0];
    this.heap[0] = this.heap.pop()!;
    this.heapifyDown();
    return top;
  }

  peek(): T | undefined {
    return this.heap[0];
  }

  size(): number {
    return this.heap.length;
  }

  private heapifyUp(): void {
    let index = this.heap.length - 1;
    while (index > 0) {
      const parentIndex = Math.floor((index - 1) / 2);
      if (this.comparator(this.heap[index], this.heap[parentIndex]) >= 0) break;
      [this.heap[index], this.heap[parentIndex]] = [
        this.heap[parentIndex],
        this.heap[index],
      ];
      index = parentIndex;
    }
  }

  private heapifyDown(): void {
    let index = 0;
    const length = this.heap.length;
    while (true) {
      let left = 2 * index + 1;
      let right = 2 * index + 2;
      let smallest = index;

      if (
        left < length &&
        this.comparator(this.heap[left], this.heap[smallest]) < 0
      ) {
        smallest = left;
      }
      if (
        right < length &&
        this.comparator(this.heap[right], this.heap[smallest]) < 0
      ) {
        smallest = right;
      }
      if (smallest === index) break;

      [this.heap[index], this.heap[smallest]] = [
        this.heap[smallest],
        this.heap[index],
      ];
      index = smallest;
    }
  }
}

function minInterval(intervals: number[][], queries: number[]): number[] {
  intervals.sort((a, b) => a[0] - b[0]); // Sort intervals by start
  const sortedQueries = queries
    .map((q, i) => [q, i])
    .sort((a, b) => a[0] - b[0]);

  const result: number[] = new Array(queries.length).fill(-1);
  const minHeap = new MinHeap<[number, number]>((a, b) => a[0] - b[0]); // Min-Heap for (size, end)
  let i = 0;

  for (const [query, index] of sortedQueries) {
    // Add all valid intervals to heap
    while (i < intervals.length && intervals[i][0] <= query) {
      const [start, end] = intervals[i];
      minHeap.push([end - start + 1, end]); // Store (size, end)
      i++;
    }

    // Remove intervals that have expired (end < query)
    while (minHeap.size() > 0 && minHeap.peek()![1] < query) {
      minHeap.pop();
    }

    if (minHeap.size() > 0) {
      result[index] = minHeap.peek()![0]; // Smallest interval containing query
    }
  }

  return result;
}
//sub: https://leetcode.com/problems/minimum-interval-to-include-each-query/submissions/1574441512/
//sol: https://leetcode.com/problems/minimum-interval-to-include-each-query/solutions/6539110/1851-minimum-interval-to-include-each-qu-pfvn/

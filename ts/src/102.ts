// 3066. Minimum Operations to Exceed Threshold Value II
function minOperations(nums: number[], k: number): number {
  // Min-heap implementation using a priority queue
  class MinHeap {
    private heap: number[];

    constructor(arr: number[]) {
      this.heap = [...arr];
      this.buildHeap();
    }

    private buildHeap() {
      this.heap.sort((a, b) => a - b); // O(n log n) sorting
    }

    push(val: number) {
      let i = this.heap.length;
      this.heap.push(val);
      while (i > 0) {
        let parent = Math.floor((i - 1) / 2);
        if (this.heap[parent] <= this.heap[i]) break;
        [this.heap[parent], this.heap[i]] = [this.heap[i], this.heap[parent]];
        i = parent;
      }
    }

    pop(): number | null {
      if (this.heap.length === 0) return null;
      if (this.heap.length === 1) return this.heap.pop()!;

      const min = this.heap[0];
      this.heap[0] = this.heap.pop()!;
      this.heapify(0);
      return min;
    }

    top(): number | null {
      return this.heap.length ? this.heap[0] : null;
    }

    size(): number {
      return this.heap.length;
    }

    private heapify(i: number) {
      let smallest = i;
      let left = 2 * i + 1;
      let right = 2 * i + 2;

      if (left < this.heap.length && this.heap[left] < this.heap[smallest]) {
        smallest = left;
      }

      if (right < this.heap.length && this.heap[right] < this.heap[smallest]) {
        smallest = right;
      }

      if (smallest !== i) {
        [this.heap[i], this.heap[smallest]] = [
          this.heap[smallest],
          this.heap[i],
        ];
        this.heapify(smallest);
      }
    }
  }

  // Initialize the min-heap
  const minHeap = new MinHeap(nums);
  let operations = 0;

  while (minHeap.top()! < k) {
    if (minHeap.size() < 2) return -1;

    const x = minHeap.pop()!;
    const y = minHeap.pop()!;
    minHeap.push(2 * x + y);
    operations++;
  }

  return operations;
}
//sub: https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/submissions/1541727232/?envType=daily-question&envId=2025-02-13
//sol: https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/solutions/6417746/3066-minimum-operations-to-exceed-thresh-euhg/

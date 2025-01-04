// 703. Kth Largest Element in a Stream

class KthLargest {
  private heap: number[];
  private k: number;

  constructor(k: number, nums: number[]) {
    this.k = k;
    this.heap = [];

    // Add all elements to the heap, keeping only the k largest
    for (const num of nums) {
      this.add(num);
    }
  }

  add(val: number): number {
    if (this.heap.length < this.k) {
      // Push directly if heap size is less than k
      this.heapPush(val);
    } else if (val > this.heap[0]) {
      // Replace the smallest element if the new value is larger
      this.heap[0] = val;
      this.heapifyDown(0);
    }

    // The k-th largest element is the root of the heap
    return this.heap[0];
  }

  private heapPush(val: number): void {
    this.heap.push(val);
    this.heapifyUp(this.heap.length - 1);
  }

  private heapifyUp(index: number): void {
    while (index > 0) {
      const parent = Math.floor((index - 1) / 2);
      if (this.heap[parent] <= this.heap[index]) break;

      // Swap parent and current element
      [this.heap[parent], this.heap[index]] = [
        this.heap[index],
        this.heap[parent],
      ];
      index = parent;
    }
  }

  private heapifyDown(index: number): void {
    const n = this.heap.length;
    while (true) {
      const left = 2 * index + 1;
      const right = 2 * index + 2;
      let smallest = index;

      if (left < n && this.heap[left] < this.heap[smallest]) smallest = left;
      if (right < n && this.heap[right] < this.heap[smallest]) smallest = right;

      if (smallest === index) break;

      // Swap current element with the smallest child
      [this.heap[index], this.heap[smallest]] = [
        this.heap[smallest],
        this.heap[index],
      ];
      index = smallest;
    }
  }
}

// submission: https://leetcode.com/problems/kth-largest-element-in-a-stream/submissions/1496917785/

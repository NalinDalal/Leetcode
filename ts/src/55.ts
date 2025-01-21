// https://leetcode.com/problems/kth-largest-element-in-an-array/description/
// 215. Kth Largest Element in an Array

function findKthLargest(nums: number[], k: number): number {
  const heapSize = nums.length;

  // Helper functions
  const left = (i: number): number => (i << 1) + 1;
  const right = (i: number): number => (i << 1) + 2;

  const maxHeapify = (i: number, size: number): void => {
    let largest = i;
    const l = left(i);
    const r = right(i);

    if (l < size && nums[l] > nums[largest]) {
      largest = l;
    }
    if (r < size && nums[r] > nums[largest]) {
      largest = r;
    }
    if (largest !== i) {
      [nums[i], nums[largest]] = [nums[largest], nums[i]]; // Swap
      maxHeapify(largest, size); // Recursively heapify
    }
  };

  const buildMaxHeap = (): void => {
    for (let i = (heapSize >> 1) - 1; i >= 0; i--) {
      maxHeapify(i, heapSize);
    }
  };

  // Build the max-heap
  buildMaxHeap();

  // Extract max (k-1) times
  let size = heapSize;
  for (let i = 0; i < k - 1; i++) {
    [nums[0], nums[size - 1]] = [nums[size - 1], nums[0]]; // Swap root with last element
    size--; // Reduce the heap size
    maxHeapify(0, size); // Restore heap property
  }

  // The root of the heap is the k-th largest element
  return nums[0];
}
//55.83%
//sub: https://leetcode.com/problems/kth-largest-element-in-an-array/submissions/1515752511/
//sol: https://leetcode.com/problems/kth-largest-element-in-an-array/solutions/6311074/215-kth-largest-element-in-an-array65-by-qzcr/

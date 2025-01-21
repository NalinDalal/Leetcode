/* https://leetcode.com/problems/kth-largest-element-in-an-array/description/

215. Kth Largest Element in an Array

Given an integer array nums and an integer k, return the kth largest element in
the array.

Note that it is the kth largest element in the sorted order, not the kth
distinct element.

Can you solve it without sorting?


Example 1:
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5

Example 2:
Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4


Constraints:

1 <= k <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4*/

/* Intuition:
1. sort the array
2. return kth largest element in array
3. use quickselect*/

/* 1. Build max heap
2. extract max k-1 times
3. return kth largest element in array
*/

class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    // Edge case: if k is invalid or the array is empty
    if (nums.empty() || k <= 0 || k > nums.size()) {
      throw invalid_argument("Invalid value of k or empty array");
    }

    // Build a max heap from the input array
    buildMaxHeap(nums);

    // Store the initial heap size
    int initialHeapSize = heap_size;

    // Extract the maximum (root) k-1 times
    for (int i = 0; i < k - 1; ++i) {
      swap(nums[0], nums[--heap_size]); // Swap the root with the last element
      maxHeapify(nums,
                 0); // Restore the heap property for the remaining elements
    }

    // Return the k-th largest element, now at the root
    heap_size = initialHeapSize; // Reset heap size for consistency
    return nums[0];
  }

private:
  int heap_size; // Tracks the current size of the heap

  // Calculate index of left child
  constexpr int left(int i) const { return (i << 1) + 1; }

  // Calculate index of right child
  constexpr int right(int i) const { return (i << 1) + 2; }

  // Restore the max-heap property at the given index
  void maxHeapify(vector<int>& nums, int i) {
    int largest = i;
    const int l = left(i);  // Index of the left child
    const int r = right(i); // Index of the right child

    // Find the largest among root, left child, and right child
    if (l < heap_size && nums[l] > nums[largest]) {
      largest = l;
    }
    if (r < heap_size && nums[r] > nums[largest]) {
      largest = r;
    }

    // If the root is not the largest, swap and continue heapifying
    if (largest != i) {
      swap(nums[i], nums[largest]);
      maxHeapify(nums, largest); // Recursive call
    }
  }

  // Build a max heap from the input array
  void buildMaxHeap(vector<int>& nums) {
    heap_size = nums.size(); // Initialize heap size
    // Start from the last non-leaf node and heapify each node
    for (int i = (heap_size >> 1) - 1; i >= 0; --i) {
      maxHeapify(nums, i);
    }
  }
};
// Time: O(n+klogn)
// Space: O(1)
// 65%
// sub:
// https://leetcode.com/problems/kth-largest-element-in-an-array/submissions/1515746689/
// sol:
// https://leetcode.com/problems/kth-largest-element-in-an-array/solutions/6311074/215-kth-largest-element-in-an-array65-by-qzcr/

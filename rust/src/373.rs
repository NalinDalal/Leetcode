//373. Find K Pairs with Smallest Sums
use std::cmp::Reverse;
use std::collections::BinaryHeap;
impl Solution {
    pub fn k_smallest_pairs(nums1: Vec<i32>, nums2: Vec<i32>, k: i32) -> Vec<Vec<i32>> {
        let mut ans = Vec::new();
        if nums1.is_empty() || nums2.is_empty() || k == 0 {
            return ans;
        }

        // Min-heap: stores (sum, i, j)
        let mut min_heap = BinaryHeap::new();

        // Push the first row of pairs (nums1[i], nums2[0]) into heap
        for i in 0..nums1.len().min(k as usize) {
            min_heap.push(Reverse((nums1[i] + nums2[0], i, 0)));
        }

        let mut k = k;
        while k > 0 && !min_heap.is_empty() {
            if let Some(Reverse((_, i, j))) = min_heap.pop() {
                ans.push(vec![nums1[i], nums2[j]]);

                // Push the next element in nums2 for the same nums1[i]
                if j + 1 < nums2.len() {
                    min_heap.push(Reverse((nums1[i] + nums2[j + 1], i, j + 1)));
                }
            }
            k -= 1;
        }

        ans
    }
}
//sub: https://leetcode.com/problems/find-k-pairs-with-smallest-sums/submissions/1588862126/?envType=study-plan-v2&envId=top-interview-150
//sol: https://leetcode.com/problems/find-k-pairs-with-smallest-sums/solutions/6588451/373-find-k-pairs-with-smallest-sums-by-n-nk6m/

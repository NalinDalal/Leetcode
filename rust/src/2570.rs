//2570. Merge Two 2D Arrays by Summing Values
impl Solution {
    pub fn merge_arrays(nums1: Vec<Vec<i32>>, nums2: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut result = Vec::new();
        let (mut i, mut j) = (0, 0);

        while i < nums1.len() || j < nums2.len() {
            if j >= nums2.len() || (i < nums1.len() && nums1[i][0] < nums2[j][0]) {
                result.push(nums1[i].clone());
                i += 1;
            } else if i >= nums1.len() || (j < nums2.len() && nums2[j][0] < nums1[i][0]) {
                result.push(nums2[j].clone());
                j += 1;
            } else {
                result.push(vec![nums1[i][0], nums1[i][1] + nums2[j][1]]);
                i += 1;
                j += 1;
            }
        }

        result
    }
}

fn main() {
    let nums1 = vec![vec![1, 2], vec![2, 3], vec![4, 5]];
    let nums2 = vec![vec![1, 4], vec![3, 2], vec![4, 1]];

    let result = Solution::merge_arrays(nums1, nums2);
    println!("{:?}", result); // Output: [[1,6],[2,3],[3,2],[4,6]]
}
//sub: https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/submissions/1560339250/?envType=daily-question&envId=2025-03-02
//sol: https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/solutions/6485941/2570-merge-two-2d-arrays-by-summing-valu-0vvh/

//80. Remove Duplicates from Sorted Array II
impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        if nums.len() <= 2 {
            return nums.len().try_into().unwrap();
        }

        let mut idx = 2;

        for i in 2..nums.len() {
            if nums[i] != nums[idx - 2] {
                nums[idx] = nums[i];
                idx += 1;
            }
        }

        idx.try_into().unwrap()
    }
}
//sub: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/submissions/1606135466/?envType=study-plan-v2&envId=top-interview-150
//sol: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/solutions/6648352/80-remove-duplicates-from-sorted-array-i-dl4x/

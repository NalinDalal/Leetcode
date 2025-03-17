//2206. Divide Array Into Equal Pairs
impl Solution {
    pub fn divide_array(mut nums: Vec<i32>) -> bool {
        nums.sort(); // Sort the array
        for i in (0..nums.len()).step_by(2) {
            if nums[i] != nums[i + 1] {
                return false;
            }
        }
        true
    }
}
//sub: https://leetcode.com/problems/divide-array-into-equal-pairs/submissions/1576404290/?envType=daily-question&envId=2025-03-17
//sol: https://leetcode.com/problems/divide-array-into-equal-pairs/solutions/6545739/2206-divide-array-into-equal-pairs-by-na-bn4y/

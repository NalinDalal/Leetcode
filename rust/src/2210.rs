//2210. Count Hills and Valleys in an Array
impl Solution{
    pub fn count_hill_valley(nums: Vec<i32>) -> i32 {
        let mut compressed = vec![nums[0]];

        // Step 1: Remove consecutive duplicates
        for i in 1..nums.len() {
            if nums[i] != nums[i - 1] {
                compressed.push(nums[i]);
            }
        }

        // Step 2: Count hills and valleys
        let mut count = 0;
        for i in 1..compressed.len() - 1 {
            if (compressed[i] > compressed[i - 1] && compressed[i] > compressed[i + 1]) ||
            (compressed[i] < compressed[i - 1] && compressed[i] < compressed[i + 1]) {
                count += 1;
            }
        }

        count
    }
}
//sub: https://leetcode.com/problems/count-hills-and-valleys-in-an-array/submissions/1713259707/
//sol: https://leetcode.com/problems/count-hills-and-valleys-in-an-array/solutions/7011252/2210-count-hills-and-valleys-in-an-array-qda0/

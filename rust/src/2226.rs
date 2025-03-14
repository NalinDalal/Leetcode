//2226. Maximum Candies Allocated to K Children
impl Solution {
    pub fn maximum_candies(candies: Vec<i32>, k: i64) -> i32 {
        fn can_distribute(candies: &Vec<i32>, k: i64, c: i32) -> bool {
            let mut count: i64 = 0;
            for &num in candies {
                count += (num / c) as i64; // Count the number of children we can satisfy
            }
            count >= k
        }

        let mut low = 1;
        let mut high = *candies.iter().max().unwrap();
        let mut result = 0;

        while low <= high {
            let mid = low + (high - low) / 2;
            if can_distribute(&candies, k, mid) {
                result = mid; // Store valid c
                low = mid + 1; // Try a larger c
            } else {
                high = mid - 1; // Try a smaller c
            }
        }

        result
    }
}

//sub: https://leetcode.com/problems/maximum-candies-allocated-to-k-children/submissions/1573380334/?envType=daily-question&envId=2025-03-14
//sol: https://leetcode.com/problems/maximum-candies-allocated-to-k-children/solutions/6535464/2226-maximum-candies-allocated-to-k-chil-k06e/

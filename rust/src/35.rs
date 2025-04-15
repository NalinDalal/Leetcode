//35. Search Insert Position

impl Solution {
    pub fn search_insert(nums: Vec<i32>, target: i32) -> i32 {
        nums.binary_search(&target).unwrap_or_else(|x| x) as i32
    }
}
//sub: https://leetcode.com/problems/search-insert-position/submissions/1607112896/?envType=study-plan-v2&envId=top-interview-150
//sol: https://leetcode.com/problems/search-insert-position/solutions/6651841/35-search-insert-position-by-nalindalal2-2nib/

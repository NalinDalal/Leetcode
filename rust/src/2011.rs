//2011. Final Value of Variable After Performing Operations
impl Solution {
    pub fn final_value_after_operations(operations: Vec<String>) -> i32 {
        let mut x = 0;
        for op in operations {
            if op.contains('+') {
                x += 1;
            } else {
                x -= 1;
            }
        }
        x
    }
}
//sub: https://leetcode.com/problems/final-value-of-variable-after-performing-operations/submissions/1806655377/?envType=daily-question&envId=2025-10-20
//sol: https://leetcode.com/problems/final-value-of-variable-after-performing-operations/solutions/7288260/2011-final-value-of-variable-after-perfo-fbwl/

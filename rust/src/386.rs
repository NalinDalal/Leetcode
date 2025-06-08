//386. Lexicographical Numbers
impl Solution {
    pub fn lexical_order(n: i32) -> Vec<i32> {
        fn dfs(current: i32, n: i32, result: &mut Vec<i32>) {
            if current > n {
                return;
            }
            result.push(current);
            for i in 0..=9 {
                let next = current * 10 + i;
                if next > n {
                    return;
                }
                dfs(next, n, result);
            }
        }

        let mut result = Vec::with_capacity(n as usize);
        for i in 1..=9 {
            dfs(i, n, &mut result);
        }
        result
    }
}
//sub: https://leetcode.com/problems/lexicographical-numbers/submissions/1657350079/
//sol: https://leetcode.com/problems/lexicographical-numbers/solutions/6822214/386-lexicographical-numbers/

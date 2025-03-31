//2551. Put Marbles in Bags
impl Solution {
    pub fn put_marbles(weights: Vec<i32>, k: i32) -> i64 {
        let mut pair_sums: Vec<i32> = Vec::new();

        for i in 0..weights.len() - 1 {
            pair_sums.push(weights[i] + weights[i + 1]);
        }

        pair_sums.sort_unstable(); // Sort in ascending order

        let min_score: i64 = pair_sums
            .iter()
            .take((k - 1) as usize)
            .map(|&x| x as i64)
            .sum();
        let max_score: i64 = pair_sums
            .iter()
            .rev()
            .take((k - 1) as usize)
            .map(|&x| x as i64)
            .sum();

        max_score - min_score
    }
}

//sub: https://leetcode.com/problems/put-marbles-in-bags/submissions/1591689638/?envType=daily-question&envId=2025-03-31
//sol: https://leetcode.com/problems/put-marbles-in-bags/solutions/6598616/2551-put-marbles-in-bags-by-nalindalal20-4cm8/

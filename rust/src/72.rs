//72. Edit Distance
impl Solution {
    pub fn min_distance(word1: String, word2: String) -> i32 {
        let (mut word1, mut word2) = (word1, word2);
        let (mut m, mut n) = (word1.len(), word2.len());

        // Ensure m <= n to optimize space usage
        if m > n {
            std::mem::swap(&mut word1, &mut word2);
            std::mem::swap(&mut m, &mut n);
        }

        // Convert strings to byte slices for efficient indexing
        let word1 = word1.as_bytes();
        let word2 = word2.as_bytes();

        // DP arrays: previous and current
        let mut previous = (0..=n as i32).collect::<Vec<i32>>();
        let mut current = vec![0; n + 1];

        // Fill the DP table
        for i in 1..=m {
            current[0] = i as i32; // Base case when word2 is empty

            for j in 1..=n {
                if word1[i - 1] == word2[j - 1] {
                    current[j] = previous[j - 1]; // No operation needed
                } else {
                    current[j] =
                        1 + std::cmp::min(previous[j - 1].min(previous[j]), current[j - 1]);
                }
            }

            // Swap previous and current for the next iteration
            std::mem::swap(&mut previous, &mut current);
        }

        // The result is stored in the last element of the previous row
        previous[n]
    }
}

//sub: https://leetcode.com/problems/edit-distance/submissions/1558693236/
//sol: https://leetcode.com/problems/edit-distance/solutions/6479233/72-edit-distance-by-nalindalal2004-9gef/

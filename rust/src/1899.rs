//1899. Merge Triplets to Form Target Triplet

impl Solution {
    pub fn merge_triplets(triplets: Vec<Vec<i32>>, target: Vec<i32>) -> bool {
        let (mut found_a, mut found_b, mut found_c) = (false, false, false);

        for triplet in triplets.iter() {
            if triplet[0] > target[0] || triplet[1] > target[1] || triplet[2] > target[2] {
                continue;
            }

            if triplet[0] == target[0] {
                found_a = true;
            }
            if triplet[1] == target[1] {
                found_b = true;
            }
            if triplet[2] == target[2] {
                found_c = true;
            }

            if found_a && found_b && found_c {
                return true;
            }
        }

        false
    }
}
//sub: https://leetcode.com/problems/merge-triplets-to-form-target-triplet/submissions/1564587907/
// Example usage
fn main() {
    let triplets = vec![vec![2, 5, 3], vec![1, 8, 4], vec![3, 6, 4]];
    let target = vec![3, 6, 4];
    println!("{}", merge_triplets(triplets, target)); // true or false
}
//sol: https://leetcode.com/problems/merge-triplets-to-form-target-triplet/solutions/6503743/1899-merge-triplets-to-form-target-tripl-bt3v/

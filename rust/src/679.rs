//679. 24 Game
pub struct Solution;

impl Solution {
    pub fn judge_point24(cards: Vec<i32>) -> bool {
        let nums: Vec<f64> = cards.into_iter().map(|x| x as f64).collect();
        Self::solve(nums)
    }

    fn solve(nums: Vec<f64>) -> bool {
        const EPS: f64 = 1e-6;

        if nums.len() == 1 {
            return (nums[0] - 24.0).abs() < EPS;
        }

        for i in 0..nums.len() {
            for j in (i + 1)..nums.len() {
                let mut next = Vec::new();
                for k in 0..nums.len() {
                    if k != i && k != j {
                        next.push(nums[k]);
                    }
                }

                for val in Self::compute(nums[i], nums[j]) {
                    let mut new_next = next.clone();
                    new_next.push(val);
                    if Self::solve(new_next) {
                        return true;
                    }
                }
            }
        }
        false
    }

    fn compute(a: f64, b: f64) -> Vec<f64> {
        const EPS: f64 = 1e-6;
        let mut res = Vec::new();
        res.push(a + b);
        res.push(a - b);
        res.push(b - a);
        res.push(a * b);
        if b.abs() > EPS {
            res.push(a / b);
        }
        if a.abs() > EPS {
            res.push(b / a);
        }
        res
    }
}

fn main() {
    println!("{}", Solution::judge_point24(vec![4, 1, 8, 7])); // true
    println!("{}", Solution::judge_point24(vec![1, 2, 1, 2])); // false
}

//sub: https://leetcode.com/problems/24-game/submissions/1739113934/?envType=daily-question&envId=2025-08-18
//sol: https://leetcode.com/problems/24-game/solutions/7093821/679-24-game-by-nalindalal2004-s9c7/

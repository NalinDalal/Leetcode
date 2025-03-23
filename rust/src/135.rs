//135. Candy
pub fn candy(ratings: Vec<i32>) -> i32 {
    let n = ratings.len();
    if n == 0 {
        return 0;
    }

    let mut candies = vec![1; n];

    // Left to Right pass
    for i in 1..n {
        if ratings[i] > ratings[i - 1] {
            candies[i] = candies[i - 1] + 1;
        }
    }

    // Right to Left pass
    for i in (0..n - 1).rev() {
        if ratings[i] > ratings[i + 1] {
            candies[i] = candies[i].max(candies[i + 1] + 1);
        }
    }

    // Sum up candies
    candies.iter().sum()
}

// Example usage
fn main() {
    println!("{}", candy(vec![1, 0, 2])); // Output: 5
    println!("{}", candy(vec![1, 2, 2])); // Output: 4
}
//sub: https://leetcode.com/problems/candy/submissions/1583190166/?envType=study-plan-v2&envId=top-interview-150
//sol: https://leetcode.com/problems/candy/solutions/6569867/135-candy-by-nalindalal2004-rwuo/

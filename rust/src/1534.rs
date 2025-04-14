//1534. Count Good Triplets

impl Solution {
    pub fn count_good_triplets(arr: Vec<i32>, a: i32, b: i32, c: i32) -> i32 {
        let mut count = 0;
        let n = arr.len();

        for i in 0..n - 2 {
            for j in i + 1..n - 1 {
                if (arr[i] - arr[j]).abs() <= a {
                    for k in j + 1..n {
                        if (arr[j] - arr[k]).abs() <= b && (arr[i] - arr[k]).abs() <= c {
                            count += 1;
                        }
                    }
                }
            }
        }

        count
    }
}
//sub: https://leetcode.com/problems/count-good-triplets/submissions/1606140489/?envType=daily-question&envId=2025-04-14
//sol:https://leetcode.com/problems/count-good-triplets/solutions/6648385/1534-count-good-triplets-by-nalindalal20-fm4i/

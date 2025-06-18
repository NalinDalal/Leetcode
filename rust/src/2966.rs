//2966. Divide Array Into Arrays With Max Difference
impl Solution {
    pub fn divide_array(mut nums: Vec<i32>, k: i32) -> Vec<Vec<i32>> {
        nums.sort();
        let mut result = Vec::new();

        for chunk in nums.chunks(3) {
            if chunk.len() != 3 || chunk[2] - chunk[0] > k {
                return vec![];
            }
            result.push(chunk.to_vec());
        }

        result
    }
}
//sub: https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/submissions/1667815673/?envType=daily-question&envId=2025-06-18
//sol: https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/solutions/6856057/2966-divide-array-into-arrays-with-max-d-lu25/

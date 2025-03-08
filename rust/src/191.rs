//191. Number of 1 Bits
impl Solution {
    pub fn hamming_weight(n: i32) -> i32 {
        let mut count = 0;
        let binary = format!("{:b}", n); // Convert to binary string

        for bit in binary.chars() {
            if bit == '1' {
                count += 1;
            }
        }

        count
    }
}

//sub: https://leetcode.com/problems/number-of-1-bits/submissions/1566738416/
//sol: https://leetcode.com/problems/number-of-1-bits/solutions/6512204/191-number-of-1-bits-by-nalindalal2004-5unl

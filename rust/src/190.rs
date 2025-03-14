//190. Reverse Bits
impl Solution {
    pub fn reverse_bits(x: u32) -> u32 {
        let mut res = 0;
        let mut num = x;
        for i in 0..32 {
            res |= (num & 1) << (31 - i); // Extract LSB and shift to the reversed position
            num >>= 1; // Right shift to process next bit
        }
        res
    }
}

fn main() {
    let num: u32 = 43261596;
    println!("{}", reverse_bits(num)); // Output: 964176192
}
//sub: https://leetcode.com/problems/reverse-bits/submissions/1573362438/
//sol: https://leetcode.com/problems/reverse-bits/solutions/6535387/190-reverse-bits-by-nalindalal2004-alpw/

//1358. Number of Substrings Containing All Three Characters
impl Solution {
    pub fn number_of_substrings(s: String) -> i32 {
        let mut count = [0; 3]; // Track frequency of 'a', 'b', 'c'
        let mut l = 0;
        let mut ans = 0;
        let chars: Vec<char> = s.chars().collect();

        for r in 0..chars.len() {
            count[(chars[r] as u8 - b'a') as usize] += 1; // Increment count of current character

            // Shrink left pointer while all 'a', 'b', 'c' are present
            while count[0] > 0 && count[1] > 0 && count[2] > 0 {
                ans += (s.len() - r) as i32; // All substrings from l to end are valid
                count[(chars[l] as u8 - b'a') as usize] -= 1; // Remove leftmost character
                l += 1; // Move left pointer
            }
        }
        ans
    }
}
//sub: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/submissions/1569768894/?envType=daily-question&envId=2025-03-11
//sol: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/solutions/6522323/1358-number-of-substrings-containing-all-3j72/

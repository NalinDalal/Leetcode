//3306. Count of Substrings Containing Every Vowel and K Consonants II

impl Solution {
    pub fn count_of_substrings(word: String, k: i32) -> i64 {
        let mut frequencies = [[0; 128], [0; 128]];
        for &v in "aeiou".as_bytes() {
            frequencies[0][v as usize] = 1;
        }

        let mut response = 0_i64;
        let mut current_k = 0;
        let mut vowels = 0;
        let mut extra_left = 0;
        let mut left = 0;
        let word_bytes = word.as_bytes();
        let k = k as usize;

        for right in 0..word_bytes.len() {
            let right_char = word_bytes[right] as usize;

            if frequencies[0][right_char] == 1 {
                if frequencies[1][right_char] == 0 {
                    vowels += 1;
                }
                frequencies[1][right_char] += 1;
            } else {
                current_k += 1;
            }

            while current_k > k {
                let left_char = word_bytes[left] as usize;
                if frequencies[0][left_char] == 1 {
                    frequencies[1][left_char] -= 1;
                    if frequencies[1][left_char] == 0 {
                        vowels -= 1;
                    }
                } else {
                    current_k -= 1;
                }
                left += 1;
                extra_left = 0;
            }

            while vowels == 5
                && current_k == k
                && left < right
                && frequencies[0][word_bytes[left] as usize] == 1
                && frequencies[1][word_bytes[left] as usize] > 1
            {
                extra_left += 1;
                frequencies[1][word_bytes[left] as usize] -= 1;
                left += 1;
            }

            if current_k == k && vowels == 5 {
                response += 1 + extra_left;
            }
        }

        response
    }
}
//sub: https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii/submissions/1569004243/?source=submission-ac
//sol: https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii/solutions/6520068/3306-count-of-substrings-containing-ever-udsj/

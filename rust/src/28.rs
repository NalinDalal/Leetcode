//28. Find the Index of the First Occurrence in a String
impl Solution {
    pub fn str_str(haystack: String, needle: String) -> i32 {
        if needle.is_empty() {
            return 0;
        }

        let haystack_len = haystack.len();
        let needle_len = needle.len();

        if needle_len > haystack_len {
            return -1;
        }

        for i in 0..=haystack_len - needle_len {
            if haystack[i..i + needle_len] == needle {
                return i as i32; // Found the first occurrence
            }
        }

        -1 // Needle not found
    }
}
//sub: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/submissions/1588831698/?envType=study-plan-v2&envId=top-interview-150

//2197. Replace Non-Coprime Numbers in Array
impl Solution {
    pub fn replace_non_coprimes(nums: Vec<i32>) -> Vec<i32> {
        fn gcd(mut a: i64, mut b: i64) -> i64 {
            while b != 0 {
                let t = b;
                b = a % b;
                a = t;
            }
            a
        }

        let mut st: Vec<i64> = Vec::new();
        for x in nums {
            st.push(x as i64);
            while st.len() > 1 {
                let a = *st.last().unwrap();
                let b = st[st.len() - 2];
                let g = gcd(a, b);
                if g == 1 {
                    break;
                } else {
                    st.pop();
                    st.pop();
                    let l = a / g * b; // lcm
                    st.push(l);
                }
            }
        }

        st.into_iter().map(|v| v as i32).collect()
    }
}

//sub: https://leetcode.com/problems/replace-non-coprime-numbers-in-array/submissions/1772183218/?envType=daily-question&envId=2025-09-16
//sol: https://leetcode.com/problems/replace-non-coprime-numbers-in-array/solutions/7194528/2197-replace-non-coprime-numbers-in-arra-c210/

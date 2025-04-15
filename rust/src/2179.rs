//2179. Count Good Triplets in an Array
struct Fenwick {
    bit: Vec<i32>,
    n: usize,
}

impl Fenwick {
    fn new(size: usize) -> Self {
        Fenwick {
            bit: vec![0; size + 2],
            n: size + 1,
        }
    }

    fn update(&mut self, mut idx: usize, delta: i32) {
        idx += 1;
        while idx <= self.n {
            self.bit[idx] += delta;
            idx += idx & (!idx + 1);
        }
    }

    fn query(&self, mut idx: usize) -> i32 {
        let mut res = 0;
        idx += 1;
        while idx > 0 {
            res += self.bit[idx];
            idx -= idx & (!idx + 1);
        }
        res
    }

    fn range_query(&self, left: usize, right: usize) -> i32 {
        if left > right {
            0
        } else {
            self.query(right) - self.query(left.saturating_sub(1))
        }
    }
}

impl Solution {
    pub fn good_triplets(nums1: Vec<i32>, nums2: Vec<i32>) -> i64 {
        let n = nums1.len();
        let mut pos2 = vec![0; n];
        for (i, &num) in nums2.iter().enumerate() {
            pos2[num as usize] = i;
        }

        let mapped: Vec<usize> = nums1.iter().map(|&x| pos2[x as usize]).collect();

        let mut bit_left = Fenwick::new(n);
        let mut bit_right = Fenwick::new(n);
        let mut right_freq = vec![0; n];

        for &x in &mapped {
            right_freq[x] += 1;
        }

        for (i, &freq) in right_freq.iter().enumerate() {
            if freq > 0 {
                bit_right.update(i, freq);
            }
        }

        let mut res: i64 = 0;
        for &mid in &mapped {
            bit_right.update(mid, -1);
            let left_count = bit_left.query(mid.saturating_sub(1)) as i64;
            let right_count = if mid + 1 < n {
                bit_right.range_query(mid + 1, n - 1) as i64
            } else {
                0
            };
            res += left_count * right_count;
            bit_left.update(mid, 1);
        }

        res
    }
}
//sub: https://leetcode.com/problems/count-good-triplets-in-an-array/submissions/1607121528/?envType=daily-question&envId=2025-04-15
//sol: https://leetcode.com/problems/count-good-triplets-in-an-array/solutions/6651868/2179-count-good-triplets-in-an-array-by-lpheo/

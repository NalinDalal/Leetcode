//3477. Fruits Into Baskets II
impl Solution {
    pub fn num_of_unplaced_fruits(fruits: Vec<i32>, baskets: Vec<i32>) -> i32 {
        let n = fruits.len();
        let mut size = 1;
        while size < n {
            size <<= 1;
        }

        let mut seg = vec![0; 2 * size];

        for i in 0..n {
            seg[size + i] = baskets[i];
        }

        for i in (1..size).rev() {
            seg[i] = seg[2 * i].max(seg[2 * i + 1]);
        }

        let mut update = |pos: usize| {
            let mut p = pos + size;
            seg[p] = 0;
            while p > 1 {
                p >>= 1;
                seg[p] = seg[2 * p].max(seg[2 * p + 1]);
            }
        };

        let query = |x: i32, seg: &Vec<i32>, size: usize, n: usize| -> i32 {
            let mut pos = 1;
            let mut l = 0;
            let mut r = size - 1;
            while pos < size {
                let mid = (l + r) / 2;
                if seg[2 * pos] >= x {
                    pos = 2 * pos;
                    r = mid;
                } else {
                    pos = 2 * pos + 1;
                    l = mid + 1;
                }
            }
            if l < n && seg[pos] >= x {
                l as i32
            } else {
                -1
            }
        };

        let mut unplaced = 0;
        for &fruit in &fruits {
            let idx = query(fruit, &seg, size, n);
            if idx == -1 {
                unplaced += 1;
            } else {
                update(idx as usize);
            }
        }

        unplaced
    }
}

impl Solution {
    pub fn num_of_unplaced_fruits(fruits: Vec<i32>, baskets: Vec<i32>) -> i32 {
        let n = fruits.len();
        let mut size = 1;
        while size < n {
            size <<= 1;
        }

        let mut seg = vec![0; 2 * size];

        for i in 0..n {
            seg[size + i] = baskets[i];
        }

        for i in (1..size).rev() {
            seg[i] = seg[2 * i].max(seg[2 * i + 1]);
        }

        fn update(seg: &mut Vec<i32>, pos: usize, size: usize) {
            let mut p = pos + size;
            seg[p] = 0;
            while p > 1 {
                p >>= 1;
                seg[p] = seg[2 * p].max(seg[2 * p + 1]);
            }
        }

        fn query(x: i32, seg: &Vec<i32>, size: usize, n: usize) -> i32 {
            let mut pos = 1;
            let mut l = 0;
            let mut r = size - 1;
            while pos < size {
                let mid = (l + r) / 2;
                if seg[2 * pos] >= x {
                    pos = 2 * pos;
                    r = mid;
                } else {
                    pos = 2 * pos + 1;
                    l = mid + 1;
                }
            }
            if l < n && seg[pos] >= x {
                l as i32
            } else {
                -1
            }
        }

        let mut unplaced = 0;
        for &fruit in &fruits {
            let idx = query(fruit, &seg, size, n);
            if idx == -1 {
                unplaced += 1;
            } else {
                update(&mut seg, idx as usize, size);
            }
        }

        unplaced
    }
}

//sub: https://leetcode.com/problems/fruits-into-baskets-ii/submissions/1723896164/
//sol: https://leetcode.com/problems/fruits-into-baskets-ii/solutions/7045726/3477-fruits-into-baskets-ii-by-nalindala-uk6y/

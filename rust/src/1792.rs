//1792. Maximum Average Pass Ratio
struct MaxHeap {
    heap: Vec<(f64, i32, i32)>, // (gain, pass, total)
}

impl MaxHeap {
    fn new() -> Self {
        MaxHeap { heap: Vec::new() }
    }

    fn push(&mut self, item: (f64, i32, i32)) {
        self.heap.push(item);
        self.bubble_up(self.heap.len() - 1);
    }

    fn pop(&mut self) -> (f64, i32, i32) {
        let top = self.heap[0];
        let last = self.heap.pop().unwrap();
        if !self.heap.is_empty() {
            self.heap[0] = last;
            self.bubble_down(0);
        }
        top
    }

    fn bubble_up(&mut self, mut i: usize) {
        while i > 0 {
            let parent = (i - 1) / 2;
            if self.heap[i].0 <= self.heap[parent].0 {
                break;
            }
            self.heap.swap(i, parent);
            i = parent;
        }
    }

    fn bubble_down(&mut self, mut i: usize) {
        let n = self.heap.len();
        loop {
            let mut largest = i;
            let left = 2 * i + 1;
            let right = 2 * i + 2;

            if left < n && self.heap[left].0 > self.heap[largest].0 {
                largest = left;
            }
            if right < n && self.heap[right].0 > self.heap[largest].0 {
                largest = right;
            }
            if largest == i {
                break;
            }
            self.heap.swap(i, largest);
            i = largest;
        }
    }
}

impl Solution {
    pub fn max_average_ratio(classes: Vec<Vec<i32>>, mut extra_students: i32) -> f64 {
        let pass_gain = |pass: i32, total: i32| -> f64 {
            (pass + 1) as f64 / (total + 1) as f64 - pass as f64 / total as f64
        };

        let mut heap = MaxHeap::new();
        for c in &classes {
            let pass = c[0];
            let total = c[1];
            heap.push((pass_gain(pass, total), pass, total));
        }

        while extra_students > 0 {
            let (gain, mut pass, mut total) = heap.pop();
            pass += 1;
            total += 1;
            heap.push((pass_gain(pass, total), pass, total));
            extra_students -= 1;
        }

        let mut total_ratio = 0.0;
        while !heap.heap.is_empty() {
            let (_, pass, total) = heap.pop();
            total_ratio += pass as f64 / total as f64;
        }

        total_ratio / classes.len() as f64
    }
}

//sub: https://leetcode.com/problems/maximum-average-pass-ratio/submissions/1755422990/?envType=daily-question&envId=2025-09-01
//sol: https://leetcode.com/problems/maximum-average-pass-ratio/solutions/6147889/1792-maximum-average-pass-ratio8547-by-n-1zrb/

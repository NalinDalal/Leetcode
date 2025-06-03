//1298. Maximum Candies You Can Get from Boxes
use std::collections::VecDeque;
impl Solution {
    pub fn max_candies(
        status: Vec<i32>,
        candies: Vec<i32>,
        keys: Vec<Vec<i32>>,
        contained_boxes: Vec<Vec<i32>>,
        initial_boxes: Vec<i32>,
    ) -> i32 {
        let n = status.len();
        let mut has_box = vec![false; n];
        let mut has_key = vec![false; n];
        let mut visited = vec![false; n];
        let mut queue = VecDeque::new();

        for &box_id in &initial_boxes {
            let box_id = box_id as usize;
            has_box[box_id] = true;
            if status[box_id] == 1 {
                queue.push_back(box_id);
                visited[box_id] = true;
            }
        }

        let mut total_candies = 0;

        while let Some(curr) = queue.pop_front() {
            total_candies += candies[curr];

            // Collect keys
            for &key in &keys[curr] {
                let k = key as usize;
                if !has_key[k] {
                    has_key[k] = true;
                    if has_box[k] && !visited[k] {
                        queue.push_back(k);
                        visited[k] = true;
                    }
                }
            }

            // Collect contained boxes
            for &b in &contained_boxes[curr] {
                let b = b as usize;
                if !has_box[b] {
                    has_box[b] = true;
                    if (status[b] == 1 || has_key[b]) && !visited[b] {
                        queue.push_back(b);
                        visited[b] = true;
                    }
                } else if (status[b] == 1 || has_key[b]) && !visited[b] {
                    queue.push_back(b);
                    visited[b] = true;
                }
            }
        }

        total_candies
    }
}
//sub: https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/submissions/1652339368/
//sol: https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/solutions/6806277/1298-maximum-candies-you-can-get-from-bo-9k9p/

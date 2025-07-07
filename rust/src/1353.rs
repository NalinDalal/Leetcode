//1353. Maximum Number of Events That Can Be Attended
use std::cmp::Reverse;
use std::collections::BinaryHeap;

impl Solution {
    pub fn max_events(mut events: Vec<Vec<i32>>) -> i32 {
        // Sort by start time, then end time
        events.sort();

        let mut res = 0;
        let mut i = 0;
        let n = events.len();
        let mut day = 1;
        let last_day = events.iter().map(|e| e[1]).max().unwrap_or(0);
        let mut min_heap = BinaryHeap::new(); // min-heap via Reverse

        for day in 1..=last_day {
            // Add all events that start today
            while i < n && events[i][0] == day {
                min_heap.push(Reverse(events[i][1]));
                i += 1;
            }

            // Remove events that already ended
            while let Some(&Reverse(end)) = min_heap.peek() {
                if end < day {
                    min_heap.pop();
                } else {
                    break;
                }
            }

            // Attend one event (earliest end day)
            if !min_heap.is_empty() {
                min_heap.pop();
                res += 1;
            }
        }

        res
    }
}

//sub: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/submissions/1689680465/
//sol: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/solutions/6931541/1353-maximum-number-of-events-that-can-b-bcl7/

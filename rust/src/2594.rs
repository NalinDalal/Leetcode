//2594. Minimum Time to Repair Cars
use std::cmp::min;

impl Solution {
    pub fn repair_cars(ranks: Vec<i32>, cars: i32) -> i64 {
        let mut low: i64 = 1;
        let mut high: i64 = (ranks[0] as i64) * (cars as i64) * (cars as i64);
        let mut ans = high;

        while low <= high {
            let mid = low + (high - low) / 2;
            if Self::can_repair_all(&ranks, cars, mid) {
                ans = mid; // Update answer with the valid time
                high = mid - 1; // Try a smaller time
            } else {
                low = mid + 1; // Increase time
            }
        }

        ans
    }

    fn can_repair_all(ranks: &Vec<i32>, cars: i32, time: i64) -> bool {
        let mut repaired = 0;

        for &r in ranks {
            let max_cars = ((time as f64) / (r as f64)).sqrt() as i32; // n = sqrt(T / r)
            repaired += max_cars;
            if repaired >= cars {
                return true; // Early stopping
            }
        }

        repaired >= cars
    }
}
//sub: https://leetcode.com/problems/minimum-time-to-repair-cars/submissions/1575423383/?envType=daily-question&envId=2025-03-16
//sol: https://leetcode.com/problems/minimum-time-to-repair-cars/solutions/6542152/2594-minimum-time-to-repair-cars-by-nali-y13f/

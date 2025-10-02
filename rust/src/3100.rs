//3100. Water Bottles II
impl Solution {
    pub fn max_bottles_drunk(mut num_bottles: i32, mut num_exchange: i32) -> i32 {
        let mut total = 0;
        let mut empty = 0;

        while num_bottles > 0 {
            // Drink all current bottles
            total += num_bottles;
            empty += num_bottles;
            num_bottles = 0;

            // Exchange if possible
            if empty >= num_exchange {
                empty -= num_exchange; // spend empties
                num_bottles = 1;       // gain 1 full bottle
                num_exchange += 1;     // harder next time
            }
        }

        total
    }
}

//sub: https://leetcode.com/problems/water-bottles-ii/submissions/1789013413/?envType=daily-question&envId=2025-10-02
//sol: https://leetcode.com/problems/water-bottles-ii/solutions/7242122/3100-water-bottles-ii-by-nalindalal2004-1361/

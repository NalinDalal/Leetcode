//904. Fruit Into Baskets
use std::collections::HashMap;

impl Solution {
    pub fn total_fruit(fruits: Vec<i32>) -> i32 {
        let mut basket = HashMap::new();
        let (mut left, mut max_fruits) = (0, 0);

        for right in 0..fruits.len() {
            *basket.entry(fruits[right]).or_insert(0) += 1;

            while basket.len() > 2 {
                let left_fruit = fruits[left];
                if let Some(count) = basket.get_mut(&left_fruit) {
                    *count -= 1;
                    if *count == 0 {
                        basket.remove(&left_fruit);
                    }
                }
                left += 1;
            }

            max_fruits = max_fruits.max(right - left + 1);
        }

        max_fruits as i32
    }
}
//sub: https://leetcode.com/problems/fruit-into-baskets/submissions/1722459373/?envType=daily-question&envId=2025-08-04
//sol: https://leetcode.com/problems/fruit-into-baskets/solutions/7041213/904-fruit-into-baskets-by-nalindalal2004-84vz/

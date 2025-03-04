//846. Hand of Straights
use std::collections::BTreeMap;
impl Solution {
    pub fn is_n_straight_hand(mut hand: Vec<i32>, group_size: i32) -> bool {
        // If not divisible, return false immediately
        if hand.len() as i32 % group_size != 0 {
            return false;
        }

        hand.sort(); // Sort the hand

        let mut count = BTreeMap::new(); // To count occurrences of each card

        // Count occurrences of each card
        for &card in &hand {
            *count.entry(card).or_insert(0) += 1;
        }

        // Try to form groups
        for &card in &hand {
            if let Some(&freq) = count.get(&card) {
                if freq > 0 {
                    for i in 0..group_size {
                        let next_card = card + i;
                        if let Some(next_freq) = count.get_mut(&next_card) {
                            if *next_freq == 0 {
                                return false; // If any card is unavailable, return false
                            }
                            *next_freq -= 1; // Decrease the count of the card used
                        } else {
                            return false; // Card not found in the map
                        }
                    }
                }
            }
        }

        true // All groups of size group_size were successfully formed
    }
}
//sub: https://leetcode.com/problems/hand-of-straights/submissions/1562241797/
//sol: https://leetcode.com/problems/hand-of-straights/solutions/6493627/846-hand-of-straights-by-nalindalal2004-d5f5/

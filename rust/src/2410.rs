//2410. Maximum Matching of Players With Trainers

impl Solution {
    pub fn match_players_and_trainers(mut players: Vec<i32>, mut trainers: Vec<i32>) -> i32 {
        players.sort();
        trainers.sort();

        let (mut i, mut j) = (0, 0);
        let mut count = 0;

        while i < players.len() && j < trainers.len() {
            if players[i] <= trainers[j] {
                count += 1;
                i += 1;
                j += 1;
            } else {
                j += 1;
            }
        }

        count
    }
}
//sub: https://leetcode.com/problems/maximum-matching-of-players-with-trainers/submissions/1696608102/
//sol: https://leetcode.com/problems/maximum-matching-of-players-with-trainers/solutions/6954279/2410-maximum-matching-of-players-with-tr-dw65/

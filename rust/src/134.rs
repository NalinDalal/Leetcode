//134. Gas Station
impl Solution {
    pub fn can_complete_circuit(gas: Vec<i32>, cost: Vec<i32>) -> i32 {
        let n = gas.len();
        let mut total_tank = 0;
        let mut current_tank = 0;
        let mut start = 0;

        for i in 0..n {
            let diff = gas[i] - cost[i];
            total_tank += diff;
            current_tank += diff;

            if current_tank < 0 {
                // Can't reach the next station
                start = (i + 1) as i32; // Start from the next station
                current_tank = 0; // Reset the current tank
            }
        }

        if total_tank >= 0 {
            start
        } else {
            -1
        } // Corrected condition
    }
}

//sub: https://leetcode.com/problems/gas-station/submissions/1560988864/
//sol: https://leetcode.com/problems/gas-station/solutions/6488419/134-gas-station-by-nalindalal2004-n2ug/

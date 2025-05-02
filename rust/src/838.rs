//838. Push Dominoes

impl Solution {
    pub fn push_dominoes(dominoes: String) -> String {
        let n = dominoes.len();
        let mut forces = vec![0; n];
        let bytes = dominoes.as_bytes();
        let mut force = 0;

        // Left to right
        for i in 0..n {
            if bytes[i] == b'R' {
                force = n as i32;
            } else if bytes[i] == b'L' {
                force = 0;
            } else {
                force = (force - 1).max(0);
            }
            forces[i] += force;
        }

        // Right to left
        force = 0;
        for i in (0..n).rev() {
            if bytes[i] == b'L' {
                force = n as i32;
            } else if bytes[i] == b'R' {
                force = 0;
            } else {
                force = (force - 1).max(0);
            }
            forces[i] -= force;
        }

        // Construct final state
        forces
            .iter()
            .map(|&f| {
                if f > 0 {
                    'R'
                } else if f < 0 {
                    'L'
                } else {
                    '.'
                }
            })
            .collect()
    }
}
//sub: https://leetcode.com/problems/push-dominoes/submissions/1623260182/?envType=daily-question&envId=2025-05-02

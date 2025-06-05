//1061. Lexicographically Smallest Equivalent String
impl Solution {
    pub fn smallest_equivalent_string(s1: String, s2: String, base_str: String) -> String {
        let mut parent = (0..26).collect::<Vec<_>>();

        fn find(parent: &mut Vec<usize>, x: usize) -> usize {
            if parent[x] != x {
                parent[x] = find(parent, parent[x]);
            }
            parent[x]
        }

        fn union(parent: &mut Vec<usize>, x: usize, y: usize) {
            let px = find(parent, x);
            let py = find(parent, y);
            if px == py {
                return;
            }
            if px < py {
                parent[py] = px;
            } else {
                parent[px] = py;
            }
        }

        for (a, b) in s1.bytes().zip(s2.bytes()) {
            union(&mut parent, (a - b'a') as usize, (b - b'a') as usize);
        }

        base_str
            .bytes()
            .map(|c| {
                let rep = find(&mut parent, (c - b'a') as usize);
                (b'a' + rep as u8) as char
            })
            .collect()
    }
}
//sub: https://leetcode.com/problems/lexicographically-smallest-equivalent-string/submissions/1654656038/
//sol: https://leetcode.com/problems/lexicographically-smallest-equivalent-string/solutions/6813531/1061-lexicographically-smallest-equivalent-string/

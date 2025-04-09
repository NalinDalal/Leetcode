//433. Minimum Genetic Mutation
use std::collections::{HashSet, VecDeque};
impl Solution {
    pub fn min_mutation(start_gene: String, end_gene: String, bank: Vec<String>) -> i32 {
        let bank_set: HashSet<_> = bank.into_iter().collect();
        if !bank_set.contains(&end_gene) {
            return -1;
        }

        let mut queue = VecDeque::new();
        queue.push_back((start_gene.clone(), 0));
        let mut visited = HashSet::new();
        visited.insert(start_gene.clone());
        let chars = ['A', 'C', 'G', 'T'];

        while let Some((gene, steps)) = queue.pop_front() {
            if gene == end_gene {
                return steps;
            }

            let gene_chars: Vec<char> = gene.chars().collect();
            for i in 0..gene_chars.len() {
                for &c in &chars {
                    if c == gene_chars[i] {
                        continue;
                    }
                    let mut mutated = gene_chars.clone();
                    mutated[i] = c;
                    let mutated_str: String = mutated.iter().collect();

                    if bank_set.contains(&mutated_str) && !visited.contains(&mutated_str) {
                        visited.insert(mutated_str.clone());
                        queue.push_back((mutated_str, steps + 1));
                    }
                }
            }
        }

        -1
    }
}
//sub: https://leetcode.com/problems/minimum-genetic-mutation/submissions/1601176610/?envType=study-plan-v2&envId=top-interview-150
//sol: https://leetcode.com/problems/minimum-genetic-mutation/solutions/6631266/433-minimum-genetic-mutation-by-nalindal-hl9m/

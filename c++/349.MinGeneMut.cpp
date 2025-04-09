/* 433. Minimum Genetic Mutation

A gene string can be represented by an 8-character long string, with choices
from 'A', 'C', 'G', and 'T'.

Suppose we need to investigate a mutation from a gene string startGene to a gene
string endGene where one mutation is defined as one single character changed in
the gene string.

For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
There is also a gene bank bank that records all the valid gene mutations. A gene
must be in bank to make it a valid gene string.

Given the two gene strings startGene and endGene and the gene bank bank, return
the minimum number of mutations needed to mutate from startGene to endGene. If
there is no such a mutation, return -1.

Note that the starting point is assumed to be valid, so it might not be included
in the bank.



Example 1:
Input: startGene = "AACCGGTT", endGene = "AACCGGTA", bank = ["AACCGGTA"]
Output: 1

Example 2:
Input: startGene = "AACCGGTT", endGene = "AAACGGTA", bank =
["AACCGGTA","AACCGCTA","AAACGGTA"] Output: 2


Constraints:
0 <= bank.length <= 10
startGene.length == endGene.length == bank[i].length == 8
startGene, endGene, and bank[i] consist of only the characters ['A', 'C', 'G',
'T'].
*/

/*Intution
do i directly count the diff?
can’t just directly count the differences between startGene and endGene unless
every intermediate gene is present in the bank.

Apply BFS*/

/* Approach
1. Use BFS, starting from startGene.

2. At each step, try to mutate one character at a time to create a new gene.

3. If the new gene is in the bank and not visited yet, add it to the BFS queue.

4. Continue until you reach endGene.
*/

class Solution {
public:
  int minMutation(string startGene, string endGene, vector<string>& bank) {
    unordered_set<string> bankSet(bank.begin(), bank.end());
    if (!bankSet.count(endGene))
      return -1;

    queue<pair<string, int>> q;
    q.push({startGene, 0});
    unordered_set<string> visited = {startGene};
    vector<char> chars = {'A', 'C', 'G', 'T'};

    while (!q.empty()) {
      auto [gene, steps] = q.front();
      q.pop();
      if (gene == endGene)
        return steps;

      for (int i = 0; i < gene.size(); ++i) {
        char original = gene[i];
        for (char c : chars) {
          gene[i] = c;
          if (bankSet.count(gene) && !visited.count(gene)) {
            visited.insert(gene);
            q.push({gene, steps + 1});
          }
        }
        gene[i] = original;
      }
    }
    return -1;
  }
};
// sub:
// https://leetcode.com/problems/minimum-genetic-mutation/submissions/1601172923/?envType=study-plan-v2&envId=top-interview-150
// sol:
// https://leetcode.com/problems/minimum-genetic-mutation/solutions/6631266/433-minimum-genetic-mutation-by-nalindal-hl9m/

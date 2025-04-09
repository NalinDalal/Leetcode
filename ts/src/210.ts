//433. Minimum Genetic Mutation
function minMutation(
  startGene: string,
  endGene: string,
  bank: string[],
): number {
  const bankSet = new Set(bank);
  if (!bankSet.has(endGene)) return -1;

  const queue: [string, number][] = [[startGene, 0]];
  const visited = new Set<string>([startGene]);
  const chars = ["A", "C", "G", "T"];

  while (queue.length > 0) {
    const [gene, steps] = queue.shift()!;
    if (gene === endGene) return steps;

    for (let i = 0; i < gene.length; i++) {
      for (const c of chars) {
        const mutated = gene.slice(0, i) + c + gene.slice(i + 1);
        if (bankSet.has(mutated) && !visited.has(mutated)) {
          visited.add(mutated);
          queue.push([mutated, steps + 1]);
        }
      }
    }
  }

  return -1;
}
//sub: https://leetcode.com/problems/minimum-genetic-mutation/submissions/1601175571/?envType=study-plan-v2&envId=top-interview-150
//sol: https://leetcode.com/problems/minimum-genetic-mutation/solutions/6631266/433-minimum-genetic-mutation-by-nalindal-hl9m/

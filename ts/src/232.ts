//781. Rabbits in Forest
function numRabbits(answers: number[]): number {
  const count = new Map<number, number>();

  for (const a of answers) {
    count.set(a, (count.get(a) || 0) + 1);
  }

  let res = 0;
  for (const [x, freq] of count.entries()) {
    const groupSize = x + 1;
    const groups = Math.ceil(freq / groupSize);
    res += groups * groupSize;
  }

  return res;
}
//sub: https://leetcode.com/problems/rabbits-in-forest/submissions/1612122675/?envType=daily-question&envId=2025-04-20
//sol: https://leetcode.com/problems/rabbits-in-forest/solutions/6668763/781-rabbits-in-forest-by-nalindalal2004-7ha0/

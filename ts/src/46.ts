// 1046. Last Stone Weight

function lastStoneWeight(stones: number[]): number {
  while (stones.length > 1) {
    stones.sort((a, b) => b - a);

    let stone1: number = stones.shift();
    let stone2: number = stones.shift();

    if (stone1 !== stone2) {
      stones.push(Math.abs(stone2 - stone1));
    }
  }
  return stones.length === 1 ? stones[0] : 0;
}
//sub: https://leetcode.com/problems/last-stone-weight/submissions/1511245452/
//sol: https://leetcode.com/problems/last-stone-weight/solutions/6292985/1046-last-stone-weight100-by-nalindalal2-q8mf/

/*1. Sort the stones array in descending order on each turn to get the two heaviest stones.
2. Remove the two heaviest stones and "smash" them:
3. If they are equal, both are destroyed.
4. If they are not equal, push the difference back into the array.
5. Repeat until only one or no stone is left.*/

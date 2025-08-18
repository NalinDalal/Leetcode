//679. 24 Game
function judgePoint24(cards: number[]): boolean {
  const EPS = 1e-6;

  function compute(a: number, b: number): number[] {
    const res: number[] = [];
    res.push(a + b, a - b, b - a, a * b);
    if (Math.abs(b) > EPS) res.push(a / b);
    if (Math.abs(a) > EPS) res.push(b / a);
    return res;
  }

  function solve(nums: number[]): boolean {
    if (nums.length === 1) {
      return Math.abs(nums[0] - 24.0) < EPS;
    }

    for (let i = 0; i < nums.length; i++) {
      for (let j = i + 1; j < nums.length; j++) {
        const next: number[] = [];
        for (let k = 0; k < nums.length; k++) {
          if (k !== i && k !== j) next.push(nums[k]);
        }

        for (const val of compute(nums[i], nums[j])) {
          next.push(val);
          if (solve(next)) return true;
          next.pop();
        }
      }
    }
    return false;
  }

  return solve(cards.map(x => x * 1.0));
}

// Example usage:
console.log(judgePoint24([4, 1, 8, 7])); // true
console.log(judgePoint24([1, 2, 1, 2])); // false

//sub: https://leetcode.com/problems/24-game/submissions/1739113501/?envType=daily-question&envId=2025-08-18
//sol: https://leetcode.com/problems/24-game/solutions/7093821/679-24-game-by-nalindalal2004-s9c7/

//46. Permutations

import { ListNode } from "../typings/ListNode";
/**
 * Given a collection of distinct numbers, return all possible permutations.
 *
 * For example,
 * [1,2,31 have the following permutations:
 * [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 *
 * @param nums
 * Areturn
 */

function permute(nums: number[]): number[][] {
  const ans: number[][] = [];
  const temp: number[] = [];
  const used: boolean[] = new Array(nums.length).fill(false);

  function backtrack(): void {
    if (temp.length === nums.length) {
      ans.push([...temp]); // Store a copy of temp
      return;
    }

    for (let i = 0; i < nums.length; i++) {
      if (used[i]) continue;
      used[i] = true;
      temp.push(nums[i]);
      backtrack();
      temp.pop();
      used[i] = false;
    }
  }

  backtrack();
  return ans;
}

// Example usage
console.log(permute([1, 2, 3]));
//sub: https://leetcode.com/problems/permutations/submissions/1526658423/
//sol: https://leetcode.com/problems/permutations/solutions/6353246/46-permutations100-by-nalindalal2004-kwg8/

//80. Remove Duplicates from Sorted Array II
function removeDuplicates(nums: number[]): number {
  if (nums.length <= 2) return nums.length;
  let idx: number = 2;

  for (let i = 2; i < nums.length; i++) {
    if (nums[i] != nums[idx - 2]) nums[idx++] = nums[i];
  }

  return idx;
}
//sub: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/submissions/1606134492/?envType=study-plan-v2&envId=top-interview-150
//sol: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/solutions/6648352/80-remove-duplicates-from-sorted-array-i-dl4x/

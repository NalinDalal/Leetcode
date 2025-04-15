//35. Search Insert Position

function searchInsert(nums: number[], target: number): number {
  let left = 0,
    right = nums.length - 1;
  while (left <= right) {
    let mid = Math.floor(left + (right - left) / 2);
    if (nums[mid] == target) return mid;
    else if (nums[mid] > target) right = mid - 1;
    else left = mid + 1;
  }
  return left;
}
//sub: https://leetcode.com/problems/search-insert-position/submissions/1607110374/?envType=study-plan-v2&envId=top-interview-150
//sol: https://leetcode.com/problems/search-insert-position/solutions/6651841/35-search-insert-position-by-nalindalal2-2nib/

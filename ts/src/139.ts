//2570. Merge Two 2D Arrays by Summing Values
function mergeArrays(nums1: number[][], nums2: number[][]): number[][] {
  let result: number[][] = [];
  let i = 0,
    j = 0;

  while (i < nums1.length || j < nums2.length) {
    if (j >= nums2.length || (i < nums1.length && nums1[i][0] < nums2[j][0])) {
      result.push(nums1[i++]);
    } else if (
      i >= nums1.length ||
      (j < nums2.length && nums2[j][0] < nums1[i][0])
    ) {
      result.push(nums2[j++]);
    } else {
      result.push([nums1[i][0], nums1[i][1] + nums2[j][1]]);
      i++;
      j++;
    }
  }
  return result;
}

// Example usage
console.log(
  mergeArrays(
    [
      [1, 2],
      [2, 3],
      [4, 5],
    ],
    [
      [1, 4],
      [3, 2],
      [4, 1],
    ],
  ),
);
// Output: [[1,6],[2,3],[3,2],[4,6]]

//sub: https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/submissions/1560338245/?envType=daily-question&envId=2025-03-02
//sol: https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/solutions/6485941/2570-merge-two-2d-arrays-by-summing-valu-0vvh/

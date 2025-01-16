// 2425. Bitwise XOR of All Pairings

function xorAllNums(nums1: number[], nums2: number[]): number {
  let ans: number = 0;

  // If nums1 has an odd size, XOR all elements in nums2
  if (nums1.length % 2 === 1) {
    for (let num of nums2) {
      ans ^= num;
    }
  }

  // If nums2 has an odd size, XOR all elements in nums1
  if (nums2.length % 2 === 1) {
    for (let num of nums1) {
      ans ^= num;
    }
  }

  return ans;
}
//sub: https://leetcode.com/problems/bitwise-xor-of-all-pairings/submissions/1510159501/?envType=daily-question&envId=2025-01-16
//sol: https://leetcode.com/problems/bitwise-xor-of-all-pairings/solutions/6287685/2425-bitwise-xor-of-all-pairings100-by-n-39ga/

//1980. Find Unique Binary String
function findDifferentBinaryString(nums: string[]): string {
  let n: number = nums.length;
  let ans: string = "";
  for (let i = 0; i < n; i++) ans += nums[i][i] == "0" ? "1" : "0";
  return ans;
}
//sub: https://leetcode.com/problems/find-unique-binary-string/submissions/1549154483/?envType=daily-question&envId=2025-02-20
//sol: https://leetcode.com/problems/find-unique-binary-string/solutions/6444503/1980-find-unique-binary-string-by-nalind-5pwk/

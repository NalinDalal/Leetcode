//1524. Number of Sub-arrays With Odd Sum

function numOfSubarrays(arr: number[]): number {
  let oddCount = 0,
    evenCount = 1; // evenCount starts at 1 to handle empty subarray
  let sum = 0,
    result = 0;
  const MOD = 1e9 + 7;

  for (let num of arr) {
    sum += num;

    if (sum % 2 === 0) {
      result = (result + oddCount) % MOD;
      evenCount++;
    } else {
      result = (result + evenCount) % MOD;
      oddCount++;
    }
  }

  return result;
}

//sub: https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/submissions/1554443951/?envType=daily-question&envId=2025-02-25
//sol: https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/solutions/6464513/1524-number-of-sub-arrays-with-odd-sum-b-m1mc/

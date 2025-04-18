//38. Count and Say

function countAndSay(n: number): string {
  if (n === 1) return "1";

  const prev = countAndSay(n - 1);
  let result = "";
  let count = 1;

  for (let i = 1; i <= prev.length; i++) {
    if (i < prev.length && prev[i] === prev[i - 1]) {
      count++;
    } else {
      result += count.toString() + prev[i - 1];
      count = 1;
    }
  }

  return result;
}
//sub: https://leetcode.com/problems/count-and-say/submissions/1610131914/?envType=daily-question&envId=2025-04-18
//sol: https://leetcode.com/problems/count-and-say/solutions/6662271/38-count-and-say-by-nalindalal2004-tqmx/

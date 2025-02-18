//2375. Construct Smallest Number From DI String
function smallestNumber(pattern: string): string {
  let n: number = pattern.length;
  let result: string = "";
  let st: number[] = [];

  for (let i = 0; i <= n; i++) {
    // Push number (1-based index)
    st.push(i + 1);

    // When 'I' is encountered or at the end, pop elements from the stack
    if (i === n || pattern[i] === "I") {
      while (st.length > 0) {
        result += st.pop();
      }
    }
  }

  return result;
}
//sub: https://leetcode.com/problems/construct-smallest-number-from-di-string/submissions/1546861332/?envType=daily-question&envId=2025-02-18
//sol: https://leetcode.com/problems/construct-smallest-number-from-di-string/solutions/6435434/2375-construct-smallest-number-from-di-s-fvgl/

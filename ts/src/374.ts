//2197. Replace Non-Coprime Numbers in Array
function gcd(a: number, b: number): number {
  while (b !== 0) {
    let t = b;
    b = a % b;
    a = t;
  }
  return a;
}

function replaceNonCoprimes(nums: number[]): number[] {
  let st: number[] = [];
  for (let x of nums) {
    st.push(x);
    // keep merging while top two are not coprime
    while (st.length > 1) {
      let a = st.pop() as number;
      let b = st.pop() as number;
      let g = gcd(a, b);
      if (g === 1) {
        // coprime, stop merging
        st.push(b);
        st.push(a);
        break;
      } else {
        let l = (a / g) * b; // lcm
        st.push(l);
      }
    }
  }
  return st;
}

//sub: https://leetcode.com/problems/replace-non-coprime-numbers-in-array/submissions/1772182787/?envType=daily-question&envId=2025-09-16
//sol: https://leetcode.com/problems/replace-non-coprime-numbers-in-array/solutions/7194528/2197-replace-non-coprime-numbers-in-arra-c210/

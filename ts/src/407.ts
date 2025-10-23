//3461. Check If Digits Are Equal in String After Operations I
function hasSameDigits(s: string): boolean {
    while (s.length > 2) {
      let new_s = "";
      for (let i = 0; i < s.length - 1; i++) {
        const new_digit = ((+s[i] + +s[i + 1]) % 10).toString();
        new_s += new_digit;
      }
      s = new_s;
    }
    return s[0] === s[1];
};
//sub: https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i/submissions/1809239197/?envType=daily-question&envId=2025-10-23
//sol: https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i/solutions/7294408/3461-check-if-digits-are-equal-in-string-i6zz/

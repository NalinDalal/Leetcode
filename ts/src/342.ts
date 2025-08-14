//2264. Largest 3-Same-Digit Number in String
function largestGoodInteger(num: string): string {
     let ans = "";

        for (let i = 0; i + 2 < num.length; i++) {
            if (num[i] === num[i + 1] && num[i] === num[i + 2]) {
                const triplet = num.substring(i, i + 3);
                if (triplet > ans) {
                    ans = triplet;
                }
            }
        }

        return ans;
};
//sub: https://leetcode.com/problems/largest-3-same-digit-number-in-string/submissions/1734435516/?envType=daily-question&envId=2025-08-14
//sol: https://leetcode.com/problems/largest-3-same-digit-number-in-string/solutions/7077957/2264-largest-3-same-digit-number-in-stri-r0lp/

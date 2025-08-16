//1323. Maximum 69 Number
function maximum69Number (num: number): number {
    let s: string[] = num.toString().split(""); // make array of chars
    let ans: number = num;

    for (let i = 0; i < s.length; i++) {
        let original: string = s[i];

        // flip digit
        if (s[i] === '6') s[i] = '9';
        else if (s[i] === '9') s[i] = '6';

        let val: number = parseInt(s.join("")); // join back into string
        ans = Math.max(ans, val);

        s[i] = original; // restore
    }

    return ans;
};

function maximum69Number(num: number): number {
    return parseInt(num.toString().replace('6', '9'));
}

//sub: https://leetcode.com/problems/maximum-69-number/submissions/1736783770/?envType=daily-question&envId=2025-08-16
//sol: https://leetcode.com/problems/maximum-69-number/solutions/7086394/1323-maximum-69-number-by-nalindalal2004-6nqr/

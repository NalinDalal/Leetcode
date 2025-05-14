/* 3337. Total Characters in String After Transformations II
You are given a string s consisting of lowercase English letters, an integer t
representing the number of transformations to perform, and an array nums of
size 26. In one transformation, every character in s is replaced according to
the following rules:

Replace s[i] with the next nums[s[i] - 'a'] consecutive characters in the
alphabet. For example, if s[i] = 'a' and nums[0] = 3, the character 'a'
transforms into the next 3 consecutive characters ahead of it, which results in
"bcd". The transformation wraps around the alphabet if it exceeds 'z'. For
example, if s[i] = 'y' and nums[24] = 3, the character 'y' transforms into the
next 3 consecutive characters ahead of it, which results in "zab". Return the
length of the resulting string after exactly t transformations.

Since the answer may be very large, return it modulo 109 + 7.



Example 1:

Input: s = "abcyy", t = 2, nums =
[1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2]

Output: 7

Explanation:

First Transformation (t = 1):

'a' becomes 'b' as nums[0] == 1
'b' becomes 'c' as nums[1] == 1
'c' becomes 'd' as nums[2] == 1
'y' becomes 'z' as nums[24] == 1
'y' becomes 'z' as nums[24] == 1
String after the first transformation: "bcdzz"
Second Transformation (t = 2):

'b' becomes 'c' as nums[1] == 1
'c' becomes 'd' as nums[2] == 1
'd' becomes 'e' as nums[3] == 1
'z' becomes 'ab' as nums[25] == 2
'z' becomes 'ab' as nums[25] == 2
String after the second transformation: "cdeabab"
Final Length of the string: The string is "cdeabab", which has 7 characters.

Example 2:

Input: s = "azbk", t = 1, nums =
[2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2]

Output: 8

Explanation:

First Transformation (t = 1):

'a' becomes 'bc' as nums[0] == 2
'z' becomes 'ab' as nums[25] == 2
'b' becomes 'cd' as nums[1] == 2
'k' becomes 'lm' as nums[10] == 2
String after the first transformation: "bcabcdlm"
Final Length of the string: The string is "bcabcdlm", which has 8 characters.



Constraints:

1 <= s.length <= 105
s consists only of lowercase English letters.
1 <= t <= 109
nums.length == 26
1 <= nums[i] <= 25 */
/* tle code
while (t--) {
// apply transformation t times
// replace s[i] with next nums[s[i] - 'a'] consecutive characters
// if z is occurred, then wrap around a with places inclusive, like
// 2, then it will be come ab
// say y is with 3 so it will become zab
string next;
for (char c : s) {
int count = nums[c - 'a'];
for (int i = 1; i <= count; i++) {
  next.push_back('a' + (c - 'a' + i) % 26);
}
}
s = next;
}

return s.size();*/

/* use a freqArr
f(i,c)-> occurrences of the character c in the string after i transformations.
initially f(0,c)
f(i,c)=∑ c ′ =0 to 25​ [f(i−1,c ′ )×T(c,c ′)]
T(c,c`) is 0 or 1 which is independent of i
if c` is in c then 1 else 0
*/
static constexpr int L = 26;
static constexpr int mod = 1000000007;

struct Mat {
  Mat() { memset(a, 0, sizeof(a)); }
  Mat(const Mat& that) {
    for (int i = 0; i < L; ++i) {
      for (int j = 0; j < L; ++j) {
        a[i][j] = that.a[i][j];
      }
    }
  }
  Mat& operator=(const Mat& that) {
    if (this != &that) {
      for (int i = 0; i < L; ++i) {
        for (int j = 0; j < L; ++j) {
          a[i][j] = that.a[i][j];
        }
      }
    }
    return *this;
  }

  int a[L][L];
};

Mat operator*(const Mat& u, const Mat& v) {
  Mat w;
  for (int i = 0; i < L; ++i) {
    for (int j = 0; j < L; ++j) {
      for (int k = 0; k < L; ++k) {
        w.a[i][j] = (w.a[i][j] + (long long)u.a[i][k] * v.a[k][j]) % mod;
      }
    }
  }
  return w;
}

// identity matrix
Mat I() {
  Mat w;
  for (int i = 0; i < L; ++i) {
    w.a[i][i] = 1;
  }
  return w;
}

// matrix exponentiation by squaring
Mat quickmul(const Mat& x, int y) {
  Mat ans = I(), cur = x;
  while (y) {
    if (y & 1) {
      ans = ans * cur;
    }
    cur = cur * cur;
    y >>= 1;
  }
  return ans;
}

class Solution {
public:
  int lengthAfterTransformations(string s, int t, vector<int>& nums) {
    Mat T;
    for (int i = 0; i < 26; ++i) {
      for (int j = 1; j <= nums[i]; ++j) {
        T.a[(i + j) % 26][i] = 1;
      }
    }
    Mat res = quickmul(T, t);
    int ans = 0;
    vector<int> f(26);
    for (char ch : s) {
      ++f[ch - 'a'];
    }
    for (int i = 0; i < 26; ++i) {
      for (int j = 0; j < 26; ++j) {
        ans = (ans + (long long)res.a[i][j] * f[j]) % mod;
      }
    }
    return ans;
  }
};

// sub:
// https://leetcode.com/problems/total-characters-in-string-after-transformations-ii/submissions/1633451578/?envType=daily-question&envId=2025-05-14

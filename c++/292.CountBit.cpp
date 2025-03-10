/*338. Counting Bits

Given an integer n, return an array ans of length n + 1 such that for each i (0
<= i <= n), ans[i] is the number of 1's in the binary representation of i.



Example 1:
Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10

Example 2:
Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101


Constraints:0 <= n <= 105


Follow up:
It is very easy to come up with a solution with a runtime of O(n log n). Can you
do it in linear time O(n) and possibly in a single pass? Can you do it without
using any built-in function (i.e., like __builtin_popcount in C++)?*/

// Approach
/* class Solution {
public:
int count(int i){
    //no of one in binary representation of i
int ans=std::bitset<32> binary(i);
int ansStr=ans.to_string();
int count=0;
for(int i=0;i<n;i++){
    if(ansStr[i]==1) count++
}
return count;
}
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
for(int i=0;i<n+1;i++){
    //ans[i]= number of 1's in the binary representation of i
    ans[i]=count(i);
}
        return ans;
    }
};*/

class Solution {
public:
  vector<int> countBits(int n) {
    vector<int> ans(n + 1);
    for (int i = 0; i <= n; i++) {
      ans[i] = __builtin_popcount(i);
    }
    return ans;
  }
};
// sub: https://leetcode.com/problems/counting-bits/submissions/1568807683/
// sol:
// https://leetcode.com/problems/counting-bits/solutions/6519440/338-counting-bits-by-nalindalal2004-2qx2/

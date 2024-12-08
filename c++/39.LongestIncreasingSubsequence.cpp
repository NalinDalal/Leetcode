/*
 300. Longest Increasing Subsequence

Given an integer array nums, return the length of the longest strictly
increasing subsequence.

Example 1:
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the
length is 4.

Example 2:
Input: nums = [0,1,0,3,2,3]
Output: 4

Example 3:
Input: nums = [7,7,7,7,7,7,7]
Output: 1
*/

// first approach
/*
 class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int length=1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]){
                length++;
            }
        }
        return length;
    }
};
*/

// problem -> [10,9,2,5,3,7,101,18] length=0; o/p =3; expected=4
// nums ->[4,10,4,3,8,9] length=1;o/p=3;expected=3

/*
my approach is for subarray
we need to go for subsequence- [10,101], [9,2] etc

to generate subsequence(brute force) -> 2^n

can do via recursion->
1.explore everything in terms of index
2.explore all possibilities, either u pick or u don't
3.take max length(pick, not_pick)

f(ind, prev_ind)
f(0, -1) -> lengthOfLIS starting from 0 and prevIndex is -1

f(i, pI) -> lengthOfLIS starting from i and prevIndex is pI

len = 0 + / ( ind+1, prev-nd)   //not take condition
if(prev==-1 || arr[ind]>arr[prev-ind]){
length=1+j(ind+1,ind)   //take cpnditipn
return length;
}

Base Case->

Recursion -> Time Complexity: O(2^n)
            Space Complexity: O(n)

to optimise: there must be overlapping subproblem; hence memoise them

Ind             prevInd
0- (п-1)        (-1,->n-1)
{N] X           [N+1]

Time- O(n^2)
Space- O(n^2)
*/

// broke code
/*
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
int f(int ind, int prev_ind, int arr[], int n, vector<vector<int>> &dp) {
if(ind == n) return 0;
if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];
int len = 0 + f(ind+1, prev_ind, arr, n,dp);
if(prev_ind == -1 || arr[ind] > arr[prev_ind]) {
len = max(len, 1 + f(ind+1, ind, arr, n,dp));
}
return dp[ind][prev_ind+1]=len;
}
int longestIncreasingSubsequence (int arr[], int n)
{vector<vector<int>> dp(n, vector<int>(n+1, -1)) ;
return  f(0, -1, arr, n, dp);}

}};
*/

// correct code
class Solution {
public:
  int f(int ind, int prev_ind, vector<int>& arr, vector<vector<int>>& dp) {
    if (ind == arr.size())
      return 0;
    if (dp[ind][prev_ind + 1] != -1)
      return dp[ind][prev_ind + 1];

    int len = f(ind + 1, prev_ind, arr, dp); // Skip current element

    // Include current element if it's greater than the previous included
    // element
    if (prev_ind == -1 || arr[ind] > arr[prev_ind]) {
      len = max(len, 1 + f(ind + 1, ind, arr, dp));
    }

    return dp[ind][prev_ind + 1] = len;
  }

  int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return f(0, -1, nums, dp);
  }
};

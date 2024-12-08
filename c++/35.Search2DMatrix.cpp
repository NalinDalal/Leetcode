/*
 74. Search a 2D Matrix
Medium
Topics
Companies
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous
row. Given an integer target, return true if target is in matrix or false
otherwise.

You must write a solution in O(log(m * n)) time complexity.

Example 1:

Input: matrix =
[
    [1,3,5,7],
    [10,11,16,20],
    [23,30,34,60]
], target = 3
Output: true

Example 2:

Input: matrix =
[
    [1,3,5,7],
    [10,11,16,20],
    [23,30,34,60]
], target = 13
Output: false

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104

*/

/*
Solution Approach->
given a target return true if exist else false
basically a sorted matrix

Algorithm->
traverse the specific rows based on binary search
apply binary search here->
if (target<arr[i]){
searchMatrix(arr[i-1])
}
if(target==arr[i][i]){
return true
}
else{
return false
}
*/

/*
 Brute Force Algorithm:

We will use a loop(say i) to select a particular row at a time.
Next, for every row, we will use another loop(say j) to traverse each column.
Inside the loops, we will check if the element i.e. matrix[i][j] is equal to the
‘target’. If we find any matching element, we will return true. Otherwise, after
completing the traversal, we will return false.
    */

/*
 Better Approach:
 If the target lies between the first and last element of the row, i (i.e.
matrix[i][0] <= target && target <= matrix[i][m-1]), we can conclude that the
target might be present in that specific row.

Once we locate the potentially relevant row containing the 'target', we need to
confirm its presence. To accomplish this, we will utilize the Binary search
algorithm, effectively reducing the time complexity. Algorithm: We will use a
loop(say i) to select a particular row at a time. Next, for every row, i, we
will check if it contains the target. If matrix[i][0] <= target && target <=
matrix[i][m-1]: If this condition is met, we can conclude that row i has the
possibility of containing the target. So, we will apply binary search on row i,
and check if the ‘target’ is present. If it is present, we will return true from
this step. Otherwise, we will return false. Otherwise, after completing the
traversal, we will return false.

*/

/* Best Approach:
flatten the given 2D matrix to a 1D array, the 1D array will also be sorted.
Constraints overlooked, space complexity increases

convert the index of the 1D array into the corresponding cell number in the 2D
matrix

When comparing elements, we will convert the index to the cell number and
retrieve the element. Thus we can apply binary search in the imaginary 1D array.

Convert 2d array to 1d array->
If index = i, and no. of columns in the matrix = m, the index i corresponds to
the cell with row = i / m and col = i % m. More formally, the cell is (i / m, i
% m)(0-based indexing).

cell with index i and column m -> row=i/m;column=i%m-> cell=[i/m][i%m]

Algorithm:
- Place the 2 pointers i.e. low and high: Initially, we will place the pointers.
The pointer low will point to 0 and the high will point to (NxM)-1.

- Calculate the ‘mid’: Now, inside the loop, we will calculate the value of
‘mid’ using the following formula: mid = (low+high) // 2 ( ‘//’ refers to
integer division)

- Eliminate the halves based on the element at index mid: To get the element, we
will convert index ‘mid’ to the corresponding cell using the above formula. Here
no. of columns of the matrix = M. row = mid / M, col = mid % M.
    - If matrix[row][col] == target: We should return true here, as we have
found the ‘target’.
    - If matrix[row][col] < target: In this case, we need bigger elements. So,
we will eliminate the left half and consider the right half (low = mid+1).
    - If matrix[row][col] > target: In this case, we need smaller elements. So,
we will eliminate the right half and consider the left half (high = mid-1).

Steps 2-3 will be inside a while loop and the loop will end once low crosses
high (i.e. low > high). If we are out of the loop, we can say the target does
not exist in the matrix. So, we will return false.

*/

class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    int low = 0;
    int high = n * m - 1;

    while (low <= high) {
      int mid = (low + high) / 2;
      int row = mid / m, col = mid % m;

      if (matrix[row][col] == target)
        return true;
      else if (matrix[row][col] < target)
        low = mid + 1;
      else
        high = mid - 1;
    }
    return false;
  }
};

/*
 What is happening:
 get n,m where n is no of rows and m is no of column,
 set a low and high for binary search where low=0, high=n*m-1

 binary search on 2d array->
    mid=low+high/2
    row=mid/m,col=mid%m

    now first apply the binary search for rows that if it goes above the
 required one then it reverts back to previous else increases

    note we only want to check if the target exist or not
    hence every time we need to adjust only low and high

    if exist then return true
    else return false
*/

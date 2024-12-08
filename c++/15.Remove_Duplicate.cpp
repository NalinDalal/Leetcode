/*
26. Remove Duplicates from Sorted Array
Given an integer array nums sorted in non-decreasing order, remove the
duplicates in-place such that each unique element appears only once. The
relative order of the elements should be kept the same. Then return the number
of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you
need to do the following things:

Change the array nums such that the first k elements of nums contain the unique
elements in the order they were present in nums initially. The remaining
elements of nums are not important as well as the size of nums. Return k. Custom
Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.



Example 1:

Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of
nums being 1 and 2 respectively. It does not matter what you leave beyond the
returned k (hence they are underscores). Example 2:

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of
nums being 0, 1, 2, 3, and 4 respectively. It does not matter what you leave
beyond the returned k (hence they are underscores).

* */

// so what i was thinking->sort the array,
//     if nums (i) == nums(i + 1) then delete nums(i + 1),

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
      // my approach - check if besiding num are equal, if then remove
      if (nums[i] == nums[i + 1]) {
        int elementToRemove = nums[i + 1];
        // Remove the element using erase function and iterators
        auto it = std::find(nums.begin(), nums.end(), elementToRemove);
        // If element is found, erase it
        if (it != nums.end()) {
          nums.erase(it);
        }
      }
    }
    return nums.size();
  }
};

//     but this gets error b / c if it contains any element 3 or more time
// hence ditch this solution
// new solution ->
// it says that if the present element of array is not equal to previous then
// initialise it in new array in the end logs whole array

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int j = 1;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] != nums[i - 1]) {
        // says that the element is not equal to it's previous then
        // initialise it in new array
        nums[j] = nums[i];
        j++;
      }
    }
    return j;
  }
};

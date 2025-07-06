//1865. Finding Pairs With a Certain Sum
class FindSumPairs {
  private nums1: number[];
  private nums2: number[];
  private cnt: Map<number, number>;

  constructor(nums1: number[], nums2: number[]) {
    this.nums1 = nums1;
    this.nums2 = nums2;
    this.cnt = new Map();
    for (const num of nums2) {
      this.cnt.set(num, (this.cnt.get(num) || 0) + 1);
    }
  }

  add(index: number, val: number): void {
    const oldVal = this.nums2[index];
    this.cnt.set(oldVal, (this.cnt.get(oldVal) || 0) - 1);
    this.nums2[index] += val;
    const newVal = this.nums2[index];
    this.cnt.set(newVal, (this.cnt.get(newVal) || 0) + 1);
  }

  count(tot: number): number {
    let ans = 0;
    for (const num of this.nums1) {
      const rest = tot - num;
      ans += this.cnt.get(rest) || 0;
    }
    return ans;
  }
}

var obj = new FindSumPairs(nums1, nums2);
obj.add(index, val);
var param_2 = obj.count(tot);
//sub:
//https://leetcode.com/problems/finding-pairs-with-a-certain-sum/submissions/1688571069/?envType=daily-question&envId=2025-07-06
//sol: https://leetcode.com/problems/finding-pairs-with-a-certain-sum/solutions/6928087/1865-finding-pairs-with-a-certain-sum-by-itq6/

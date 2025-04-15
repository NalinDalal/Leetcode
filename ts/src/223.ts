//2179. Count Good Triplets in an Array
class Fenwick {
  private bit: number[];
  private n: number;

  constructor(size: number) {
    this.n = size + 1;
    this.bit = Array(this.n + 1).fill(0);
  }

  update(idx: number, delta: number): void {
    idx++;
    while (idx <= this.n) {
      this.bit[idx] += delta;
      idx += idx & -idx;
    }
  }

  query(idx: number): number {
    idx++;
    let res = 0;
    while (idx > 0) {
      res += this.bit[idx];
      idx -= idx & -idx;
    }
    return res;
  }

  rangeQuery(left: number, right: number): number {
    if (left > right) return 0;
    return this.query(right) - this.query(left - 1);
  }
}

function goodTriplets(nums1: number[], nums2: number[]): number {
  const n = nums1.length;
  const pos2 = Array(n);
  nums2.forEach((num, i) => (pos2[num] = i));

  const mapped = nums1.map((x) => pos2[x]);

  const bitLeft = new Fenwick(n);
  const bitRight = new Fenwick(n);

  const rightFreq = Array(n).fill(0);
  for (const x of mapped) {
    rightFreq[x]++;
  }

  for (let i = 0; i < n; i++) {
    if (rightFreq[i] > 0) {
      bitRight.update(i, rightFreq[i]);
    }
  }

  let res = 0;
  for (const mid of mapped) {
    bitRight.update(mid, -1);
    const leftCount = bitLeft.query(mid - 1);
    const rightCount =
      mid + 1 <= n - 1 ? bitRight.rangeQuery(mid + 1, n - 1) : 0;
    res += leftCount * rightCount;
    bitLeft.update(mid, 1);
  }

  return res;
}
//sub: https://leetcode.com/problems/count-good-triplets-in-an-array/submissions/1607121066/?envType=daily-question&envId=2025-04-15
//sol: https://leetcode.com/problems/count-good-triplets-in-an-array/solutions/6651868/2179-count-good-triplets-in-an-array-by-lpheo/

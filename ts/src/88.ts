//1726. Tuple with Same Product
function tupleSameProduct(nums: number[]): number {}

function tupleSameProduct(nums: number[]): number {
  if (nums.length < 4) return 0;

  const productCount = new Map<number, number>();
  let count: number = 0;

  // Compute all possible products
  for (let i = 0; i < nums.length; i++) {
    for (let j = i + 1; j < nums.length; j++) {
      let product: number = nums[i] * nums[j];
      // Count valid tuples
      // Use .get() method instead of direct object indexing
      count += 8 * (productCount.get(product) || 0);

      productCount.set(product, (productCount.get(product) || 0) + 1);
    }
  }

  return count;
}

//sub: https://leetcode.com/problems/tuple-with-same-product/submissions/1533255902/?envType=daily-question&envId=2025-02-06
//sol: https://leetcode.com/problems/tuple-with-same-product/solutions/6383461/1726-tuple-with-same-product100-by-nalin-jad2/

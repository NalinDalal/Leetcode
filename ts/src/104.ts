// 1352. Product of the Last K Numbers
class ProductOfNumbers {
  private prefix: number[];

  constructor() {
    this.prefix = [1]; // Initialize with 1 for multiplication identity
  }

  add(num: number): void {
    if (num === 0) {
      // Reset if 0 is added, as any product including 0 is 0
      this.prefix = [1];
    } else {
      // Multiply with the last prefix product
      this.prefix.push(this.prefix[this.prefix.length - 1] * num);
    }
  }

  getProduct(k: number): number {
    if (k >= this.prefix.length) {
      return 0; // If k exceeds stored products, it means a zero was added
    }
    return (
      this.prefix[this.prefix.length - 1] /
      this.prefix[this.prefix.length - k - 1]
    );
  }
}

// Example usage:
const productOfNumbers = new ProductOfNumbers();
productOfNumbers.add(3);
productOfNumbers.add(0);
productOfNumbers.add(2);
productOfNumbers.add(5);
productOfNumbers.add(4);
console.log(productOfNumbers.getProduct(2)); // 5 * 4 = 20
console.log(productOfNumbers.getProduct(3)); // 2 * 5 * 4 = 40

var obj = new ProductOfNumbers();
obj.add(num);
var param_2 = obj.getProduct(k);
//sub: https://leetcode.com/problems/product-of-the-last-k-numbers/submissions/1542626573/
//sol: https://leetcode.com/problems/product-of-the-last-k-numbers/solutions/6420822/1352-product-of-the-last-k-numbers-by-na-bfkc/

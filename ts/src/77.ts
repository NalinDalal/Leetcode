//380. Insert Delete GetRandom O(1)

class RandomizedSet {
  private set: Set<number>;

  constructor() {
    this.set = new Set<number>();
  }

  insert(val: number): boolean {
    if (!this.set.has(val)) {
      this.set.add(val);
      return true;
    } else {
      return false;
    }
  }

  remove(val: number): boolean {
    if (this.set.has(val)) {
      this.set.delete(val);
      return true;
    } else {
      return false;
    }
  }

  getRandom(): number {
    const items = Array.from(this.set);
    const randomIndex = Math.floor(Math.random() * items.length);
    return items[randomIndex];
  }
}

//Your RandomizedSet object will be instantiated and called as such:
var obj = new RandomizedSet();
var param_1 = obj.insert(val);
var param_2 = obj.remove(val);
var param_3 = obj.getRandom();
//sub: https://leetcode.com/problems/insert-delete-getrandom-o1/submissions/1527244078/
//sol: https://leetcode.com/problems/insert-delete-getrandom-o1/solutions/6356135/380-insert-delete-getrandom-o1-by-nalind-fzxg/

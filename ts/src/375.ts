//2353. Design a Food Rating System
class MyHeap<T> {
  private data: T[];
  private compare: (a: T, b: T) => number;

  constructor(compare: (a: T, b: T) => number) {
    this.data = [];
    this.compare = compare;
  }

  push(item: T): void {
    this.data.push(item);
    this.bubbleUp(this.data.length - 1);
  }

  pop(): T | undefined {
    if (this.size() === 0) return undefined;
    this.swap(0, this.data.length - 1);
    const item = this.data.pop();
    this.bubbleDown(0);
    return item;
  }

  peek(): T | undefined {
    return this.data[0];
  }

  size(): number {
    return this.data.length;
  }

  private bubbleUp(index: number): void {
    while (index > 0) {
      const parent = Math.floor((index - 1) / 2);
      if (this.compare(this.data[index], this.data[parent]) < 0) break;
      this.swap(index, parent);
      index = parent;
    }
  }

  private bubbleDown(index: number): void {
    const n = this.data.length;
    while (true) {
      let largest = index;
      const left = 2 * index + 1;
      const right = 2 * index + 2;

      if (left < n && this.compare(this.data[left], this.data[largest]) > 0) {
        largest = left;
      }
      if (right < n && this.compare(this.data[right], this.data[largest]) > 0) {
        largest = right;
      }
      if (largest === index) break;
      this.swap(index, largest);
      index = largest;
    }
  }

  private swap(i: number, j: number): void {
    [this.data[i], this.data[j]] = [this.data[j], this.data[i]];
  }
}

class FoodRatings {
  private foodInfo: Map<string, [string, number]>;
  private cuisineFoods: Map<string, MyHeap<[number, string]>>;

  constructor(foods: string[], cuisines: string[], ratings: number[]) {
    this.foodInfo = new Map();
    this.cuisineFoods = new Map();

    for (let i = 0; i < foods.length; i++) {
      const food = foods[i];
      const cuisine = cuisines[i];
      const rating = ratings[i];

      this.foodInfo.set(food, [cuisine, rating]);
      if (!this.cuisineFoods.has(cuisine)) {
        this.cuisineFoods.set(
          cuisine,
          new MyHeap<[number, string]>((a, b) => {
            if (a[0] !== b[0]) return a[0] - b[0];
            return b[1].localeCompare(a[1]);
          }),
        );
      }
      this.cuisineFoods.get(cuisine)!.push([rating, food]);
    }
  }

  changeRating(food: string, newRating: number): void {
    const [cuisine, _oldRating] = this.foodInfo.get(food)!;
    this.foodInfo.set(food, [cuisine, newRating]);
    this.cuisineFoods.get(cuisine)!.push([newRating, food]);
  }

  highestRated(cuisine: string): string {
    const heap = this.cuisineFoods.get(cuisine)!;
    while (true) {
      const [rating, food] = heap.peek()!;
      const [_c, currentRating] = this.foodInfo.get(food)!;
      if (rating === currentRating) {
        return food;
      }
      heap.pop(); // stale entry
    }
  }
}

//sub: https://leetcode.com/problems/design-a-food-rating-system/submissions/1773348432/?envType=daily-question&envId=2025-09-17
//sol: https://leetcode.com/problems/design-a-food-rating-system/solutions/7197850/2353-design-a-food-rating-system-by-nali-3m29/

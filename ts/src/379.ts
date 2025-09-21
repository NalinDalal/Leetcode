//1912. Design Movie Rental System
class CustomHeap<T> {
  private data: T[] = [];
  constructor(private cmp: (a: T, b: T) => number) {}

  size(): number {
    return this.data.length;
  }

  peek(): T | undefined {
    return this.data[0];
  }

  push(x: T) {
    this.data.push(x);
    this._siftUp(this.data.length - 1);
  }

  pop(): T | undefined {
    if (this.data.length === 0) return undefined;
    const top = this.data[0];
    const last = this.data.pop()!;
    if (this.data.length > 0) {
      this.data[0] = last;
      this._siftDown(0);
    }
    return top;
  }

  private _siftUp(i: number) {
    while (i > 0) {
      const p = (i - 1) >> 1;
      if (this.cmp(this.data[i], this.data[p]) < 0) {
        [this.data[i], this.data[p]] = [this.data[p], this.data[i]];
        i = p;
      } else break;
    }
  }

  private _siftDown(i: number) {
    const n = this.data.length;
    while (true) {
      let smallest = i;
      const l = 2 * i + 1,
        r = 2 * i + 2;
      if (l < n && this.cmp(this.data[l], this.data[smallest]) < 0)
        smallest = l;
      if (r < n && this.cmp(this.data[r], this.data[smallest]) < 0)
        smallest = r;
      if (smallest !== i) {
        [this.data[i], this.data[smallest]] = [
          this.data[smallest],
          this.data[i],
        ];
        i = smallest;
      } else break;
    }
  }
}

class MovieRentingSystem {
  private priceMap = new Map<string, number>();
  private stateMap = new Map<string, number>();
  private versionMap = new Map<string, number>();

  private available = new Map<number, CustomHeap<[number, number, number]>>();

  private rentedHeap = new CustomHeap<[number, number, number, number]>(
    (a, b) => {
      if (a[0] !== b[0]) return a[0] - b[0];
      if (a[1] !== b[1]) return a[1] - b[1];
      if (a[2] !== b[2]) return a[2] - b[2];
      return a[3] - b[3];
    },
  );

  constructor(n: number, entries: number[][]) {
    for (const [shop, movie, price] of entries) {
      const key = `${shop},${movie}`;
      this.priceMap.set(key, price);
      this.stateMap.set(key, 0);
      this.versionMap.set(key, 0);

      if (!this.available.has(movie)) {
        this.available.set(
          movie,
          new CustomHeap<[number, number, number]>((a, b) => {
            if (a[0] !== b[0]) return a[0] - b[0];
            if (a[1] !== b[1]) return a[1] - b[1];
            return a[2] - b[2];
          }),
        );
      }
      this.available.get(movie)!.push([price, shop, 0]);
    }
  }

  search(movie: number): number[] {
    const res: number[] = [];
    const heap = this.available.get(movie);
    if (!heap) return res;

    const temp: [number, number, number][] = [];

    while (res.length < 5 && heap.size() > 0) {
      const top = heap.pop()!;
      const [price, shop, ver] = top;
      const key = `${shop},${movie}`;
      const curVer = this.versionMap.get(key) ?? -1;
      const state = this.stateMap.get(key) ?? -1;

      if (state === 0 && ver === curVer) {
        res.push(shop);
        temp.push(top);
      } else {
        // stale or not currently unrented -> discard (lazy deletion)
      }
    }

    // reinsert popped valid entries (to keep heap intact)
    for (const item of temp) heap.push(item);
    return res;
  }

  rent(shop: number, movie: number): void {
    const key = `${shop},${movie}`;
    const price = this.priceMap.get(key)!;

    const newVer = (this.versionMap.get(key) ?? 0) + 1;
    this.versionMap.set(key, newVer);

    this.stateMap.set(key, 1);
    this.rentedHeap.push([price, shop, movie, newVer]);
  }

  drop(shop: number, movie: number): void {
    const key = `${shop},${movie}`;
    const price = this.priceMap.get(key)!;

    const newVer = (this.versionMap.get(key) ?? 0) + 1;
    this.versionMap.set(key, newVer);

    this.stateMap.set(key, 0);

    if (!this.available.has(movie)) {
      this.available.set(
        movie,
        new CustomHeap<[number, number, number]>((a, b) => {
          if (a[0] !== b[0]) return a[0] - b[0];
          if (a[1] !== b[1]) return a[1] - b[1];
          return a[2] - b[2];
        }),
      );
    }
    this.available.get(movie)!.push([price, shop, newVer]);
  }

  report(): number[][] {
    const res: number[][] = [];
    const temp: [number, number, number, number][] = [];

    while (res.length < 5 && this.rentedHeap.size() > 0) {
      const top = this.rentedHeap.pop()!;
      const [price, shop, movie, ver] = top;
      const key = `${shop},${movie}`;
      const curVer = this.versionMap.get(key) ?? -1;
      const state = this.stateMap.get(key) ?? -1;

      if (state === 1 && ver === curVer) {
        res.push([shop, movie]);
        temp.push(top);
      } else {
        // stale or not rented -> discard
      }
    }

    for (const item of temp) this.rentedHeap.push(item);
    return res;
  }
}
var obj = new MovieRentingSystem(n, entries);
var param_1 = obj.search(movie);
obj.rent(shop, movie);
obj.drop(shop, movie);
var param_4 = obj.report();
//sub: https://leetcode.com/problems/design-movie-rental-system/submissions/1777724333/?envType=daily-question&envId=2025-09-21
//sol: https://leetcode.com/problems/design-movie-rental-system/solutions/7209797/1912-design-movie-rental-system-by-nalin-jvgj/

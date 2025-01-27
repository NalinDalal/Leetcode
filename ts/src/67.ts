// 295. Find Median from Data Stream
class Heap {
  private data: number[];
  private comparator: (a: number, b: number) => boolean;

  constructor(comparator: (a: number, b: number) => boolean) {
    this.data = [];
    this.comparator = comparator;
  }

  size(): number {
    return this.data.length;
  }

  peek(): number | undefined {
    return this.data[0];
  }

  push(value: number): void {
    this.data.push(value);
    this.bubbleUp();
  }

  pop(): number | undefined {
    if (this.size() === 0) return undefined;

    const top = this.data[0];
    const last = this.data.pop();

    if (this.size() > 0 && last !== undefined) {
      this.data[0] = last;
      this.bubbleDown();
    }

    return top;
  }

  private bubbleUp(): void {
    let index = this.data.length - 1;

    while (
      index > 0 &&
      this.comparator(this.data[index], this.data[this.parent(index)])
    ) {
      this.swap(index, this.parent(index));
      index = this.parent(index);
    }
  }

  private bubbleDown(): void {
    let index = 0;

    while (this.leftChild(index) < this.data.length) {
      let target = this.leftChild(index);

      if (
        this.rightChild(index) < this.data.length &&
        this.comparator(this.data[this.rightChild(index)], this.data[target])
      ) {
        target = this.rightChild(index);
      }

      if (this.comparator(this.data[index], this.data[target])) break;

      this.swap(index, target);
      index = target;
    }
  }

  private parent(index: number): number {
    return Math.floor((index - 1) / 2);
  }

  private leftChild(index: number): number {
    return 2 * index + 1;
  }

  private rightChild(index: number): number {
    return 2 * index + 2;
  }

  private swap(i: number, j: number): void {
    [this.data[i], this.data[j]] = [this.data[j], this.data[i]];
  }
}

class MedianFinder {
  private maxHeap: Heap; // Max heap for the lower half
  private minHeap: Heap; // Min heap for the upper half

  constructor() {
    // MaxHeap for lower half (largest value at the top)
    this.maxHeap = new Heap((a, b) => a > b);

    // MinHeap for upper half (smallest value at the top)
    this.minHeap = new Heap((a, b) => a < b);
  }

  addNum(num: number): void {
    if (this.maxHeap.size() === 0 || num <= this.maxHeap.peek()!) {
      this.maxHeap.push(num);
    } else {
      this.minHeap.push(num);
    }

    // Balance the heaps
    if (this.maxHeap.size() > this.minHeap.size() + 1) {
      this.minHeap.push(this.maxHeap.pop()!);
    } else if (this.minHeap.size() > this.maxHeap.size()) {
      this.maxHeap.push(this.minHeap.pop()!);
    }
  }

  findMedian(): number {
    if (this.maxHeap.size() > this.minHeap.size()) {
      return this.maxHeap.peek()!;
    }

    return (this.maxHeap.peek()! + this.minHeap.peek()!) / 2;
  }
}

var obj = new MedianFinder();
obj.addNum(num);
var param_2 = obj.findMedian();

//sub: https://leetcode.com/problems/find-median-from-data-stream/submissions/1522318440/
//sol: https://leetcode.com/problems/find-median-from-data-stream/solutions/6336339/295-find-median-from-data-stream50-by-na-0cp1/

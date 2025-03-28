//2503. Maximum Number of Points From Grid Queries
class MinHeap {
  private heap: { value: number; x: number; y: number }[];

  constructor() {
    this.heap = [];
  }

  push(val: { value: number; x: number; y: number }) {
    this.heap.push(val);
    this.bubbleUp();
  }

  pop(): { value: number; x: number; y: number } | undefined {
    if (this.heap.length === 0) return undefined;
    if (this.heap.length === 1) return this.heap.pop();

    const min = this.heap[0];
    this.heap[0] = this.heap.pop()!;
    this.bubbleDown();
    return min;
  }

  peek(): { value: number; x: number; y: number } | undefined {
    return this.heap.length > 0 ? this.heap[0] : undefined;
  }

  isEmpty(): boolean {
    return this.heap.length === 0;
  }

  private bubbleUp() {
    let index = this.heap.length - 1;
    while (index > 0) {
      let parentIndex = Math.floor((index - 1) / 2);
      if (this.heap[parentIndex].value <= this.heap[index].value) break;
      [this.heap[parentIndex], this.heap[index]] = [
        this.heap[index],
        this.heap[parentIndex],
      ];
      index = parentIndex;
    }
  }

  private bubbleDown() {
    let index = 0;
    let length = this.heap.length;
    while (true) {
      let left = 2 * index + 1;
      let right = 2 * index + 2;
      let smallest = index;

      if (left < length && this.heap[left].value < this.heap[smallest].value) {
        smallest = left;
      }
      if (
        right < length &&
        this.heap[right].value < this.heap[smallest].value
      ) {
        smallest = right;
      }
      if (smallest === index) break;

      [this.heap[index], this.heap[smallest]] = [
        this.heap[smallest],
        this.heap[index],
      ];
      index = smallest;
    }
  }
}

function maxPoints(grid: number[][], queries: number[]): number[] {
  const m = grid.length,
    n = grid[0].length;
  const ans: number[] = new Array(queries.length).fill(0);
  const sortedQueries = queries
    .map((val, idx) => [val, idx])
    .sort((a, b) => a[0] - b[0]);

  const minHeap = new MinHeap();
  const visited = Array.from({ length: m }, () => new Array(n).fill(false));
  const directions = [
    [0, 1],
    [1, 0],
    [0, -1],
    [-1, 0],
  ];

  minHeap.push({ value: grid[0][0], x: 0, y: 0 });
  visited[0][0] = true;
  let count = 0;

  for (const [query, index] of sortedQueries) {
    while (!minHeap.isEmpty() && minHeap.peek()!.value < query) {
      let { value, x, y } = minHeap.pop()!;
      count++;

      for (const [dx, dy] of directions) {
        let nx = x + dx,
          ny = y + dy;
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
          visited[nx][ny] = true;
          minHeap.push({ value: grid[nx][ny], x: nx, y: ny });
        }
      }
    }
    ans[index] = count;
  }
  return ans;
}
//sub: https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/submissions/1588891563/?envType=daily-question&envId=2025-03-28
//sol: https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/solutions/6588563/2503-maximum-number-of-points-from-grid-804wd/

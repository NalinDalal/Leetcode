//778. Swim in Rising Water
function swimInWater(grid: number[][]): number {
  let n: number = grid.length;
  const directions = [
    [0, 1],
    [1, 0],
    [0, -1],
    [-1, 0],
  ]; // Right, Down, Left, Up
  const visited: boolean[][] = Array.from({ length: n }, () =>
    Array(n).fill(false),
  );

  // Min Heap (Priority Queue) -> [elevation, x, y]
  const pq = new MinHeap<[number, number, number]>((a, b) => a[0] - b[0]);
  pq.push([grid[0][0], 0, 0]); // Start at (0,0)
  visited[0][0] = true;

  let ans = 0;

  while (!pq.isEmpty()) {
    const [elevation, x, y] = pq.pop()!;
    ans = Math.max(ans, elevation); // Track max elevation in path

    // If reached the bottom-right corner
    if (x === n - 1 && y === n - 1) return ans;

    for (const [dx, dy] of directions) {
      const nx = x + dx,
        ny = y + dy;
      if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny]) {
        visited[nx][ny] = true;
        pq.push([grid[nx][ny], nx, ny]);
      }
    }
  }

  return -1; // Should never reach here
}

class MinHeap<T> {
  private heap: T[];
  private comparator: (a: T, b: T) => number;

  constructor(comparator: (a: T, b: T) => number) {
    this.heap = [];
    this.comparator = comparator;
  }

  push(value: T) {
    this.heap.push(value);
    this.bubbleUp();
  }

  pop(): T | undefined {
    if (this.heap.length === 0) return undefined;
    const top = this.heap[0];
    const last = this.heap.pop();
    if (this.heap.length > 0 && last !== undefined) {
      this.heap[0] = last;
      this.bubbleDown();
    }
    return top;
  }

  isEmpty(): boolean {
    return this.heap.length === 0;
  }

  private bubbleUp() {
    let index = this.heap.length - 1;
    while (index > 0) {
      const parentIndex = Math.floor((index - 1) / 2);
      if (this.comparator(this.heap[index], this.heap[parentIndex]) >= 0) break;
      [this.heap[index], this.heap[parentIndex]] = [
        this.heap[parentIndex],
        this.heap[index],
      ];
      index = parentIndex;
    }
  }

  private bubbleDown() {
    let index = 0;
    const length = this.heap.length;
    while (true) {
      const left = 2 * index + 1;
      const right = 2 * index + 2;
      let smallest = index;

      if (
        left < length &&
        this.comparator(this.heap[left], this.heap[smallest]) < 0
      ) {
        smallest = left;
      }
      if (
        right < length &&
        this.comparator(this.heap[right], this.heap[smallest]) < 0
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
//sub: https://leetcode.com/problems/swim-in-rising-water/submissions/1545719935/
//sol: https://leetcode.com/problems/swim-in-rising-water/solutions/6431445/778-swim-in-rising-water-by-nalindalal20-axwl/

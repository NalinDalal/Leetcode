//1353. Maximum Number of Events That Can Be Attended
class MinHeap {
  private data: number[] = [];

  private swap(i: number, j: number) {
    [this.data[i], this.data[j]] = [this.data[j], this.data[i]];
  }

  private up(i: number) {
    while (i > 0) {
      let p = Math.floor((i - 1) / 2);
      if (this.data[i] >= this.data[p]) break;
      this.swap(i, p);
      i = p;
    }
  }

  private down(i: number) {
    const n = this.data.length;
    while (true) {
      let left = 2 * i + 1,
        right = 2 * i + 2,
        smallest = i;
      if (left < n && this.data[left] < this.data[smallest]) smallest = left;
      if (right < n && this.data[right] < this.data[smallest]) smallest = right;
      if (smallest === i) break;
      this.swap(i, smallest);
      i = smallest;
    }
  }

  insert(val: number) {
    this.data.push(val);
    this.up(this.data.length - 1);
  }

  pop(): number | undefined {
    if (this.data.length === 0) return undefined;
    const top = this.data[0];
    const last = this.data.pop()!;
    if (this.data.length) {
      this.data[0] = last;
      this.down(0);
    }
    return top;
  }

  peek(): number | undefined {
    return this.data[0];
  }

  size(): number {
    return this.data.length;
  }
}

function maxEvents(events: number[][]): number {
  events.sort((a, b) => a[0] - b[0]);

  const n = events.length;
  let i = 0;
  let res = 0;
  let day = 1;
  let lastDay = Math.max(...events.map((e) => e[1]));
  const heap = new MinHeap();

  for (day = 1; day <= lastDay; day++) {
    // Add all events starting today
    while (i < n && events[i][0] === day) {
      heap.insert(events[i][1]);
      i++;
    }

    // Remove events that already expired
    while (heap.size() && heap.peek()! < day) {
      heap.pop();
    }

    // Attend one event
    if (heap.size()) {
      heap.pop();
      res++;
    }
  }

  return res;
}

//sub: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/submissions/1689678185/
//sol: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/solutions/6931541/1353-maximum-number-of-events-that-can-b-bcl7/

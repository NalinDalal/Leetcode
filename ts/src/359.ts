//1792. Maximum Average Pass Ratio
class MaxHeap {
  heap: [number, number, number][] = []; // [gain, pass, total]

  push(item: [number, number, number]) {
    this.heap.push(item);
    this.bubbleUp(this.heap.length - 1);
  }

  pop(): [number, number, number] {
    const top = this.heap[0];
    const last = this.heap.pop()!;
    if (this.heap.length > 0) {
      this.heap[0] = last;
      this.bubbleDown(0);
    }
    return top;
  }

  bubbleUp(i: number) {
    while (i > 0) {
      const parent = Math.floor((i - 1) / 2);
      if (this.heap[i][0] <= this.heap[parent][0]) break;
      [this.heap[i], this.heap[parent]] = [this.heap[parent], this.heap[i]];
      i = parent;
    }
  }

  bubbleDown(i: number) {
    const n = this.heap.length;
    while (true) {
      let largest = i;
      const left = 2 * i + 1;
      const right = 2 * i + 2;
      if (left < n && this.heap[left][0] > this.heap[largest][0])
        largest = left;
      if (right < n && this.heap[right][0] > this.heap[largest][0])
        largest = right;
      if (largest === i) break;
      [this.heap[i], this.heap[largest]] = [this.heap[largest], this.heap[i]];
      i = largest;
    }
  }
}

function maxAverageRatio(classes: number[][], extraStudents: number): number {
  const passGain = (pass: number, total: number) =>
    (pass + 1) / (total + 1) - pass / total;

  const heap = new MaxHeap();
  for (const [pass, total] of classes) {
    heap.push([passGain(pass, total), pass, total]);
  }

  while (extraStudents-- > 0) {
    let [_, pass, total] = heap.pop();
    pass++;
    total++;
    heap.push([passGain(pass, total), pass, total]);
  }

  let totalRatio = 0;
  while (heap.heap.length > 0) {
    const [_, pass, total] = heap.pop();
    totalRatio += pass / total;
  }

  return totalRatio / classes.length;
}
//sub: https://leetcode.com/problems/maximum-average-pass-ratio/submissions/1755412856/?envType=daily-question&envId=2025-09-01
//sol: https://leetcode.com/problems/maximum-average-pass-ratio/solutions/6147889/1792-maximum-average-pass-ratio8547-by-n-1zrb/

//3408. Design Task Manager
class TaskManager {
  private heap: { priority: number; taskId: number; userId: number }[] = [];
  private map: Map<number, [number, number]> = new Map();
  // taskId -> [userId, priority]

  constructor(tasks: number[][]) {
    for (const [userId, taskId, priority] of tasks) {
      this.add(userId, taskId, priority);
    }
  }

  add(userId: number, taskId: number, priority: number): void {
    this.map.set(taskId, [userId, priority]);
    this.push({ priority, taskId, userId });
  }

  edit(taskId: number, newPriority: number): void {
    const userId = this.map.get(taskId)![0];
    this.map.set(taskId, [userId, newPriority]);
    this.push({ priority: newPriority, taskId, userId });
  }

  rmv(taskId: number): void {
    this.map.delete(taskId);
  }

  execTop(): number {
    while (this.heap.length > 0) {
      const top = this.pop()!;
      const entry = this.map.get(top.taskId);
      if (entry && entry[0] === top.userId && entry[1] === top.priority) {
        this.map.delete(top.taskId);
        return top.userId;
      }
    }
    return -1;
  }

  // ---- Heap utilities ----
  private push(task: { priority: number; taskId: number; userId: number }) {
    this.heap.push(task);
    this.bubbleUp(this.heap.length - 1);
  }

  private pop():
    | { priority: number; taskId: number; userId: number }
    | undefined {
    if (this.heap.length === 0) return undefined;
    const top = this.heap[0];
    const end = this.heap.pop()!;
    if (this.heap.length > 0) {
      this.heap[0] = end;
      this.bubbleDown(0);
    }
    return top;
  }

  private bubbleUp(idx: number) {
    const element = this.heap[idx];
    while (idx > 0) {
      const parentIdx = Math.floor((idx - 1) / 2);
      const parent = this.heap[parentIdx];
      if (this.compare(parent, element) >= 0) break;
      this.heap[parentIdx] = element;
      this.heap[idx] = parent;
      idx = parentIdx;
    }
  }

  private bubbleDown(idx: number) {
    const length = this.heap.length;
    const element = this.heap[idx];
    while (true) {
      let leftIdx = 2 * idx + 1;
      let rightIdx = 2 * idx + 2;
      let swap = -1;

      if (leftIdx < length) {
        if (this.compare(this.heap[leftIdx], element) > 0) {
          swap = leftIdx;
        }
      }
      if (rightIdx < length) {
        if (
          (swap === -1 && this.compare(this.heap[rightIdx], element) > 0) ||
          (swap !== -1 &&
            this.compare(this.heap[rightIdx], this.heap[swap]) > 0)
        ) {
          swap = rightIdx;
        }
      }
      if (swap === -1) break;
      this.heap[idx] = this.heap[swap];
      this.heap[swap] = element;
      idx = swap;
    }
  }

  // Compare two tasks: higher priority wins; tie-break by higher taskId
  private compare(
    a: { priority: number; taskId: number },
    b: { priority: number; taskId: number },
  ): number {
    if (a.priority !== b.priority) return a.priority - b.priority;
    return a.taskId - b.taskId;
  }
}

function main() {
  var obj = new TaskManager(tasks);
  obj.add(userId, taskId, priority);
  obj.edit(taskId, newPriority);
  obj.rmv(taskId);
  var param_4 = obj.execTop();
}
//sub: https://leetcode.com/problems/design-task-manager/submissions/1774468038/?envType=daily-question&envId=2025-09-18
//sol: https://leetcode.com/problems/design-task-manager/solutions/7200925/3408-design-task-manager-by-nalindalal20-68sj/

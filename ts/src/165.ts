//2013. Detect Squares
class DetectSquares {
  private pointCounts: Map<number, Map<number, number>>;

  constructor() {
    this.pointCounts = new Map();
  }

  add(point: number[]): void {
    const [x, y] = point;
    if (!this.pointCounts.has(x)) {
      this.pointCounts.set(x, new Map());
    }
    const yMap = this.pointCounts.get(x)!;
    yMap.set(y, (yMap.get(y) || 0) + 1);
  }

  count(point: number[]): number {
    const [x, y] = point;
    let totalCount = 0;

    for (const [px, pyMap] of this.pointCounts) {
      if (px === x) continue; // Skip if same x-coordinate
      const dx = Math.abs(px - x);

      for (const [py, count] of pyMap) {
        if (Math.abs(py - y) === dx) {
          totalCount +=
            count *
            (pyMap.get(y) || 0) *
            (this.pointCounts.get(x)?.get(py) || 0);
        }
      }
    }

    return totalCount;
  }
}
//sub: https://leetcode.com/problems/detect-squares/submissions/1575402261/
//sol: https://leetcode.com/problems/detect-squares/solutions/6542076/2013-detect-squares-by-nalindalal2004-v3mc/

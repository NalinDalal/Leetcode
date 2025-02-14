//1584. Min Cost to Connect All Points

function find(parent: number[], i: number): number {
    if (parent[i] === i) return i;
    return (parent[i] = this.find(parent, parent[i]));
}

function unionNodes(parent: number[], rank: number[], i: number, j: number): void {
    const rootI = this.find(parent, i);
    const rootJ = this.find(parent, j);

    if (rootI !== rootJ) {
      if (rank[rootI] > rank[rootJ]) {
        parent[rootJ] = rootI;
      } else if (rank[rootI] < rank[rootJ]) {
        parent[rootI] = rootJ;
      } else {
        parent[rootJ] = rootI;
        rank[rootI]++;
      }
    }
}

  function minCostConnectPoints(points: number[][]): number {
    const n = points.length;
    const edges: [number, number, number][] = []; // [weight, point1, point2]

    // Constructing the edge list
    for (let i = 0; i < n; i++) {
      for (let j = i + 1; j < n; j++) {
        const dist = Math.abs(points[i][0] - points[j][0]) + Math.abs(points[i][1] - points[j][1]);
        edges.push([dist, i, j]);
      }
    }

    // Sort edges based on weight (distance)
    edges.sort((a, b) => a[0] - b[0]);

    // Union-Find structures
    const parent: number[] = Array.from({ length: n }, (_, i) => i);
    const rank: number[] = new Array(n).fill(0);

    let minCost = 0;
    let edgesUsed = 0;

    // Kruskal's algorithm to find MST
    for (const [weight, u, v] of edges) {
      if (this.find(parent, u) !== this.find(parent, v)) {
        this.unionNodes(parent, rank, u, v);
        minCost += weight;
        edgesUsed++;
        if (edgesUsed === n - 1) break; // MST has n-1 edges
      }
    }

    return minCost;
  }
}

const points = [
  [0, 0],
  [2, 2],
  [3, 10],
  [5, 2],
  [7, 0],
];
console.log(minCostConnectPoints(points)); // Expected Output: 20
//sub: https://leetcode.com/problems/min-cost-to-connect-all-points/submissions/1542571776/
//sol: https://leetcode.com/problems/min-cost-to-connect-all-points/solutions/6420620/1584-min-cost-to-connect-all-points-by-n-nbzn/

//399. Evaluate Division
const graph: Map<string, [string, number][]> = new Map();

function buildGraph(equations: string[][], values: number[]): void {
  graph.clear(); // Clear previous data when calling multiple times
  for (let i = 0; i < equations.length; i++) {
    const [A, B] = equations[i];
    const value = values[i];

    if (!graph.has(A)) graph.set(A, []);
    if (!graph.has(B)) graph.set(B, []);

    graph.get(A)!.push([B, value]);
    graph.get(B)!.push([A, 1 / value]);
  }
}

function dfs(src: string, dest: string, visited: Set<string>): number {
  if (!graph.has(src) || !graph.has(dest)) return -1.0;
  if (src === dest) return 1.0;

  visited.add(src);

  for (const [neighbor, weight] of graph.get(src)!) {
    if (!visited.has(neighbor)) {
      const res = dfs(neighbor, dest, visited);
      if (res !== -1.0) return res * weight;
    }
  }

  return -1.0;
}

function calcEquation(
  equations: string[][],
  values: number[],
  queries: string[][],
): number[] {
  buildGraph(equations, values);
  const results: number[] = [];

  for (const [A, B] of queries) {
    results.push(dfs(A, B, new Set()));
  }

  return results;
}

// Example usage:
const equations = [
  ["a", "b"],
  ["b", "c"],
];
const values = [2.0, 3.0];
const queries = [
  ["a", "c"],
  ["b", "a"],
  ["a", "e"],
  ["a", "a"],
  ["x", "x"],
];

console.log(calcEquation(equations, values, queries)); // Expected output: [6.0, 0.5, -1.0, 1.0, -1.0]
//sub: https://leetcode.com/problems/evaluate-division/submissions/1586280703/?envType=study-plan-v2&envId=top-interview-150
//sol: https://leetcode.com/problems/evaluate-division/solutions/6579905/399-evaluate-division-by-nalindalal2004-etf2/

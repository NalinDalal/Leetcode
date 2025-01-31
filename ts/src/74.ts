//2493. Divide Nodes Into the Maximum Number of Groups
function magnificentSets(n: number, edges: number[][]): number {
  let adjList: number[][] = new Array(n).fill(0).map(() => []);

  // Build adjacency list (convert to 0-indexed)
  for (let edge of edges) {
    adjList[edge[0] - 1].push(edge[1] - 1);
    adjList[edge[1] - 1].push(edge[0] - 1);
  }

  let colors: number[] = new Array(n).fill(-1);

  // Check if the graph is bipartite
  for (let node = 0; node < n; node++) {
    if (colors[node] !== -1) continue;
    colors[node] = 0;
    if (!isBipartite(adjList, node, colors)) return -1;
  }

  // Compute longest shortest path for each node
  let distances: number[] = new Array(n).fill(0);
  for (let node = 0; node < n; node++) {
    distances[node] = getLongestShortestPath(adjList, node, n);
  }

  // Calculate total maximum groups across all components
  let maxNumberOfGroups = 0;
  let visited: boolean[] = new Array(n).fill(false);
  for (let node = 0; node < n; node++) {
    if (visited[node]) continue;
    maxNumberOfGroups += getNumberOfGroupsForComponent(
      adjList,
      node,
      distances,
      visited,
    );
  }

  return maxNumberOfGroups;
}

// Function to check if the graph is bipartite
function isBipartite(
  adjList: number[][],
  node: number,
  colors: number[],
): boolean {
  for (let neighbor of adjList[node]) {
    if (colors[neighbor] === colors[node]) return false;
    if (colors[neighbor] !== -1) continue;
    colors[neighbor] = (colors[node] + 1) % 2;
    if (!isBipartite(adjList, neighbor, colors)) return false;
  }
  return true;
}

// Computes the longest shortest path (height) using BFS
function getLongestShortestPath(
  adjList: number[][],
  srcNode: number,
  n: number,
): number {
  let queue: number[] = [];
  let visited: boolean[] = new Array(n).fill(false);

  queue.push(srcNode);
  visited[srcNode] = true;
  let distance = 0;

  while (queue.length > 0) {
    let numOfNodesInLayer = queue.length;
    for (let i = 0; i < numOfNodesInLayer; i++) {
      let currentNode = queue.shift()!;
      for (let neighbor of adjList[currentNode]) {
        if (visited[neighbor]) continue;
        visited[neighbor] = true;
        queue.push(neighbor);
      }
    }
    distance++;
  }

  return distance;
}

// Calculates the maximum number of groups for a connected component
function getNumberOfGroupsForComponent(
  adjList: number[][],
  node: number,
  distances: number[],
  visited: boolean[],
): number {
  let maxNumberOfGroups = distances[node];
  visited[node] = true;

  for (let neighbor of adjList[node]) {
    if (visited[neighbor]) continue;
    maxNumberOfGroups = Math.max(
      maxNumberOfGroups,
      getNumberOfGroupsForComponent(adjList, neighbor, distances, visited),
    );
  }

  return maxNumberOfGroups;
}
//sub: https://leetcode.com/problems/divide-nodes-into-the-maximum-number-of-groups/submissions/1526634214/
//sol: https://leetcode.com/problems/divide-nodes-into-the-maximum-number-of-groups/solutions/6353159/2493-divide-nodes-into-the-maximum-numbe-ff9s/

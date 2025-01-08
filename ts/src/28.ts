// 547. Number of Provinces
function findCircleNum(isConnected: number[][]): number {
  let visited = new Array(isConnected.length).fill(0);
  let count = 0;
  for (let i = 0; i < visited.length; i++) {
    if (visited[i] == 0) {
      count++;
      dfs(i, isConnected, visited);
    }
  }
  return count;
}

function dfs(node: number, isConnected: number[][], visited: number[]) {
  visited[node] = 1;
  for (let i = 0; i < isConnected[node].length; i++) {
    if (isConnected[node][i] == 1 && visited[i] == 0) {
      dfs(i, isConnected, visited);
    }
  }
}

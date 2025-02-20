//787. Cheapest Flights Within K Stops
function findCheapestPrice(
  n: number,
  flights: number[][],
  src: number,
  dst: number,
  k: number,
): number {
  const INF = Number.MAX_SAFE_INTEGER;
  let cost: number[] = new Array(n).fill(INF);
  cost[src] = 0; // Starting point has 0 cost

  for (let i = 0; i <= k; i++) {
    let tempCost: number[] = [...cost]; // Create a temporary array for this iteration

    for (const flight of flights) {
      const [u, v, price] = flight;

      if (cost[u] !== INF && cost[u] + price < tempCost[v]) {
        tempCost[v] = cost[u] + price; // Relax the edge
      }
    }
    cost = tempCost; // Update cost array after processing all flights
  }

  return cost[dst] === INF ? -1 : cost[dst]; // If dst is unreachable, return -1
}
//sub: https://leetcode.com/problems/cheapest-flights-within-k-stops/submissions/1548588216/
//sol: https://leetcode.com/problems/cheapest-flights-within-k-stops/solutions/6442483/787-cheapest-flights-within-k-stops-by-n-jfo7/

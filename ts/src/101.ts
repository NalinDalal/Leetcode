//332. Reconstruct Itinerary
function findItinerary(tickets: string[][]): string[] {
  const flightGraph: Record<string, string[]> = {};
  const itinerary: string[] = [];

  // Build the adjacency list and sort destinations in descending order
  for (const [from, to] of tickets) {
    if (!flightGraph[from]) flightGraph[from] = [];
    flightGraph[from].push(to);
  }

  for (const airport in flightGraph) {
    flightGraph[airport].sort((a, b) => b.localeCompare(a)); // Sort in descending order
  }

  function dfs(airport: string) {
    const destinations = flightGraph[airport] || [];

    while (destinations.length > 0) {
      const nextDestination = destinations.pop()!; // Get the smallest lexicographical airport
      dfs(nextDestination);
    }
    itinerary.push(airport);
  }

  dfs("JFK");
  return itinerary.reverse(); // Reverse to get the correct order
}
//sub: https://leetcode.com/problems/reconstruct-itinerary/submissions/1541711023/
//sol: https://leetcode.com/problems/reconstruct-itinerary/solutions/6417694/332-reconstruct-itinerary-by-nalindalal2-qxnp/

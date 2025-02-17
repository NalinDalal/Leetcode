//1079. Letter Tile Possibilities

function numTilePossibilities(tiles: string): number {
  const sortedTiles = tiles.split("").sort().join("");
  const visited: boolean[] = new Array(tiles.length).fill(false);
  let count = 0;

  function backtrack(path: string): void {
    for (let i = 0; i < sortedTiles.length; i++) {
      if (visited[i]) continue; // Skip already used tile
      if (i > 0 && sortedTiles[i] === sortedTiles[i - 1] && !visited[i - 1])
        continue; // Skip duplicates

      visited[i] = true;
      count++;
      backtrack(path + sortedTiles[i]);
      visited[i] = false;
    }
  }

  backtrack("");
  return count;
}
//sub: https://leetcode.com/problems/letter-tile-possibilities/submissions/1545734170/?envType=daily-question&envId=2025-02-17
//sol: https://leetcode.com/problems/letter-tile-possibilities/solutions/6431483/1079-letter-tile-possibilities-by-nalind-clui/

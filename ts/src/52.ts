// 973. K Closest Points to Origin

function kClosest(points: number[][], k: number): number[][] {}
function kClosest(points: number[][], k: number): number[][] {
  // Calculate the distance for each point and sort them by distance
  points.sort((a, b) => {
    const distA = a[0] * a[0] + a[1] * a[1]; // squared distance
    const distB = b[0] * b[0] + b[1] * b[1]; // squared distance
    return distA - distB; // compare the distances
  });

  // Return the first k points
  return points.slice(0, k);
}

//sub: https://leetcode.com/problems/k-closest-points-to-origin/submissions/1513219728/
//sol: https://leetcode.com/problems/k-closest-points-to-origin/solutions/6301080/973-k-closest-points-to-origin985-by-nal-pcb7/

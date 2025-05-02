//838. Push Dominoes

function pushDominoes(dominoes: string): string {
  const n = dominoes.length;
  const forces = new Array<number>(n).fill(0);
  let force = 0;

  // Left to right
  for (let i = 0; i < n; i++) {
    if (dominoes[i] === "R") {
      force = n;
    } else if (dominoes[i] === "L") {
      force = 0;
    } else {
      force = Math.max(force - 1, 0);
    }
    forces[i] += force;
  }

  // Right to left
  force = 0;
  for (let i = n - 1; i >= 0; i--) {
    if (dominoes[i] === "L") {
      force = n;
    } else if (dominoes[i] === "R") {
      force = 0;
    } else {
      force = Math.max(force - 1, 0);
    }
    forces[i] -= force;
  }

  // Final result
  return forces.map((f) => (f > 0 ? "R" : f < 0 ? "L" : ".")).join("");
}
//sub: https://leetcode.com/problems/push-dominoes/submissions/1623259901/?envType=daily-question&envId=2025-05-02

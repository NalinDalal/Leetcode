//1432. Max Difference You Can Get From Changing an Integer
function maxDiff(num: number): number {
  const s = num.toString();

  // Maximize: replace first non-9 digit with 9
  let maxS = s.split("");
  let toReplace: string | null = null;

  for (const c of maxS) {
    if (c !== "9") {
      toReplace = c;
      break;
    }
  }

  if (toReplace !== null) {
    maxS = maxS.map((c) => (c === toReplace ? "9" : c));
  }
  const a = parseInt(maxS.join(""), 10);

  // Minimize
  let minS = s.split("");
  toReplace = null;

  if (minS[0] !== "1") {
    toReplace = minS[0];
    minS = minS.map((c) => (c === toReplace ? "1" : c));
  } else {
    for (let i = 1; i < minS.length; i++) {
      if (minS[i] !== "0" && minS[i] !== "1") {
        toReplace = minS[i];
        break;
      }
    }
    if (toReplace !== null) {
      minS = minS.map((c) => (c === toReplace ? "0" : c));
    }
  }

  const b = parseInt(minS.join(""), 10);

  return a - b;
}
//sub: https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/submissions/1664536394/?envType=daily-question&envId=2025-06-15
//sol: https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/solutions/6844775/1432-max-difference-you-can-get-from-cha-8swi/

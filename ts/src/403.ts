//1625. Lexicographically Smallest String After Applying Operations
function findLexSmallestString(s: string, a: number, b: number): string {
  const seen = new Set<string>();
  const queue: string[] = [s];
  let smallest = s;

  while (queue.length > 0) {
    const cur = queue.shift()!;
    if (cur < smallest) smallest = cur;

    // Operation 1: add 'a' to all digits at odd indices
    let addOp = cur.split("");
    for (let i = 1; i < addOp.length; i += 2) {
      let digit = (parseInt(addOp[i]) + a) % 10;
      addOp[i] = digit.toString();
    }
    const addStr = addOp.join("");
    if (!seen.has(addStr)) {
      seen.add(addStr);
      queue.push(addStr);
    }

    // Operation 2: rotate right by b positions
    const rotateStr = cur.slice(-b) + cur.slice(0, -b);
    if (!seen.has(rotateStr)) {
      seen.add(rotateStr);
      queue.push(rotateStr);
    }
  }

  return smallest;
}
//sub: https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/submissions/1805802117/?envType=daily-question&envId=2025-10-19
//sol: https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/solutions/7285898/1625-lexicographically-smallest-string-a-3fvv/

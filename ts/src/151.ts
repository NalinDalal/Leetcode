//763. Partition Labels
function partitionLabels(s: string): number[] {
  const lastIndex: number[] = new Array(26).fill(0);
  const result: number[] = [];

  // Step 1: Store last occurrence of each character
  for (let i = 0; i < s.length; i++) {
    lastIndex[s.charCodeAt(i) - 97] = i; // 'a' has ASCII code 97
  }

  // Step 2: Traverse and partition
  let start = 0,
    end = 0;
  for (let i = 0; i < s.length; i++) {
    end = Math.max(end, lastIndex[s.charCodeAt(i) - 97]);

    if (i === end) {
      result.push(end - start + 1);
      start = i + 1;
    }
  }

  return result;
}

//sub: https://leetcode.com/problems/partition-labels/submissions/1568045152/
//sol: https://leetcode.com/problems/partition-labels/solutions/6517178/763-partition-labels-by-nalindalal2004-98is/

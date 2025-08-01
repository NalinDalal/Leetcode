//118. Pascal's Triangle
function pascalTriangle(row: number): number[] {
let ans = 1;
    const ansRow: number[] = [1]; // First element is always 1

    for (let col = 1; col < row; col++) {
      ans = (ans * (row - col)) / col;
      ansRow.push(ans);
    }

    return ansRow;
  }

function  generate(N: number): number[][] {
    const result: number[][] = [];

    for (let i = 1; i <= N; i++) {
      result.push(pascalTriangle(i));
    }

    return result;
  }
//sub: https://leetcode.com/problems/pascals-triangle/submissions/1719136228/?envType=daily-question&envId=2025-08-01
//sol: https://leetcode.com/problems/pascals-triangle/solutions/7030943/118-pascals-triangle-by-nalindalal2004-2n8b/

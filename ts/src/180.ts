// 427. Construct Quad Tree

// Definition for _Node.
class _Node {
  val: boolean;
  isLeaf: boolean;
  topLeft: _Node | null;
  topRight: _Node | null;
  bottomLeft: _Node | null;
  bottomRight: _Node | null;
  constructor(
    val?: boolean,
    isLeaf?: boolean,
    topLeft?: _Node,
    topRight?: _Node,
    bottomLeft?: _Node,
    bottomRight?: _Node,
  ) {
    this.val = val === undefined ? false : val;
    this.isLeaf = isLeaf === undefined ? false : isLeaf;
    this.topLeft = topLeft === undefined ? null : topLeft;
    this.topRight = topRight === undefined ? null : topRight;
    this.bottomLeft = bottomLeft === undefined ? null : bottomLeft;
    this.bottomRight = bottomRight === undefined ? null : bottomRight;
  }
}

function construct(grid: number[][]): _Node | null {
  return build(grid, 0, 0, grid.length);
}

function build(grid: number[][], row: number, col: number, size: number): Node {
  if (size === 1) {
    return new Node(grid[row][col] === 1, true);
  }

  let isSame = true;
  let firstVal = grid[row][col];

  for (let i = row; i < row + size; i++) {
    for (let j = col; j < col + size; j++) {
      if (grid[i][j] !== firstVal) {
        isSame = false;
        break;
      }
    }
    if (!isSame) break;
  }

  if (isSame) {
    return new Node(firstVal === 1, true);
  }

  let newSize = size / 2;
  let topLeft = build(grid, row, col, newSize);
  let topRight = build(grid, row, col + newSize, newSize);
  let bottomLeft = build(grid, row + newSize, col, newSize);
  let bottomRight = build(grid, row + newSize, col + newSize, newSize);

  return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
}
//sub: https://leetcode.com/problems/construct-quad-tree/submissions/1583808829/?envType=study-plan-v2&envId=top-interview-150
//sol: https://leetcode.com/problems/construct-quad-tree/solutions/6571784/427-construct-quad-tree-by-nalindalal200-lkvk/

// 427. Construct Quad Tree#[derive(Debug)]
struct Node {
    val: bool,
    is_leaf: bool,
    top_left: Option<Box<Node>>,
    top_right: Option<Box<Node>>,
    bottom_left: Option<Box<Node>>,
    bottom_right: Option<Box<Node>>,
}

impl Node {
    fn new(val: bool, is_leaf: bool) -> Self {
        Node {
            val,
            is_leaf,
            top_left: None,
            top_right: None,
            bottom_left: None,
            bottom_right: None,
        }
    }
}

struct Solution;

impl Solution {
    pub fn construct(grid: Vec<Vec<i32>>) -> Option<Box<Node>> {
        Self::build(&grid, 0, 0, grid.len())
    }

    fn build(grid: &Vec<Vec<i32>>, row: usize, col: usize, size: usize) -> Option<Box<Node>> {
        if size == 1 {
            return Some(Box::new(Node::new(grid[row][col] == 1, true)));
        }

        let first_val = grid[row][col];
        let mut is_same = true;

        for i in row..row + size {
            for j in col..col + size {
                if grid[i][j] != first_val {
                    is_same = false;
                    break;
                }
            }
            if !is_same {
                break;
            }
        }

        if is_same {
            return Some(Box::new(Node::new(first_val == 1, true)));
        }

        let new_size = size / 2;
        let top_left = Self::build(grid, row, col, new_size);
        let top_right = Self::build(grid, row, col + new_size, new_size);
        let bottom_left = Self::build(grid, row + new_size, col, new_size);
        let bottom_right = Self::build(grid, row + new_size, col + new_size, new_size);

        Some(Box::new(Node {
            val: true,
            is_leaf: false,
            top_left,
            top_right,
            bottom_left,
            bottom_right,
        }))
    }
}

// Example Usage
fn main() {
    let grid = vec![
        vec![1, 1, 0, 0],
        vec![1, 1, 0, 0],
        vec![0, 0, 1, 1],
        vec![0, 0, 1, 1],
    ];

    let result = Solution::construct(grid);
    println!("{:?}", result);
}
//no snippet for rust, so no submission
//sol: https://leetcode.com/problems/construct-quad-tree/solutions/6571784/427-construct-quad-tree-by-nalindalal200-lkvk/

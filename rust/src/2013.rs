//2013. Detect Squares
use std::collections::HashMap;

struct DetectSquares {
    point_counts: HashMap<i32, HashMap<i32, i32>>,
}

impl DetectSquares {
    fn new() -> Self {
        DetectSquares {
            point_counts: HashMap::new(),
        }
    }

    fn add(&mut self, point: Vec<i32>) {
        let (x, y) = (point[0], point[1]);
        self.point_counts
            .entry(x)
            .or_insert_with(HashMap::new)
            .entry(y)
            .and_modify(|c| *c += 1)
            .or_insert(1);
    }

    fn count(&self, point: Vec<i32>) -> i32 {
        // Ensure count takes `&self`
        let (x, y) = (point[0], point[1]);
        let mut total_count = 0;

        for (&px, py_map) in &self.point_counts {
            if px == x {
                continue;
            }
            let dx = (px - x).abs();

            if let Some(py_map_x) = self.point_counts.get(&x) {
                if let Some(&count1) = py_map_x.get(&(y + dx)) {
                    if let Some(&count2) = py_map.get(&(y + dx)) {
                        if let Some(&count3) = py_map.get(&y) {
                            total_count += count1 * count2 * count3;
                        }
                    }
                }
                if let Some(&count1) = py_map_x.get(&(y - dx)) {
                    if let Some(&count2) = py_map.get(&(y - dx)) {
                        if let Some(&count3) = py_map.get(&y) {
                            total_count += count1 * count2 * count3;
                        }
                    }
                }
            }
        }

        total_count
    }
}
//sub: https://leetcode.com/problems/detect-squares/submissions/1575404954/
//sol: https://leetcode.com/problems/detect-squares/solutions/6542076/2013-detect-squares-by-nalindalal2004-v3mc/

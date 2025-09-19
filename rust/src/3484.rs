//3484. Design Spreadsheet
use std::collections::HashMap;

struct Spreadsheet {
    rows: usize,
    table: HashMap<String, i32>,
}

impl Spreadsheet {
    fn new(rows: usize) -> Self {
        Spreadsheet {
            rows: rows.try_into().unwrap(),
            table: HashMap::new(),
        }
    }

    fn set_cell(&mut self, cell: String, value: i32) {
        self.table.insert(cell, value);
    }

    fn reset_cell(&mut self, cell: String) {
        self.table.insert(cell, 0);
    }

    fn is_number(s: &str) -> bool {
        s.chars().all(|c| c.is_ascii_digit())
    }

    fn get_value(&mut self, formula: &str) -> i32 {
        if !formula.starts_with('=') {
            return 0;
        }
        let expr = &formula[1..];
        expr.split('+')
            .map(|token| {
                if Self::is_number(token) {
                    token.parse::<i32>().unwrap_or(0)
                } else {
                    *self.table.get(token).unwrap_or(&0)
                }
            })
            .sum()
    }
}

fn main() {
    let mut sheet = Spreadsheet::new(5);
    sheet.set_cell("A1".to_string(), 10);
    sheet.set_cell("B2".to_string(), 20);

    println!("{}", sheet.get_value("=A1+B2"));   // 30
    println!("{}", sheet.get_value("=A1+100"));  // 110

    sheet.reset_cell("A1".to_string());
    println!("{}", sheet.get_value("=A1+B2"));   // 20
}

//sub: https://leetcode.com/problems/design-spreadsheet/submissions/1775537756/?envType=daily-question&envId=2025-09-19
//sol: https://leetcode.com/problems/design-spreadsheet/solutions/7203828/3484-design-spreadsheet-by-nalindalal200-dqv9/

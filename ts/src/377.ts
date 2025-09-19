//3484. Design Spreadsheet
class Spreadsheet {
  private table: Map<string, number>;
  private rows: number;

  constructor(rows: number) {
    this.rows = rows;
    this.table = new Map();
  }

  setCell(cell: string, value: number): void {
    this.table.set(cell, value);
  }

  resetCell(cell: string): void {
    this.table.set(cell, 0);
  }

  private isNumber(s: string): boolean {
    return /^\d+$/.test(s);
  }

  getValue(formula: string): number {
    if (!formula.startsWith("=")) return 0;

    const expr = formula.slice(1);
    const parts = expr.split("+");
    let sum = 0;

    for (const part of parts) {
      if (this.isNumber(part)) {
        sum += parseInt(part, 10);
      } else {
        sum += this.table.get(part) ?? 0;
      }
    }
    return sum;
  }
}

// Your Spreadsheet object will be instantiated and called as such:
function main() {
  var obj = new Spreadsheet(rows);
  obj.setCell(cell, value);
  obj.resetCell(cell);
  var param_3 = obj.getValue(formula);
}
//sub: https://leetcode.com/problems/design-spreadsheet/submissions/1775535092/?envType=daily-question&envId=2025-09-19
//sol: https://leetcode.com/problems/design-spreadsheet/solutions/7203828/3484-design-spreadsheet-by-nalindalal200-dqv9/

//2043. Simple Bank System
class Bank {
  private balance: number[];
  private n: number;

  constructor(balance: number[]) {
    this.balance = balance;
    this.n = balance.length;
  }

  transfer(account1: number, account2: number, money: number): boolean {
    if (!this.isValid(account1) || !this.isValid(account2)) return false;
    if (this.balance[account1 - 1] < money) return false;

    this.balance[account1 - 1] -= money;
    this.balance[account2 - 1] += money;
    return true;
  }

  deposit(account: number, money: number): boolean {
    if (!this.isValid(account)) return false;
    this.balance[account - 1] += money;
    return true;
  }

  withdraw(account: number, money: number): boolean {
    if (!this.isValid(account)) return false;
    if (this.balance[account - 1] < money) return false;

    this.balance[account - 1] -= money;
    return true;
  }

  private isValid(account: number): boolean {
    return account >= 1 && account <= this.n;
  }
}

// Your Bank object will be instantiated and called as such:
var obj = new Bank(balance);
var param_1 = obj.transfer(account1, account2, money);
var param_2 = obj.deposit(account, money);
var param_3 = obj.withdraw(account, money);

//sub: https://leetcode.com/problems/simple-bank-system/submissions/1812363670/?envType=daily-question&envId=2025-10-26
//sol: https://leetcode.com/problems/simple-bank-system/solutions/7303230/2043-simple-bank-system-by-nalindalal200-x8av/

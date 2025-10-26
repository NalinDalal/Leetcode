//2043. Simple Bank System
struct Bank {
    balance: Vec<i64>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Bank {

    fn new(balance: Vec<i64>) -> Self {
        Self{balance}
    }

    fn is_valid(&self, account: i32) -> bool {
        account >= 1 && (account as usize) <= self.balance.len()
    }
    
    fn transfer(&self, account1: i32, account2: i32, money: i64) -> bool {
        if !self.is_valid(account1) || !self.is_valid(account2) {
            return false;
        }

        let i1 = (account1 - 1) as usize;
        let i2 = (account2 - 1) as usize;

        if self.balance[i1] < money {
            return false;
        }

        self.balance[i1] -= money;
        self.balance[i2] += money;
        true
    }
    
    fn deposit(&self, account: i32, money: i64) -> bool {
        if !self.is_valid(account) {
            return false;
        }

        let i = (account - 1) as usize;
        self.balance[i] += money;
        true
    }
    
    fn withdraw(&self, account: i32, money: i64) -> bool {
        if !self.is_valid(account) {
            return false;
        }

        let i = (account - 1) as usize;
        if self.balance[i] < money {
            return false;
        }

        self.balance[i] -= money;
        true
    }
}

 fn main(){ let obj = Bank::new(balance);
 let ret_1: bool = obj.transfer(account1, account2, money);
  let ret_2: bool = obj.deposit(account, money);
  let ret_3: bool = obj.withdraw(account, money);
}
//sub: https://leetcode.com/problems/simple-bank-system/submissions/1812356311/?envType=daily-question&envId=2025-10-26
//sol: https://leetcode.com/problems/simple-bank-system/solutions/7303230/2043-simple-bank-system-by-nalindalal200-x8av/

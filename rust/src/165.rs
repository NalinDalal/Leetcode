//165. Compare Version Numbers
impl Solution {
    pub fn compare_version(version1: String, version2: String) -> i32 {
        let v1: Vec<i32> = version1.split('.').map(|s| s.parse().unwrap()).collect();
        let v2: Vec<i32> = version2.split('.').map(|s| s.parse().unwrap()).collect();
        
        let n = v1.len().max(v2.len());
        
        for i in 0..n {
            let num1 = *v1.get(i).unwrap_or(&0);
            let num2 = *v2.get(i).unwrap_or(&0);
            
            if num1 < num2 {
                return -1;
            } else if num1 > num2 {
                return 1;
            }
        }
        
        0
    }
}

//sub: https://leetcode.com/problems/compare-version-numbers/submissions/1779797144/?envType=daily-question&envId=2025-09-23
//sol: https://leetcode.com/problems/compare-version-numbers/solutions/7215888/165-compare-version-numbers-by-nalindala-0200/

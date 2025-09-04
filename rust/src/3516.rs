//3516. Find Closest Person
impl Solution {
    pub fn find_closest(x: i32, y: i32, z: i32) -> i32 {
        let mut aDist:i32=(z-x).abs();
        let mut bDist:i32=(z-y).abs();

        if(aDist<bDist){ 1}
        else if(aDist>bDist){ 2}
        else {0}
    }
}
//sub: https://leetcode.com/problems/find-closest-person/submissions/1758945033/?envType=daily-question&envId=2025-09-04
//sol: https://leetcode.com/problems/find-closest-person/solutions/7153442/3516-find-closest-person-by-nalindalal20-d66w/

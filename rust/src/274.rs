//274. H-Index

impl Solution {
    pub fn h_index(mut citations: Vec<i32>) -> i32 {
    citations.sort_by(|a, b| b.cmp(a)); // Sort in descending order

    let mut i = 0;
    while i < citations.len() && citations[i] as usize >= i + 1 {
        i += 1;
    }

    i as i32
}
//sub: https://leetcode.com/problems/h-index/submissions/1590780869/?envType=study-plan-v2&envId=top-interview-150
    //sol: https://leetcode.com/problems/h-index/solutions/6594947/274-h-index-by-nalindalal2004-n3n6/

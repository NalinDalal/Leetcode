//3169. Count Days Without Meetings
impl Solution {
    fn count_days(days: i32, mut meetings: Vec<Vec<i32>>) -> i32 {
        if meetings.is_empty() {
            return days;
        }

        // Sort meetings by start day
        meetings.sort();

        let mut occupied_days = 0;
        let mut prev_end = 0;

        for meeting in meetings {
            let (start, end) = (meeting[0], meeting[1]);

            if start > prev_end + 1 {
                occupied_days += end - start + 1;
            } else {
                occupied_days += (end - prev_end).max(0);
            }

            prev_end = prev_end.max(end);
        }

        days - occupied_days
    }
}

// Example Usage
fn main() {
    let days = 10;
    let meetings = vec![vec![2, 3], vec![5, 6], vec![8, 10]];
    println!("{}", count_days(days, meetings)); // Output: Free days
}
//sub: https://leetcode.com/problems/count-days-without-meetings/submissions/1583819650/?envType=daily-question&envId=2025-03-24
//sol: https://leetcode.com/problems/count-days-without-meetings/solutions/6571831/3169-count-days-without-meetings-by-nali-tjjs/

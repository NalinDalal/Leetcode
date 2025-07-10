//3440. Reschedule Meetings for Maximum Free Time II
impl Solution {
    pub fn max_free_time(event_time: i32, start_time: Vec<i32>, end_time: Vec<i32>) -> i32 {
        let n = start_time.len();
        let mut q = vec![false; n];
        let mut t1 = 0;
        let mut t2 = 0;

        for i in 0..n {
            if end_time[i] - start_time[i] <= t1 {
                q[i] = true;
            }
            t1 = t1.max(start_time[i] - if i == 0 { 0 } else { end_time[i - 1] });

            let j = n - i - 1;
            if end_time[j] - start_time[j] <= t2 {
                q[j] = true;
            }
            t2 = t2.max(
                if i == 0 {
                    event_time
                } else {
                    start_time[n - i]
                } - end_time[j],
            );
        }

        let mut res = 0;
        for i in 0..n {
            let left = if i == 0 { 0 } else { end_time[i - 1] };
            let right = if i == n - 1 {
                event_time
            } else {
                start_time[i + 1]
            };

            if q[i] {
                res = res.max(right - left);
            } else {
                res = res.max(right - left - (end_time[i] - start_time[i]));
            }
        }

        res
    }
}
//sub: https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-ii/submissions/1692934423/?envType=daily-question&envId=2025-07-10
//sol: https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-ii/solutions/6942151/3440-reschedule-meetings-for-maximum-fre-r0s2/

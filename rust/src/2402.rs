//2402. Meeting Rooms III
impl Solution {
    pub fn most_booked(n: i32, mut meetings: Vec<Vec<i32>>) -> i32 {
        let n = n as usize;
        meetings.sort_by_key(|m| m[0]); // Step 2: sort by start time

        let mut room_availability_time = vec![0i64; n]; // Step 1: availability time for each room
        let mut meeting_count = vec![0; n]; // Step 1: meeting count per room

        for meeting in meetings {
            let start = meeting[0] as i64;
            let end = meeting[1] as i64;
            let duration = end - start;

            let mut assigned = false;

            // Step 3a: Try to find an available room
            for room in 0..n {
                if room_availability_time[room] <= start {
                    room_availability_time[room] = end;
                    meeting_count[room] += 1;
                    assigned = true;
                    break;
                }
            }

            // Step 3b: If no room is available, find the room with earliest availability
            if !assigned {
                let mut earliest_room = 0;
                for i in 1..n {
                    if room_availability_time[i] < room_availability_time[earliest_room] {
                        earliest_room = i;
                    }
                }

                room_availability_time[earliest_room] += duration;
                meeting_count[earliest_room] += 1;
            }
        }

        // Step 4: Find the room with the highest meeting count
        let mut max_room = 0;
        for i in 1..n {
            if meeting_count[i] > meeting_count[max_room] {
                max_room = i;
            }
        }

        max_room as i32
    }
}

//sub: https://leetcode.com/problems/meeting-rooms-iii/submissions/1694454151/?envType=daily-question&envId=2025-07-11
//sol: https://leetcode.com/problems/meeting-rooms-iii/solutions/6947194/2402-meeting-rooms-iii-by-nalindalal2004-1sc4/

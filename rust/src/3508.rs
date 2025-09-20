//3508. Implement Router
use std::collections::{HashSet, HashMap, VecDeque};

#[derive(Hash, Eq, PartialEq, Debug, Clone)]
struct Packet {
    source: i32,
    destination: i32,
    timestamp: i32,
}

struct Router {
    memory_limit: usize,
    packet_queue: VecDeque<Packet>,
    packet_set: HashSet<Packet>,
    destination_map: HashMap<i32, VecDeque<i32>>, // destination -> timestamps
}

/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */

impl Router {
    fn new(memory_limit: i32) -> Self {
        Self {
            memory_limit: memory_limit as usize,
            packet_queue: VecDeque::new(),
            packet_set: HashSet::new(),
            destination_map: HashMap::new(),
        }
    }

    fn add_packet(&mut self, source: i32, destination: i32, timestamp: i32) -> bool {
        let packet = Packet { source, destination, timestamp };

        if self.packet_set.contains(&packet) {
            return false;
        }

        if self.packet_queue.len() >= self.memory_limit {
            // Evict oldest
            if let Some(oldest) = self.packet_queue.pop_front() {
                self.packet_set.remove(&oldest);

                if let Some(timestamps) = self.destination_map.get_mut(&oldest.destination) {
                    if let Some(&front) = timestamps.front() {
                        if front == oldest.timestamp {
                            timestamps.pop_front();
                        }
                    }
                }
            }
        }

        // Insert new packet
        self.packet_queue.push_back(packet.clone());
        self.packet_set.insert(packet.clone());

        self.destination_map
            .entry(destination)
            .or_insert_with(VecDeque::new)
            .push_back(timestamp);

        true
    }

    fn forward_packet(&mut self) -> Vec<i32> {
        if let Some(packet) = self.packet_queue.pop_front() {
            self.packet_set.remove(&packet);

            if let Some(timestamps) = self.destination_map.get_mut(&packet.destination) {
                if let Some(&front) = timestamps.front() {
                    if front == packet.timestamp {
                        timestamps.pop_front();
                    }
                }
            }

            vec![packet.source, packet.destination, packet.timestamp]
        } else {
            vec![]
        }
    }

    fn get_count(&self, destination: i32, start_time: i32, end_time: i32) -> i32 {
        if let Some(timestamps) = self.destination_map.get(&destination) {
            // binary search lower_bound
            let lower = timestamps.partition_point(|&t| t < start_time);
            // binary search upper_bound
            let upper = timestamps.partition_point(|&t| t <= end_time);

            (upper - lower) as i32
        } else {
            0
        }
    }
}


/**
 * Your Router object will be instantiated and called as such:
 * let obj = Router::new(memoryLimit);
 * let ret_1: bool = obj.add_packet(source, destination, timestamp);
 * let ret_2: Vec<i32> = obj.forward_packet();
 * let ret_3: i32 = obj.get_count(destination, startTime, endTime);
 */
//sub: https://leetcode.com/problems/implement-router/submissions/1776662861/?envType=daily-question&envId=2025-09-20
//sol: https://leetcode.com/problems/implement-router/solutions/7207173/3508-implement-router-by-nalindalal2004-j8rr/

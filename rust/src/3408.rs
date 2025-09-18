//3408. Design Task Manager
use std::collections::{BinaryHeap, HashMap};
use std::cmp::Ordering;

#[derive(Eq, PartialEq, Debug, Clone)]
struct Task {
    priority: i32,
    task_id: i32,
    user_id: i32,
}

// Custom ordering for BinaryHeap (max-heap by priority, then task_id)
impl Ord for Task {
    fn cmp(&self, other: &Self) -> Ordering {
        if self.priority == other.priority {
            self.task_id.cmp(&other.task_id) // higher task_id wins
        } else {
            self.priority.cmp(&other.priority) // higher priority wins
        }
    }
}

impl PartialOrd for Task {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

struct TaskManager {
    heap: BinaryHeap<Task>,
    map: HashMap<i32, (i32, i32)>, // task_id -> (user_id, priority)
}

impl TaskManager {
    fn new(tasks: Vec<Vec<i32>>) -> Self {
        let mut tm = TaskManager {
            heap: BinaryHeap::new(),
            map: HashMap::new(),
        };
        for t in tasks {
            tm.add(t[0], t[1], t[2]);
        }
        tm
    }
    
    fn add(&mut self, user_id: i32, task_id: i32, priority: i32) {
        self.map.insert(task_id, (user_id, priority));
        self.heap.push(Task { priority, task_id, user_id });
    }
    
    fn edit(&mut self, task_id: i32, new_priority: i32) {
        if let Some(&(user_id, _)) = self.map.get(&task_id) {
            self.map.insert(task_id, (user_id, new_priority));
            self.heap.push(Task { priority: new_priority, task_id, user_id });
        }
    }
    
    fn rmv(&mut self, task_id: i32) {
        self.map.remove(&task_id);
    }
    
    fn exec_top(&mut self) -> i32 {
        while let Some(top) = self.heap.pop() {
            if let Some(&(cur_user, cur_priority)) = self.map.get(&top.task_id) {
                if cur_user == top.user_id && cur_priority == top.priority {
                    self.map.remove(&top.task_id);
                    return top.user_id;
                }
            }
        }
        -1
    }
}





fn main(){ let obj = TaskManager::new(tasks);
 obj.add(userId, taskId, priority);
  obj.edit(taskId, newPriority);
  obj.rmv(taskId);
  let ret_4: i32 = obj.exec_top();
}
//sub: https://leetcode.com/problems/design-task-manager/submissions/1774469065/?envType=daily-question&envId=2025-09-18
//sol: https://leetcode.com/problems/design-task-manager/solutions/7200925/3408-design-task-manager-by-nalindalal20-68sj/

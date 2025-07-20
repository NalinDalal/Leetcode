//1948. Delete Duplicate Folders in System
impl Solution {
    pub fn delete_duplicate_folder(paths: Vec<Vec<String>>) -> Vec<Vec<String>> {
        let mut root = TrieNode::new("");
        for path in &paths {
            root.insert(path);
        }

        let mut serial_map: HashMap<String, Vec<*mut TrieNode>> = HashMap::new();
        root.serialize(&mut serial_map);

        // Mark all duplicates
        for nodes in serial_map.values() {
            if nodes.len() > 1 {
                for &ptr in nodes {
                    unsafe {
                        (*ptr).marked = true;
                    }
                }
            }
        }

        let mut result = Vec::new();
        for child in root.children.values() {
            let mut path = Vec::new();
            child.collect(&mut path, &mut result);
        }

        result
    }
}

use std::collections::{BTreeMap, HashMap};

#[derive(Default)]
struct TrieNode {
    name: String,
    children: BTreeMap<String, TrieNode>,
    marked: bool,
}

impl TrieNode {
    fn new(name: &str) -> Self {
        Self {
            name: name.to_string(),
            children: BTreeMap::new(),
            marked: false,
        }
    }

    fn insert(&mut self, path: &[String]) {
        let mut node = self;
        for part in path {
            node = node
                .children
                .entry(part.clone())
                .or_insert_with(|| TrieNode::new(part));
        }
    }

    fn serialize(&mut self, map: &mut HashMap<String, Vec<*mut TrieNode>>) -> String {
        if self.children.is_empty() {
            return "()".to_string();
        }

        let mut serials = String::new();
        for (name, child) in &mut self.children {
            let sub_serial = child.serialize(map);
            serials.push_str(&format!("{}{}", name, sub_serial));
        }

        let full_serial = format!("({})", serials);
        let ptr: *mut TrieNode = self;
        map.entry(full_serial.clone()).or_default().push(ptr);
        full_serial
    }

    fn collect(&self, path: &mut Vec<String>, res: &mut Vec<Vec<String>>) {
        if self.marked {
            return;
        }

        if !self.name.is_empty() {
            path.push(self.name.clone());
            res.push(path.clone());
        }

        for child in self.children.values() {
            child.collect(path, res);
        }

        if !self.name.is_empty() {
            path.pop();
        }
    }
}
//sub: https://leetcode.com/problems/delete-duplicate-folders-in-system/submissions/1704561569/?envType=daily-question&envId=2025-07-20
//sol: https://leetcode.com/problems/delete-duplicate-folders-in-system/solutions/6981349/1948-delete-duplicate-folders-in-system-kw5ea/

//1233. Remove Sub-Folders from the Filesystem
impl Solution {
    pub fn remove_subfolders(folder: Vec<String>) -> Vec<String> {
        let mut folder = folder;
        folder.sort(); // Sort lexicographically

        let mut result: Vec<String> = Vec::new();

        for f in folder {
            if result.is_empty() || !f.starts_with(&(result.last().unwrap().to_string() + "/")) {
                result.push(f);
            }
        }

        result
    }
}

//sub: https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/submissions/1703048227/?envType=daily-question&envId=2025-07-19
//sol: https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/solutions/6976395/1233-remove-sub-folders-from-the-filesys-wxlo/

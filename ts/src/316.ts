//1233. Remove Sub-Folders from the Filesystem
function removeSubfolders(folder: string[]): string[] {
  folder.sort(); // sort folders lexicographically
  const result: string[] = [];

  for (let i = 0; i < folder.length; i++) {
    if (
      result.length === 0 ||
      !folder[i].startsWith(result[result.length - 1] + "/")
    ) {
      result.push(folder[i]);
    }
  }

  return result;
}
//sub: https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/submissions/1703045970/?envType=daily-question&envId=2025-07-19
//sol: https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/solutions/6976395/1233-remove-sub-folders-from-the-filesys-wxlo/

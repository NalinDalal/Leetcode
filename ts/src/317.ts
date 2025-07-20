//1948. Delete Duplicate Folders in System
class TrieNode {
  name: string;
  children: Map<string, TrieNode>;
  marked: boolean;

  constructor(name = "") {
    this.name = name;
    this.children = new Map();
    this.marked = false;
  }
}

function deleteDuplicateFolder(paths: string[][]): string[][] {
  const root = new TrieNode();
  const serialMap: Map<string, TrieNode[]> = new Map();

  // Step 1: Build Trie
  for (const path of paths) {
    let node = root;
    for (const folder of path) {
      if (!node.children.has(folder)) {
        node.children.set(folder, new TrieNode(folder));
      }
      node = node.children.get(folder)!;
    }
  }

  // Step 2: Serialize subtrees
  function serialize(node: TrieNode): string {
    if (node.children.size === 0) return "()";

    const serials: string[] = [];
    const keys = Array.from(node.children.keys()).sort();
    for (const key of keys) {
      const child = node.children.get(key)!;
      const subSerial = serialize(child);
      serials.push(key + subSerial);
    }

    const fullSerial = "(" + serials.join("") + ")";
    if (!serialMap.has(fullSerial)) {
      serialMap.set(fullSerial, []);
    }
    serialMap.get(fullSerial)!.push(node);
    return fullSerial;
  }

  serialize(root);

  // Step 3: Mark duplicates
  for (const nodes of serialMap.values()) {
    if (nodes.length > 1) {
      for (const node of nodes) {
        node.marked = true;
      }
    }
  }

  // Step 4: Collect valid paths
  const result: string[][] = [];

  function collect(node: TrieNode, path: string[]) {
    if (node.marked) return;

    if (node.name) path.push(node.name);
    if (node.name) result.push([...path]);

    for (const child of node.children.values()) {
      collect(child, path);
    }

    if (node.name) path.pop();
  }

  for (const child of root.children.values()) {
    collect(child, []);
  }

  return result;
}

//sub: https://leetcode.com/problems/delete-duplicate-folders-in-system/submissions/1704560536/?envType=daily-question&envId=2025-07-20
//sol: https://leetcode.com/problems/delete-duplicate-folders-in-system/solutions/6981349/1948-delete-duplicate-folders-in-system-kw5ea/

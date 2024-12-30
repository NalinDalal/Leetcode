//208. Implement Trie [Prefix Tree]

/**
 * Your Trie object will be instantiated and called as such:
 * var obj = new Trie()
 * obj.insert(word)
 * var param_2 = obj.search(word)
 * var param_3 = obj.startsWith(prefix)
 */

// Define the TrieNode class
class TrieNode {
  children: Array<TrieNode | null>;
  isEnd: boolean;

  constructor() {
    this.isEnd = false;
    this.children = new Array(26).fill(null);
  }
}

// Define the Trie class
class Trie {
  private root: TrieNode;

  constructor() {
    this.root = new TrieNode();
  }

  insert(word: string): void {
    let node = this.root;
    for (const char of word) {
      const index = char.charCodeAt(0) - "a".charCodeAt(0);
      if (node.children[index] === null) {
        node.children[index] = new TrieNode();
      }
      node = node.children[index]!;
    }
    node.isEnd = true;
  }

  search(word: string): boolean {
    let node = this.root;
    for (const char of word) {
      const index = char.charCodeAt(0) - "a".charCodeAt(0);
      if (node.children[index] === null) {
        return false;
      }
      node = node.children[index]!;
    }
    return node.isEnd;
  }

  startsWith(prefix: string): boolean {
    let node = this.root;
    for (const char of prefix) {
      const index = char.charCodeAt(0) - "a".charCodeAt(0);
      if (node.children[index] === null) {
        return false;
      }
      node = node.children[index]!;
    }
    return true;
  }
}

/**
 * Usage example:
 * const trie = new Trie();
 * trie.insert("apple");
 * console.log(trie.search("apple"));   // true
 * console.log(trie.search("app"));     // false
 * console.log(trie.startsWith("app")); // true
 * trie.insert("app");
 * console.log(trie.search("app"));     // true
 */

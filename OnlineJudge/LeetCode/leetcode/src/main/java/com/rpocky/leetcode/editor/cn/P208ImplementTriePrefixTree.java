//Trie（发音类似 "try"）或者说 前缀树 是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。这一数据结构有相当多的应用情景，例如自动补全和拼
//写检查。 
//
// 请你实现 Trie 类： 
//
// 
// Trie() 初始化前缀树对象。 
// void insert(String word) 向前缀树中插入字符串 word 。 
// boolean search(String word) 如果字符串 word 在前缀树中，返回 true（即，在检索之前已经插入）；否则，返回 
//false 。 
// boolean startsWith(String prefix) 如果之前已经插入的字符串 word 的前缀之一为 prefix ，返回 true ；否
//则，返回 false 。 
// 
//
// 
//
// 示例： 
//
// 
//输入
//["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
//[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
//输出
//[null, null, true, false, true, null, true]
//
//解释
//Trie trie = new Trie();
//trie.insert("apple");
//trie.search("apple");   // 返回 True
//trie.search("app");     // 返回 False
//trie.startsWith("app"); // 返回 True
//trie.insert("app");
//trie.search("app");     // 返回 True
// 
//
// 
//
// 提示： 
//
// 
// 1 <= word.length, prefix.length <= 2000 
// word 和 prefix 仅由小写英文字母组成 
// insert、search 和 startsWith 调用次数 总计 不超过 3 * 10⁴ 次 
// 
//
// Related Topics 设计 字典树 哈希表 字符串 👍 1767 👎 0

package com.rpocky.leetcode.editor.cn;

import java.util.HashSet;
import java.util.Set;

//Java：实现 Trie (前缀树)
public class P208ImplementTriePrefixTree {
    public static void main(String[] args) {
        // TO TEST
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Trie {
//        // 直观想法，完整的string存一份，所有前缀string存一份
//        private final Set<String> intactStrings = new HashSet<>();
//        private final Set<String> partStrings = new HashSet<>();
//
//        public Trie() {
//        }
//
//        public void insert(String word) {
//            intactStrings.add(word);
//            for (int i = 1; i <= word.length(); i++) {
//                partStrings.add(word.substring(0, i));
//            }
//        }
//
//        public boolean search(String word) {
//            return intactStrings.contains(word);
//        }
//
//        public boolean startsWith(String prefix) {
//            return partStrings.contains(prefix);
//        }

        // 本题实际要求建前缀树，那么每个树的节点都代表一个字母
        // 每个节点都有26个子节点，代表自己之后一个字母的26种可能性
        private final Trie[] nextCharacters;
        // 为了标记从根到这个点组成的字符串是插入的完整的字符串还是某个字符串的字串，需要一个标记
        private boolean isEnd;

        public Trie() {
            nextCharacters = new Trie[26];
            isEnd = false;
        }

        public void insert(String word) {
            // 遍历树，将字符串插入，最后一个点设为终点
            Trie current = this;
            for (int i = 0; i < word.length(); i++) {
                char c = word.charAt(i);
                if (current.nextCharacters[c - 'a'] == null) {
                    current.nextCharacters[c - 'a'] = new Trie();
                }
                current = current.nextCharacters[c - 'a'];
            }
            // 标记为终点
            current.isEnd = true;
        }

        /**
         * 判断prefix是否是前缀，是则返回遍历到的节点，否则返回null
         * 因为search只比startsWith多了最后的isEnd判断，而startsWith固定了返回boolean，所以创建一个中间方法来返回执行startsWith逻辑时遍历到的最后节点
         */
        private Trie getTrieAfterCheckStartsWith(String prefix) {
            Trie current = this;
            for (int i = 0; i < prefix.length(); i++) {
                char c = prefix.charAt(i);
                if (current.nextCharacters[c - 'a'] == null) {
                    return null;
                }
                current = current.nextCharacters[c - 'a'];
            }
            return current;
        }

        public boolean search(String word) {
            Trie t = getTrieAfterCheckStartsWith(word);
            return t != null && t.isEnd;
        }

        public boolean startsWith(String prefix) {
            Trie t = getTrieAfterCheckStartsWith(prefix);
            return t != null;
        }
    }

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */
//leetcode submit region end(Prohibit modification and deletion)

}

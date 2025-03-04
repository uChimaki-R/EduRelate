//给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。 
//
// 
// '.' 匹配任意单个字符 
// '*' 匹配零个或多个前面的那一个元素 
// 
//
// 所谓匹配，是要涵盖 整个 字符串 s 的，而不是部分字符串。 
//
// 示例 1： 
//
// 
//输入：s = "aa", p = "a"
//输出：false
//解释："a" 无法匹配 "aa" 整个字符串。
// 
//
// 示例 2: 
//
// 
//输入：s = "aa", p = "a*"
//输出：true
//解释：因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
// 
//
// 示例 3： 
//
// 
//输入：s = "ab", p = ".*"
//输出：true
//解释：".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 20 
// 1 <= p.length <= 20 
// s 只包含从 a-z 的小写字母。 
// p 只包含从 a-z 的小写字母，以及字符 . 和 *。 
// 保证每次出现字符 * 时，前面都匹配到有效的字符 
// 
//
// Related Topics 递归 字符串 动态规划 👍 3966 👎 0

package com.rpocky.leetcode.editor.cn;

import java.util.*;

//Java：正则表达式匹配
public class P10RegularExpressionMatching {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P10RegularExpressionMatching().new Solution();
        System.out.println(solution.isMatch("aa", "a"));
        System.out.println(solution.isMatch("aa", "a*"));
        System.out.println(solution.isMatch("ab", ".*"));
        System.out.println(solution.isMatch("mississippi", "mis*is*ip*."));
        // todo 加上NFA转DFA的逻辑估计可以快一点，加上DFA最小化应该更加，不过太麻烦了，NFA能过就算了
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        // 随便找个字符来当'.'表示的任意字符
        private final char any = 'Γ';
        // epsilon
        private final char epsilon = 'ε';

        // NFA点
        private static class Node {
            // 通过k到达的所有点的集合v
            public Map<Character, List<Node>> children = new HashMap<>();
        }

        // NFA
        private static class NFA {
            public NFA(Node st, Node ed) {
                this.st = st;
                this.ed = ed;
            }

            public Node st, ed;
        }

        /**
         * 求点的epsilon闭包
         */
        private Set<Node> epsilonClosures(Node node) {
            Set<Node> result = new HashSet<>();
            Queue<Node> queue = new LinkedList<>();
            queue.add(node);
            while (!queue.isEmpty()) {
                Node n = queue.remove();
                result.add(n);
                // 对出边为epsilon的终点集合入队继续判断
                queue.addAll(n.children.getOrDefault(epsilon, Collections.emptyList()));
            }
            return result;
        }

        /**
         * 获取节点集合输入字符c后到达的新的节点集合
         */
        private Set<Node> getNext(Set<Node> nodes, Character c) {
            Set<Node> result = new HashSet<>();
            Set<Node> temp1 = new HashSet<>();
            Set<Node> temp2 = new HashSet<>();
            // 先求epsilon闭包
            for (Node node : nodes) {
                temp1.addAll(epsilonClosures(node));
            }
            // 对每个点输入c/any
            for (Node n : temp1) {
                // 有c或者有any都行，将到达的点集加入temp2
                if (n.children.containsKey(c)) {
                    temp2.addAll(n.children.get(c));
                }
                if (n.children.containsKey(any)) {
                    temp2.addAll(n.children.get(any));
                }
            }
            // 对temp2再求epsilon闭包得到结果
            for (Node n : temp2) {
                result.addAll(epsilonClosures(n));
            }
            return result;
        }

        /**
         * 连接节点
         */
        private void addEdge(Node from, Node to, char with) {
            List<Node> children = from.children.getOrDefault(with, new ArrayList<>());
            children.add(to);
            from.children.put(with, children);
        }

        public boolean isMatch(String s, String p) {
            // 题目没有转义符号，没有括号，没有或、可选、正闭包等等其他东西，比编译原理项目简单很多（
            // 题目等价于有*和&两个个正则运算符号，需要考虑运算顺序
            // 先补充&运算，这里没有括号，只要后面不是*就可以加
            StringBuilder newStr = new StringBuilder();
            for (int i = 0; i < p.length(); i++) {
                newStr.append(p.charAt(i));
                if (i < p.length() - 1 && p.charAt(i + 1) != '*') {
                    newStr.append('&');
                }
            }
            p = newStr.toString();
            // 转后缀表达式，只用考虑*和&的优先级，肯定是*更高，而且没有括号，很多情况不需要考虑
            Queue<Character> suffix = getSuffix(p);
            // 生成NFA
            NFA nfa = generateNFA(suffix);
            // 就不转DFA了，直接使用NFA来解题，用epsilon闭包函数
            Set<Node> set = new HashSet<>();
            set.add(nfa.st);
            for (int i = 0; i < s.length(); i++) {
                set = getNext(set, s.charAt(i));
            }
            for (Node node : set) {
                // 可以到达终点
                if (node == nfa.ed) return true;
            }
            return false;
        }

        /**
         * 根据后缀表达式生成NFA
         */
        private NFA generateNFA(Queue<Character> suffix) {
            Stack<NFA> nfaStack = new Stack<>(); // NFA栈
            while (!suffix.isEmpty()) {
                Character c = suffix.poll();
                if (c == '*') {
                    NFA nfa = nfaStack.pop();
                    Node n1 = new Node();
                    Node n2 = new Node();
                    // n1是新起点，n2是新终点
                    // 连接n1到原来的起点
                    addEdge(n1, nfa.st, epsilon);
                    // 原来的终点连向新终点
                    addEdge(nfa.ed, n2, epsilon);
                    // *可以是0个字符，所以可以从 n1-->n2 直接跳过中间的NFA
                    addEdge(n1, n2, epsilon);
                    // *可以是1个及以上字符，需要在中间的NFA中循环
                    addEdge(nfa.ed, nfa.st, epsilon);
                    // 新NFA入栈
                    nfaStack.push(new NFA(n1, n2));
                } else if (c == '&') {
                    // left.st ... left.ed ---epsilon---> right.st ... right.ed (newEd)
                    // 先出栈的放右边，对于正则的&来说尤为重要
                    NFA right = nfaStack.pop();
                    NFA left = nfaStack.pop();
                    addEdge(left.ed, right.st, epsilon);
                    // 新NFA入栈
                    nfaStack.push(new NFA(left.st, right.ed));
                } else {
                    // 字符直接入栈
                    if (c == '.') {
                        // 匹配任意字符，替换为any标记
                        c = any;
                    }
                    // st ---c/any---> ed
                    Node n1 = new Node();
                    Node n2 = new Node();
                    addEdge(n1, n2, c);
                    NFA nfa = new NFA(n1, n2);
                    // 入栈
                    nfaStack.push(nfa);
                }
            }
            // 最后栈顶就是生成的NFA
            return nfaStack.pop();
        }

        /**
         * 将正则表达式转换为后缀表达式
         */
        private Queue<Character> getSuffix(String p) {
            Queue<Character> suffix = new LinkedList<>(); // 后缀表达式
            Stack<Character> stack = new Stack<>(); // 运算符栈
            for (int i = 0; i < p.length(); i++) {
                if (p.charAt(i) == '*') {
                    // *优先级最高直接入栈
                    stack.push('*');
                } else if (p.charAt(i) == '&') {
                    // 弹出优先级高于自己的到后缀表达式（只会是*）
                    while (!stack.isEmpty() && stack.peek() == '*') {
                        stack.pop();
                        suffix.add('*');
                    }
                    // 入栈
                    stack.push('&');
                } else {
                    // 字符直接入后缀表达式
                    suffix.add(p.charAt(i));
                }
            }
            // 最后把运算符全部到后缀表达式
            while (!stack.isEmpty()) {
                suffix.add(stack.pop());
            }
            return suffix;
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}

//
// 请你设计并实现一个满足 
// LRU (最近最少使用) 缓存 约束的数据结构。
// 
//
// 
// 实现 
// LRUCache 类：
// 
//
// 
// 
// 
// LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存 
// int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。 
// void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 
//key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。 
// 
// 
// 
//
// 函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。 
//
// 
//
// 示例： 
//
// 
//输入
//["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
//[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
//输出
//[null, null, null, 1, null, -1, null, -1, 3, 4]
//
//解释
//LRUCache lRUCache = new LRUCache(2);
//lRUCache.put(1, 1); // 缓存是 {1=1}
//lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
//lRUCache.get(1);    // 返回 1
//lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
//lRUCache.get(2);    // 返回 -1 (未找到)
//lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
//lRUCache.get(1);    // 返回 -1 (未找到)
//lRUCache.get(3);    // 返回 3
//lRUCache.get(4);    // 返回 4
// 
//
// 
//
// 提示： 
//
// 
// 1 <= capacity <= 3000 
// 0 <= key <= 10000 
// 0 <= value <= 10⁵ 
// 最多调用 2 * 10⁵ 次 get 和 put 
// 
//
// Related Topics 设计 哈希表 链表 双向链表 👍 3395 👎 0

package com.rpocky.leetcode.editor.cn;

import java.util.HashMap;
import java.util.Map;

//Java：LRU 缓存
public class P146LruCache {
    public static void main(String[] args) {
        // TO TEST
        LRUCache LRUCache = new P146LruCache().new LRUCache(1);
        LRUCache.put(2, 1);
        LRUCache.get(2);
        LRUCache.put(3, 2);
        LRUCache.get(2);
        LRUCache.get(3);
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class LRUCache {
        // 需要维护一个map和一个链表，链表存节点
        static class Node {
            Node prev, next;
            int key, value;
        }

        // 链表
        private final Node head = new Node();
        private final Node tail = new Node();

        {
            head.next = tail;
            tail.prev = head;
        }

        // map
        private final Map<Integer, Node> map = new HashMap<>();
        private final int capacity;

        public LRUCache(int capacity) {
            this.capacity = capacity;
        }

        public int get(int key) {
            if (!map.containsKey(key)) {
                return -1;
            }
            // 修改在链表的位置，放到头节点之后
            Node node = map.get(key);
            removeFromLinkedList(node);
            addToHead(node);
            return node.value;
        }

        private void removeFromLinkedList(Node node) {
            node.prev.next = node.next;
            node.next.prev = node.prev;
        }

        private void addToHead(Node node) {
            node.next = head.next;
            node.next.prev = node;
            node.prev = head;
            head.next = node;
        }

        private void addToTail(Node node) {
            node.prev = tail.prev;
            node.prev.next = node;
            node.next = tail;
            tail.prev = node;
        }

        public void put(int key, int value) {
            if (map.containsKey(key)) {
                Node node = map.get(key);
                node.value = value;
                removeFromLinkedList(node);
                addToHead(node);
                return;
            }
            // 创建节点
            if (map.size() == capacity) {
                Node lruNode = tail.prev;
                removeFromLinkedList(lruNode);
                map.remove(lruNode.key);
            }
            Node node = new Node();
            node.key = key;
            node.value = value;
            addToHead(node);
            map.put(key, node);
        }
    }

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
//leetcode submit region end(Prohibit modification and deletion)

}

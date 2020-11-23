/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU缓存机制
 */

// @lc code=start
class LRUCache {
public:
    map<int, int> m;
    deque<int> dq;
    int size;
    int cur_size;
    LRUCache(int capacity) {
        size = capacity;
        cur_size = 0;
    }
    
    int get(int key) {
        if (m.count(key) == 0) {
            return -1;
        }
        else {//也可以deque<pair<int, int>>存数据，哈希表value存index的位置
            for (auto it = dq.begin(); it != dq.end(); it++) {
                if (*it == key) {
                    dq.erase(it);
                    break;
                }
            }
            dq.push_front(key);
            return m[key];
        }
    }
    
    void put(int key, int value) {
        if (m.count(key) >= 1) {
            m[key] = value;
            for (auto it = dq.begin(); it != dq.end(); it++) {
                if (*it == key) {
                    dq.erase(it);
                    break;
                }
            }
            dq.push_front(key);
            return;
        }
        if (cur_size < size) {
            dq.push_front(key);
            m[key] = value;
            cur_size++;
        }
        else {
            m.erase(dq.back());
            dq.pop_back();
            dq.push_front(key);
            m[key] = value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end


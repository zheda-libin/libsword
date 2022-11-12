#include "base.h"


// 第一版本, 哈希map
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }

        unordered_map<Node*, Node*> map;
        Node *cur = head;
        while(cur) {
            map[cur] = new Node(cur->val);
            cur = cur->next;
        }

        cur = head;
        while(cur) {
            map[cur]->next = map[cur->next];
            map[cur]->random = map[cur->random];
            cur = cur->next;
        }

        return map[head];
    }
};


// 第二版本, 倍增,再拆分.
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head){
            return nullptr;
        }

        Node *cur = head, *tmp, *res;
        while(cur) {
            tmp = new Node(cur->val);
            tmp->next = cur->next;
            cur->next = tmp;
            cur = cur->next->next;
        }

        cur = head;
        while(cur){
            if (cur->random) {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }

        cur = head; 
        tmp = head->next; 
        res = head->next;
        // 这一步最难想, tmp->next本来就是next不需要处理，只需要处理此时的cur，将其next赋值为nullptr.
        while (tmp->next) {
            cur->next = cur->next->next;
            tmp->next = tmp->next->next;
            cur = cur->next;
            tmp = tmp->next;
        }
        cur->next = nullptr;
        return res;
    }
};

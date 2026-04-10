#include<iostream>
#include<vector>
#include<unordered_map>


using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr){
            return nullptr;
        }

        //建立 < 原节点 -> 新节点 > 的 Map 映射
        unordered_map<Node*, Node*> m;
        Node* cur = head;
        while(cur != nullptr){
            Node* temp = new Node(cur->val);
            m.insert(pair<Node*, Node*>(cur, temp));
            cur = cur->next;
        }

        cur = head;
        while(cur != nullptr){
            m[cur]->next = m[cur->next];
            m[cur]->random = m[cur->random];
            cur = cur->next;
        }

        return m[head];
    }
};

int main(){


    return 0;
}
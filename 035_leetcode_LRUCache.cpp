#include<iostream>
#include<vector>
#include<unordered_map>


using namespace std;

struct Node {
    int key;
    int val;
    Node *next;
    Node *prev;
    Node() : key(0), val(0), next(nullptr), prev(nullptr) {}
    Node(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
};

class LRUCache {
public:
    LRUCache(int capacity) {
        this->cap = capacity;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if(m.count(key) == 1){
            Node* temp = m[key];

            temp->next->prev = temp->prev;      //将节点移动至表头（最近访问过）
            temp->prev->next = temp->next;
            temp->next = head->next;
            temp->prev = head;
            head->next = temp;
            temp->next->prev = temp;

            return temp->val;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(m.count(key) == 1){                  //key存在，则变更其value
            Node* temp = m[key];
            m[key]->val = value;
            
            temp->next->prev = temp->prev;      //将节点移动至表头（最近访问过）
            temp->prev->next = temp->next;
            temp->next = head->next;
            temp->prev = head;
            head->next = temp;
            temp->next->prev = temp;
        }else{                                  //key不存在，添加value
            Node* temp = new Node(key, value);
                
            temp->next = head->next;            //将节点添加至表头
            temp->prev = head;
            head->next = temp;
            temp->next->prev = temp;
            m[key] = temp;                      //更新哈希表

            if(m.size() > cap){                 //缓存已满，移除链表尾节点
                Node* n = tail->prev;
                n->next->prev = n->prev;
                n->prev->next = n->next;
                m.erase(n->key);                //更新哈希表
                delete n;                       //防止内存泄漏
            }
        }
        return;
    }

private:
    unordered_map<int, Node*> m;
    int cap;
    Node* head;
    Node* tail;
};

int main(){


    return 0;
}
#include<iostream>
#include<vector>


using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* f = head;
        ListNode* s = head;
        
        while(f != nullptr && f->next != nullptr){
            s = s->next;
            f = f->next->next;
            if(f == s){
                break;
            }
        }
        if(f == nullptr || f->next == nullptr){
            return nullptr;
        }
        //快慢指针第一次相遇
        //f 走的步数是 s 步数的 2 倍 f = 2s
        //f 比 s 多走了 n 个环的长度 f = s + nb（b为环的节点数）
        //由上面两式得到 s = nb

        //快慢指针第二次相遇
        //到链表入口节点需要的步数是 a + nb（a为链表头部到环入口的节点数）
        //s 需要再走 a 步，即可到达环入口
        f = head;
        while(f != s){
            s = s->next;
            f = f->next;
        }
        
        return f;
    }
};

int main(){


    return 0;
}
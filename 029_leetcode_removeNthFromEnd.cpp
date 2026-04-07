#include<iostream>
#include<vector>


using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //快慢指针，快指针比慢指针快 n 个节点，当快指针遍历到链表的末尾时，慢指针就恰好处于倒数第 n 个节点
        ListNode* pre = new ListNode(0);
        pre->next = head;
        
        //慢指针指向倒数第 n 个节点的前驱节点，方便删除下一个节点
        ListNode* s = pre;
        ListNode* f = head;

        //temp 为相差的节点数
        int temp = 0;
        while(f != nullptr){
            if(temp < n){
                temp++;
            }else{
                s = s->next;
            }
            f = f->next;
        }
        s->next = s->next->next;
        
        return pre->next;
    }
};

int main(){


    return 0;
}
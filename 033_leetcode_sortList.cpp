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
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        
        //将链表截为两段
        ListNode* f = head->next;
        ListNode* s = head;
        while(f!=nullptr && f->next!=nullptr){
            s = s->next;
            f = f->next->next;
        }
        ListNode* temp = s->next;
        s->next = nullptr;

        //对两段链表分别进行排序
        ListNode* l1 = head;
        ListNode* l2 = temp;
        ListNode* sl1 = sortList(l1);
        ListNode* sl2 = sortList(l2);

        //合并两段有序链表
        ListNode* pre = new ListNode(0);
        ListNode* ans = pre;
        while(sl1 != nullptr && sl2 != nullptr){
            if(sl1->val <= sl2->val){
                pre->next = sl1;
                sl1 = sl1->next;
            }else{
                pre->next = sl2;
                sl2 = sl2->next;
            }
            pre = pre->next;
        }
        if(sl1 != nullptr){
            pre->next = sl1;
        }
        if(sl2 != nullptr){
            pre->next = sl2;
        }

        return ans->next;
    }
};

int main(){


    return 0;
}
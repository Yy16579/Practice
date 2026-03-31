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
    //反转链表
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur != nullptr){
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

    bool isPalindrome(ListNode* head) {
        //快慢指针，获取链表后半段
        ListNode* f = head;
        ListNode* s = head;
        while(f != nullptr && f->next != nullptr){
            f = f->next->next;
            s = s->next;
        }

        //反转链表后半段
        ListNode* p;
        p = reverseList(s);

        //判断是否回文
        ListNode* p1 = head;
        ListNode* p2 = p;
        while(p2 != nullptr){
            if(p1->val != p2->val){
                return false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }
};

int main(){

    
    return 0;
}
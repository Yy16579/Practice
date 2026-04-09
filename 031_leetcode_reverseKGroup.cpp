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

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* pre = new ListNode(0);
        ListNode* ans = pre;
        ListNode* cur = head;

        while(cur != nullptr){
            ListNode* tail = cur;           //tail 指向一组链表的尾节点
            
            //判断即将翻转的这一组链表节点数是否满足 k 个
            for(int i=1 ; i<k && tail!=nullptr ; i++){
                tail = tail->next;
            }
            if(tail == nullptr){            //数量不满足 k 个，直接退出
                break;              
            }

            //保存下一组的头，并切断这一组
            ListNode* nextG = tail->next;         
            tail->next = nullptr;           
            
            //翻转链表
            ListNode* start = cur;
            pre->next = reverseList(cur);
            start->next = nextG;    

            //更新指针
            pre = start;
            cur = nextG;
        }
        return ans->next;
    }
};       

int main(){


    return 0;
}
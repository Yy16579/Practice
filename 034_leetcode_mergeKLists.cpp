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
    //归并排序
    ListNode* merge(vector<ListNode*>& v, int l, int r){
        if(l >= r){
            return v[l];
        }
        int mid = l + (r-l)/2;
        ListNode* l1 = merge(v , l , mid);
        ListNode* l2 = merge(v , mid+1 , r);
        
        ListNode* ans = new ListNode();
        ListNode* cur = ans;
        while(l1!=nullptr && l2!=nullptr){
            if(l1->val <= l2->val){
                cur->next = l1;
                l1 = l1->next;
            }else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if(l1 != nullptr){
            cur->next = l1;
        }
        if(l2 != nullptr){
            cur->next = l2;
        }

        return ans->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return nullptr;
        }
        return merge(lists , 0 , lists.size()-1);
    }
};

int main(){


    return 0;
}
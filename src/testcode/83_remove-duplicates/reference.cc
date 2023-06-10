#include <iostream>
#include <vector>

using namespace std;

typedef struct ListNode{
    int val;
    ListNode* next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* slow = head;
        if(!slow || !slow->next){return head;}
        ListNode* fast = head->next;
        // 使用快慢指针的方式
        while(fast){
            if(slow->val == fast->val){
                fast = fast->next;
                // 清空主要是为了防止最后出现相同的值
                slow->next = nullptr;
                continue;
            }else{
                // slow与fast的值不相等，则将fast给slow的next
                slow->next = fast;
                fast = fast->next;
                slow = slow->next;
            }
        }

        return head;
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}
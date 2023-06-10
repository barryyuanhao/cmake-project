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
        ListNode* new_head = new ListNode;
        new_head->next = head;
        ListNode* cur_node = new_head;
        ListNode* slow = nullptr;
        ListNode* fast = nullptr;
        while(cur_node && cur_node->next){
            // slow与fast都为cur_node的next节点
            slow = cur_node->next;
            fast = cur_node->next;
            // fast与自身的next节点比较，相等则往后移动
            while(fast->next && fast->next->val == fast->val){
                fast = fast->next;
            }
            // 如果slow与fast相同，则说明无重复节点
            if(slow == fast){
                cur_node = cur_node->next;
            }else{
                // 此处cur_node不需要往后移，因为已经删除了slow到fast的节点，
                // cur_node的next为新节点
                cur_node->next = fast->next;

                // 删除重复节点
                while(slow!=fast){
                    ListNode* temp = slow;
                    slow = slow->next;
                    delete temp;
                }
                delete slow;
            }
        }

        return new_head->next;
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}
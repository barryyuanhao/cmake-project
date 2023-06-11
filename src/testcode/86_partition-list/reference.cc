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
    ListNode* partition(ListNode* head, int x) {
        // 使用两个链表头分别存储大于等于 、 小于目标值的两个链表
        ListNode* lessNode = new ListNode();
        ListNode* greatNode = new ListNode();
        ListNode* less_cur = lessNode;
        ListNode* great_cur = greatNode;
        ListNode* cur_node = head;
        while(cur_node){
            // 存入小于x的链表
            if(cur_node->val < x){
                less_cur->next = cur_node;
                less_cur = less_cur->next;
            }else{
            // 存入大于等于x的链表
                great_cur->next = cur_node;
                great_cur = great_cur->next;
            }
            cur_node = cur_node->next;
        }
        // 注意::一定要将great_cur的next至为null
        great_cur->next = nullptr;
        less_cur->next = greatNode->next;

        return lessNode->next;
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}
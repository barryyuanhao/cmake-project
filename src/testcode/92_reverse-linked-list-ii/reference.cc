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
    // 注意题目中的left、right表示在链表中的位置，不是数值
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // 头节点
        ListNode* new_head = new ListNode;
        new_head->next = head;
        // pre_node是left的前一个节点
        ListNode* pre_node = new_head;
        for(int i=0; i<left-1; i++){
            pre_node = pre_node->next;
        }

        // 翻转节点的头节点
        ListNode* sub_head = nullptr;
        // 翻转开始节点
        ListNode* cur_node = pre_node->next;
        // 翻转开始节点，为翻转后的尾节点
        ListNode* tail = cur_node;
        // 循环到right截止
        for(int i=left; i<=right;i++){
            ListNode* next = cur_node->next;
            cur_node->next = sub_head;
            sub_head = cur_node;
            cur_node = next;
        }
        // 将原链表与反转后的链表连接起来
        pre_node->next = sub_head;
        tail->next = cur_node;

        return new_head->next;
    }
};

int main(int argc, char* argv[]){
    
    return 0;
}
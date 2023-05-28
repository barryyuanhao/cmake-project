#include <iostream>

using namespace std;
typedef struct ListNode{
    int val;
    ListNode* next;
};

class Solution {
public:
    // K个节点翻转函数
    ListNode* revertListNode(ListNode* pre_head, int k){
        // 翻转后的尾节点为第一个节点
        ListNode* tail = pre_head->next;
        // 翻转中的头节点
        ListNode* new_head = nullptr;
        // 当前翻转节点位置
        ListNode* cur_node = pre_head->next;
        // 循环K个节点进行翻转
        for(int i =0; i< k; i++){
            ListNode* next_node = cur_node->next;
            cur_node->next = new_head;
            new_head = cur_node;
            cur_node = next_node;
        }
        // 翻转结束后pre节点的next为 new_head
        pre_head->next = new_head;
        // 尾节点的next为cur_node
        tail->next = cur_node;

        // 返回尾节点
        return tail;
    }

    // 主入口函数，主要控制是否需要进行K个节点的翻转
    ListNode* reverseKGroup(ListNode* head, int k) {
        int size = 0;
        ListNode* cur_node = head;
        ListNode* new_head = new ListNode;
        new_head->next = head;
        // 计算链表的长度
        while(cur_node){
            size++;
            cur_node = cur_node->next;
        }
        cur_node = new_head;
        // 以K组为单位，分阶段进行K个链表的翻转
        while(size>=k){
            // 每个循环size-k
            size = size -k;
            // 返回值为上一个K节点翻转的末尾节点，输入参数为K翻转节点的pre节点
            ListNode* temp = revertListNode(cur_node,k);
            cur_node = temp;
        }

        return new_head->next;
    }
};

int main(int argc, char* argv[]){

    return 0;
}
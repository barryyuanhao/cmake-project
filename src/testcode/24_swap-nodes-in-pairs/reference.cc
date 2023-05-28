#include <iostream>

using namespace std;

typedef struct ListNode{
    int val;
    ListNode* next;
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // 创建新的头节点
        ListNode* new_head = new ListNode;
        // 创建当前节点，当前节点要比待翻转的两个节点早一个节点
        ListNode* cur_node = new_head;
        cur_node->next = head;

        // 待翻转的两个节点不为空，如果有一个为空，则翻转结束
        while(cur_node->next && cur_node->next->next){
            // 翻转后的下一个节点
            ListNode* next = cur_node->next->next->next;
            // 翻转节点1
            ListNode* a = cur_node->next;
            // 翻转节点2
            ListNode* b = cur_node->next->next;

            // 节点翻转
            cur_node->next = b;
            b->next = a;
            a->next = next;
            // 移动当前节点至翻转后的第二个节点（下一个翻转的前一节点）
            cur_node = a;
        }
        // 返回翻转后的头节点
        return new_head->next;
    }
};

int main(int argc, char* argv[]){

    return 0;
}
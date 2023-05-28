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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur_node = head;
        int size =0;
        // 获取链表的长度
        while(cur_node){
            cur_node = cur_node->next;
            size++;
        }
        // n=size标识删除第一个节点
        if(size == n){return head->next;}

        cur_node = head;
        // 运行至删除节点的前一个节点
        for(int i =0; i< size-n-1; i++){
            cur_node =cur_node->next;
        }

        // 删除cur_node的下一个节点
        cur_node->next = cur_node->next->next;

        return head;
    }
};

int main(int argc, char* argv[]){

    return 0;
}
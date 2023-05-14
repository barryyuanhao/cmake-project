#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k);
};

ListNode* Solution::rotateRight(ListNode* head, int k) {
    int length =0;
    // 查找最后一个链表节点
    ListNode* tail = nullptr;
    ListNode* cur_node = head;
    // 如果链表为空，直接返回
    if(!head){return head;}
    // 计算链表长度，以及获取链表尾节点
    while(cur_node){
        cur_node = cur_node->next;
        if(cur_node){
            tail = cur_node;
        }
        length++;
    }
    
    // 避免K的长度超过链表长度
    k = k%length;
    if(k ==0){return head;}

    // 运行至需要截断的节点处
    cur_node = head;
    for(int i =0; i< length -k-1; i++){
        cur_node = cur_node->next;
    }

    // 重新对链表进行连接
    tail->next = head;
    head = cur_node->next;
    cur_node->next = nullptr;

    return head;
}

int main(int argc, char* argv[]){
    
    return 0;
}
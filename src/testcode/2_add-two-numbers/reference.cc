#include <iostream>
#include <vector>
typedef struct ListNode{
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
}ListNode;

class Solution{
public:
    ListNode* creatLnode(std::vector<int> arg);
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
};

ListNode* Solution::creatLnode(std::vector<int> arg){

}

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head  = new ListNode(0);
    ListNode* cur_node = head;
    ListNode* temp = nullptr;
    int carry_value = 0;

    while(l1 && l2){
        temp = new ListNode(0);
        temp->val =(l1->val + l2->val + carry_value) % 10;
        carry_value = (l1->val + l2->val + carry_value) / 10;
        cur_node->next = temp;
        cur_node = cur_node->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    if(!l1){
        while(l2){
            temp = new ListNode(0);
            temp->val =(l2->val + carry_value) % 10;
            carry_value = (l2->val + carry_value) / 10;
            cur_node->next = temp;
                cur_node = cur_node->next;
                l2 = l2->next;
        }
    }
    if(!l2){
        while(l1){
            temp = new ListNode(0);
            temp->val =(l1->val + carry_value) % 10;
            carry_value = (l1->val + carry_value) / 10;
            cur_node->next = temp;
                cur_node = cur_node->next;
                l1 = l1->next;
        }
    }
    if(carry_value > 0){
        temp = new ListNode(carry_value);
        cur_node->next = temp;
    }

    return head->next;
}

int main(int argc, char* argv[]){
    return 0;
}
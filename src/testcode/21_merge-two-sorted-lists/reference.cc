#include <iostream>
#include <vector>

using namespace std;

typedef struct ListNode{
    int val;
    ListNode* next;
};
class Solution {
public:
    ListNode* creatLnode(vector<int> arg);
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
};

ListNode* Solution::creatLnode(vector<int> arg){

}

ListNode* Solution::mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* new_head = new ListNode;
    ListNode* cur_node = new_head;

    while(list1 && list2){
        if(list1->val <= list2->val){
            cur_node->next = list1;
            cur_node = cur_node->next;
            list1 = list1->next;
        }else{
            cur_node->next = list2;
            cur_node = cur_node->next;
            list2 = list2->next;
        }
    }

    if(!list1){
        cur_node->next = list2;
    }
    if(!list2){
        cur_node->next = list1;
    }

    return new_head->next;
}

int main(int argc, char* argv[]){

    return 0;
}
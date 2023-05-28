#include <iostream>
#include <vector>

using namespace std;

typedef struct ListNode{
    int val;
    ListNode* next;
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        ListNode* new_head = new ListNode;
        ListNode* cur_node = new_head;
        while(list1 && list2){
            if(list1->val <=list2->val){
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

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        // 合并思想：连续两两链表合并的方法
        ListNode* temp = nullptr;
        for(int i=0; i<size; i++){
            temp = mergeTwoLists(temp, lists[i]);
        }

        return temp;
    }
};

int main(int argc, char* argv[]){

    return 0;
}
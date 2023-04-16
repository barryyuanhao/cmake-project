#include <iostream>
#include <vector>
typedef struct ListNode{
    int val;
    ListNode* next;
}ListNode;

class Solution{
public:
    ListNode* creatLnode(std::vector<int> arg);
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
    void printNode(ListNode* node);

    std::vector<int> raw_l1 = {9,9,9,9,9,9,9};
    std::vector<int> raw_l2 = {9,9,9,9};
};

int main(int argc, char* argv[]){
    Solution obj;
    ListNode* node1 = obj.creatLnode(obj.raw_l1);
    ListNode* node2 = obj.creatLnode(obj.raw_l2);
    ListNode* result = obj.addTwoNumbers(node1,node2);
    return 0;
}
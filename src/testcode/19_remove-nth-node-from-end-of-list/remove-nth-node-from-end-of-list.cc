#include <iostream>
#include <vector>

typedef struct ListNode{
    int val;
    ListNode* next;
};

ListNode* creatLnode(std::vector<int> arg){
    ListNode* head = nullptr;
    ListNode* cur_node = nullptr;
    for (int i = 0; i < arg.size(); i++)
    {
        ListNode* temp = new ListNode;
        temp->val = arg[i];
        temp->next = nullptr;

        if (head == nullptr)
        {
            head = temp;
            cur_node = temp;
        }else{
            cur_node->next = temp;
            cur_node = cur_node->next;
        }
    }
    
    return head; 
}

ListNode* removeLnode(ListNode* node , int last){
    ListNode* head = node;
    ListNode* right = node;
    ListNode* left = node;
    ListNode* temp = node;
    int count =last;
    while (count-- && right!=nullptr)
    {   
        right = right->next;
    }

    if(right == nullptr){
        temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    while (right->next != nullptr)
    {
        left = left->next;
        right = right->next;
    }
    if(last ==1 ){
        temp = left->next;
        left->next = nullptr;
        delete temp;
    }else{
        temp = left->next;
        left->next = left->next->next;
        delete temp;
    }
    return head;
}

int main(int argc, char* argv[]){
    std::vector<int> l1 = {1,2,3,4,5,6,7,8,9,10,11,12};
    ListNode* Lnode = creatLnode(l1);
    auto temp = Lnode;
    while (temp != nullptr)
    {
        std::cout << temp->val << " > ";
        temp = temp->next;
    }
    std::cout << std::endl;

    int last = std::atoi(argv[1]);
    ListNode* new_node = removeLnode(Lnode, last);
    temp = new_node;
    while (temp != nullptr)
    {
        std::cout << temp->val << " > ";
        temp = temp->next;
    }
    std::cout << std::endl;
    
    return 0;
}
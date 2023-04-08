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

ListNode* addLnode(ListNode* Lnode1, ListNode* Lnode2){
    ListNode* head = nullptr;
    ListNode* cur_node = nullptr;
    ListNode* node1 = Lnode1;
    ListNode* node2 = Lnode2;
    int carry = 0;
    while (node1 != nullptr || node2 != nullptr)
    {
        ListNode* temp = new ListNode;
        if(node1 != nullptr && node2 != nullptr){
            temp->val = (node1->val + node2->val + carry)%10;
            carry = (node1->val + node2->val + carry)/10;
            node1=node1->next;
            node2=node2->next;
        }else if(node1 == nullptr){
            temp->val = (node2->val + carry)%10;
            carry = (node2->val + carry)/10;
            node2=node2->next;
        }else{
            temp->val = (node1->val + carry)%10;
            carry = (node1->val + carry)/10;
            node1=node1->next;
        }

        if(head == nullptr){
            head = temp;
            cur_node = temp;
        }else{
            cur_node->next = temp;
            cur_node = cur_node->next;
        }
    }
    if(carry >0){
        ListNode* temp = new ListNode;
        temp->val = carry;
        cur_node->next = temp;
        cur_node = cur_node->next;
    }
    
    return head;
}

int main(int argc, char* argv[]){
    std::vector<int> l1 = {9,9,9,9,9,9,9};
    std::vector<int> l2 = {9,9,9,9};
    ListNode* Lnode1 = creatLnode(l1);
    auto temp = Lnode1;
    while (temp != nullptr)
    {
        std::cout << temp->val << " > ";
        temp = temp->next;
    }
    std::cout << std::endl;

    ListNode* Lnode2 = creatLnode(l2);
    temp = Lnode2;
    while (temp != nullptr)
    {
        std::cout << temp->val << " > ";
        temp = temp->next;
    }
    std::cout << std::endl;

    ListNode* ans = addLnode(Lnode1, Lnode2);
    while (ans != nullptr)
    {
        std::cout << ans->val << " > ";
        ans = ans->next;
    }
    std::cout << std::endl;

    return 0;
}
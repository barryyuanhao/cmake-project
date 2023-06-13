#include <iostream>
#include <vector>

using namespace std;

typedef struct ListNode{
    int val;
    ListNode* next;
    ListNode(int a):val(a),next(nullptr){}
};

class Solution{
public:
    ListNode* creatListNode(vector<int> nums);
    void printListNode(ListNode* node);
    ListNode* sortListNode(ListNode* head);
private:
    void quickSortListNode(ListNode* left, ListNode* right);
    ListNode* partition(ListNode* left, ListNode* right);
};

ListNode* Solution::creatListNode(vector<int> nums){
    ListNode* head = nullptr;
    ListNode* cur_node = nullptr;
    int size = nums.size();
    for(int i=0; i<size; i++){
        ListNode* temp = new ListNode(nums[i]);
        if(head == nullptr){
            head = temp;
            cur_node = temp;
        }else{
            cur_node->next = temp;
            cur_node = cur_node->next;
        }
    }

    return head;
}

void Solution::printListNode(ListNode* node){
    while(node){
        std::cout << node->val << "->";
        node = node->next;
    }
    std::cout << std::endl;
}

ListNode* Solution::partition(ListNode* left, ListNode* right){
    // 以最左边节点的val作为key
   int key = left->val;
    // loc从最左边开始，
   ListNode* loc = left;
    // 检测到i->val 小于 key，将i的值往loc处移动，同时loc向右移动
   for(ListNode* i=left->next; i!=right; i = i->next){
        if(i->val < key){
            loc = loc->next;
            // 将loc与i交换，保证loc左侧的值都小于key
            swap(loc->val, i->val);
        }
   }
    // 最后将left与loc交换，
   swap(left->val, loc->val);
   return loc;
}

// 返回为空，因为head节点指针没有改变，只是对链表的值进行修改排序
void Solution::quickSortListNode(ListNode* left, ListNode* right){
    // [left, right)左开右闭区间
    // left->next ==right，可以理解为只有一个有效节点，所以不需要排序
    if(left != right && left->next != right){
        // 获取中间节点
        ListNode* mid = partition(left,right);
        // [left, mid)排序
        quickSortListNode(left,mid);
        // [mid->next， right)排序
        quickSortListNode(mid->next,right);
    }
}

ListNode* Solution::sortListNode(ListNode* head){
    ListNode* tail = nullptr;
    // 快速排序的入口，定义tail为空节点
    // 返回为空，因为head节点指针没有改变，只是对链表的值进行修改排序
    quickSortListNode(head, tail);

    return head;
}

int main(int argc, char* argv[]){
    vector<int> Input = {5,3,7,9,3,1,2,4,8,6};
    Solution obj;
    ListNode* node = obj.creatListNode(Input);
    obj.printListNode(node);
    ListNode* result = obj.sortListNode(node);
    obj.printListNode(result);
    return 0;
}
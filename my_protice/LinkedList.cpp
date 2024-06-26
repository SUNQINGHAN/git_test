#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeElements(ListNode* head, int val) {
    ListNode *dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode *cur = dummyHead;
    while(cur->next != nullptr){
        if(cur->next->val == val){
            ListNode *tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;
        }
        else cur = cur->next;
    }
    head = dummyHead->next;
    delete dummyHead;
    return head;
}

class MyLinkedList {
public:
    struct ListNode{
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    MyLinkedList() {
        _dummyHead = new ListNode(0);
        _size = 0;
    }
    
    int get(int index) {
        ListNode* cur = _dummyHead->next;
        if (index > (_size - 1) || index < 0) {
            return -1;
        }
        while(index--){
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }
    
    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        ListNode* cur = _dummyHead;
        while(cur->next != NULL){
            cur = cur->next;
        }
        cur->next = newNode;
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        ListNode* newNode = new ListNode(val);
        ListNode* cur = _dummyHead;
        if (index > _size || index < 0) {
            return;
        }
        while(index--){
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        _size++;
    }
    
    void deleteAtIndex(int index) {
        ListNode* cur = _dummyHead;
        if (index > (_size - 1) || index < 0)  {
            return;
        }
        while(index--){
            cur = cur->next;
        }
        ListNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        _size--;
    }
private:
    int _size;
    ListNode* _dummyHead;
};


int main(){
    ListNode *head = nullptr, *tail = nullptr;
    vector<int> values = {1, 2, 6, 3, 4, 5, 6};
    for(int val : values){
        if(head == nullptr){
            head = tail = new ListNode(val);
        }
        else{
            tail->next = new ListNode(val);
            tail = tail->next;
        }
    }
    head = removeElements(head, 6);
    ListNode *cur = head;
    while(cur != nullptr){
        cout << cur->val << ' ';
        cur = cur->next;
    }
    return 0;
}
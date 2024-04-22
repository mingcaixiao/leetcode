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

#define _CRTDBG_MAP_ALLOC

#include <vector>
#include <iostream>

#include <crtdbg.h>

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  int listLength(ListNode* head) {
    int result = 0;
    ListNode* p = head;
    while (p != nullptr) {
      ++result;
      p = p->next;
    }
    return result;
  }
  ListNode* rotateRight(ListNode* head, int k) {
    int lenOfList = listLength(head);
    k = k % lenOfList;
    //首先找到起始位置
    ListNode *p = head, *q = head;
    int i = 0;
    while (i < k - 1) {
      q = q->next;
      ++i;
    }
    while(q->next != nullptr){
      p = p->next;
      q = q->next;
    }
    i = 1;
    ListNode *resultHead = new ListNode(p->val);
    q = resultHead;
    while (i < lenOfList) {
      p = p->next;
      if (p == nullptr) p = head;
      q->next = new ListNode(p->val);
      q = q->next;
      ++i;
    }
    return resultHead;
  }
};

void destroyList(ListNode* head){
  ListNode *p = head, *q = nullptr;
  while(p != nullptr){
    q = p->next;
    delete p;
    p = q;
  }
}

void printList(ListNode* head){
  ListNode *p = head;
  while(p!=nullptr){
    std::cout << p->val << " ";
    p = p->next;
  }
  std::cout<<std::endl;  
}

ListNode* getList(std::vector<int>& data) {
  ListNode* head = new ListNode(*data.begin());
  ListNode* p = head;
  for(auto i = data.begin() + 1; i < data.end(); ++i){
    p->next = new ListNode(*i, nullptr);
    p = p->next;
  }
  return head;  
}

int main() {
  _CrtDumpMemoryLeaks();
  std::vector<int> data{1,2,3,4,5};
  Solution s;
  ListNode* initial = getList(data);
  printList(initial);
  ListNode* result = s.rotateRight(initial, 11);
  printList(result);
}
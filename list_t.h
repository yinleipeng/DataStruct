#include <iostream>

class list_t {
public:    
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int val):val(val),next(nullptr){}
    };

    list_t() {
        heard_ = new ListNode(0);
        size_ = 0;
    }
    ~list_t(){}

    /*获取链表中第index个节点的值，如果索引无效，返回-1*/
    int get(int index) {
        
        if(index < 0 || index > size_ - 1) {
            return -1;
        }

        ListNode *l0 = heard_->next;
        for(int i = 0; i < index; i++) {
            l0 = l0->next;
        }
        return l0->val;
    }

    /*在链表的第index个节点之前添加值为val的节点。如果等于链表的长度，插入末尾，
     * 如果等于0,插入头;如果无效，返回-1*/
    int addAtIndex(int index, int val) {
        
        if(index < 0 || index > size_) {
            return -1;
        }
        ListNode *l0 = heard_;
        for(int i = 0; i < index; i++) {
            l0 = l0->next;
        }
        ListNode *l1 = new ListNode(val);
        l1->next = l0->next;
        l0->next = l1;
        size_++;
        return 0;
    }

    /*如果索引index有效，删除节点*/
    int deleteAtIndex(int index) {

        if(index < 0 || index > size_ - 1) {
            return -1;
        }
       ListNode *l0 = heard_->next;
       for(int i = 0; i < index - 1; i++) {
           l0 = l0->next;
       }
       ListNode *l1 = l0->next;
       l0->next = l0->next->next;
       delete l1;
       size_--;
       return 0;
    }

    /*删除链表中给定值为val的所有节点*/
    int deleteAtVal(int val) {
       
        ListNode *l0 = heard_;
        while(l0->next != nullptr) {
            if(l0->next->val == val) {
                ListNode *l1 = l0->next;
                l0->next = l0->next->next;
                delete l1;
            } else {
                l0 = l0->next;
            }
        }
        return 0;
    }

    /*反转链表*/
    int ReversalList() {
        
        ListNode *l0 = heard_;
        ListNode *l1 = l0->next;
        ListNode *temp;
        l0 = nullptr;
        
        while(l1 != nullptr) {
            temp = l1->next;
            l1->next = l0;
            l0 = l1;
            l1 = temp;
        }
        heard_->next = l0;
        
        return 0;
    }

    /*给定一个链表，两两交换其中相邻的节点，并返回交换后的链表
     * 不能只是单纯变换节点内部的值，而是需要实际进行节点的交换*/
   int ExchangeList() {
        
       ListNode *l0 = l0->next;
       ListNode *temp;
       ListNode *l1 = l0;

       while(l0 != nullptr && l0->next != nullptr) {
            
            temp = l0->next;
            l1->next = l0;
            l0->next = temp;
            l0 = temp;
            l1 = temp->next;
       }
       l0->next = nullptr;
       return 0;
   }
    
   void  printf_list() {
        ListNode *l = heard_->next;
        while(l != nullptr) {
            std::cout << l->val <<std::endl;
            l = l->next;
        }
    }
private:
    ListNode *heard_;
    int size_;
};

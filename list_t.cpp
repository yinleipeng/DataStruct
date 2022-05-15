#include "list_t.h"


int main() {

    list_t l;
    l.addAtIndex(0,1);
    l.addAtIndex(0,2);
    l.addAtIndex(0,3);
    l.addAtIndex(0,3);
    l.addAtIndex(0,4);
    l.addAtIndex(0,5);
    l.addAtIndex(0,6);
    l.printf_list();
    std::cout <<"this val is "<<l.get(1) << std::endl;
    l.deleteAtIndex(2);
    l.printf_list();
    std::cout << "this is deleteAtVal " << std::endl;
    l.deleteAtVal(3);
    l.printf_list();
    std::cout << "this is reval list" << std::endl;
    l.ReversalList(); 
    l.printf_list();
    std::cout << "this is exchange list" << std::endl;
    l.ExchangeList();
    l.printf_list();
    
    return 0;
}

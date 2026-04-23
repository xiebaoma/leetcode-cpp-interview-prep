#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int v){
        val=v;
        next=nullptr;
    }
};

Node* group(Node* head){
    if(head==nullptr){
        return;
    }
    Node odd(0);
    Node* oddnext=&odd;

    Node even(0);
    Node* evennext=&even;

    int i=1;
    while(head){
        Node* next=head->next;
        head->next=nullptr;

        if(i==1){
            oddnext->next=head;
            oddnext=oddnext->next;
            i=0;
        }else{
            evennext->next=head;
            evennext=evennext->next;
            i=1;
        }
        
        head=next;
    }
    oddnext->next=even.next;

    return odd.next;
}
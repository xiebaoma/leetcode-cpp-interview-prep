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

void reverse(Node* n1, Node* n2){
    Node* pre= n2->next;
    Node* cur=n1;
    Node* next=n1->next;
    while(cur!=n2){
        cur->next=pre;
        pre=cur;
        cur=next;
        next=next->next;
    }
    cur->next=pre;
}

Node* reverseK(Node* head, int k){
    if(head==nullptr || k==0 || k==1){
        return head;
    }
    Node dummy(0);
    Node* pre= &dummy;
    pre->next=head;

    Node* cur=head;
    Node* n1=head;
    Node* n2=cur;

    while(cur){
        for(int i=1;i<k;i++){
            if(cur==nullptr){
                return dummy.next;
            }
            cur=cur->next;
            if(cur==nullptr){
                return dummy.next;
            }
        }
        n2=cur;
        reverse(n1, n2);
        pre->next=n2;
        pre=n1;
        n1=pre->next;
        n2=pre->next;
        cur=pre->next;
    }
    return dummy.next;
}

void print(Node* head){
    while(head){
        cout<< head->val << " ";
        head=head->next;
    }
    cout << endl;
}

int main(){

    Node n1(1);
    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);
    
    n1.next=&n2;
    n2.next=&n3;
    n3.next=&n4;
    n4.next=&n5;

    print(&n1);

    print(reverseK(&n1, 3));

    return 0;
}
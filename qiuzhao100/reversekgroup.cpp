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

void printlist(Node* head){
    while(head){
        cout << head->val << " ";
        head=head->next;
    }
    cout << endl;
}

void reverselist(Node* n1, Node* n2){
    Node* pre= n2->next;
    Node* cur= n1;
    Node* next=n1->next;
    while(cur!=n2){
        cur->next=pre;
        pre=cur;
        cur=next;
        next=next->next;
    }
    cur->next=pre;
}

Node* reversekgroup(Node* head, int k){
    Node dummy(0);
    Node* pre= &dummy;
    pre->next= head;
    while(true){
        Node* n1= pre->next;
        Node* n2= pre->next;
        if(n2==nullptr){
            return dummy.next;
        }
        for(int i=1;i<k;i++){
            n2=n2->next;
            if(n2==nullptr){
                return dummy.next;
            }
        }
        cout << "n1="<< n1->val << " " << "n2="<< n2->val << endl;
        reverselist(n1, n2);
        pre->next=n2;
        pre=n1;
    }
    return dummy.next;
}

int main(){
    Node n1(1);
    Node n2(2);
    Node n3(3);
    Node n4(4);
    n1.next=&n2;
    n2.next=&n3;
    n3.next=&n4;

    printlist(&n1);
    Node* head= reversekgroup(&n1, 3);
    printlist(head);
    return 0;
}
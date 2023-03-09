# include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

node *insertnode(node *&head, int data)
{
    node *temp = new node(data);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
    return head;
}

void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

node* reverse(node* head){
    node* prev = NULL;
    node* fwd = NULL;
    node* curr = head;
    while(curr!=NULL){
        fwd=curr->next;
        curr->next=prev;
        prev=curr;
        curr=fwd;
    }
    return prev;
}

node* addNums(node* head1,node* head2){
    node* temp1 = reverse(head1);
    node* temp2 = reverse(head2);

    node* ans = new node(-1);
    int carry=0;
    while(temp1!=NULL || temp2!=NULL){
        int i = 0;
        int j = 0;
        if(temp1!=NULL){
            i=temp1->data; 
        }
        if(temp2!=NULL){
            j=temp2->data; 
        }

        int res= i+j;
        res+=carry;
        carry=0;
        if(res>9){
            int val = res%10;
            insertnode(ans,val);
            carry = res/10;
        }
        else{
            int val = res;
            insertnode(ans,val);
        }
        if(temp1!=NULL){
            // cout<<temp1->data;
            temp1=temp1->next;
        }
        if(temp2!=NULL){
            // cout<<temp2->data;
            temp2=temp2->next;
        }
    }
    // cout<<"hii";
    ans=ans->next;
    ans = reverse(ans);
    return ans;
}

int main(){

    node *head1 = NULL;
    insertnode(head1, 4);
    insertnode(head1, 5);

    node* head2 = NULL;
    insertnode(head2, 3);
    insertnode(head2, 4);
    insertnode(head2, 5);
    print(head1);
    print(head2);
    cout<<"-----------------------------\n";

    node* temp = addNums(head1,head2);
    print(temp);

    return 0;
}
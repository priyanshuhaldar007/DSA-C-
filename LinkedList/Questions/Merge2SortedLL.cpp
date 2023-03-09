#include <bits/stdc++.h>
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

node *mergeSorted(node *head1, node *head2)
{
    node *finalHead = NULL;
    if (head1 == NULL)
    {
        return head2;
    }
    else if (head2 == NULL)
    {
        return head1;
    }
    else
    {
        node *finalTemp = finalHead;
        node *temp1 = head1;
        node *temp2 = head2;
        while (temp1 != NULL && temp2 != NULL)
        {
            if (finalTemp == NULL)
            {
                    // finalHead =temp1->data < temp2->data? temp1:temp2;
                    if(temp1->data < temp2->data){
                        finalTemp = temp1;
                        temp1=temp1->next;
                    }
                    else{
                        finalTemp = temp2;
                        temp2=temp2->next;
                    }
                    finalHead=finalTemp;
            }
            else{
                // while (finalTemp->next!= NULL)
                // {
                //     finalTemp = finalTemp->next;
                // }
                // finalTemp =temp1->data < temp2->data? temp1:temp2;
                if(temp1->data < temp2->data){
                    finalTemp->next = temp1;
                    temp1=temp1->next;
                }
                else{
                    finalTemp->next = temp2;
                    temp2=temp2->next;
                }
                finalTemp = finalTemp->next;
            }
            // print(finalHead);
            // cout<<finalTemp->data<<" ";
        }
        // cout<<"loop broken";
        while(temp1!=NULL){
            finalTemp->next = temp1;
            temp1=temp1->next;
            finalTemp=finalTemp->next;
        }
        
        while(temp2!=NULL){
            finalTemp->next = temp2;
            temp2=temp2->next;
            finalTemp=finalTemp->next;
        }

    }
    return finalHead;
}

int main()
{

    node *head1 = NULL;
    node *head2 = NULL;

    insertnode(head1, 1);
    insertnode(head1, 4);
    insertnode(head1, 5);
    insertnode(head2, 2);
    insertnode(head2, 3);
    insertnode(head2, 5);

    print(head1);
    print(head2);

    node* finalHead= mergeSorted(head1,head2);
    print(finalHead);

    return 0;
}
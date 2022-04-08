#include <iostream>

using namespace std;
class Node
{
public:
    int data;
    Node *next,*prev;
};
class List:public Node
{
    Node *head,*last;
public:
    List()
    {
        head=NULL;
        last=NULL;
    }
    void create();
    void delet();
    void insert();
    void display();
    void search();

};
void List::create()
{
    Node *temp;
    temp = new Node;
    int n;
    cout<<"Enter an element";
    cin>>n;
    temp->data=n;
    temp->data=NULL;
    if(head==NULL)
    {
        head=temp;
        last=head;
    }
    else
    {
        last->next=temp;
        last=temp;
    }


}
void List::insert()
{
    Node *prev,*cur;
    prev=NULL;
    cur=head;
    int count=1,pos,ch,n;
    Node *temp=new Node;
    cout<<"Enter an Element";
    cin>>n;
    temp->data=n;
    temp->next=NULL;
    cout<<"Insert n1 for first node----- n2 for last node---- n3 for node in between";
    cout<<"Enter your choice";
    cin>>ch;
    switch(ch)
    {
    case 1:
        temp->next=head;
        head=temp;
        break;
    case 2:
        last->next=temp;
        last=temp;
        break;
    case 3:
        cout<<"Enter the Position to Insert";
        cin>>pos;
        while(count!=pos)
        {
            prev=cur;
            cur=cur->next;
            count++;

        }
        if(count==pos)
        {
            prev->next=temp;
            temp->next=cur;
        }
        else
            cout<<"Not able to insert";
        break;
    }
}
void List::delet()
{
    Node *prev=NULL,*cur=head;
    int count=1,pos,ch;
    cout<<"Delete n1 for first node----- n2 for last node---- n3 for node in between";
    cout<<"Enter your choice";
    cin>>ch;
    switch(ch)
    {
    case 1:
        if(head!=NULL)
        {
            cout<<"Deleted Element is  "<<head->data;
            head=head->next;
        }
        else
            cout<<"Cant Delete";
        break;
    case 2:
        if(head=NULL)
        {
            cout<<"Not able to delete";

        }
        else{
            while(cur!=last)
            {
                prev=cur;
                cur=cur->next;

            }
            if(cur==last)
            {
                cout<<"Deleted Element"<<cur->data;
                prev->next=NULL;
                last=prev;
            }
        }
        break;
    case 3:
        cout<<"Enter the Position of Deletion:";
        cin>>pos;
        if(head=NULL)
        {
            cout<<"Not Able to delete";

        }
        else
        {
            while(count!=pos)
             {
                 prev=cur;
                 cur=cur->next;
                 count++;
             }
             if(count==pos)
             {
                 cout<<"Deleted Element is:"<<cur->data;
                 prev->next=cur->next;
             }
                   break;}
        }}
void List::display()
{
    Node *temp=head;
    if(temp==NULL)
    {
        cout<<"List is Empty";
    }
    while(temp!=NULL)
    {
        cout<<temp->data;

        temp=temp->next;
    }
    cout<<"NULL";
    }
    void List::search()
    {
        int value,pos=0;
        bool flag=false;
        if(head==NULL)
        {
            cout<<"List is empty";
            return;
        }
        cout<<"Enter the value to be searched:";
        cin>>value;
        Node *temp;
        temp=head;
        while(temp!=NULL)
        {
            pos++;
            if(temp->data==value)
            {
                flag=true;
                cout<<"Element"<<value<<"is found at"<<pos<<"Position";
                return;
            }
            temp=temp->next;

        }
        if(!flag)
        {
            cout<<"Element not found in the list";

        }
    }
int main()
{
    List l;
    int ch;
    while(1)
    {
        cout<<"n1  Create ---n2 Insert--- n3 Delete---n4 Search----n5 Display-----n6 Exit";
        cout<<"Enter Your Choice:";
        cin>>ch;
        switch(ch)
        {
        case 1:
            l.create();
            break;
        case 2:
            l.insert();
            break;
        case 3:
            l.delet();
            break;
        case 4:
            l.search();
            break;
        case 5:
            l.display();
            break;
        case 6:
            return 0;
        }
    }
    return 0;
}

#include<iostream>
#include<stdlib.h>
using namespace std;
class cllist
{
public:
    int choice,value;
    struct node
    {
        int data;
        struct node *next;
    }*list=NULL,*p,*q,*r,*s,*t;
    void get_data()
    {
        do
        {
            cout<<"Enter choice:\n";
            cout<<"1.Insertion from beginning.\n2.Insertion from end.\n3.Insertion before an element.\n4.Insertion after an element.\n5.Deletion from beginning.\n6.Deletion from end.\n7.Deletion of an element.\n8.Counting number of elements.\n9.Reverse of linked list.\n10.Sorting of linked list.\n11.Display.\n12.Exit\n";
            cin>>choice;
            switch(choice)
            {
                case 1:
                    insertb();
                    break;

                case 2:
                    inserte();
                    break;

                case 3:
                    insertbe();
                    break;

                case 4:
                    insertae();
                    break;

                case 5:
                    deleteb();
                    break;

                case 6:
                    deletee();
                    break;

                case 7:
                    deletes();
                    break;

                case 8:
                    count();
                    break;

                case 9:
                    reverse();
                    break;

                case 10:
                    sort();
                    break;

                case 11:
                    show_data();
                    break;

                case 12:
                    break;

                default:
                    cout<<"Invalid choice.\n";
            }
        }while(choice!=12);
    }
    void insertb()
    {
        int temp;
        p=(struct node*)malloc(sizeof(node));
        cout<<"Enter data:\t";
        cin>>temp;
        p->data=temp;
        if(list==NULL)
        {
            cout<<"Linked list does not exist. First node is created.\n";
            p->next=p;
            list=p;

        }
        else{q=list;
            while(q->next!=list)//last node
            {
                q=q->next;
            }
            q->next=p;
            p->next=list;
            list=p;		}
    }
    void inserte()
    {
        int temp;
        cout<<"Enter data:\t";
        cin>>temp;
        p=(struct node*)malloc(sizeof(node));
        p->data=temp;
        p->next=list;
        if(list==NULL)
        {
            list=p;
            list->next=list;
        }
        else
        {
            q=list;
            while(q->next!=list)
            {
                q=q->next;
            }
            q->next=p;
        }
    }
    void insertbe()
    {
        int temp;
        cout<<"Enter data to be inserted:\t";
        cin>>temp;
        p=(struct node*)malloc(sizeof(node));
        p->data=temp;
        cout<<"Enter element before which you want to insert "<<temp<<" :\t";
        cin>>value;
        q=list;
        if(list==NULL)
        {
            cout<<"Linked list does not exist. First node is created.\n";

            list=p;
            list->next=list;
        }
        else{
            while(q->data!=value && q->next!=list)
            {
                r=q;
                q=q->next;
            }
            if(q->next==list && q->data!=value)//data not found till last
            {
                cout<<value<<" does not exist.\n";
            }
            else if(q->data==value)
            {
                if(list->data==value)
                {
                    p->next=list;
                    //q=list;
                    while(q->next!=list)
                    {
                        cout<<"GANDU";
                        q=q->next;
                    }
                    list=p;
                    q->next=p;
                }
                else
                {
                    r->next=p;
                    p->next=q;
                }
            }	}
    }
    void insertae()
    {
        int temp;
        cout<<"Enter data to be inserted:\t";
        cin>>temp;
        p=(struct node*)malloc(sizeof(node));
        p->data=temp;
        cout<<"Enter element after which you want to insert "<<temp<<" :\t";
        cin>>value;
        q=list;
        if(list==NULL)
        {
            cout<<"Linked list does not exist. First node is created.\n";
            list=p;
            list->next=list;

        }
        else{while(q->data!=value && q->next!=list)
            {

                q=q->next;

            }
            r=q->next;
            if(q->next==list & q->data!=value)
            {
                cout<<value<<" does not exist.\n";
            }
            else if(q->data==value)
            {

                if(q->next==list)
                {
                    q->next=p;
                    p->next=list;
                }
                else
                {
                    q->next=p;
                    p->next=r;
                }
            }
        }
    }
    void deleteb()
    {
        if(list==NULL)
        {
            cout<<"Linked List is empty.\n";
        }
        else
        {	if(list->next==list)
            {
                cout<<"Deleting last node.\n";
                cout<<list->data<<" is deleted.\n";
                list=NULL;
            }
            else
            {
                q=list;
                r=list;
                list=list->next;
                cout<<q->data<<" is deleted.\n";
                while(r->next!=q)
                {
                    r=r->next;
                }
                r->next=list;
                free(q);
            }
        }
    }
    void deletee()
    {
        if(list==NULL)
        {
            cout<<"Linked List is empty.\n";
        }
        else
        {	if(list->next==list)
            {
                cout<<"Deleting last node.\n";
                cout<<list->data<<" is deleted.\n";
                list=NULL;
            }
            else
            {
                q=list;
                while(q->next!=list)
                {
                    r=q;
                    q=q->next;
                }
                r->next=list;
                cout<<q->data<<" is deleted.\n";
                free(q);
            }
        }
    }
    void deletes()
    {
        //int temp;
        if(list==NULL)
        {
            cout<<"Linked List is empty.\n";
        }
        else
        {
            cout<<"Enter element to be deleted:\n";
            cin>>value;
            q=list;
            while(q->data!=value && q->next!=list)
            {
                r=q;
                q=q->next;
            }
            if(q->next==list && q->data!=value)//data not found till last
            {
                cout<<value<<" does not exist.\n";
            }
            if(q->data==value)
            {
                if(list->data==value)
                {
                    q=list;
                    list=q->next;
                    p=list;
                    while(p->next!=q)
                    {
                        p=p->next;
                    }
                    p->next=list;
                    free(q);
                }
                else if(q->next==list)
                {
                    r->next=q->next;
                    cout<<q->data<<" is deleted.\n";
                    free(q);
                }
                else
                {
                    r->next=q->next;
                    cout<<q->data<<" is deleted.\n";
                    free(q);
                }
            }
        }
    }
    void count()
    {
        q=list;
        int counter=0;
        while(q->next!=list)
        {
            counter++;
            q=q->next;
        }
        counter++;
        cout<<"Number of nodes in linked list: "<<counter<<"\n";
    }
    void reverse()
    {
        q=list;
        s=list;
        t=NULL;
        r=q->next;
        while(r!=list)
        {
            t=q;
            q=r;
            r=q->next;
            q->next=t;
        }
        list=q;
        s->next=list;
    }
    void sort()
    {
        int temp;
        q=list;
        while(q->next!=list)
        {
            r=q->next;
            while(r!=list)
            {
                if(q->data>r->data)
                {
                    temp=q->data;
                    q->data=r->data;
                    r->data=temp;
                }
                r=r->next;
            }
            q=q->next;
        }
        cout<<"Sorted ";
        show_data();
    }
    void show_data()
    {

        q=list;
        if(list==NULL)
        {
            cout<<"Linked List is empty.\n";
        }
        else
        {
            cout<<"Linked list:\n";
            while(q->next!=list)
            {
                cout<<q->data<<"--->";
                q=q->next;
            }
            cout<<q->data<<"--->";
            cout<<"\n";
        }
    }
};
int main()
{
    cllist obj1;
    obj1.get_data();
}
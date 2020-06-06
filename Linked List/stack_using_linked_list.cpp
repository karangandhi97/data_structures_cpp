#include<iostream>
#include<stdlib.h>
using namespace std;
class stackusingll
{
public:
    int choice,value;
    struct node
    {
        int data;
        struct node *next;
    }*top=NULL,*list=NULL,*p,*q,*r,*s,*t;
    void get_data()
    {
        do{

            cout<<"Enter your choice:\n1.Push.\n2.Pop.\n3.Display Stack.\n4.Exit.\n";
            cin>>choice;
            switch(choice)
            {
                case 1:
                    push();
                    break;
                case 2:
                    pop();
                    break;
                case 3:
                    show_data();
                    break;
                case 4:
                    break;
                default:
                    cout<<"!!!!----Invalid choice----!!!!\n";
                    break;
            }
        }while(choice!=4);
    }
    void push()
    {
        cout<<"Enter data:\n";
        cin>>value;
        if(top==NULL)
        {
            p=(struct node*)malloc(sizeof(node));
            p->data=value;
            p->next=NULL;
            list=p;
        }
        else
        {
            p=list;
            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=(struct node*)malloc(sizeof(node));
            p=p->next;
            p->data=value;
            p->next=NULL;

        }
        top=p;
    }
    void pop()
    {
        if(top==NULL || list==NULL)
        {
            cout<<"Stack underflow.\n";
        }
        else if(top==list)
        {
            p=list;
            cout<<p->data<<" popped.\n";
            free(p);
            list=NULL;
            top=NULL;
        }
        else{
            p=list;
            while(p->next!=NULL)
            {
                s=p;
                p=p->next;
            }
            s->next=NULL;
            top=s;
            cout<<p->data<<" popped.\n";
            free(p);
        }
    }
    void show_data()
    {
        if(top==NULL)
        {
            cout<<"Stack is empty.\n";
        }
        else
        {
            r=list;
            cout<<"Content of Stack:\n";
            while(r!=NULL)
            {
                cout<<r->data<<"->";
                r=r->next;
            }
        }
        cout<<"\n";
    }
};
int main()
{
    stackusingll obj1;
    obj1.get_data();
}
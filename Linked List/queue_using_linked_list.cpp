#include<iostream>
#include<stdlib.h>
using namespace std;
class qusingll
{
public:
    int choice,value;
    struct node
    {
        int data;
        struct node *next;
    }*front=NULL,*rear=NULL,*list=NULL,*p,*q,*r,*s,*t;
    void get_data()
    {
        do{

            cout<<"Enter your choice:\n1.Enqueue.\n2.Dequeue.\n3.Display Queue.\n4.Exit.\n";
            cin>>choice;
            switch(choice)
            {
                case 1:
                    enqueue();
                    break;
                case 2:
                    dequeue();
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
    void enqueue()
    {
        cout<<"Enter data:\t";
        cin>>value;
        if(rear==NULL)
        {
            p=(struct node*)malloc(sizeof(node));
            p->data=value;
            p->next=NULL;
            list=p;
            cout<<"First node is created now.\n";
            front=list;
            rear=list;
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
            rear=p;
        }
    }
    void dequeue()
    {
        if(rear==NULL)
        {
            cout<<"Queue underflow\n";

        }
        else
        {
            if(front->next!=NULL)
            {
//				front=list;
                list=list->next;
                p=front;
                front=front->next;
                cout<<p->data<<" deleted.\n";
                free(p);
            }
            else
            {
                p=front;
                front=front->next;
                cout<<p->data<<" deleted.\n";
                free(p);
                front=NULL;
                rear=NULL;
                list=NULL;
            }
        }

    }
    void show_data()
    {
        if(list==NULL)
        {
            cout<<"Queue is empty.\n";
        }
        else
        {
            r=list;
            cout<<"Content of Queue:\n";
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
    qusingll obj1;
    obj1.get_data();
}
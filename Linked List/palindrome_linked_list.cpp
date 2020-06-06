//
// Created by Karan on 5/9/2020.
//

#include<iostream>
using namespace std;
class palindromell
{
public:
    int counter;
    bool flag;
    palindromell()
    {
        counter=0;
        flag=false;
    }
    struct node
    {
        int data;
        struct node *next;
    }*p,*q,*r,*list=NULL;
    void insert()
    {
        int temp;
        cout<<"Enter data to insert:";
        cin>>temp;
        counter++;
        p=(struct node*)malloc(sizeof(node));
        p->data=temp;
        p->next=NULL;
        if(list==NULL)//linked list does not exist
        {
            cout<<"\nFirst node has been created\n";
            list=p;
        }
        else//linked list exists
        {
            q=list;
            while(q->next!=NULL)
            {
                q=q->next;
            }
            q->next=p;
        }
//        cout<<"Num of nodes:"<<counter;
    }
    void menu()
    {
        int choice;
        do {
            cout<<"Enter choice:\n1.Insert Node\t2. Check Palindrome\t3.Display\t4.Exit\n";
            cin>>choice;
            switch (choice)
            {
                case 1:
                    insert();
                    break;
                case 2:
                    palindrome();
                    break;
                case 3:
                    show_data();
                    break;
                case 4:
                    break;
                default:
                    cout<<"Incorrect choice.\n";
            }
        }while(choice!=4);
    }
    void palindrome()
    {
        int mid;
        if(counter==1)//only 1 node
        {
            cout<<"Enter more elements!\n";
            menu();
        }
        else if(counter==2)//only 2 nodes
        {
            if(list->data==list->next->data)
            {
                flag=true;
            }
            else
            {
                flag=false;
            }
        }
        if(counter%2==0)//even number of nodes
        {
            mid=counter/2;
            q=list;
            while(mid>0)
            {
                p=q;
                q=q->next;
                mid--;
                //p points to last node of first half
                //q points to first node of 2nd half
            }
        }
        else//odd number of nodes
        {
            mid=counter/2+1;
            q=list;
            while(mid>0)
            {
                r=p;
                p=q;
                q=q->next;
                mid--;
                //p points to node before the middle node
                //q points to node after middle node
            }
                p=r;
        }
        if(counter>2)
        {
            do{
                if(p->data==q->data)
                {
                    flag=true;
                    r=list;
                    while(r->next!=p && p!=list)
                    {
                        r=r->next;
                    }
                    p=r;
                    if(q->next!=NULL)
                        q=q->next;
                }
                else if(p->data!=q->data)
                {
                    flag=false;
                    break;
                }
            }while(q->next!=NULL && p!=list);
        }
        if(flag)
        {
            cout<<"Palindrome.\n";
        }
        else
        {
            cout<<"Not Palindrome.\n";
        }
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
            while(q!=NULL)
            {
                cout<<q->data<<"---->";
                q=q->next;
            }
            cout<<"\n";
        }
    }
};
int main()
{
    palindromell obj1;
    obj1.menu();
}
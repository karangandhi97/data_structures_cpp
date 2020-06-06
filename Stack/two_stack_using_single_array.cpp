//
// Created by Karan on 5/8/2020.
//

#include<iostream>
using namespace std;
class twostackusingarray
{
public:
    int *array,size,top1,top2,stacksize;
    twostackusingarray()
    {
        top1=-1;
    }
    void get_data() {
        cout << "Enter Size of Stack:";
        cin >> size;
        stacksize=2*size;
        array = new int[stacksize];
        top2 = (size/2)+1;
    }
    void menu()
    {
        int choice;
        do{
            cout<<"\nEnter choice: \n1.Stack One\t2.Stack Two\t3.Exit\n";
            cin>>choice;
            switch(choice)
                {
                    case 1:
                        stackone();
                        break;
                    case 2:
                        stacktwo();
                        break;
                    case 3:
                        break;
                    default:
                        cout<<"Incorrect choice.\n";
                }
            }while(choice!=3);
    }
    void stackone()
    {
        int choice;
        do{
            cout<<"Enter choice for stack 1: \n1.Push\t2.Pop\t3.Display\t4.Go Back\n";
            cin>>choice;
            switch(choice)
            {
                case 1:
                    pushone();
                    break;
                case 2:
                    popone();
                    break;
                case 3:
                    displayone();
                    break;
                case 4:
                    menu();
                    break;
                default:
                    cout<<"Incorrect choice.\n";
            }
        }while(choice!=4);
    }
    void stacktwo()
    {
        int choice;
        do{
            cout<<"Enter choice for stack 2: \n1.Push\t2.Pop\t3.Display\t4.Go Back\n";
            cin>>choice;
            switch(choice)
            {
                case 1:
                    pushtwo();
                    break;
                case 2:
                    poptwo();
                    break;
                case 3:
                    displaytwo();
                    break;
                case 4:
                    menu();
                    break;
                default:
                    cout<<"Incorrect choice.\n";
            }
        }while(choice!=4);
    }
    void pushone()
    {
        int data;
        if(top1>(size/2))
        {
            cout<<"Stack 1 overflow.\nStack 1 is full\n";
        }
        else if(top1<=size/2)
        {
            cout<<"Enter data to be pushed into stack 1:\t";
            cin>>data;
            top1++;
            array[top1]=data;
        }        cout<<endl;

    }
    void pushtwo()
    {
        int data;
        if(top2>size+1)
        {
            cout<<"Stack 2 overflow.\nStack 2 is full\n";
        }
        else if(top2<=size+1)
        {
            cout<<"Enter data to be pushed into stack 2:\t";
            cin>>data;
            top2++;
            array[top2]=data;
        }
        cout<<endl;
    }
    void popone()
    {
        int data;
        if(top1>-1)
        {
            data=array[top1];
            top1--;
            cout<<"Popping the topmost element:\t"<<data<<"\n";
        }
        else if(top1==-1)
        {
            cout<<"Stack 1 underflow.\nStack 1 is empty\n";
        }        cout<<endl;

    }
    void poptwo()
    {
        int data;
        if(top2>(size/2)+1)
        {
            data=array[top2];
            top2--;
            cout<<"Popping the topmost element:\t"<<data<<"\n";
        }
        else if(top2==(size/2)+1)
        {
            cout<<"Stack 2 underflow.\nStack 2 is empty\n";
        }	        cout<<endl;

    }
    void displayone()
    {if(top1>-1)
        {
            cout<<"Data\tLocation\n";
            for(int i=top1;i>=0;i--)
            {
                cout<<array[i]<<"\t"<<i<<"\n";
            }
        }
        else if(top1==-1)
        {
            cout<<"Stack is empty.\n";
        }
    }
    void displaytwo()
    {
        if(top2>=size/2)
        {
            cout<<"Data\tLocation\n";
            for(int i=top2;i>(size/2)+1;i--)
            {
                cout<<array[i]<<"\t"<<i<<"\n";
            }
        }
        else if(top2==size+1)
        {
            cout<<"Stack is empty.\n";
        }
    }
};
int main()
{
    twostackusingarray obj1;
    obj1.get_data();
    obj1.menu();
}
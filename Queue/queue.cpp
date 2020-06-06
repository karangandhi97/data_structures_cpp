#include<iostream>
using namespace std;
class que
{
    int rear,front,choice,size,q[100],data;
public:
    que()
    {
        rear=-1;
        front=0;
    }
    void get_data()
    {
        cout<<"Enter size of queue:\t";
        cin>>size;
        do{
            cout<<"Enter your choice:\n1.Enqueue\n2.Dequeue\n3.Display Queue\n4.Exit\n";
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
                    cout<<"Invalid choice.";

            }
        }while(choice!=4);
    }
    void enqueue()
    {
        if(rear<size-1)
        {
            rear++;
            cout<<"Enter data:\t";
            cin>>q[rear];
        }
        else
        {
            cout<<"Queue overflow.\n";
        }
    }
    void dequeue()
    {
        if(front<=rear)
        {
            cout<<q[front]<<" has been deleted from the queue.\n";
            front++;
        }
        else
        {
            cout<<"Queue underflow.\n";
        }
    }
    void show_data()
    {
        if(rear>front)
        {
            cout<<"Data:\t\t";
            for(int i=front;i<=rear;i++)
            {
                cout<<q[i]<<"\t";
            }
            cout<<"\nLocation:\t";
            for(int i=front;i<=rear;i++)
            {
                cout<<i<<"\t";
            }
            cout<<"\n";
        }
        else
        {
            cout<<"Queue is empty.\n";
        }
    }
};
int main()
{
    que obj1;
    obj1.get_data();
}

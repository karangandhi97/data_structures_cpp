#include<iostream>
using namespace std;
class cque
{
    int rear,front,choice,size,q[100],data,finc;
	bool flag;
public:
    cque()
    {
        rear=-1;
        front=-1;
        finc=0;
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
        int rold;
	flag=false;
        rold=rear;
        rear=(rear+1)%size;
        if(front==rear && front!=-1)
        {
            cout<<"Queue overflow.\n";
            rear=rold;
        }
        else
        {
            if(finc==0) {
                front=0;
                finc++;
            }
            cout<<"Enter data:\t";
            cin>>q[rear];
        }
    }
    void dequeue()
    {
        int flod;
        if(front==-1)
        {
            cout<<"Queue underflow.\n";
        }
        else
        {
            cout<<q[front]<<" has been deleted from the queue.\n";
            if(front==rear)
            {flag=true;
                front=-1;
                rear=-1;
finc=0;
            }
            else {
                front = (front + 1) % size;
            }
        }
    }
    void show_data()
    {
            if(front>rear) {
                cout << "Data:\t\t";
                for (int i = 0; i <=rear; i++)
                {
                    cout << q[i] << "\t";
                }
                for (int i = front; i <size; i++)
                {
                    cout << q[i] << "\t";
                }
                cout << "\nLocation:\t";
                for (int i = 0; i <=rear; i++)
                {
                    cout << i << "\t";
                }
                for (int i = front; i <size; i++)
                {
                    cout << i << "\t";
                }
                cout<<endl;
            }
            else if(flag)
            {
                cout<<"Circular Queue is empty.\n";
            }

            else
            {
                cout << "Data:\t\t";
                for (int i=front;i<=rear;i++)
                {
                    cout << q[i] << "\t";
                }
                cout << "\nLocation:\t";
                for (int i=front;i<=rear;i++)
                {
                    cout << i << "\t";
                }
                cout<<endl;
            }
    }
};
int main()
{
    cque obj1;
    obj1.get_data();
}

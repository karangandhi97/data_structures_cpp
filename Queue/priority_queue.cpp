//
// Created by Karan on 5/8/2020.
//

#include<iostream>
using namespace std;
class priorityqueue
{
public:
    int *array1,*array2,size,rear,front;
    priorityqueue()
    {
        rear=-1;
        front=0;
    }
    void get_data()
    {
        cout<<"Enter size of priority queue:";
        cin>>size;
        array1=new int[size];
        array2=new int[size];
        menu();
    }
    void menu()
    {
        int choice;
        do{
            cout<<"Enter choice: 1.Enqueue\t2.Dequeue\t3.Display\t4.Exit\n";
            cin>>choice;
            switch (choice)
            {
                case 1:
                    enqueue();
                    break;
                case 2:
                    dequeue();
                    break;
                case 3:
                    show_data();
                case 4:
                    break;
                default:
                    cout << "Incorrect choice.\n";
            }
        }while(choice!=4);
    }
    void enqueue()
    {
        if(rear<size-1)
        {
            rear++;
            cout<<"Enter data:";
            cin>>array1[rear];
            cout<<"Enter priority:";
            cin>>array2[rear];
            sort();
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
            cout<<array1[front]<<" has been deleted from the queue.\n";
            front++;
        }
        else
        {
            cout<<"Queue underflow.\n";
        }
    }
    void show_data()
    {
        if(rear<front)
        {
            cout<<"Queue is empty.\n";
        }
        else
        {
            cout<<"Data:\t\t";
            for(int i=front;i<=rear;i++)
            {
                cout<<array1[i]<<"\t";
            }
            cout<<"\nPriority:\t";
            for(int i=front;i<=rear;i++)
            {
                cout<<array2[i]<<"\t";
            }
            cout<<"\nLocation:\t";
            for(int i=front;i<=rear;i++)
            {
                cout<<i<<"\t";
            }
            cout<<"\n";
        }
    }
    void sort() {
        int temp;
        for (int i = 1; i < rear; i++) {
            for (int j = 0; j < rear ; j++) {
                if (array2[j] < array2[j + 1]) {
                    temp = array1[j];
                    array1[j] = array1[j + 1];
                    array1[j + 1] = temp;
                    temp = array2[j];
                    array2[j] = array2[j + 1];
                    array2[j + 1] = temp;
                }
            }
        }
    }
};
int main()
{
    priorityqueue obj1;
    obj1.get_data();

}
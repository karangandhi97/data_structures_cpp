//
// Created by Karan on 5/15/2020.
//

#include<iostream>
using namespace std;
class adj_mat
{
public:
    int **matrix;
    int nodes,rear,front,top;
    adj_mat()
    {
        rear=0;
        front=0;
        top=-1;
    }
    void get_data()
    {
        cout<<"Enter number of nodes in the graph:";
        cin>>nodes;
        matrix=new int*[nodes];
        for(int i=0;i<nodes;i++)
        {
            matrix[i] = new int[nodes];
        }
    }
    void get_matrix()
    {
        cout<<"Enter Adjacency Matrix:\n";
        for(int i=0;i<nodes;i++)
        {
            for(int j=0;j<nodes;j++)
            {
                cout<<"From node "<<i<<" to node "<<j<<" :";
                cin>>matrix[i][j];
                if(matrix[i][j]!=1 && matrix[i][j]!=0)
                {
                    cout<<"Incorrect input. Try again!\n";
                    j--;
                }
            }
        }
    }
    void show_data()
    {
        cout<<"Adjacency Matrix:\n\t";
        for(int i=0;i<nodes;i++)
        {
            cout<<"Node "<<i<<"\t";
        }
        cout<<"\n";
        for(int i=0;i<nodes;i++)
        {
            cout<<"Node "<<i<<"\t";
            for(int j=0;j<nodes;j++)
            {
                cout<<matrix[i][j]<<"\t";
            }
            cout<<"\n";
        }
    }
    void menu()
    {
        int choice;
        do{
            cout<<"\nEnter choice:\n1.Display Adjacency Matrix.\n2.Breadth First Search.\n3.Depth First Search.\n4.Exit.\n";
            cin>>choice;
            switch(choice)
            {
                case 1:
                    show_data();
                    break;
                case 2:
                    bfs();
                    break;
                case 3:
                    dfs();
                    break;
                case 4:
                    break;
                default:
                    cout<<"Incorrect choice.\n";
            }
        }while(choice!=4);
    }
    void bfs()
    {
        int visited[nodes];//array to keep count of nodes that have visited the queue
        for(int i=0;i<nodes;i++)
        {
            visited[i]=0;//setting all nodes as not visited
        }
        int passes=0;
        int sequence[nodes];//to store final sequence of bfs
        int q[nodes];//queue for traversal
        q[rear]=0;//entering first node as NODE 0
        rear++;
        cout<<"Pass: "<<passes<<"\nFront: "<<front<<"\nRear: "<<rear<<"\nQueue: "<<q[0]<<"\n";
        visited[0]=1;//marking first NODE 0 as visited
        passes++;
        for(int i=0;i<nodes;i++)
        {
            for(int j=0;j<nodes;j++)
            {
//                cout<<"at ("<<i<<","<<j<<")\n";//to check iteration values
                if(matrix[front][j]==1 && visited[j]==0)//checking adjacent nodes have visited or not
                {
                    q[rear]=j;//enqueue in queue
                    rear++;
                    visited[j]=1;//mark as visited
//                    cout<<q[rear]<<" is inserted\n";//to check which node is inserted
                }
            }

            sequence[i]=q[front];
            front++;
            cout<<"Pass: "<<passes<<"\nFront: "<<front<<"\nRear: "<<rear<<"\nQueue: ";
            passes++;
            for(int z=front;z<rear;z++)
            {
                    cout<<q[z]<<" ";//displaying current queue
            }
            if(front==rear)
            {
                cout<<"NULL";
            }
            cout<<"\n";
            cout<<"\n";
//            cout<<q[front]<<" is deleted\n";//to check which node was deleted
        }
        cout<<"\nBFS Sequence: ";
        for(int i=0;i<nodes;i++)
        {
            cout<<sequence[i]<<" ";//final sequence of bfs
        }
        cout<<"\n";

    }
    void dfs()
    {
        int visited[nodes];//array to keep count of nodes that have visited the queue
        int sequence[nodes];//to store final sequence of dfs
        for(int i=0;i<nodes;i++)
        {
            visited[i]=0;//setting all nodes as not visited
        }
        int stack[nodes];//stack for traversal
        top++;
        int passes=0;
        int temp;
        stack[top]=0;//entering first node as NODE 0
        visited[top]=1;//marking first NODE 0 as visited
        for(int i=0;i<nodes;i++)
        {
            cout<<"Pass: "<<passes<<"\nTop: "<<top<<"\nStack: ";
            sequence[i]=stack[top];
            passes++;
            temp=stack[top];
            for(int z=0;z<=top;z++)
            {
                cout<<stack[z]<<" ";//displaying current stack
            }
            top--;
            cout<<"\n";
//            cout<<stack[top]<<" is deleted\n";//to check node that is deleted
            for(int j=0;j<nodes;j++)
            {
//                cout<<"at ("<<i<<","<<j<<")\n";//to check iteration
                if(matrix[temp][j]==1 && visited[j]==0)//check adjacent nodes have visited or not
                {
                    top++;
                    stack[top]=j;
                    visited[j]=1;//marking nodes as visited
//                    cout<<stack[top]<<" is inserted\n";//  to check nodes inserted in stack
                }
            }
            cout<<"\n";
        }
        cout<<"Pass: "<<passes<<"\nTop: "<<top<<"\nStack: ";
        if(top==-1)
        {
            cout<<"NULL";
        }
        cout<<"\n";
        cout<<"\nDFS Sequence: ";
        for(int i=0;i<nodes;i++)
        {
            cout<<sequence[i]<<" ";//display final dfs sequence
        }
        cout<<"\n";
    }
};
int main()
{
    adj_mat obj1;
    obj1.get_data();
    obj1.get_matrix();
    obj1.menu();
}

//test cases:
//6 0 1 1 1 0 0 1 0 0 0 1 0 1 0 0 0 1 0 1 0 0 0 0 1 0 1 1 0 0 1 0 0 0 1 1 0
//9 0 1 1 1 1 0 0 0 0 1 0 1 0 0 1 0 0 0 1 1 0 1 0 1 1 0 0 1 0 1 0 1 0 1 1 0 1 0 0 1 0 0 0 0 0 0 1 1 0 0 0 1 0 1 0 0 1 1 0 1 0 1 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 1 0 0 0
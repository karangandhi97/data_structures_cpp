//
// Created by Karan on 3/30/2020.
//
#include<iostream>
#include<cmath>
using namespace std;
class hs
{
public:

    void get_data()
    {
        int n;
        int choice;
        cout<<"Enter array size:";
        cin>>n;
        int arr[n];
        cout<<"Enter array:\n";
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cout<<"\n1.Maximum Heap(Descending).\n2.Minimum Heap(Ascending).\n3.Heap Sort.\n4.Exit.\n";
        do
        {
            cout<<"Enter choice:";
            cin>>choice;
            switch(choice)
            {
                case 1:
                    max(arr,n);
                    cout<<"Array representation:\n";
                    show_data(arr,n);
                    cout<<"\n";
                    cout<<"Tree representation:\n";
                    show_tree(arr,n);
                    break;
                case 2:
                    min(arr,n);
                    cout<<"Array representation:\n";
                    show_data(arr,n);
                    cout<<"\n";
                    cout<<"Tree representation:\n";
                    show_tree(arr,n);
                    break;
                case 3:
                    int x;
                    cout<<"1.Using max heap.\n2.Using min heap.\n";
                    cin>>x;
                    switch(x)
                    {
                        case 1:
                            max(arr,n);
                            cout<<"Sorted Array:\t";
                            show_data(arr,n);
                            cout<<"\n";
                            break;
                        case 2:
                            min(arr,n);
                            cout<<"Sorted Array:\t";
                            show_data(arr,n);
                            cout<<"\n";
                            break;
                        default:
                            cout<<"Invalid choice.\n";
                            break;
                    }
                    break;
                case 4:
                    break;
                default:
                    cout<<"Invalid choice.\n";
                    break;
            }
        }while(choice!=4);
    }
    void maxheapify(int arr[], int n, int i)
    {
        int smallest = i; // root
        int l=2*i+1; // left child
        int r=2*i+2; // right child
        int temp;
        if(r<n && arr[r]<arr[smallest])
        {
            smallest=r;
        }
        if(l<n && arr[l]<arr[smallest])
        {
            smallest=l;
        }
        if(smallest!=i)
        {
            temp=arr[i];
            arr[i]=arr[smallest];
            arr[smallest]=temp;
            maxheapify(arr, n, smallest);
        }
    }
    void minheapify(int arr[], int n, int i)
    {
        int largest = i; //  root
        int l=2*i+1; // left child
        int r=2*i+2; // right child
        int temp;
        if (l<n && arr[l]>arr[largest])
        {
            largest=l;
        }
        if(r<n && arr[r]>arr[largest])
        {
            largest=r;
        }
        if(largest!=i)
        {
            temp=arr[i];
            arr[i]=arr[largest];
            arr[largest]=temp;
            minheapify(arr, n, largest);
        }
    }
    void min(int arr[], int n)
    {
        int temp;
        for(int i=n/2-1;i>-1;i--)
        {
            minheapify(arr, n, i);
        }
        for(int i=n-1;i>-1;i--)
        {
            temp=arr[0];
            arr[0]=arr[i];
            arr[i]=temp;
            minheapify(arr, i, 0);
        }
    }
    void max(int arr[], int n)
    {
        int temp;
        for(int i=n/2-1;i>-1;i--)
        {
            maxheapify(arr, n, i);
        }
        for(int i=n-1;i>-1;i--)
        {
            temp=arr[0];
            arr[0]=arr[i];
            arr[i]=temp;
            maxheapify(arr, i, 0);
        }
    }
    void show_data(int arr[], int n)
    {
        for (int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
    void show_tree(int arr[],int n)
    {
        int max=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<pow(2,i) && j+pow(2,i)<n;j++)
            {
                if(j>max)
                {
                    max=j;
                }
            }
        }
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<pow(2,i) && j+pow(2,i)<=n;j++)
            {
                for(int k=0;(k<max/((int)pow(2,i)));k++)
                {
                    cout<<"  ";
                }
                cout<<arr[j+(int)pow(2,i)-1]<<"   ";
            }
            cout<<"\n";
        }
    }
};
int main()
{
    hs obj1;
    obj1.get_data();
}
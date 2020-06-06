#include<iostream>
using namespace std; 
class Insertion
{
	int array[100];
	int passes,size;
	public:
	Insertion(){passes=1;size=0;}
	void get_data()
	{
		cout<<"Enter size of array:\n";
		cin>>size;
		cout<<"Enter values of the array:\n";
		for(int i=0;i<size;i++)
		{
			cin>>array[i];
		}
	}
void logic()  
{  
	bool flag;
    int i,key,j;  
    for (i=1;i<size;i++) 
    {  
        key=array[i];  
        j=i-1;  
        while(j>=0 && array[j]>key) 
        {  
            array[j+1]=array[j];  
            j=j-1;  
            flag=true;
        }  
        array[j+1]=key;  
        if(flag)
		{
			show_data();
			passes++;
		}
		else if(!flag)
			{
				cout<<"\nArray entered is in ascending order.";
				break;
			}

    }  
}  
void show_data()  
{
	cout<<"Pass:\t"<<passes;
	cout<<"\n Array:\t";
	for(int i=0;i<size;i++)  
        cout<<array[i]<<" ";  
    cout<<endl; 
}  
};
int main()  
{  
	Insertion obj1;
	obj1.get_data();
	obj1.logic();
}  
  

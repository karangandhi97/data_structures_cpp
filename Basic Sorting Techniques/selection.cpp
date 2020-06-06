#include<iostream>
using namespace std;
class Selection
{
	int array[100];
	int passes,size,temp,i,j,smallest;
	public:
	Selection(){passes=1;}
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
	{  bool flag;
    	for(i=0;i<size-1;i++)
    	{    flag=false;
        smallest=i;  
        for(j=i+1;j<size;j++)  
        { 
		if(array[j]<array[smallest])  
        {
		    smallest = j;  
		    flag=true;
		}
		}
		if(array[i]>array[smallest])
        {
		temp=array[smallest];  
    	array[smallest]=array[i];  
    	array[i]=temp;
    }	if(flag)
		{
			show_data();
			passes++;
		}
		else
		{
			else if(passes<1)
            {
				cout<<"\nArray entered is in ascending order.";
				break;
			}
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
	Selection obj1;
	obj1.get_data();
	obj1.logic();
}  
   

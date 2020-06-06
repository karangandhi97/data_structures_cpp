#include<iostream>
using namespace std;
class Binarysearch
{
	public:
	int array[100],size,key,i,j,mid,low,high,temp;
	bool flag1;
	void set_data()
	{	
		cout<<"Enter size of array:\n";
		cin>>size;
		cout<<"Enter elements for the array:\n";
		for(i=0;i<size;i++)
		{	
			cin>>array[i];
		}
		sort();
		cout<<"Enter the key element to be searched within the array:\t";
		cin>>key;
	}
	void sort()
	{
		for(i=1;i<size;i++)
		{
			for(j=0;j<size-1;j++)
			{
				if(array[j]>array[j+1])
				{
					temp=array[j];
					array[j]=array[j+1];
					array[j+1]=temp;
				}
			
			}
		
		}
		show_data();
	}
		void logic()
	{	
		low=0;
		high=size-1;
		flag1=false;
		while(low<=high)
		{	
			mid=(low+high)/2;
			if(array[mid]==key)
			{
				flag1=true;
				cout<<"Key element found in the array at index: "<<mid<<" OR position: "<<mid+1<<endl;
				break;
			}
			else if(key>array[mid])
			{
				low=mid+1;
				
			}
			else if(key<array[mid])
			{
				high=mid-1;
				
			}
		}
		if(!flag1)
		{
			cout<<"Key element not found in the array.\n";	
		}
	}
	void show_data()
	{
		cout<<"The elements of array.\n";
		for(int i=0;i<size;i++)
		{
			cout<<array[i]<<"\t";
		}
		cout<<endl;
	}
};
int main()
{
	Binarysearch obj1;
	obj1.set_data();
	obj1.logic();
}

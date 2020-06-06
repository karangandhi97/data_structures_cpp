#include<iostream>
using namespace std;
class Linearsearch
{
	public:
	int array[100],size,key,i;
	bool flag;
	void set_data()
	{	
		cout<<"Enter size of array:\n";
		cin>>size;
		cout<<"Enter elements for the array:\n";
		for(i=0;i<size;i++)
		{	
			cin>>array[i];
		}
		cout<<"Enter the key element to be searched within the array:\t";
		cin>>key;
	}
	void logic()
	{
		for(i=0;i<size;i++)
		{
			flag=false;
			if(array[i]==key)
			{
				flag=true;
				cout<<"Key element found in the array at index: "<<i<<" OR position: "<<i+1<<endl;
				break;
			}
	
		}
		if(!flag)
		{
			cout<<"Key element not found in the array.\n";
			array[size]=key;
			show_data();		
		}
	}
	void show_data()
	{
		cout<<"The elements of array.\n";
		for(int i=0;i<size+1;i++)
		{
			cout<<array[i]<<"\t";
		}
		cout<<endl;
	}
};
int main()
{
	Linearsearch obj1;
	obj1.set_data();
	obj1.logic();
}

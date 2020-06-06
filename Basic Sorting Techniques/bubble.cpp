#include<iostream>
using namespace std;
class Bubble
{

	int array[100];
	int passes,size_array,tempvar;
	public:
	Bubble(){passes=1;size_array=0;}
	void get_data()
	{
		cout<<"Enter size of array:\n";
		cin>>size_array;
		cout<<"Enter values of the array:\n";
		for(int i=0;i<size_array;i++)
		{
			cin>>array[i];
		}
	}
	void logic()
	{	bool flag;
		for(int i=1;i<size_array;i++)
		{
			flag=false;
		for(int j=0;j<size_array-1;j++)
		{
			if(array[j]>array[j+1])
			{
				flag=true;
				tempvar=array[j];
				array[j]=array[j+1];
				array[j+1]=tempvar;
			}
			
		}
		if(flag)
		{
			show_data();
			passes++;
		}
		else
		{
			if(passes<=1)
			{
				cout<<"\nArray entered is in ascending order.";
				break;
			}
		}
		
	}
}
	void show_data()
	{	cout<<"\nPasses taken: "<<passes<<" ";
		cout<<"Array: ";
		for(int i=0;i<size_array;i++)
		{
			cout<<array[i]<<" ";
		}
		cout<<endl;
	}
};
int main()
{
	Bubble object1;
	object1.get_data();
	object1.logic();
	return 0;
}


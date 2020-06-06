#include <iostream>
using namespace std;
int array[100];
int size;
static int passes=1;
class Quick
{
	public:
	void set_data()
	{
		cout<<"Enter size:"<<endl;
		cin>>size;
		cout<<"Enter elements:\n";
		for(int i=0;i<size;i++)
		{
			cin>>array[i];
		}
	}
	bool issorted()
	{
		bool flag=true;
		for(int i=0;i<size-1;i++)
		{
			if(array[i]>array[i+1])
			{ 
				flag=false;
				break;
			}
		}
			return flag;
	}
		
	int iteration(int array[],int low, int high)
	{
		int j=high+1;
		int pivot=array[low];
		int i=low;
		int temp=0;
		do
		{
	       		do
        		{
				i++;
			}while(array[i]<pivot&&i<=high);
               		do
            		{
				j--;
        		}while(pivot<array[j]);
               		if(i<j)
        		{
        	    		temp=array[i];
        	    		array[i]=array[j];
        	    		array[j]=temp;
        		}
        	}while(i<j);
			array[low]=array[j];
    			array[j]=pivot;
    			return j;
		}
		void logic(int array[],int low, int high)
		{	
			    int j;
    			if(low<high && !issorted())
    			{
				j=iteration(array,low,high);
				cout<<"Pass:"<<passes;
				show_data();
				passes++;
				logic(array,low,j-1);
				logic(array,j+1,high);
			}
			else if (issorted())
			{
				cout<<"Elements are in ascending order.\n";
			}
		}
		void show_data()
		{	
			cout<<"\nElements:\t";
			for(int i=0;i<size;i++)
			{
				cout<<array[i]<<"\t";
			}
			cout<<endl;
		}			
};

int main()
{
	Quick obj1;
	obj1.set_data();
	int i=0,j=size-1;
	obj1.logic(array,i,j);
}
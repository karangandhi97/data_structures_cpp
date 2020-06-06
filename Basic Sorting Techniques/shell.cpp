#include<iostream>
#include<cmath>
using namespace std;
class Shell
{
	public:
		int array[100];
		int size,passes,temp;
		Shell()
		{
		passes=1;
	}
		void set_data() 
		{
	        cout<<"Enter size:\n";
	        cin>>size;
	        cout<<"Enter elements:\n";
	        for(int i=0;i<size;i++)
			{
	            cin>>array[i];
	        }
	    }
		
		bool isSorted()
		{	bool flag=true;
			for(int i=0;i<size-1;i++)
			{
				if(array[i]>array[i+1])
				{
					flag=false;
				}}
			return flag;
		}
		
		void logic()
		{	
			int increment=ceil(double(size/2.0));
            while(increment>=1)
			{if(isSorted()) {
                    cout<<"Data is in ascending order.\n";
                    break;
                }
				for(int i=0;i<size;i++)
				{
					for(int j=i;j<size-increment;j+=increment)
					{	
						if(array[j]>array[j+increment])
						{
							temp=array[j];
							array[j]=array[j+increment];
							array[j+increment]=temp;
						}		
					}
				}
				increment=ceil(double(increment/2.0));
				show_data();
				passes++;

			}
		}
		

	void show_data()
	{
		cout<<"Pass:"<<passes;
		cout<<"\nElements:\n";				
        for(int i=0;i<size;i++)
		{
            cout<<array[i]<<"\t";
        }
        cout<<endl;
    }		
};


int main()
{
	Shell obj1;
	obj1.set_data();
    obj1.logic();
	return 0;
}
	

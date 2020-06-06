#include <iostream>
using namespace std;
class Radix
{
	public:
		int array1[100],array2[100],i,j,k,l,passes,mod,size,msd,condition;
		Radix()
		{
			passes=0;
			mod=1;
			msd=0;
		}
		void set_data()
		{
			cout<<"Enter number of elements in array"<<endl;
			cin>>size;
			cout<<"Enter elements inside the array \n";
			for(int i=0;i<size;i++)
			{
				cin>>condition;
				if(condition<0)
				{
					cout<<condition<<" can not be inserted.\nEnter another element:";
					i--;
					continue;
				}
				array1[i]=condition;	
			}
		}

		bool isSorted()
		{	bool flag=true;
			for(int i=0;i<size-1;i++)
			{
				if(array1[i]>array1[i+1])
				{
					flag=false;
				}
			}
			return flag;
		}

		void logic()
		{	
			int largest=array1[0]; 
			for(i=1;i<size;i++) 
			{ 
				if(array1[i]>largest) 
				{
					largest=array1[i]; 
				}
			} 
			while(largest>0)  
		    {  
	    	    passes++;  
	        	largest/=10;  
		    } 
		
		    for(i=0;i<passes;i++)
		    {	
		    	if(isSorted())
		    	{
		    	    cout<<"Data already in ascending order.\n";
		    		break;
			}
			l=0;
			mod*=10;
		    	for(j=0;j<9;j++)
		    	{
		   		for(k=0;k<size;k++)
		    		{
		    			msd=array1[k]%mod/(mod/10);
		    			if(j==msd)
		    			{	
							array2[l]=array1[k];
		    				l++;
					}
				}
			}
				for(int m=0;m<size;m++)
				{
					array1[m]=array2[m];
				}
				cout<<"Pass:"<<i+1<<endl;;
				show_data();
			}
		}
		
		void show_data()
		{	
			cout<<"Elements:\n";
			for(int i=0;i<size;i++)
			{
				cout<<array1[i]<<"\t";
			}
			cout<<endl;
		}
};

int main()
{
	Radix obj1;
	obj1.set_data();
	obj1.logic();
	return 0;
}

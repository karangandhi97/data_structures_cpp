#include <iostream>
#include <cmath>
using namespace std;
class midsquare
{
    public:
    int array1[100],array2[100];
    int size1,size2;
    void getdata()
    {
        cout<<"Enter number of key values: "<<endl;
        cin>>size1;
        cout<<"Enter number of locations: "<<endl;
        cin>>size2;
        for(int i=0;i<size2;i++)
        {
            array2[i]='\0';
        }
        cout<<"Enter key values: "<<endl;
        for(int i=0;i<size1;i++)
        {
            cin>>array1[i];
            if(array1[i]<0)
            {
            	cout<<"Data cannot be negative. Insert data again.\n";
            	i--;
            	continue;
			}
        }
      
    }
    int length(int sq)
    {	int len=0;
    	     if(sq==0)
            	len=1;
            else{
				while(sq>0)  
		    {  
	    	    len++;  
	        	sq/=10;  
		    } 
		}
		return len;
	}
	int midval_ext(int sq)
  	{		
	  		int mod,tmp,len,mid,p,mid_val;
            len=length(sq);
		int i=len-1;
		mid_val=sq;
		while(mid_val>size2)
            {
            	if(i==1)
            		mid_val%=10;
            	else if(i==2 && len%2==0)
            		mid_val%=10;
            		else
            		{
            			p=pow(10,i);
            			mid_val=mid_val%p/10;
           			 	i--;
         		   }
			}
            return mid_val;
  		
	  }
      void mid_sq()
    
    {
        int ml,sq;
        for(int i=0;i<size1;i++)
        {
            sq=array1[i]*array1[i];
            ml=midval_ext(sq);
            while(array2[ml]!='\0')
                {
                   ml++;
                   if(ml>=size2)
                      ml=0;
                }
            array2[ml]=array1[i];            
        }
        
    } 
    void show_data()
    {
    	cout<<"\nData\tLocation\n";
        for(int i=0;i<size2;i++)
        {
        	if(array2[2]=='\0')
        	{
        		continue;
        	}
				cout<<array2[i]<<"\t"<<i<<"\n";
        }
    }
};

int main()
{
    midsquare obj1;
    obj1.getdata();
    obj1.mid_sq();
    obj1.show_data();
    return 0;
}

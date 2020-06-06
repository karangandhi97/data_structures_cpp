#include<iostream>
#include<cmath>
using namespace std;
class foldboundary
{
    public:
    int array1[100],array2[100],size,loc,l_loc,sum,mod,temp2,location;
    float l_key;
    void get_data()
    {
        cout<<"Enter number of data elements:\t";
        cin>>size;
        cout<<"Enter number of locations:\t";
        cin>>loc;
        l_loc=length(loc-1);
        for(int i=0;i<loc;i++)
        {
            array2[i]='\0';
        }
        cout<<"Enter Data:\n";
        for(int i=0;i<size;i++)
        {
            cin>>array1[i];
            if(array1[i]<0)
            {
            	cout<<"Data cannot be negative. Insert again:\n";
            	i--;
            	continue;
			}
            temp2=array1[i];
            digit(temp2);
        }

    }
    int length(int k)
    {
        int len=0;
        int temp=k;
    	while(temp>0)
    	{
        	temp=temp/10;
	        len++;
	    }
        //	cout<<len;
	    return len;
    }
    void digit(int k)
    {
    	int key=k;
    	int counter=0;
    	sum=0;
    	int divisor=pow(10,l_loc);
    	int multiplier=pow(10,l_loc-1);
    	l_key=length(k);
    	l_key/=l_loc;
    	while(key!=0)
    	{
    		temp2=key%divisor;
    		key=key/divisor;
                if (counter == 0 || counter == (ceil(l_key)-1)) {
                    mod = temp2 % multiplier;
                    temp2 /= multiplier;
                    mod *= multiplier;
                    temp2 += mod;
                }
                sum += temp2;
                counter++;
		}
        sum%=divisor;
	    location=sum;
        while(array2[location]!='\0')
        {
            location++;
            if(location>=loc)
            {
                location=0;
            }
        }
        array2[location]=k;
    }
    void show_data()
    {
        cout<<"Data\tLocation\n";
        for(int i=0;i<loc;i++)
        {
            if(array2[i]=='\0')
            {
                continue;
            }
            cout<<array2[i]<<"\t"<<i<<"\n";
        }
    }
};
int main()
{
    foldboundary obj1;
    obj1.get_data();
    obj1.show_data();
}

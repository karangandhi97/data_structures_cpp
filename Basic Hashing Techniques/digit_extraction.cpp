#include<iostream>
#include<cmath>
using namespace std;
class digitextraction
{
	public:
    int array1[100],array2[100],size,loc,l_loc,mod,temp,location,dig,dig_place[100];
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
        cout<<"Enter number of digits to be extracted:\t";
        cin>>dig;
        cout<<"Enter digit place:";
        for(int i=0;i<dig;i++)
        {
        	cin>>dig_place[i];
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
			temp=array1[i];
			digit(temp);
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
	    return len;
    }
        void digit(int k)
    {
    	int modded=0;
  //  	int counter=1;
    	int num=0;
    	int key=k;
	 	l_key=length(key);
//	    n=l_key;
		//it=
//	    while(key!=0)
//		{
			int abcd;
			l_key=length(key);
			for(int i=0;i<dig;i++)
			{
			abcd=dig_place[i];
			int a=pow(10,abcd);
			int b=pow(10,abcd-1);
			modded=(k%a)/b;
	//		cout<<"MOD"<<modded<<endl;
			modded=(modded*pow(10,i));
			num+=modded;
//			cout<<"location"<<num<<endl;
			}
  

//		}		
		if(num>loc)
		{
			num%=loc;
		}
		location=num;
        while(array2[location]!='\0')
        {
            location++;
            if(location>=loc)
            {
                location=0;
            }
        }
        array2[location]=k;
        //cout<<"LOC:"<<location;
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
    digitextraction obj1;
    obj1.get_data();
	obj1.show_data();
}

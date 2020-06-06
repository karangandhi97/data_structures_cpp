#include <iostream>
using namespace std;
int array1[100],array2[100];
static int a;
class Modulo
{
    int size1,size2,i,temp,location;
    public:
    void get_data()
    {
        cout<<"Enter number of elements:";
        cin>>size1;
        cout<<"\nEnter elements:\n";
        for(i=0;i<size1;i++)
        {
            cin>>array1[i];
            if(array1[i]<0)
            {
            	cout<<"Data cannot be negative. Insert again:\n";
            	i--;
            	continue;
			}
        }
        cout<<"Enter number of locations:";
        cin>>size2;
        for(i=0;i<size2;i++)
        {
            array2[i]='\0';
        }
        for(i=0;i<size1;i++)
        {
            if(i<size2)
            {
             logic(array1[i]);
            }
            else if(i>=size2)
            {
                cout<<"\nAll elements will not be stored.\n";
            }
      }

    }
    void show_data()
    {
        cout<<"Data\tLocation\n";
        for(i=0;i<size2;i++)
        {
            cout<<array2[i]<<"\t"<<i<<"\n";
        }
    }
    void logic(int key)
    {
        location=key%size2;
        while(array2[location]!='\0')
        {
            location++;
            if(location>=size2)
            {
                location=0;
            }
        }
        array2[location]=key;
    }

};
int main()
{
    Modulo obj1;
    obj1.get_data();
    obj1.show_data();
    return 0;
}

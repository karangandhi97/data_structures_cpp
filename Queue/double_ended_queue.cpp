#include<iostream>
using namespace std;
class doubleque
{
    int lrear,lfront,rrear,rfront,choice,size,q[100],data;
    bool flag,is_empty;
public:
    doubleque()
    {
        lrear=-1;
        lfront=0;
        flag=false;
        is_empty=false;
    }
    void get_data()
    {
        cout<<"Enter size of queue:\t";
        cin>>size;
        rrear=size;
        rfront=size-1;
        do{
            cout<<"Enter your choice:\n1.Enqueue from left\n2.Dequeue from left\n3.Enqueue from right\n4.Dequeue from right\n5.Display Queue\n6.Exit\n";
            cin>>choice;
            switch(choice)
            {
                case 1:
                    lenqueue();
                    break;

                case 2:
                    ldequeue();
                    break;

                case 3:
                    renqueue();
                    break;

                case 4:
                    rdequeue();
                    break;

                case 5:
                    show_data();
                    break;

                case 6:
                    break;

                default:
                    cout<<"Invalid choice.";

            }
        }while(choice!=6);
    }
    void overflow()
    {
        if(lrear>=rrear) {
            if ((lrear > rfront && rfront > lfront) || (rrear < lfront && lfront>rfront)) {
                flag = false;
            } else {
                flag = true;
            }
        }
        if(lrear==size || rrear==-1)
        {
            flag=true;
        }
    }
    void lenqueue()
    {
        lrear++;
        flag=false;
        overflow();
        if(flag)
        {
            cout<<"Queue overflow.\n";
            lrear--;
        }
        else
        {
            cout<<"Enter data:\t";
            cin>>q[lrear];
        }
    }
    void ldequeue()
    {

        if(lfront>lrear && lfront!=0)
        {
            cout << "Queue is empty from left.\n";
            if(rfront<=rrear)
            {
                cout<<"Try dequeue from right.\n";
            }
        }
        else{
            cout<<q[lfront]<<" has been deleted from the queue.\n";
            lfront++;
        }
    }
    void renqueue()
    {
        rrear--;
        flag=false;
        overflow();
        if(flag)
        {
            cout<<"Queue overflow.\n";
            rrear++;
        }
        else
        {
            cout<<"Enter data:\t";
            cin>>q[rrear];
        }
    }
    void rdequeue()
    {
        if(rfront<rrear && rfront!=size-1) {
            cout << "Queue is empty from right.\n";

            if (lrear <= lfront) {
                cout << "Try dequeue from left.\n";
            }
        }
        else{
            cout<<q[rfront]<<" has been deleted from the queue.\n";
            rfront--;
        }
        cout<<"lf:"<<lfront<<endl;
        cout<<"lr:"<<lrear<<endl;
        cout<<"rf:"<<rfront<<endl;
        cout<<"rr:"<<rrear<<endl;
    }
    void isempty()
    {
		if(lfront>rfront && lrear<rrear)//everything deleted after overflow
        {is_empty=true;}
        else if(lrear==-1 && rrear==size)//nothing inserted
        {
            is_empty= true;
        }
        else if(lrear<lfront && rrear>rfront)//something deleted from both sides
        {
            is_empty=true;
        }
        else{
            is_empty=false;
        }
    }

    void show_data()
    {
        isempty();
        if(is_empty)
        {
            cout<<"Queue is empty.\n";
        }
        else
        {	cout<<"Data:\t\t";
            if(lrear>=lfront)
            {
                for(int i=lfront;i<=lrear;i++)
                {
                    cout<<q[i]<<"\t";
                }
            }
            if(rrear<=rfront)
            {
                for(int i=rrear;i<=rfront;i++)
                {
                    cout<<q[i]<<"\t";
                }
            }
            cout<<"\nLocation:\t";
            if(lrear>=lfront)
            {

                for(int i=lfront;i<=lrear;i++)
                {
                    cout<<i<<"\t";
                }
            }
            if(rrear<=rfront)
            {
                for(int i=rrear;i<=rfront;i++)
                {
                    cout<<i<<"\t";
                }

            }
            cout<<"\n";
        }
    }
};
int main()
{
    doubleque obj1;
    obj1.get_data();
}

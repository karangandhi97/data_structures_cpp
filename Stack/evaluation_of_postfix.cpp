#include<iostream>
#include<string>
using namespace std;
class eval
{
public:
    string ch;
    int top,stack[100],size,temp,sum;
    eval()
    {
        top=-1;
        temp=0;
        sum=0;
    }
    void get_data()
    {
        cout<<"Enter your array of expressions (separate characters using space):\n";
        getline(cin,ch);
        size=ch.length();
        verification();
    }
    void verification()
    {
        if(ch[2]=='+' || ch[3]=='+' ||ch[2]=='-' || ch[3]=='-'||ch[2]=='-' || ch[3]=='-'||ch[2]=='/' || ch[3]=='/' || ch[0]=='+' || ch[1]=='+' ||ch[0]=='-' || ch[1]=='-'||ch[0]=='-' || ch[1]=='-'||ch[0]=='/' || ch[1]=='/')
        {
            cout<<"First two characters cannot be operators.\n";
            get_data();
        }
        else
        {
            for(int i=0;i<size;i++)
            {
                if (ch[i]!=' ')
                {
                    if ((int) ch[i] - 48 >= 0 && (int) ch[i] - 48<=9)
                    {
                        temp += (int) ch[i] - 48;
                        if (ch[i+1]==' ')
                        {
                            evaluation(temp);
                            temp=0;
                        }
                        else
                        {
                            temp *= 10;
                        }
                    }
                    else if(ch[i]=='+' ||ch[i]=='-'|| ch[i]=='*'||ch[i]=='/')
                    {
                        temp=ch[i];
                        operate(temp);
                    }
                }
                else if(ch[i]==')')
                {
                    show_data();
                }
            }
        }
    }
    void evaluation(int t)
    {
        top++;
        stack[top]=t;
        show_data();
    }
    void operate(char op)
    {
        int b=stack[top];
        top--;
        int a=stack[top];
        top--;
        if(op=='+')
        {
            sum=b+a;
            evaluation(sum);
        }
        else if(op=='-')
        {
            sum=b-a;
            evaluation(sum);
        }
        else if(op=='*')
        {
            sum=b*a;
            evaluation(sum);
        }
        else if(op=='/')
        {
            sum=b/a;
            evaluation(sum);
        }
        temp=0;
    }
    void show_data()
    {
        if(top>-1)
        {
            cout<<"Data\tLocation\n";
            for(int i=top;i>=0;i--)
            {
                cout<<stack[i]<<"\t"<<i<<"\n";
            }
        }
        else if(top==-1)
        {
            cout<<"Stack is empty.\n";
        }
    }
};
int main()
{
    eval obj1;
    obj1.get_data();
}
//12 3 * 4 + 5 * )
#include<iostream>
#include<string>
using namespace std;
class intopost
{
	public:
	string str,exp;
	int stack[100];
	int top,size,weight1,weight2;
	intopost()
	{
		top=-1;
		exp="";
	}
	void get_data()
	{
		cout<<"Enter a valid expression:\t";
		cin>>str;
		size=str.length();
        if(str[0]!='(')
        {
            top++;
            stack[top]=40;
        }
        for(int i=0;i<size;i++)
		{
            if(str[i]=='^' ||str[i]=='+' ||str[i]=='*'||str[i]=='-'||str[i]=='/'||str[i]=='(' )
			{
			    push_operation(str[i]);
			}
			else if(((int)str[i]>=65 && (int)str[i]<=90) || ((int)str[i]>=97 && (int)str[i]<=122))
			{
				charac(str[i]);
			}
			else if(str[i]==')')
			{
				pop_operation();
			}

		}
	}
	void push_operation(char temp)
	{
	    weight1=priority(stack[top]);
        weight2=priority(temp);
        if(weight1==1||weight1==2||weight1==3)
        {
            if (weight2>=weight1)
            {
                charac(stack[top]);
                stack[top]=temp;
            }
            else
            {
                top++;
                stack[top]=(int)temp;	//store operator into stack
            }
        }
        else
        {
            top++;
            stack[top]=(int)temp;
        }
	}
	int priority(char temp)
    {
	    if(temp=='^')
	        return 1;
	    else if(temp=='*' || temp=='/')
	        return 2;
	    else if(temp=='+' || temp=='-')
	        return 3;
        else
            return 0;
    }
	void pop_operation()
	{
		char oprnd;
		char temp=stack[top];
		while(temp!='(')
		{
		if(top>-1)
		{	
			oprnd=stack[top];			
			top--;
			charac(oprnd);
		}
		else if(top==-1)
		{
			cout<<"Stack underflow.\n";
			break;
		}
		temp=stack[top];
		}
		top--;
	}
	void charac(char temp)
	{
		exp+=temp;
 	}
	void show_data()
	{
			cout<<"Expression:\n";
			cout<<exp<<endl;
    }
};
int main()
{
	intopost obj1;
	obj1.get_data();
	obj1.show_data();
	return 0;
}
//TEST CASE:(A+(B*C-(d/e^f)*g)*h)


#include<iostream>
#include<string>
using namespace std;

class balance
{
	public:
	string str,stack[100];
	int len,top,size;
	balance()
	{
	top=-1;
	size=100;
	}
	void get_data()
	{
		cout<<"Enter a string with paranthesis:\t";
		cin>>str;
		len=str.length();
	}
	void logic()
	{
		string temp;
		for(int i=0;i<len;i++)
		{
			if(str[i]=='(')
			{
				temp=str[i];			
				push_operation(temp);
			}
			else if(str[i]==')')
			{
				pop_operation();
			}
		}
	}
	void push_operation(string temp)
	{
		string data=temp;
		if(top>=size-1)
		{
			cout<<"Stack overflow.\n";
		}
		else if(top<size)
		{
			top++;
			stack[top]=data;

		}
	}
	void pop_operation()
	{
		if(top>-1)
		{	
			top--;
		}
		else if(top==-1)
		{
			cout<<"Stack underflow.\n";
		}	
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
			cout<<"Paranthesis unbalanced.";
		}
		else if(top==-1)
		{
			cout<<"Stack is empty. Paranthesis are balanced.";
		}
	}
};
int main()
{
	balance obj1;
	obj1.get_data();
	obj1.logic();
	obj1.show_data();
}

#include<iostream>
using namespace std;
class Stackk
{
	public:
	int top,array[100],size;
	Stackk()
	{
		top=-1;
	}
	void get_data()
	{
		cout<<"Enter size of stack: ";
		cin>>size;
	}
	void push_operation()
	{
		int data;
		if(top>=size-1)
		{
			cout<<"Stack overflow.\nStack is full\n";
		}
		else if(top<size)
		{
			cout<<"Enter data to be pushed into stack:\t";	
			cin>>data;
			top++;
			array[top]=data;
		}
	}
	void pop_operation()
	{
		int data;
		if(top>-1)
		{	
			data=array[top];
			top--;
			cout<<"Popping the topmost element:\t"<<data<<"\n";
		}
		else if(top==-1)
		{
			cout<<"Stack underflow.\nStack is empty\n";
		}	
	}
	void show_data()
	{
		if(top>-1)
		{
			cout<<"Data\tLocation\n";
			for(int i=top;i>=0;i--)
			{
				cout<<array[i]<<"\t"<<i<<"\n";
			}
		}
		else if(top==-1)
		{
			cout<<"Stack is empty.";
		}
	}
	void menu()
	{
		int choice,key;
		do{
		cout<<"Enter your choice:\n1.Push\t2.Pop\t3.Display stack\t4.Exit\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
			push_operation();
			break;
			case 2:
			pop_operation();
			break;
			case 3:
			show_data();
			break;
			case 4:
			break;
			default:
			cout<<"Invalid input.\n";
			break;
		}
		}while(choice!=4);
	}
};	
int main()
{
	Stackk obj1;
	obj1.get_data();
	obj1.menu();
}

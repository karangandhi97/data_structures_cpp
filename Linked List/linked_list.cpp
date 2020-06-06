#include<iostream>
#include<stdlib.h>
using namespace std;
class llist
{
	public:
	int choice,value;
	struct node
	{
	int data;
	struct node *next;
	}*list=NULL,*p,*q,*r,*s,*t;
	void get_data()
	{
		do
		{
			cout<<"Enter choice:\n";
			cout<<"1.Insertion from beginning.\n2.Insertion from end.\n3.Insertion before an element.\n4.Insertion after an element.\n5.Deletion from beginning.\n6.Deletion from end.\n7.Deletion of an element.\n8.Counting number of elements.\n9.Reverse of linked list.\n10.Sorting of linked list.\n11.Display.\n12.Exit\n";
			cin>>choice;
			switch(choice)
			{
				case 1:
					insertb();
				break;

				case 2:
					inserte();
				break;

				case 3:
					insertbe();
				break;

				case 4:
					insertae();
				break;

				case 5:
					deleteb();
				break;

				case 6:
					deletee();
				break;

				case 7:
					deletes();
				break;

				case 8:
					count();
				break;

				case 9:
					reverse();
				break;

				case 10:
				    sort();
				break;

                case 11:
                    show_data();
                break;

				case 12:
				break;

				default:
					cout<<"Invalid choice.\n";
			}
		}while(choice!=12);
	}
	void insertb()
	{
		int temp;
		p=(struct node*)malloc(sizeof(node));		
		cout<<"Enter data to insert:";
		cin>>temp;
		p->data=temp;
		if(list==NULL)
        {
		    cout<<"Linked list does not exist.\nFirst node has been created\n";
        }
        p->next=list;
        list=p;
	}
	void inserte()
	{
		int temp;
		cout<<"Enter data to insert:\t";
		cin>>temp;
		p=(struct node*)malloc(sizeof(node));
		p->data=temp;
		p->next=NULL;
		if(list==NULL)//linked list does not exist
		{
            cout<<"Linked list does not exist.\nFirst node has been created\n";
			list=p;
		}		
		else//linked list exists
		{
			q=list;
			while(q->next!=NULL)
			{
				q=q->next;	
			}
			q->next=p;		
		}
	}
	void insertbe()
	{
		int temp;
		cout<<"Enter data to be inserted:\t";
		cin>>temp;
		p=(struct node*)malloc(sizeof(node));
		p->data=temp;
		cout<<"Enter element before which you want to insert "<<temp<<" :\t";
		cin>>value;
		q=list;
		if(list==NULL)//linked list does not exist
        {
		    cout<<"Linked list does not exist.\n";
        }
		else
		{
            while (q->data != value && q != NULL)//trying to find element
            {
                r = q;
                q = q->next;
            }
            if (q == NULL)//couldn't find the element
            {
                cout << value << " does not exist.\n";
            }
            else if (q->data == value)//found the element
            {
                if (list->data == value)//element is in the first node
                {
                    p->next = list;
                    list = p;
                }
                else//element is not in first node
                {
                    r->next = p;
                    p->next = q;
                }
            }
        }
	}
	void insertae()
	{
		int temp;
		cout<<"Enter data to be inserted:\t";
		cin>>temp;
		p=(struct node*)malloc(sizeof(node));
		p->data=temp;
		cout<<"Enter element after which you want to insert "<<temp<<" :\t";
		cin>>value;
		q=list;
        if(list==NULL)//linked list does not exist
        {
            cout<<"Linked list does not exist.\n";
        }
        else
        {
            while (q->data != value && q != NULL)//trying to find the element
            {
                q = q->next;
            }
            r = q->next;
            if (q == NULL)//element not found
            {
                cout << value << " does not exist.\n";
            }
            else if (q->data == value)//element is found
            {
                if (q->next == NULL)//element is in the last node
                {
                    q->next = p;
                    p->next = NULL;
                }
                else//element is not in the last node
                {
                    q->next = p;
                    p->next = r;
                }
            }
        }
	}
	void deleteb()
	{
		if(list==NULL)//linked list does not exist
		{
			cout<<"Linked List is empty.\n";
		}
		else
		{
			q=list;
            if(list->next==NULL)//there is only one node
            {
                cout << q->data << " is deleted.\n";
                free(q);
                list=NULL;
            }
            else//there are more than one node
            {
                list=list->next;
                cout<<q->data<<" is deleted.\n";
                free(q);
            }
		}
	}
	void deletee()
	{
		if(list==NULL)//linked list does not exist
		{
			cout<<"Linked List is empty.\n";
		}
		else//linked list exists
		{
			q=list;
			while(q->next!=NULL)//finding the last node
			{
				r=q;				
				q=q->next;	
			}
            if(list->next==NULL)//if there is only one node
            {
                cout << q->data << " is deleted.\n";
                free(q);
                list=NULL;
            }
            else//there are more than one node
            {
                r->next=NULL;
                cout<<q->data<<" is deleted.\n";
                free(q);
		    }
		}
	}
	void deletes()
	{
		if(list==NULL)//linked list does not exist
		{
			cout<<"Linked List is empty.\n";
		}
		else//linked list exists
		{
			cout<<"Enter element to be deleted:\n";
			cin>>value;
			q=list;
			while(q->data!=value && q!=NULL)//finding the element
			{
				r=q;
				q=q->next;
			}
			if(q->data==value)//element is found
			{
				if(list->data==value)//element is found at first node
				{
					list=q->next;
					free(q);
				}
				else if(q->next==NULL)//element is found in the last node
				{
					r->next=NULL;
					cout<<q->data<<" is deleted.\n";
					free(q);
				}
				else
				{
					r->next=q->next;
					cout<<q->data<<" is deleted.\n";
					free(q);
				}		
			}		
		}
	}
	void count()
	{
	    if(list==NULL)
        {
	        cout<<"Linked list is empty.\n";
        }
	    else
	    {
	        q=list;
    	    int counter=0;
	        while(q!=NULL)
            {
	            counter++;
	            q=q->next;
            }
	        cout<<"Number of nodes in linked list: "<<counter<<"\n";
	    }
    }
	void reverse()
	{
        if (list == NULL)
        {
            cout << "Linked list is empty.\n";
        }
        else
        {
            q = list;
            s = list;
            t = NULL;
            r = q->next;
            while (r != NULL)
            {
                t = q;
                q = r;
                r = q->next;
                q->next = t;
            }
            list = q;
            s->next = NULL;
        }
    }
	void sort()
    {
        if(list==NULL)
        {
            cout<<"Linked list is empty.\n";
        }
        else
        {
            int temp;
            q=list;
            while(q!=NULL)
            {
                r=q->next;
                while(r!=NULL)
                {
                    if(q->data>r->data)
                    {
                        temp=q->data;
                        q->data=r->data;
                        r->data=temp;
                    }
                    r=r->next;
                }
                q=q->next;
            }
            cout<<"Sorted ";
            show_data();
        }
    }
    void show_data()
    {
        q=list;
        if(list==NULL)
        {
            cout<<"Linked List is empty.\n";
        }
        else
        {
            cout<<"Linked list:\n";
            while(q!=NULL)
            {
                cout<<q->data<<"---->";
                q=q->next;
            }
            cout<<"\n";
        }
    }
};
int main()
{
	llist obj1;
	obj1.get_data();
}

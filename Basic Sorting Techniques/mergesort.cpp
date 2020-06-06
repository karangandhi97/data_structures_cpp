
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
class mergesort
{
	public:
	int array[100];
	void get_data()
	{
		int i = 0;
		int x;
		ifstream inFile;
		inFile.open("testcases.txt");
		if (!inFile) 
		{
		        cout << "Unable to open file";
    		}
		else
		{
			while (inFile >> x) 
			{
				array[i]=x;
				i++;
			}
			for(i=0;i<100;i++)
			{
				cout<<array[i]<<"\n";
			}
		}
		inFile.close();
	}
	void merge()
	{

	}
	void print_data()
	{
		ofstream File ("result.txt");
		if(File.is_open())
		{
			for(int i=0;i<100;i++)
			{
				File<<array[i]<<"\n";
			}
		    File.close();
		}
	}
};

int main() 
{
	mergesort obj1;
	obj1.get_data();
	obj1.print_data();
}

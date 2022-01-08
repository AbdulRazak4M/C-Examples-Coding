// WAP to create the class as Employee with 
// a three field NAme, ID, Sal 
//allocate memory dynamically using malloc function 
//find the second highest salary

#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
 
class Employee // declaring class
{
 	private:
 		char name[90];
 		int ID;
 	public:
 		int salary;
 		void setData(char n[], int i, int s) // defining functions
 		{
 			strcpy(name,n);
 			ID=i;
 			salary=s;
		}
		void showData()
		{
			cout<<name<<"\t"<<ID<<"\t"<<salary<<"\n";
		}
};
int main()
 {
 	char n[90];
 	int id, size, sal;
 	Employee *p;// creating pointer object
 	cout<<"How much memory required:\n";
 	cin>>size;
 	p=(Employee*) malloc (sizeof(Employee) * size); // allocate dynamic array in memory
 	for(int i=0; i<size;i++)
 	{
 		cout<<"Enter the Name ID and Salary of Employee:\n";
 		cin>>n>>id>>sal;
 		p[i].setData(n, id, sal);
	}
	
	cout<<"The Input Data:\n";
	for(int i=0; i<size; i++)
	{
		p[i].showData();
	}
	// sorting logic
	for(int i=0; i<size; i++)
	{
		for(int j=i+1; j<size; j++)
		{	
			if (p[i].salary > p[j].salary)
			{	
				Employee temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
	
	/*sorting the data
	cout<<"\nThe Data after :\n";
	for(int i=0; i<size; i++)
	{
		p[i].showData();
	}*/
	
	cout<<"\n The second Highest Salary is: \n";
	for(int i=0; i<size; i++)
	{
		for(int j=i+1; j<size; j++)
		{	
			if (p[i].salary < p[j].salary)
			{	cout<<p[j].salary;
				break;
			}	
		}
		break;
	}
	return 0;	
}

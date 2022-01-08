// write a program to create the class name as Student
//design the product class with setter and getter method or function with field id,name,per
//one more class name as School with two methods
// void acceptStudent(student s[])
//void findTopper()
#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

class Student
{
	private:
	 int id;
 	 char name[90];
 	 float per;
	public:
		void setId(int id)
		{	this->id=id; // this -> represent current working
		}
		int getId()
		{	return id;
		}
		//setting name of Student
		void setName(char name[])
		{ strcpy(this->name,name);
		}
		char *getName()// pointer used to save the string
		{	return name;
		}
		//setting percentage of student
		void setPer(float per)
		{	this->per=per;
		}
		float getPer()
		{	return per;
		}	
};
class School
{
	Student *s;
	int count;
	public:
		void acceptStudent(Student s[],int count)
		{
			this->s=s;
			this->count=count;
		}
		void findTopper()
		{
			float max=s[0].getPer();
			for(int i=0; i<count; i++)
			{
				for (int j=i+1; j<count; j++)
				{
					if (max<s[j].getPer())
					{
						max=s[j].getPer();
					}
					
				}
			}
			//Print the output
			cout<<"The Student with Max Percentage is:\n";
			for (int i=0; i<count; i++)
			{
				if (s[i].getPer()==max)
				{
					cout<<s[i].getId()<<"\t"<<s[i].getName()<<"\t"<<s[i].getPer()<<"\n";
				}
			}
			
		}
};

int main()
{
	School a; // object for school class
	int count;
	cout<<"Enter the count of Student\n";
	cin>>count;
	Student s[count]; // array object od student class
	int id;
	char name[90];
	float per;
	for (int i=0; i<count;i++)
	{
		cout<<"Enter ID, Name, Percentage of Student:\n";
		cin>>id>>name>>per;
		s[i].setId(id);
		s[i].setName(name);
		s[i].setPer(per);
	}
	a.acceptStudent(s,count);
	a.findTopper();
	return 0;
	
}

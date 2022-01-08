// write a program to create the biling application 
//design the product class with setter and getter method or function with field id,name,qty,rate
//one more class name as CalculateBill with two methods
// void acceptProdut(Product p[])
//void calBill()

#include<iostream>
#include<string.h>
#include<iomanip> // required to set width between couloumn
using namespace std;

class Product
{
	private:
	 int id;
 	 char name[90];
	 int qty;
	 int rate;
	public:
		int total;
		// use getter setter method to get and retriev data
		void setId(int id)
		{	this->id=id; // this -> represent current working
		}
		int getId()
		{	return id;
		}
		//setting name of Product
		void setName(char name[])
		{ strcpy(this->name,name);
		}
		char *getName()// pointer used to save the string
		{	return name;
		}
		void setQty(int qty)
		{	this->qty=qty;
		}
		int getQty()
		{	return qty;
		}
		void setRate(int rate)
		{	this->rate=rate;
		}
		int getRate()
		{	return rate;
		}	
};
// creating second class
class CalculateBill
{
	public:
	Product p[3]; // created object od product class
	int count;
	void acceptProduct(Product p[],int count)
	{
		for (int i=0; i<3; i++)
		{
			this->p[i]=p[i];
			this->count=count;
		}
	}
	void calBill()
	{ int grand = 0;
	//calculate total for each product
		for(int i=0; i<count; i++)
		{	p[i].total=p[i].getQty() * p[i].getRate();
		 grand = grand + p[i].total;
		}
		//printinf the output
		cout<<"Product ID"<<"\t"<<"Product Name"<<"\t"<<"Quantity"<<"\t"<<"Rate"<<"\t"<<setw(13)<<"Total\n";
		for(int i=0; i<count; i++)
		{
			cout<<left<<setw(10)<<p[i].getId()<<"\t"
			<<setw(12)<<p[i].getName()<<"\t"
			<<setw(10)<<p[i].getQty()<<"\t"
			<<setw(13)<<p[i].getRate()<<"\t"
			<<p[i].total<<"\n";
		}
		//for printing line after output
		for(int i=0; i<65; i++)
		{
			cout<<"-"; 
		}
	
		cout<<"\n"<<setw(60)<<"Grand Total: "<<grand;
	}
};

int main()
{
	CalculateBill b; // class 2 object created
	int count;
	cout<<"Enter the total Products Purchased:\n";
	cin>>count;
	Product p[count];
	int id,qty,rate;
	char name[90];
	for (int i=0; i<count;i++)
	{
		cout<<"Enter ID, Name, Qty, And Rate of Product:\n";
		cin>>id>>name>>qty>>rate;
		p[i].setId(id);
		p[i].setName(name);
		p[i].setQty(qty);
		p[i].setRate(rate);
	}
	b.acceptProduct(p,count);
	b.calBill();
	return 0;
}

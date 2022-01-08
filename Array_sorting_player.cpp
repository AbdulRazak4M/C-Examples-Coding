#include<iostream>
#include<string.h>
using namespace std;

class Player
{
	private:
		char name[90];
	 	int id;
	public:
		int score;
		void setdata(char n[], int i, int s)
		{
			strcpy(name,n);
			id=i;
			score=s;
		}
		void showData()
		{
			cout<<name<<"\t"<<id<<"\t"<<score<<"\n";
		}	
};
int main()
{
	int j,s,i;
	char n[90];
	Player ind[5];
	for (j=0; j<5; j++)
	{
		cout<<"Input the NAME, ID and SCORE of player:\n";
		cin>>n>>i>>s;
		ind[j].setdata(n,i,s);
	}
	cout<<"The details before sorting:\n";
	for(j=0; j<5; j++)
	{
		ind[j].showData();
	}
	for (j=0;j<5;j++)
	{
		for (int k=(j+1); k<5; k++)
		{
			if(ind[j].score>ind[k].score)
			{
				Player temp = ind[j];
				ind[j]=ind[k];
				ind[k]=temp;
			}
		}
	}
	cout<<"The details after sorting:\n";
	for(j=0; j<5; j++)
	{
		ind[j].showData();
	}
	return 0;
}


//Basics of stack using class
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class STACK
{
private:
	int TOP;
	int s[10];
public:
    get_data(int top);
	push(int element);
    pop();
	display();

};

STACK :: get_data(int top)
{
	TOP=top;
	
}
STACK :: push(int element)
{
	if(TOP==10-1)
	{
		cout<<"Stack is full"<<endl;
	}
	else
	{
		TOP++;
		s[TOP]=element;
	}
}
STACK :: pop()
{
	if(TOP==-1)
	{
		cout<<"Stack is empty"<<endl;
	}
	else
	{
		cout<<"The deleted element is "<<s[TOP]<<endl;
		TOP--;
		
	}
	
}
STACK :: display()
{
	if(TOP==-1)
	{
		cout<<"Stack is empty";
		
	}
	else
	{
		for(int i=TOP;i>=0;i--)
		{
			cout<<s[i]<<endl;
		}
	}
}

int main()
{
	STACK s1;
	int choice;
	int element;
	s1.get_data(-1);
	char ch;
	do
	{
		cout<<"Enter the choice you want to select : 1) Push 2) Pop 3) Display 4)Exit"<<endl;
		cin>>choice;
		
		switch(choice)
		{
			
			case 1:
				cout<<"Input the element :";
				cin>>element;
				s1.push(element);
				break;
			case 2:
				s1.pop();
				break;
			case 3:
				s1.display();
				break;
		    case 4:
		    	ch='n';
		    	break;
		    default:
		    	cout<<"wrong choice :";
		}
		cout<<"Do you want to continue if yes (Y or y) else ( n ):";
		cin>>ch;
		
		
	}while(ch=='Y'||ch=='y');
	
	
	
	return 0;
}

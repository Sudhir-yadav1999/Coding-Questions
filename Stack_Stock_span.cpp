The Stock Span Problem
-----------------------
The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate span of stock’s price for all n days.
The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, 
for which the price of the stock on the current day is less than or equal to its price on the given day.
For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}


------
code
------
#include <iostream> 
#include <stack> 
using namespace std; 

// A stack based efficient method to calculate 
// stock span values 
void calculateSpan(int price[], int n, int S[]) 
{ 
stack<int> st;
st.push(0);
S[0]=1;

for(int i=1;i<n;i++)
{
	//while loop to empty the small element from top of stack in compare with the current element
   while(!st.empty() && price[st.top()]<=price[i])
   {
   	st.pop();
   }
   //if stack empty all elements on the left are smaller than the current element so current element +1 (index 0)
   //else current index - top index of stack (ie the elemnt greater than the current element)
	if(st.empty())
	{
	S[i]=i+1;	
	}
	else
	{
	S[i]=i-st.top();
	}
	st.push(i);
	
}
} 

// A utility function to print elements of array 
void printArray(int arr[], int n) 
{ 
	for (int i = 0; i < n; i++) 
		cout << arr[i] << " "; 
} 

// Driver program to test above function 
int main() 
{ 
	int price[] = {100, 80, 60, 70, 60, 75, 85}; 
	int n = sizeof(price) / sizeof(price[0]); 
	int S[n]; 

	// Fill the span values in array S[] 
	calculateSpan(price, n, S); 

	// print the calculated span values 
	printArray(S, n); 

	return 0; 
} 

Time Complexity: O(n). It seems more than O(n) at first look. If we take a closer look, we can observe that every element of the array is added and removed from the stack at most once. So there are total 2n operations at most. Assuming that a stack operation takes O(1) time, we can say that the time complexity is O(n).

Auxiliary Space: O(n) in worst case when all elements are sorted in decreasing order.
	
---------------------   ---------------------------------
ANOTHER GOOD SOLUTION | LINKED WITH GREATEST ELEMENT TYPE
---------------------   ---------------------------------

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> v;
stack<pair<int,int> > st;//stack(element,index)
int greatest_left(int arr[],int size)
{
	
		

		for(int i=0;i<size;i++)
	{
		if(st.empty()==true)
		{
			v.push_back(-1);
		}
		else if( !st.empty() && st.top().first>arr[i] )
		{
			v.push_back(st.top().second);
		}
		else if(!st.empty() && st.top().first<=arr[i])
		{
			while(!st.empty() && st.top().first<=arr[i])
			{
				st.pop();
			}
			if(st.empty()==true)
			{
				v.push_back(-1);
			}
			else
			{
				v.push_back(st.top().second);
			}
			
		}
		st.push({arr[i],i});
		
	}
  
}

sub()
{
	for(int k=0;k<v.size();k++)
	{
		v[k]= k-v[k];
	}
	
}
int main()
{
	int arr[]={100, 80, 60, 70, 60, 75, 85};
	int size=sizeof(arr)/sizeof(arr[0]);

	
    greatest_left(arr,size);
    
    sub();

	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	
	
	return 0;
}

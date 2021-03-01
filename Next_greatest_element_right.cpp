Next greater element in same order as input

Given an array, print the Next Greater Element (NGE) for every element.
The Next greater Element for an element x is the first greater element on the right side of x in array.
Elements for which no greater element exist, consider next greater element as -1. The next greater elements should be printed in same order as input array.

Examples:

Input : arr[] = [4, 5, 2, 25}
Output : 5 25 25 -1

Input : arr[] = [4, 5, 2, 25, 10}
Output : 5 25 25 -1 -1

Data type
---------
vector to store output;
stack to push element
//code

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int arr[]={5,10,2,15};
	int size=sizeof(arr)/sizeof(arr[0]);
	stack<int> st;
	vector<int> v;
	for(int i=size-1;i>=0;i--)
	{
		if(st.empty()==true)
		{
			v.push_back(-1);
		}
		else if( !st.empty() && st.top()>arr[i] )
		{
			v.push_back(st.top());
		}
		else if(!st.empty() && st.top()<=arr[i])
		{
			while(!st.empty() && st.top()<=arr[i])
			{
				st.pop();
			}
			if(st.empty()==true)
			{
				v.push_back(-1);
			}
			else
			{
				v.push_back(st.top());
			}
			
		}
		st.push(arr[i]);
		
	}
	reverse(v.begin(),v.end());
	for(int k=0;k<v.size();k++)
	{
		cout<<v[k]<<endl;
	}
	
	
	return 0;
}

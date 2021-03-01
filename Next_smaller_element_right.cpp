Ques ) Find the next smaller element on the right

arr- [4,5,2,10,8]
out -[2,2,-1,8,-1]

Data structure
--------------
stack- store element
vector- store output
--------------------
code
--------------------
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int arr[]={4,5,2,10,8};
	int size=sizeof(arr)/sizeof(arr[0]);
	stack<int> st;
	vector<int> v;
	for(int i=size-1;i>=0;i--)
	{
		if(st.empty()==true)
		{
			v.push_back(-1);
		}
		else if( !st.empty() && st.top()<arr[i] )
		{
			v.push_back(st.top());
		}
		else if(!st.empty() && st.top()>=arr[i])
		{
			while(!st.empty() && st.top()>=arr[i])
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
Time complexity - O(n)

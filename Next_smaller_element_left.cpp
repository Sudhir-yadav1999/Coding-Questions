Ques ) Find the next smaller element on the left side of the array

arr - [4,5,2,10,8]
o/p - [-1,4,-1,2,2]

Data structure
--------------
vector- store the output
stack - store element on the left array 
----------------------------------------
code
-----
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int arr[]={5,10,2,15};
	int size=sizeof(arr)/sizeof(arr[0]);
	stack<int> st;
	vector<int> v;
	for(int i=0;i<size;i++)
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

	for(int k=0;k<v.size();k++)
	{
		cout<<v[k]<<endl;
	}
	
	
	return 0;
}

Time complexity -O(n)

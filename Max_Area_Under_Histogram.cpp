
Ques Find the max area of rectangle under the histogram.


-----
code
-------
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> lt;
stack<pair<int,int> > st;//stack(element,index)
vector<int> rt;
stack<pair<int,int> > stt;
int width[7];
int area1[7];
int small_left(int arr[],int );
int small_right(int arr[],int );

int small_left(int arr[],int size)
{
	
	int sudopos=-1;	
int i;
		for(i=0;i<size;i++)
	{
		if(st.empty()==true)
		{
			lt.push_back(sudopos);
		}
		else if( !st.empty() && st.top().first<arr[i] )
		{
			lt.push_back(st.top().second);
		}
		else if(!st.empty() && st.top().first>=arr[i])
		{
			while(!st.empty() && st.top().first>=arr[i])
			{
				st.pop();
			}
			if(st.empty()==true)
			{
				lt.push_back(-1);
			}
			else
			{
				lt.push_back(st.top().second);
			}
			
		}
		st.push({arr[i],i});
		
	}
  
}
//stack(element,index)/*
int small_right(int arr[],int size)
{
int i;
	int sudopos=7;
	for(i=size-1;i>=0;i--)
	{
		if(stt.empty())
		{
			rt.push_back(sudopos);
		}
		else if(!stt.empty() && stt.top().first < arr[i])
		{
			rt.push_back(stt.top().second);
		}
		else if(!stt.empty() && stt.top().first>=arr[i])
		{
			while(!stt.empty() && stt.top().first>=arr[i])
			{
				stt.pop();
			}
			if(stt.empty())
			{
			rt.push_back(sudopos);	
			}
			else
			{
				rt.push_back(stt.top().second);
			}
			
		}
		stt.push({arr[i],i});
		
	}
	reverse(rt.begin(),rt.end());
}
void diff()
{
	
	for(int i=0;i<lt.size();i++)
	{
		width[i]=rt[i]-lt[i]-1;
	//	cout<<width[i]<<" ";
	}
}

void area(int arr[],int size)
{
	cout<<"AREA ";
	for(int i=0;i<size;i++)
	{
		area1[i]=arr[i]*width[i];
		cout<<area1[i]<<" ";
	}
	
}
int max(int size)
{
	stack<int> s1;
	int max_area =0;
	for(int i=0;i<size;i++)
	{
		if(area1[i]>max_area)
		{
			max_area=area1[i];
		}
	}
	cout<<"Max area is "<<max_area<<" ";
	
}
int main()
{
	int arr[]={6,2,5,4,5,1,6};
	int size=sizeof(arr)/sizeof(arr[0]);

	
    small_left(arr,size);
    small_right(arr,size);
  	diff();
  area(arr,size);
  max(size);
  
  cout<<"left side";
	for(int i=0;i<lt.size();i++)
	{
		cout<<lt[i]<<" ";
	}
  cout<<"right side";
    for(int i=0;i<rt.size();i++)
    {
    	cout<<rt[i]<<" ";
	}
	
	
	return 0;
}

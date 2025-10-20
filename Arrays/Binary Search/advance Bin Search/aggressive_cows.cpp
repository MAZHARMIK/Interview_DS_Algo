/*advance binary search */


//Company Tags    : Amazon, Facebook, Google
//problem link
//https://www.spoj.com/problems/AGGRCOW/

 
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<bits/stdc++.h>

#define int             long long int
#define pb              push_back
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mod             1000000007
#define w(x)            int x; cin>>x; while(x--)
using namespace std;
 
 
int32_t main() {
 
    w(T)
    {
        int n,c,ans;
        cin>>n>>c;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        
        sort(arr,arr+n);
        int low=arr[0],high=arr[n-1]-arr[0];
		
		while(low<=high)
		{
			int prev=arr[0],mid=(low+high)>>1;
			int cow_count=1;
			for(int i=1;i<n;i++)
			{
				if(arr[i]-prev >= mid)
				{
				cow_count++; prev=arr[i];
				if(c==cow_count)break;
				}
			}
			if(cow_count>=c)
			{
				low=mid+1;ans=mid;
			}
			else
			{
				high=mid-1;
			}
			
		}
		cout<<ans<<endl;
		        
    }
 
 
    return 0;
}
 
 
 

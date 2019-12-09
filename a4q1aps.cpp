#include <iostream>
#include <bits/stdc++.h>
#include <time.h> 

using namespace std;
#define ll long long int

void swap(ll* a, ll* b)
{
	ll temp = *a;
	*a = *b;
	*b = temp;
}

ll partition(ll arr[], ll low, ll high)
{
	  ll pivotele = arr[high]; 
    ll min = low-1;
    ll max = high - 1; 
  
    while(true)
    {
      do
      {
        min++;
      }while(arr[min] < pivotele);
      
      while(max > 0 && arr[max] > pivotele)
      {
        max--;
      }

      if(min >= max)
        break;
      else
      {
        swap(&arr[min], &arr[max]);
      }
    }  
    swap(&arr[min], &arr[high]);  
    return min;
}

ll randompartition(ll arr[],ll low,ll high)
{
	ll random = low + (rand() % (high-low+1));
	swap(&arr[random], &arr[high]);
	return partition(arr, low, high);
} 

void quicksort(ll arr[], ll low, ll high,ll k)
{
	if(k < 0 && k > high+1)
		cout<<"Not possible"<<endl;
	else
	{
		ll pivot = randompartition(arr, low, high);
     /* cout<<"k "<<k<<endl;
      cout<<"low "<<low<<endl;
      cout<<"pivot "<<pivot<<endl;
      cout<<"high "<<high<<endl;
      cout<<" element "<<arr[pivot]<<endl; */
   		if(k-1 == pivot)
   		{
      		cout<<"Kth element "<<arr[pivot]<<endl;
      		return;
   		} 
   		else if (k-1 < pivot-low)
    	    quicksort(arr,low,pivot-1, k);
   		else
      		quicksort(arr,pivot+1,high, k);
	}
}

int main()
{
	ll n;
	cin>>n;
	ll arr[n];
	ll cpy[n];
	for(ll i=0; i<n; i++)
	{
		cin>>arr[i];
    	cpy[i] = arr[i];
	}
	ll k;
	cin>>k;

	ll low =0;
	ll high = n-1;
	cout<<"My method"<<endl;
	clock_t startquick; 
    startquick = clock();
	quicksort(arr,low,high,k);
	clock_t endquick; 
    endquick = clock()-startquick;
    cout<<"Time taken in my method "<<endquick<<endl;


    cout<<"nth element method"<<endl;
    clock_t nthelestart; 
    nthelestart = clock();
    nth_element(cpy,cpy+k-1,cpy+n);
    cout<<cpy[k-1]<<endl;
    clock_t nthelestop; 
    nthelestop = clock()-nthelestart;
    cout<<"Time taken in nth element "<<nthelestop<<endl;
}

#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n)
{
	cout<<"\n\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void rearrange(int arr[], int N) 
{
	    // code here
	    int p[N]; int count_p=0;
	    int n[N]; int count_n=0;
	    int z[N]; int count_0=0;
	    int i;
	    int m=0;
	    int j=0;
	    int k=0;
	    
	    for(i=0;i<N;i++)
	    {
	        if(arr[i]<0)
	        {
	            n[j]=arr[i];
	            j++;
	            count_n++;
	        }
	        else if(arr[i]>=0)
	        {
	            p[k]=arr[i];
	            k++;
	            count_p++;
	        }
	        else if(arr[i]==0)
	        {
	        	z[m]=arr[i];
	        	m++;
	        	count_0++;
			}
	    }
	    
	    //test
	    cout<<"\nArray of + integers => ";
	    printArray(p,count_p);
	    cout<<"\nArray of - integers => ";
	    printArray(n,count_n);
	    cout<<"\nNo. of 0s => ";
	    printArray(z,count_0);
	    
	    //transforming the array
	    int pos=0;
	    int neg=0;
	    int zer=0;
	    i=0;
	    while((pos<count_p) && (neg<count_n))
	    {
	    	cout<<"\n\ni => "<<i;
	    	cout<<"\npos => "<<pos;
	    	cout<<"\nneg => "<<neg;
	    	
	    	arr[i]=p[pos];
	    	pos++;i++;
	    	arr[i]=n[neg];
	    	neg++;i++;
		}
		cout<<"\n\nWhile loop breaks at i => \n"<<i;
		
		//if positives are remaining
		if(neg==count_n && i<N)
		{
			while(pos<count_p)
			{
				cout<<"\n\ni => "<<i;
	    		cout<<"\npos => "<<pos;
				arr[i]=p[pos];
				i++;
				pos++;
			}
		}
		//if negatives are remaining
		if(pos==count_p && i<N)
		{
			while(neg<count_n)
			{
				cout<<"\n\ni => "<<i;
	    		cout<<"\nneg => "<<neg;
				arr[i]=n[neg];
				i++;
				neg++;
			}
		}
		//lastly agar 0s baaki hai to unko last me daalo
		if((pos==count_p) && (neg==count_n) &&i<N)
		{
			cout<<"\n\ni => "<<i;
			arr[i]=0;
			i++;
		}
	    
	    
}

// Driver code
int main()
{
     
    int arr[] = { -5, -2, 5, 2,4, 7, 1, 8, 0, -8 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    cout << "Given array is \n";
    printArray(arr, n);
 
    rearrange(arr, n);
 
    cout << "\n\nRearranged array is \n";
    printArray(arr, n);
 
    return 0;
}

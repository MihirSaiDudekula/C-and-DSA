class Quick
{
	int[] arr = {7,3,1,2,9,5,8,6,4};

	public void swap(int[] arr, int i, int j) 
	{
	    int temp = arr[i];
	    arr[i] = arr[j];
	    arr[j] = temp;
	}

	public void quicksort(int[] arr, int low, int high)
	{
		if(low<high)
		{
			int pivot = arr[low];
			int i = low+1;
			int j=arr.length-1;

			while(i<j)
			{
				while(arr[i]<=pivot && i<arr.length)
				{
					i++;
				}
				while(arr[j]>pivot && j>=0)
				{
					j--;
				}
				if(i<j)
				{
					swap(arr,i,j);
				}
			}

			swap(arr,low,j);
			quicksort(arr,low,j-1);
			quicksort(arr,j+1,high);

		}
	}

}

class Merge
{
	public static void mergesort(int[] arr,int low,int high)
	{
		while(low<high)
		{
			int mid = low+high/2;
			mergesort(arr,low,mid);
			mergesort(arr,mid+1,high);
			merge(arr,low,mid,high);
		}
	}
	public static void merge(int[] arr,int low,int mid,int high)
	{
		int[] first = new int[mid-low+1];
		int[] sec = new int[high-mid];

		// fill arrays
		for(int i=0; i<(mid-low+1);i++)
		{
			first[i] = arr[low+i];
		}
		for(int i=0; i<(high-mid);i++)
		{
			sec[i] = arr[mid+1+i];
		}

		int i=0;
		int j=0;
		int k=left;

		while(i<first.length && j<sec.length)
		{
			if(first[i]<=sec[j])
			{
				arr[k]=first[i];
				i++;
			}
			else
			{
				arr[k]=sec[i];
				j++;
			}
			k++;
		}

		while(i<first.length)
		{
			arr[k]=first[i];
			i++;
			k++;
		}
	}
}
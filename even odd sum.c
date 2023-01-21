#include<stdio.h>
#include<unistd.h>
int main()
{
	printf("Name - Rashmi Singh \n");
	int even_sum = 0, odd_sum = 0, n;

	printf("Enter size of array: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter numbers:\n");
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&arr[i]);
	
	}

	int pid = fork();
	if(pid == 0)
	{
		for(int i = 0; i < n; i++)
		{
			if(arr[i]%2 != 0)
				odd_sum += arr[i];
		}
		printf("Sum of Odd Numbers: %d\n", odd_sum);
	}
	else
	{
		for(int i = 0; i < n; i++)
		{
			if(arr[i]%2 == 0)
     				even_sum += arr[i];
		}	
		printf("Sum of Even Numbers: %d\n",even_sum);
	}

	return 0;
}
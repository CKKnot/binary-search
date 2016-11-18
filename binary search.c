/* C implementation Binary search algorithm */
#include <stdio.h>
int main() {

	int array[10],x,n,m,c=0,l,u,mid;
	
	printf("Please enter the size of an array: ");
	scanf("%i",&n);
	
	printf("Enter the elements in ascending order: ");
	
	for(x=0;x<n;x++)
		scanf("%i",&array[x]);
		
	printf("Enter the number to be search: ");
	scanf("%d",&m);
	
	l=0,u=n-1;
	while(l<=u){
		mid=(l+u)/2;
		if(m==array[mid]){
			c=1;
			break;
		}
		else if(m<array[mid]){
			u=mid-1;
		}
		else
			l=mid+1;
	}
	
	if(c==0)
		 printf("The number is not found.");
	else
		 printf("The number is found and its located at no.%i element.",mid+1);
		 
	return 0;
}

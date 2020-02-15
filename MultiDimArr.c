#include<stdio.h>
#include<stdlib.h>
#include<time.h>


//Procedure One

//Initializing array elements to zero

void init_v1(int *myarr, int size){
	for(int i=0; i<size; i++){
	  *(myarr+i)=0;
	}
}
//Procedure Two

//Setting 10% of the array elements to 1's

void init_v2(int *myarr, int size){
	srand((unsigned int) time(0));
	int i, j;
	int upper = 0.1*size;
	for( i=0; i<upper; i++){
		j=rand()%size;
		*(myarr+j)=1;
	}
}

//Procedure Three

//Displaying values and the corresponding indices of 5% of the array elements

void dispvalue_index(int *myarr, int size, int ndim){
	int i, j, k, index[ndim], portion, mod, res, var;
	srand((unsigned int) time(0));
	portion = 0.05*size;
	
	for(i=0;i<portion;i++){
		var=rand()%size;
		res=0;
		mod=0;
		
		for(j=0;j<ndim;j++){
			res=(int)var/ndim;
			mod=var%ndim;
			index[j]=mod;
		}
		printf("Value %d at index ", *(myarr+var));
		for(k=ndim-1;k>=0;i++){
			printf("[%d]", index[k]);
		}
		printf("\n");
	}
} 


int  main(void){
	
	//dynamic array creation
	int *arr1, *arr2, *arr3, *arr4;


	printf("Calling all the procedures");
	printf("\nArray1\n");
	arr1 = malloc(5*5*sizeof(int));
	if(arr1 == NULL){
	    fprintf(stderr, "Cannot allocate arr1\n");
	    return 0;
	}else{
		printf("Arr1 allocated\n");
		//init_v1(arr1, 5*5);
		//init_v2(arr1, 5*5);
		dispvalue_index(arr1, 5*5, 2);
		free(arr1);
	}



	printf("\nArray2\n");
	arr2 = (int *)malloc(5*5*5*sizeof(int));
	if(arr2 == NULL){
	    fprintf(stderr, "Cannot allocate arr2\n");
	    return 0;
	}

	init_v1(arr2, 5*5);
	init_v2(arr2, 5*5);
	dispvalue_index(arr2, 5*5, 2);
	free(arr2);

	printf("\nArray3\n");
	arr3 = (int *)malloc(2*2*2*2*sizeof(int));
	if(arr3 == NULL){
	    fprintf(stderr, "Cannot allocate arr3\n");
	    return 0;
	}
	init_v1(arr3, 5*5);
	init_v2(arr3, 5*5);
	dispvalue_index(arr3, 5*5, 2);
	free(arr3);

	printf("\nArray4\n");
	arr4 = (int *)malloc(2*2*2*2*2*sizeof(int));
	if(arr4 == NULL){
	    fprintf(stderr, "Cannot allocate arr4\n");
	    return 0;
	}
	init_v1(arr4, 5*5);
	init_v2(arr4, 5*5);
	dispvalue_index(arr4, 5*5, 2);
	free(arr4);

	return 0;
}






/*
3.	Input an array of n integers. Find the largest sorted sub array
(sorted array increasing/decreasing and has the largest number of elements)
Ex:
 _____________________________________________
| Input: 2 5 3 4 8 9 7 6 10                   |
| Output: Increasing 3 4 8 9 Decreasing 9 7 6 |
|_____________________________________________|
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Ex3(int in_arr[], int n){
	int i,j, k, countin, compin, countde=1, compde=1;
	// find largest number of elements that increase
	for (i=0; i<n; i++) {
		countin=1;
		for (j=i+1; j<n; j++) {
			if (in_arr[j-1]<in_arr[j])
				countin++;
			else {
				if (compin<countin)
					compin = countin;
				break;
			}
		}
	}	
	// find largest number of elements that decrease
	for (i=0; i<n; i++) {
		countde = 1;
		for (j=i+1; j<n; j++) {
			if (in_arr[j-1]>in_arr[j])
				countde++;
			else {
				if (compde<countde)
					compde = countde;
				break;
			}
		}
	}	
	// check increase array and print them
	for (i=0; i<n-compin; i++) {
		int check = 1;
		for (j=i+1; j<i+compin; j++) 
			if (in_arr[j-1]>in_arr[j]) {
				check = 0;
				break;
			}
		
		if (check) {
			printf("Increasing ");
			for (k=i; k<=compin+i-1; k++)
				printf("%d ", in_arr[k]);
		}
	}
	// check for decrease array and print them
	for (i=0; i<n-compde; i++) {
		int check = 1;
		for (j=i+1; j<i+compde; j++) 
			if (in_arr[j-1]<in_arr[j]) {
				check = 0;
				break;
			}
		
		if (check) {
			printf("Decreasing ");
			for (k=i; k<=compde+i-1; k++)
				printf("%d ", in_arr[k]);
		}
	}
}
int main(int argc, char *argv[]) {
	//testing variable, applying it to your algorithm for auto-evaluating
	argc--;
	int testcase[argc],i;
	for(i=0; i<argc;i++){
		testcase[i] = atoi(argv[i+1]);
	}
	
	Ex3(testcase, argc);
	
	return 0;
}

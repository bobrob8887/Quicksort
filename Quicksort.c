/**********************************
 Author: Maurice Robert Sivanesan
 Program: Question_3_TMA_2.c,
**********************************/
#include "stdafx.h"  
#include<stdio.h>
char answer;

void quicksort(int array[100], int first, int last) {
	int i, j, pivot, temp;

	if (first < last) {                               //Quicksort is a divide and conquer algorithm.The steps are :
		pivot = first;                                //1) Pick an element from the array and call it "pivot".
		i = first;
		j = last;
		while (i < j) {                               //2) The partition operation....
			while (array[i] <= array[pivot] && i < last)//...Divide the unsorted array of elements in two arrays with values less than....
				i++;                                  //...the pivot come in the first sub array, while all elements with values greater...
			while (array[j] > array[pivot])           //...than the pivot come in the second sub - array.
				j--;
			if (i < j) {                              //3) Recursively repeat the step 2(until the sub - arrays are sorted) to the
				temp = array[i];                      //sub - array of elements with smaller values and separately to the sub - array
				array[i] = array[j];                  //of elements with greater values.
				array[j] = temp;
			}
		}
		temp = array[pivot];
		array[pivot] = array[j];
		array[j] = temp;
		quicksort(array, first, j - 1);
		quicksort(array, j + 1, last);
	}
}

int main()
{
	int array[100], c, n, i, ori[100], sorta[100], index;
		
	printf("Prepared by Maurice Robert, ID: 031150290\n");
	printf("Class: 3SPG1\n");
	printf("This program takes in a set of numbers and performs sorting and indexing. \n");
	do {
		printf("\nPlease key how many numbers do you want to sort(max. 100) : ");
		scanf_s("%d", &n);
		printf("Enter %d elements\n", n);    //User enters how many elements to sort, which is "n" array length
		for (c = 1; c < n + 1; c++)          //"c" initialised to 1 because 0 is not displayed....
		{
			printf("Key in number # %d = ", c);
			scanf_s("%d", &array[c - 1]);    //...however array is stored in c - 1 (proper index starting from 0)
		}
		printf("\nThe original order of the numbers are: ");
		for (c = 0; c < n; c++)
		{
			printf("%d  ", array[c]);       //Prints original order of numbers, as entered by user
			ori[c] = array[c];
		}

		quicksort(array, 0, n - 1);         //quicksort function executes with parameters of ...
		                                    //...the array, first index 0, and last index: length - 1 
		printf("\nThe sorted numbers are: ");
		for (i = 0; i < n; i++)
		{
		printf(" %d", array[i]);            //sorted array is printed and copy to "sorta"
		sorta[i] = array[i];
	    }

		for (c = 1; c < n + 1; c++)
		{
			for (i = 0; i < n + 1; i++) {    //This nested "for" loop checks the index of the sorted...
			if (ori[c - 1] == sorta[i])      //...int, however it fails to correctly find if the same...
				index = i + 1;               //...int is entered :(
		    }
			printf("\nThe index for number #%d (%d) is %d", c, ori[c - 1], index);
		}
		printf("\nDo you want to repeat the program? (Y/N): ");
		scanf_s(" %c", &answer);

	} while (answer == 'y');                 //If user press Y, control will return to "do" (line 42)
	printf("Thanks for using my program.\n");//If user press ANY other key, program terminates
	return 0;
}


#include <stdio.h>
#include <string.h>
void my_sort(char arr[][100], int n){
    char temp[100];//temp variable for storing the swapped values
    int i, j;
    //outer loop to iterate through the array
    for (i=0; i<n-1; i++){
            //I use inner loop to compare adjacent values
       for (j=0; j<n-i-1; j++){

        if (strcmp (arr[j],arr[j+1])>0){
            //here we are using string function for comparison
           strcpy (temp,arr[j]);
           strcpy ( arr[j],arr[j+1]);
           strcpy( arr[j+1],temp);
        }
       }

    }
}

int main() {
//
char mystudents[][100]={"Matthew", "Andrew", "Dylan", "Melody","Nancy", "Imran", "Jacob", "Juliet"};
//divides the total size of the array by the size of one element for find number of elements
int n =sizeof(mystudents)/sizeof(mystudents[0]);
my_sort(mystudents, n);
printf("Here is the sorted list of students  ");
for (int i=0; i<n; i++){
    printf("  %s  ",  mystudents[i]);
}

    return 0;
}

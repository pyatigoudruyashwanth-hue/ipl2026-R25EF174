#include <stdio.h>

#include<stdlib.h>
void printbinary(int n){
    for(int i=31;i>=0;i--){
        int bit=(n>>i)&1;
        printf("%d ", bit );
    }
    printf("\n");
}
int countone(int num){
    int count = 0;
    for(int i = 31; i >= 0; i--){   // loop through all 32 bits
        if(((num >> i) & 1) == 1){  // check if bit is 1
            count++;
        }
    }
    return count;
}



int main(){
    int n;
    printf("Enter a number:");
    scanf("%d",&n);
    int ones=countone(n);
    printf("\nNumber of 1's:%d\n",ones);
    printf("Binary representation:");
    printbinary(n);
    
   
    return 0;
}

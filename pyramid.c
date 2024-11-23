#include <stdint.h>
#include <stdio.h>

void wait_for_user_input(void);

void main(void){

    int32_t height;    
    printf("Please enter a height: ");
    scanf("%d",&height);


    while (height<0){
        printf("Enter a positive number as height cannot be negative:\n");
        scanf("%u",&height);
    }    
    
    for(uint32_t i = 1; i<=height; i++){
        for(uint32_t j=i;j>0;j--){
            printf("%2d",j);
        }
        printf("\n");
    }


    wait_for_user_input();
}



void wait_for_user_input(void){
    while (getchar()!= '\n')
    {
        /* code */
    }
    getchar();
}
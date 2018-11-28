#include <stdio.h>

int main(void){
    int coin_count = 0;

    float change;

    printf("Change: ");
    scanf("%f", &change);
    int input = (int)(change*100);
    printf("You entered %d: ", input);
    do{
        if((input - 25) >= 00){
            input -= 25;
        }
        else if((input - 10) >= 00){
            input -= 10;
        }
        else if((input - 5) >= 00){
            input -= 5;
        }
        else if((input - 01) >= 00){
            input -= 01;
        }
        coin_count++;
        printf("Use a quarter\n");
        printf("Your remaining input is: %d\n", input);
    }while( input > 0);

    printf("Number of coins: %d", coin_count);

    return 0;
}
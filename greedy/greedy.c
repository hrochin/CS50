#include <stdio.h>

int main(void){
    int coin_count = 0;

    long double change;

    printf("Change: ");
    scanf("%Lf", &change);
    printf("You entered %Lf: ", change);
    do{
        if(change >= 0.25){
            change -= .25;
            coin_count++;
            printf("Use a quarter\n");
            printf("Your remaining change is: %Lf\n", change);
        }
        if(change >= 0.10){
            change -= .10;
            coin_count++;
            printf("Use a dime\n");
            printf("Your remaining change is: %Lf\n", change);
        }
        if(change >= 0.05){
            change -= .05;
            coin_count++;
            printf("Use a nickle\n");
            printf("Your remaining change is: %Lf\n", change);
        }
        if(change >= 0.01){
            change -= .01;
            coin_count++;
            printf("Use a penny\n");
            printf("Your remaining change is: %Lf\n", change);
        }

    }while( change >= 0.0);

    printf("Number of coins: %d", coin_count);

    return 0;
}
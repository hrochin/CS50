#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int digit_count(long long);
int initial_sum(long long, int, bool);
int sum_remaining(long long, int, bool);
void get_type(long long, int);

int main(void){

    long long credit_card;

    printf("Number: ");
    scanf("%lld", &credit_card);

    printf("Your number is: %lld\n", credit_card);
    int count = digit_count(credit_card);
    //printf("You have %d numbers.\n", count);
    bool is_even = (count % 2) + 1;
    int first_sum = initial_sum(credit_card, count, is_even);
    int remaining_sum = sum_remaining(credit_card, count, is_even);

    printf("Your initial sum is: %d\n", first_sum);
    printf("remaining sum is: %d\n", remaining_sum);

    if((first_sum + remaining_sum)%10 == 0){
        printf("Valid\n");
    }
    else{
        printf("inValid\n");
    }

    get_type(credit_card, count);


    return 0;
}

int digit_count(long long number){
    int count = 0;

    while(number > 0){
        number /= 10;
        count++;
    }
    return count;
}

int initial_sum(long long number, int count, bool is_even){

    int loop = count/2;
    long mod = 10;
    long int_div = 1;

    int sum = 0;

    printf("\n-------------------\n");

    if(is_even){
        mod = 100;
        int_div = 10;
        while(loop > 0){
            int add = (int)((number % mod) / int_div) * 2;
            if(add >= 10){
                add = 1 + (add % 10);
            }
            printf("adding: %d\n", add);
            sum += add;
            mod *= 100;
            int_div *= 100;
            loop--;
        }
    }
    else{
        while(loop > 0){
            int add = (int)((number % mod) / int_div) * 2;
            if(add >= 10){
                add = 1 + (add % 10);
            }
            printf("adding: %d\n", add);
            sum += add;
            mod *= 100;
            int_div *= 100;
            loop--;
        }
    }

    return sum;
}

int sum_remaining(long long number, int count, bool is_even){

    int loop = count/2;
    long mod = 10;
    long int_div = 1;

    int sum = 0;

    printf("\n-------------------\n");

    if(!is_even){
        mod = 100;
        int_div = 10;
        while(loop > 0){
            int add = (int)((number % mod) / int_div);
            printf("adding: %d\n", add);
            sum += add;
            mod *= 100;
            int_div *= 100;
            loop--;
        }
    }
    else{
        while(loop > 0){
            int add = (int)((number % mod) / int_div);
            printf("adding: %d\n", add);
            sum += add;
            mod *= 100;
            int_div *= 100;
            loop--;
        }
    }

    return sum;
}

void get_type(long long number, int count){
    // check type
    long long int_div = pow(10,count-2);
    int type = (int)(number/int_div);

    printf("\n-------------------\n");
    printf("type: %d\n, int_div: %lld\n", type, int_div);
    printf("\n-------------------\n");

    switch(type){
        case 34:
            if(count == 15){
                printf("Amex\n");
            }
            break;
        case 37:
            if(count == 15){
                printf("Amex\n");
            }
            break;
        case 51:
            if(count == 16){
                printf("MasterCard\n");
            }
            break;
        case 52:
            if(count == 16){
                printf("MasterCard\n");
            }
            break;
        case 53:
            if(count == 16){
                printf("MasterCard\n");
            }
            break;
        case 54:
            if(count == 16){
                printf("MasterCard\n");
            }
            break;
        case 55:
            if(count == 16){
                printf("MasterCard\n");
            }
            break;
        case 4:
            if(count == 16 || count == 13){
                printf("Visa\n");
            }
            break;
    }
}
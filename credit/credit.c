#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <cs50.h>

int digit_count(long long);
bool get_type(long long);
bool check_sum(long long);

int main(void){

    long long credit_card;

    //printf("Number: ");
    credit_card = get_long_long("Number: ");

    if(check_sum(credit_card) && get_type(credit_card)){
        printf("VALID\n");
    }
    else{
        printf("INVALID\n");
    }

    return 0;
}

int digit_count(long long number){

    return (int)(log10(number)+1);
}

bool get_type(long long number){
    // check type
    int count = digit_count(number);
    long long int_div = pow(10, count - 2);
    int type = (int)(number/int_div);

    if((type == 34 || type == 37) && count == 15){
        printf("AMEX\n");
        return true;
    }
    else if(type >= 51 && type <= 55 && count == 16){
        printf("MASTERCARD\n");
        return true;
    }
    else if( (type >= 40 && type <= 49) && (count == 13 || count == 16)){
        printf("VISA\n");
        return true;
    }
    return false;
}

bool check_sum(long long number){

    long mod = 10;
    long int_div = 1;
    int count = digit_count(number);
    int loop = 1;
    int sum = 0;

    while(loop <= count){
        // run through each digit from least significant
        // and add according to is_even

        // Check if odd index
        if( loop%2 != 0){
            sum += (int)((number % mod) / int_div);
            //printf("adding: %d\n", add_val);
            //sum += add_val;
        }
        else{
            int add_val = (int)((number % mod) / int_div) * 2;
            //printf("adding: %d\n", add_val);
            if(add_val >= 10){
                sum+= 1 + (add_val % 10);
            }
            else{
                sum+= add_val;
            }
        }
    mod *= 10;
    int_div *= 10;
    loop++;
    }
    //printf("%d\n", sum);
    return (sum % 10 == 0) ? true: false;
}
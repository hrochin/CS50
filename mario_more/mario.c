#include <stdio.h>

int get_valid_height(void);
void print_stairwell(int);
void make_left(int, int);
void make_right(int, int);

int main(void){

    int height;


    height = get_valid_height();
    print_stairwell(height);
    //printf("You have selected a mario stair of height %d\n",height);

}

int get_valid_height(){

    int height;
    //printf("Entering Loop\n");
    do
    {
        printf("Enter stairs height (between 0 and 23): ");
        scanf("%d",&height);

        //if(height < 0 || height > 23){
        //    printf("Invalid entry, try again: ");
        //}

    } while (height < 0 || height > 23);
    //printf("Leaving Loop and returning value of %d\n",height);

    return height;
}

void print_stairwell(int height){

    int hashes = 1;
    int spaces = height -1;

    do{
        make_left(spaces, hashes);
        printf("  ");
        make_right(spaces, hashes);
        printf("\n");
        hashes++;
        spaces--;
        height--;
    }while(height > 0);
}

void make_left(int spaces, int hashes){
    for(int i = 0; i < spaces; i++){
            printf(" ");
        }
        for(int i = 0; i < hashes; i++){
            printf("#");
        }
}

void make_right(int spaces, int hashes){
    for(int i = 0; i < hashes; i++){
                printf("#");
            }
}
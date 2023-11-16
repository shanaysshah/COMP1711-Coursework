#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"
#include <limits.h>

// Struct moved to header file

// Define any additional variables here
/**
 *
 * @param input
 * @param delimiter
 * @param date
 * @param time
 * @param steps 
 */
// Global variables for filename and FITNESS_DATA array
char filename[100];
char choice[1];
// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

                    }




// Complete the main function
int B(){
    FITNESS_DATA records[500];
    int buffer_size = 100;
    char line[buffer_size];
    int counter=0;

    FILE *input =fopen(filename , "r");

    char date[15];
    char time[10];
    char steps[10];

    while (fgets(line, buffer_size, input)){
        tokeniseRecord(line,",",date,time,steps);

        strcpy(records[counter].date, date);
        strcpy(records[counter].time, time);
        records[counter].steps= atoi(steps);
        counter++;
    }
    printf("Total records: %d\n\n", counter);
}

int C(){
    FITNESS_DATA records[500];
    int buffer_size = 100;
    char line[buffer_size];
    int counter=0, min= INT_MAX , minIndex= -1;

    FILE *input =fopen(filename , "r");

    char date[15];
    char time[10];
    char steps[10];

   
    
    while (fgets(line, buffer_size, input)){
        tokeniseRecord(line,",",date,time,steps);

        strcpy(records[counter].date, date);
        strcpy(records[counter].time, time);
        records[counter].steps= atoi(steps);
        
        if (records[counter].steps < min){
            min = records[counter].steps;
            minIndex = counter;
        }
        counter++;
}
        
    
    printf("Fewest Steps: %s %s\n\n", records[minIndex].date, records[minIndex].time);
}
int D(){
FITNESS_DATA records[500];
    int buffer_size = 100;
    char line[buffer_size];
    int counter=0, max= INT_MIN , maxIndex= 0;

    FILE *input =fopen(filename , "r");

    char date[15];
    char time[10];
    char steps[10];

   
    
    while (fgets(line, buffer_size, input)){
        tokeniseRecord(line,",",date,time,steps);

        strcpy(records[counter].date, date);
        strcpy(records[counter].time, time);
        records[counter].steps= atoi(steps);
        
        if (records[counter].steps > max){
            max = records[counter].steps;
            maxIndex = counter;
        }
        counter++;
}
        
    
    printf("Largest Steps: %s %s\n\n", records[maxIndex].date, records[maxIndex].time);
}
int E(){
    FITNESS_DATA records[500];
    int buffer_size = 100;
    char line[buffer_size];
    int i, total, mean, counter=0;

    FILE *input =fopen(filename , "r");

    char date[15];
    char time[10];
    char steps[10];

   
    
    while (fgets(line, buffer_size, input)){
        tokeniseRecord(line,",",date,time,steps);

        strcpy(records[counter].date, date);
        strcpy(records[counter].time, time);
        records[counter].steps= atoi(steps);
        total = total + records[counter].steps;
        counter++;
    
    
        
    }  
    
    
    mean = total/counter;
    printf("Mean step count: %d\n\n", mean);
}

int F(){
    FITNESS_DATA records[500];
    int buffer_size = 100;
    char line[buffer_size];
    int counter=0, Current= 0, Longest=0, startIndex= -1, endIndex= -1;

    FILE *input =fopen(filename , "r");

    char date[15];
    char time[10];
    char steps[10];

    while (fgets(line, buffer_size, input)){
        tokeniseRecord(line,",",date,time,steps);

        strcpy(records[counter].date, date);
        strcpy(records[counter].time, time);
        records[counter].steps= atoi(steps);
        
        if (records[counter].steps > 500){
            if (startIndex == -1){
                startIndex = counter;
            }
            Current++;
        }
            else{
                if (Current > Longest){
                    Longest = Current;
                    endIndex = counter -1;
                }
            Current = 0;
            startIndex = -1;
            }
        
        counter++;
    }
    startIndex = endIndex - Longest+1;
    printf("Longest period start: %s %s\n", records[startIndex].date, records[startIndex].time);
    printf("Longest period end: %s %s\n\n", records[endIndex].date, records[endIndex].time);
}


int main() {

    while(choice != "q"| choice != "Q"){
    printf("Menu Options:\n");
    printf("A: Specify the filename to be imported\n");
    printf("B: Display the total number of records in the file\n");
    printf("C: Find the date and time of the timeslot with the fewest steps\n");
    printf("D: Find the date and time of the timeslot with the largest number of steps\n");
    printf("E: Find the mean step count of all the records in the file\n");
    printf("F: Find the longest continuous period where the step count is above 500 steps\n");
    printf("Q: Quit\n");
    printf("Enter Choice: ");

    scanf("%s", choice);

    
        switch(choice[0]){
            case 'A':
            case 'a':
                printf("Input Filename: ");
                scanf("%s", filename);
                
                FILE *input = fopen(filename, "r");
                if (!input){

                    printf("Could not find or open the file.\n\n");
                    
                } 
                
                else{
                    printf("File successfully loaded\n\n");
                
                }
                break;

            case 'B':
            case 'b':
                B();
                break;

            case 'C':
            case 'c':
                C();
                break;


            case 'D':
            case 'd':
                D();
                break;
            case 'E':
            case 'e':
                E();
                break;

            case 'F':
            case 'f':
                F();
                break;
            case 'Q':
            case 'q':
                return 0;
            
            default: 
                printf("Invalid choice. Try again\n\n");
        }
    }

    // if (choice[0] == 'Q'){
    //     return 0;
    // }
    
    // if (choice[0] == 'A'){
    //     printf("Input Filename: ");
    //     scanf("%s", filename);
    //     if (access(filename, F_OK) !=0){
    //         printf("Error: Could not find or open the file\n");
    //     }
    //     else{
    //         printf("File successfully loaded\n");
    //     }
    //     printf("\n\n");
    //     main();
    // }
    // if (choice[0] == 'B'){
    //     FITNESS_DATA records[500];
    //     int buffer_size = 100;
    //     char line[buffer_size];
    //     int counter=0;

    //     FILE *input =fopen(filename , "r");

    //     char date[15];
    //     char time[10];
    //     char steps[10];

    //     while (fgets(line, buffer_size, input)){
    //         tokeniseRecord(line,",",date,time,steps);
    //         strcpy(records[counter].date, date);
    //         strcpy(records[counter].time, time);
    //         records[counter].steps= atoi(steps);
    //         counter++;
    // }
    //     printf("Total records: %d\n\n\n", counter);
    //     main();

    

    
        


    

}










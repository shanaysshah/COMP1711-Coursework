#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "FitnessDataStruct.h"

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
    int i, counter=0;

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
int main() {

    while(choice != "q"| choice != "Q"){
    printf("A: Specify the filename to be imported\nB: Display the total number of records in the file\nC: Find the date and time of the timeslot with the fewest steps\nD: Find the date and time of the timeslot with the largest number of steps\nE: Find the mean step count of all the records in the file\nF: Find the longest continuous period where the step count is above 500 steps\nQ: Quit\nEnter Choice: ");
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
               
                break;


            case 'D':
            case 'd':
                break;
            case 'E':
            case 'e':
                E();
                break;

            case 'F':
            case 'f':
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










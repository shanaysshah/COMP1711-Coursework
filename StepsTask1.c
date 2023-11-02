#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here
/**
 *
 * @param input
 * @param delimiter
 * @param date
 * @param time
 * @param steps 
 */


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
int main() {
    FITNESS_DATA records[500];
    int buffer_size = 100;
    char line[buffer_size];
    int counter=0;

    FILE *input =fopen("FitnessData_2023.csv" , "r");

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

    printf("Number of records in file: %d\n", counter);

    int n=0;
    while (n<3){
        printf("%s/%s/%d\n", records[n].date,records[n].time,records[n].steps);
        n++;
    }


}

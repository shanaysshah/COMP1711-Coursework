#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;
char filename[100];

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}

int Sort(){
    FitnessData records[500];
    int buffer_size = 100;
    char line[buffer_size];
    int counter=0;

    FILE *input =fopen(filename , "r");
    if (!input){
        printf("Error: Invalid File\n");
        return 1;
    }
    char outputfilename[105];
    snprintf(outputfilename, sizeof(outputfilename), "%s.tsv", filename);
    FILE *output = fopen(outputfilename, "w");

    char date[15];
    char time[10];
    int steps;

    while (fgets(line, buffer_size, input)){
        tokeniseRecord(line,',',date,time, &steps);

        strcpy(records[counter].date, date);
        strcpy(records[counter].time, time);
        records[counter].steps= steps;
        counter++;
        }
       
        for (int i = 0; i < counter; i++){
            for (int j = 0; j < counter-i-1; j++){
                if (records[j].steps < records[j+1].steps){
                FitnessData temp = records[j];
                records[j] = records[j+1];
                records[j+1] = temp;

            }
        }
     
    }
    for (int i = 0; i < counter; i++) {
        fprintf(output, "%s\t%s\t%d\n", records[i].date, records[i].time, records[i].steps);
        // printf("Date: %s\n", records[i].date);
        // printf("Time: %s\n", records[i].time);
        // printf("Steps: %d\n", records[i].steps);
        // printf("\n");
}
fclose(input);
fclose(output);
}

int main() {
    FitnessData data;
    printf("Enter Filename: ");
    scanf("%s", filename);
  
    Sort();

}

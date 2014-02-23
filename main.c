#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "common.h"

FILE *out;
int main (int argc, const char *argv[])
{
    FILE *source_file;
    char source_name[MAX_FILE_NAME_LENGTH];

	int line_number=0;	//total lines
	time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int date[6]={tm.tm_mon + 1, tm.tm_mday, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec};

	printf("Enter the source file name\n");
	scanf("%s", &source_name);


    out=fopen("OUTPUT.txt","w");

    if((source_file=fopen(source_name, "r"))==NULL){
        puts("source could not be opened");
    }else{
        //fopen to open file
        puts("source opened!!!");
        while(get_source_line(source_file, source_name, date)==TRUE){

        }
    }
    fclose(source_file);
    fclose(out);


    return 0;
}

void print_to_output(char output_line[]){
    fprintf(out, output_line);
}

BOOLEAN get_source_line(FILE *src_file, char src_name[], char todays_date[])
{
    char print_buffer[MAX_SOURCE_LINE_LENGTH + 9];
    char source_buffer[MAX_SOURCE_LINE_LENGTH];
    static int line_number = 0;
    line_number++;

    if(fgets(source_buffer, sizeof source_buffer, src_file)!=NULL){
		print_line(source_buffer, src_name, todays_date);
		//fprintf(out, "%d:\t%s",line_number, source_buffer);
		fputs(source_buffer, stdout);     //prints out the file to console
        return (TRUE);
    }
    else
    {
        return (FALSE);
    }
}

#include "common.h"

static void print_page_header(char source_name[], char date[]);
static int line_count=0;
static int page_number = 1;

void print_line (char line[], char source_name_to_print[], char date_to_print[])// Prints line and headers into the output file
{
char save_ch;
char *save_chp = NULL;

if (line_count > MAX_LINES_PER_PAGE-1 || line_count==0){
    print_page_header( source_name_to_print, date_to_print);
}

if (strlen(line) > MAX_PRINT_LINE_LENGTH){
    save_chp = line;
    line[MAX_PRINT_LINE_LENGTH] = '\0';
}

if(save_chp != NULL){
    print_to_output(line, line_count);
    line = save_chp;
}

if (save_chp == NULL){
    print_to_output(line, line_count);
}
line_count++;
}

static void print_page_header(char source_name[], char date[])// Used to print headers for each page
{


line_count=1;
print_to_header( date, page_number, source_name);
page_number++;

}

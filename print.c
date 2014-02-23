#include "common.h"

static void print_page_header(char source_name[], char date[]);

void print_line(char line[], char source_name_to_print[], char date_to_print[])
{
    
	char save_ch;
	char *save_chp = NULL;
    	static int line_count = MAX_LINES_PER_PAGE;
    
    	if (++line_count > MAX_LINES_PER_PAGE)
    		{
        		print_page_header(source_name_to_print[], date_to_print[])
   		}
   	if (strlen(line) > MAX_PRINT_LINE_LENGTH) 
    		{
			save_ch = line[MAX_PRINT_LINE_LENGTH -1];
			line[MAX_PRINT_LINE_LENGTH -1] = '\0'
			*save_chp = &line[];
			
			
			
			
    		}
    	if (save_chp == NULL)
    		{
        		fprintf(source_name[], "%s\n", line[]);
    		}
		
    		
	if (save_chp != NULL)
    		{
			fprintf(source_name[], "%s\n", *save_chp);
			print_line(char line[], char source_name_to_print[], char date_to_print[])	
    		}
}
static void print_page_header(char source_name[], char date[])
{
    
	static int page_number = 0;
   	lin_count = 0;
	fprintf(source_name[], "%s\t%d\n", date[], page_number); 	
	page_number++; 
	    
}

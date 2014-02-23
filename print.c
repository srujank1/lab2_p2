#include "common.h"

static void print_page_header(char source_name[], char date[]);

void print_line (char line[], char source_name_to_print[], char date_to_print[])
{
    
	
	char save_ch;
	char *save_chp = NULL;
    	static int line_count = MAX_LINES_PER_PAGE;
    
    	if (++line_count > MAX_LINES_PER_PAGE)
    		{
        		print_page_header( source_name_to_print, date_to_print);
   		}
   	if (strlen(line) > MAX_PRINT_LINE_LENGTH) 
    		{
						
			save_chp = line;
			line[MAX_PRINT_LINE_LENGTH] = '\0';
			

    		}
    	if (save_chp != NULL)
    		{
        		fprintf(source_name_to_print, "%s\n", line);
			line = save_chp;
			
    		}
		
    		
	if (save_chp == NULL)
    		{
			fprintf(source_name_to_print, "%s\n", line);
				
    		}
}
static void print_page_header(char source_name[], char date[])
{
    
	static int page_number = 0;
   	line_count = 0;
	fprintf(source_name, "%s\t%s\t%d\n", source_name, date, page_number); 	
	page_number++; 
	    
}

#include "common.h"

static void print_page_header(char source_name[], char date[]);
static int line_count;
FILE *out;

void print_line (char line[], char source_name_to_print[], char date_to_print[])
{
    	//FILE *out_file = fopen( source_name_to_print, "w");
	out=fopen("OUTPUT.txt","w");
	
	char save_ch;
	char *save_chp = NULL;
    	line_count = MAX_LINES_PER_PAGE;
    
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
        		print_to_output( line);
			line = save_chp;
			
    		}
		
    		
	if (save_chp == NULL)
    		{
			print_to_output( line);
				
    		}
fclose(out);
}
static void print_page_header(char source_name[], char date[])
{
    
	static int page_number = 0;
	//char num = page_number;
	//strcat(date, source_name);
	//strcat(date, num);
   	line_count = 0;
	//fprintf(out_file, "%s %d", date, page_number); 
	print_to_header( date, page_number, date);	
	page_number++; 
	    
}
void print_to_output(char output_line[]){
    fprintf(out, output_line);
}

void print_to_header(char yearetc[], int page, char name[]){
    fprintf(out,"%s %d %s\n", yearetc, page, name);
}

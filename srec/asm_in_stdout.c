#include"types.h"

#pragma warning(disable:4996)
void display_asm_stdout( char *input_file_name )
{
	FILE *fp = NULL ;
	char contents =  ' ' ; 
	int counter = 0; 
	
	fp = fopen(input_file_name , "rb" ) ; 
	if( fp == NULL )
	{
		printf("CANNOT OPEN INPUT FILE\n") ;
	}
	else
	{ 
		printf("OUTPUT DATA:\n") ;
		printf("%s ", input_file_name ) ;
		while( ( contents = fgetc(fp) ) !=EOF )
		{
			if (counter == 16) 
			{
				printf("\n%s " , input_file_name ) ; 
				counter = 0 ;
			}
			printf("$%x " , contents);
			counter++; 
		}
		if( fclose(fp) != 0 )
		{
			printf("CANNOT CLOSE FILE\n" ) ;
		}
	}
}
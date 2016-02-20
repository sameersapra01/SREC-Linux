#include"types.h"

#pragma warning (disable:4996)
void display_asm( char *filename , char *output_file_name )
{
	FILE *fp = NULL ;
	FILE *ofp = NULL ;
	char contents = ' ' ; 
	int counter = 0; 
	
	while( 1 )
	{
		fp = fopen( filename , "rb") ;
		if( fp == NULL) 
		{
			printf("CANNOT OPEN FILE") ;
		}
		else
		{

			ofp = fopen(output_file_name , "w" ) ;
			if( ofp == NULL )
			{
				printf("CANNOT OPEN OUTPUT FILE\n") ;
				break ;
			}
		
			fprintf(ofp , "OUTPUT DATA:\n") ;
			fprintf(ofp , "%s ", filename ) ;
			while ((contents = fgetc(fp)) !=EOF)
			{
				if (counter == 16) 
				{
					fprintf(ofp , "\n%s " , filename ) ; 
					counter = 0 ;
				}
				fprintf(ofp ,"$%x ", contents);
				counter++; 
			}
			break ;
		}
	}
	if( fclose(fp) != 0)
	{
		printf("CANNOT CLOSE FILE") ;
	}
	if( fclose( ofp ) != 0 )
	{
		printf("CANNOT CLOSE OUTPUT FILE") ;
	}
}
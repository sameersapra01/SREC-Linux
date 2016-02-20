#include"types.h"

#pragma warning(disable:4996)
void display_at_stdout( char *input_file_name )
{
	FILE *inp_1 = NULL ;
	FILE *inp_2 = NULL ;

	int character = 0 ;
	int count_characters = 0 ;
	int copy_count_characters = 0 ;
	int total_characters = 0 ;
	int count_null_term = 0 ;
	int loop1 , loop2 = 0 ;
	int sum  = 0 ;
	int asci = 0 ;
	int length = 0 ; 
	int count_S1 = 0 ;
	int address = 0 ;
	
	char buffer[50] = "" ;
	char buffer_1[50] = "" ;
	char buffer_2[50] = "" ;

	inp_1 = fopen("aa.txt" , "rb" ) ;
	if( inp_1 == NULL )
	{
		printf("CANNOT OPEN FILE") ;
	}
	else
	{
		printf("S0 SAMEER\n" ) ;
		while( 1 )
		{
			character = getc( inp_1 ) ;
			if( character =='\n' )
			{
				count_null_term++ ;
			}
			if( feof( inp_1 ) )
			{
				break ;
			}
			total_characters++ ;
		}
		total_characters -= count_null_term ;
	}
	if(fclose(inp_1) != 0 )
	{
		printf("cannot close file") ;
	}
	
	else
	{
		inp_1 = fopen("aa.txt" , "rb" ) ;
		if( inp_1 == NULL )
		{
			printf("CANNOT OPEN FILE") ;
		}
	}
	//printf("total_characters are %d\n" , total_characters ) ;

	while( 1 )
	{
		character = getc( inp_1) ;

		//Ignoring new line in counting number of characters from file input.
		if( character == '\n' )
		{
			continue ;
		}

		//If reached end of file.
		if( feof( inp_1) )
		{
			break ;
		}
		if( ( count_characters == 0 ) )
		{
			if( total_characters >= 16 ) 
			{
				printf("S1%02X%04X", kNINETEEN , address ) ;
				sum += kNINETEEN + address ;
				address += kSIXTEEN ;
			}
			else
			{
				printf("S1%02x%04x", total_characters+3 , address ) ;
				sum += total_characters + 3 + address ;
				address += kSIXTEEN ;
			}
		}
		printf( "%X" , character)  ;
		sum += character ;	
	
		if( ( count_characters == 15 ) || total_characters == count_characters+1 ) 
		{
			copy_count_characters = count_characters ;
			count_characters = -1 ;
			printf("%02X\n" , 255^(sum&255) ) ;
			count_S1 += 1 ;
			total_characters-= kSIXTEEN ;
			
			if( total_characters < 0 )
			{
				total_characters = 0 ;
			}
				
			sum = 0 ;
		}
			
		count_characters++ ;
	}
	
	if( total_characters == 0 )
	{
		sum+= 3 + count_S1 ;
		
		printf("S503%04X%02X\n" , count_S1 ,255^(sum&255) ) ;
		printf("S9030000FC" ) ;
	}
	}
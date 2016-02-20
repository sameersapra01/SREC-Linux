#include"types.h"

#pragma warning(disable:4996 )

int main( int argc , char *argv[] )
{
	int loop1 = 0 ;
	int loop2 = 0 ;
	int count = 0 ;
	int count_1 = 0 ;

	char *input_filename = NULL ;
	char *output_filename = NULL ;
	char *srec = NULL ;
	char *help = NULL ;
	char *ls = NULL ;
	char switches[5][15] = {"-i" , "-o" , "-srec" , "-h" , "ls -l |"} ;
	
	for( loop1 = 1 ; loop1 < argc ; loop1++ )
	{
			if( strnicmp( switches[0] , argv[loop1] , 2 ) == 0 )
			{
				input_filename = argv[ loop1 ] + 2 ;
				printf("INPUT FILE NAME IS %s\n" , input_filename ) ;
			}

			if( strnicmp( switches[1] , argv[loop1] , 2 ) == 0 )
			{
				output_filename = argv [loop1 ] + 2 ;
				printf("OUTPUT FILE NAME IS %s\n" , output_filename ) ;
			}	 
			if( strnicmp( switches[2] , argv[loop1] , 5 ) == 0 )
			{
				srec = argv[ loop1 ] ;
				printf("SREC OPTION IS PRESENT %s\n" , srec ) ;
			}
			if( strnicmp( switches[3 ] , argv[loop1] , 2 ) == 0 )
			{
				help = argv[loop1] ;
				printf("HELP IS PRESENT %s" , help ) ;
			}
			if( strnicmp( switches[4]  , argv[loop1] , 8 ) == 0 ) 
			{
				ls = argv[loop1] ;
			}

	}
	for( loop1 = 1 ; loop1<argc ; loop1++ )
	{
		for( loop2 = 0 ; loop2 < 5 ; loop2++ )
		{
			if( strnicmp ( argv[loop1] , switches[loop2] , 2 ) == 0 )
			{
				count_1 = 0 ;
				break ;
			}
			else
			{
				count_1 += 4 ;
			}
		}
		if( count_1 == 16 )
		{
			printf("DO NOT ADD EXTRA SWITCHES\n") ;
		}
	}
	
	if( count_1 != 16 )
	{
		process_output( input_filename , output_filename , srec , help ) ;
	}

	return 0 ;
}
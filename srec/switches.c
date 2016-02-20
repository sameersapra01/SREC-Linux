
#include"types.h"

#pragma warning( disable:4996)

int process_output( char *inp_filename , char *out_filename , char *s_rec , char *help ) 
{
	FILE *ifp = NULL ;
	FILE *ofp = NULL ;
	char dir[50] = "c:\\" ;
	char *enter_file_name = NULL ;
	char *output_file_name = NULL ;
		
	int character = 0 ; 

	while( 1 )
	{
	
		if( help != NULL )
		{
			printf( " LINUX UTILITY \n" ) ;
			printf( "   SWITCHES \n" ) ;
			printf( "1. -iINPUTFILENAME   =>  name of the input file.\n" ) ;
			printf( "2. -oOUTPUTFILENAME  =>  name of the output file.\n" ) ;
			printf( "3. -srec             =>  make output file as inputfilename.srec.\n" ) ;
			printf( "4. -h                =>  help.\n" ) ;
			break ;
		}
		else
		{
			if( inp_filename != NULL)
			{
				if( out_filename == NULL )
				{
					if( s_rec == NULL )
					{
						output_file_name = (char *)malloc(50) ;
						strcpy( output_file_name , inp_filename ) ;
						strcat( output_file_name ,".asm" ) ;
						printf("FORMAT OUTPUT FILE WITH .ASM  %s \n" , output_file_name ) ;
						display_asm( inp_filename , output_file_name ) ;
						break ;
					}
					else
					{
						output_file_name = (char *)malloc(50) ;
						strcpy( output_file_name , inp_filename ) ;
						strcat( output_file_name ,".srec" ) ;
						printf("FORMAT OUTPUT FILE WITH .SREC  %s \n" , output_file_name ) ;
						srec_format( output_file_name , inp_filename ) ;
						break ;
					}
				}
				else
				{
					if( s_rec == NULL )
					{
						output_file_name = (char *)malloc(50) ;
						strcpy( output_file_name , inp_filename ) ;
						strcat( output_file_name ,".asm" ) ;
						printf("FORMAT OUTPUT FILE WITH .ASM  %s \n" , output_file_name ) ;
						display_asm( inp_filename , output_file_name ) ;
						break ;
					}
					else
					{
						output_file_name = (char *)malloc(50) ;
						strcpy( output_file_name , inp_filename ) ;
						strcat( output_file_name ,".srec" ) ;
						printf("FORMAT OUTPUT FILE WITH .SREC  %s \n" , output_file_name ) ;
						srec_format( output_file_name , inp_filename ) ;
						break ;
					}
				}
			}
			else
			{
				//OBTAIN FILE NAME FROM KEYBOARD
			
				printf( "Enter file name\n") ;	
				enter_file_name = (char *)malloc(50) ;
				gets( enter_file_name ) ;

				if( out_filename == NULL )
				{
					// SEND OUTPUT TO STDOUT.
					if( s_rec == NULL )
					{
						//PRINT WITH .ASM FORMAT
						display_asm_stdout( enter_file_name ) ;
						printf("\n") ;
						break ;
					}
					else
					{
						//PRINT WITH SREC FORMAT.
						display_at_stdout( enter_file_name ) ;
						printf("\n") ;
						break ;
					}
				}
				else
				{

					if ( s_rec == NULL )
					{
						 //FORMAT OUTPUT FILE WITH .ASM FORMAT
						display_asm( enter_file_name , out_filename ) ;
						break ;		
					}
					else
					{
						//FORMAT OUTPUT FILE WITH .SREC
						srec_format( out_filename , enter_file_name ) ;
						break ;
					}
				}
			}
		}
	}
	return 0 ;
}
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

FILE *globe; 
int line = 0;
char ignore[1024];
int data[13][9];
int data_2[14][8];
int data_3[14][10];

FILE * printf_check(FILE *f,int x)
{
	
	char a[11]={'p','r','i','n','t','f','(','"','"',')',';'};
	
	int i=0;
	char ct;
	for(i=0;i<8;i++)
	{
		if(fgetc(f)!=a[i])
		{
			fprintf(globe,"Line %d does not contain %c character\n",line+1,a[i]);
			fgets(ignore,1024,f);	
			return f;
			break;		
		}
	}
	do
	{
		ct = fgetc(f);
	}
	while(ct!='"' && ct!=')' && ct!=';' && ct!='\n');
	
	if(ct=='"')
	{
		if(fgetc(f)==')')
		{
			if(fgetc(f)==';')
				return f;
			else
			{
				fprintf(globe,"Line %d does not contain ;\n",line+1);
				fgets(ignore,strlen(ignore),f);	
				return f;	
			}
		}
		else
		{
			fprintf(globe,"Line %d does not contain )\n",line+1);
			fgets(ignore,strlen(ignore),f);	
			return f;
		}
	}
	else
	{
		fprintf(globe,"Line %d does not contains \"\n",line+1);
		fgets(ignore,strlen(ignore),f);	
		return f;
	}
	

}


void printonconsole()
{
	char c,count=0;
	fseek(globe,0,SEEK_SET);
	if(!globe)
	{
		printf("\nProgram doesn't have syntax error in printf,scanf,int,float and char\n");
		return;
	}
		
	while((c=fgetc(globe))!=EOF)
	{
		if(c!='\n' && c!=' ' && count==0)
		{
			printf("Program has syntax error as follows:\n");
			printf("%c",c);
			count++;
		}
		else
			printf("%c",c);
	}
}

void initialize2()
{
	int i,j;
	for(i=0;i<14;i++)
		for(j=0;j<8;j++)
			data_2[i][j] = 42;
	
	for(i=0;i<8;i++)
	{
		data_2[13][i] = 13;
		data_2[6][i] = 6;
	}
	
	
	data_2[0][0] = 1;
	data_2[1][1] = 2;
	data_2[2][2] = 3;
	data_2[3][2] = 3;
	data_2[3][4] = 4;
	data_2[4][4] = 4;
	data_2[4][2] = 5;
	data_2[4][3] = 6;
	data_2[4][6] = 7;
	data_2[5][2] = 5;
	data_2[5][3] = 6;
	data_2[5][6] = 7;
	data_2[7][2] = 8;
	data_2[7][5] = 9;
	data_2[8][2] = 2;
	data_2[8][5] = 9;
	data_2[9][4] = 10;
	data_2[10][5] = 11;
	data_2[11][3] = 13;
	data_2[11][2] = 12;
	data_2[11][7] = 3;
	data_2[12][3] = 13;
	
	data_2[12][7] = 3;
}

void initialize()
{
	int i,j;
	for(i=0;i<13;i++)
		for(j=0;j<9;j++)
			data[i][j] = 42;
			
	
	for(i=0;i<8;i++)
	{
		data[12][i] = 12;
		data[7][i] = 7;
	}	
	data[0][0] = 1;
	data[1][1] = 2;
	data[2][2] = 3;	 																																																																																																														
    data[3][3] = 4;
	data[4][3] = 4;
	
	data[4][7] = 5;
	data[5][7] = 5;
	data[5][4] = 7;
	data[5][3] = 6;
	data[5][5] = 8;
	data[6][4] = 7;
	data[6][3] = 6;
	data[6][5] = 8;
	data[8][3] = 9;
	data[8][8] = 11;
	data[9][3] = 9;
	data[9][8] =11;
	data[11][8] = 11;
	data[11][6] = 4;
	data[11][4] = 12;
	data[11][3] = 10;
	data[11][6] = 4;
	data[10][3] = 10;
	data[10][4] = 12;
	data[10][6] = 4;
}

void initialize3()
{
	int i,j;
	for(i=0;i<14;i++)
		for(j=0;j<10;j++)
			data_3[i][j] = 42;
		
	for(i=0;i<10;i++)
	{
		data_3[12][i] = 12;
		data_3[6][i] = 6;
	}
	
	data_3[0][0] = 1;
	data_3[1][1] = 2;
	data_3[2][2] = 3;
	data_3[3][3] = 4;
	data_3[4][3] = 4;
	data_3[4][4] = 5;
	data_3[5][4] = 5;
	data_3[5][3] = 7;
	data_3[5][5] = 6;
	data_3[5][6] = 8;
	data_3[7][3] = 7;
	data_3[7][5] = 6;
	data_3[7][6] = 8;
	data_3[8][3] = 8;
	data_3[8][7] = 10;
	data_3[8][8] = 9;
	data_3[9][8] = 9;
	data_3[9][7] = 10;
	data_3[10][8] = 11;
	data_3[11][8] = 11;
	data_3[11][5] = 12;
	data_3[11][3] = 13;
	data_3[13][5] = 12;
	data_3[11][9] = 4;
	data_3[13][9] = 4;
}


FILE * float_check(FILE *f,int x)
{
	int in = 0;
	while(1)
	{
		char c = fgetc(f);
		if(c=='o')
				{	
			
					in = data_3[in][0];
					
					if(in==42)
					{
						fprintf(globe,"@@Line %d has syntax error\n",line+1);
						fgets(ignore,1024,f);
						line++;
						return f;
					
					}
					if(in==6 || in==12)
					{
						return f;
					
					}
					continue;
				}
		if(c=='a')
				{	
				
					in = data_3[in][1];
					
					if(in==42)
					{
						fprintf(globe,"**Line %d has syntax error\n",line+1);
						fgets(ignore,1024,f);
						line++;
						return f;
					
					}
					if(in==6 || in==12)
					{
						return f;
					
					}
					continue;
				}
		if(c=='t')
				{	
				
					in = data_3[in][2];
					
					if(in==42)
					{
						fprintf(globe,"@@Line %d has syntax error\n",line+1);
						fgets(ignore,1024,f);
						line++;
						return f;
					
					}
					if(in==6 || in==12)
					{
						return f;
					
					}
					continue;
				}
		if(c==' ')
				{	
					
				
					in = data_3[in][3];
					
					if(in==42)
					{
						fprintf(globe,"!!Line %d has syntax error\n",line+1);
						fgets(ignore,1024,f);
						line++;
						return f;
					
					}
					if(in==6 || in==12)
					{
						return f;
					
					}
					continue;
				}
		if(c==';')
				{	
					
					in = data_3[in][5];
					
					if(in==42)
					{
						fprintf(globe,"@@Line %d has syntax error\n",line+1);
						fgets(ignore,1024,f);
						line++;
						return f;
					
					}
					if(in==6 || in==12)
					{
						return f;
					
					}
					continue;
				}
		if(c=='=')
				{	
				
					in = data_3[in][6];
					
					if(in==42)
					{
						fprintf(globe,"@@Line %d has syntax error\n",line+1);
						fgets(ignore,1024,f);
						line++;
						return f;
					
					}
					if(in==6 || in==12)
					{
						return f;
					
					}
					continue;
				}
		if(c=='.')
				{	
				
					in = data_3[in][7];
					
					if(in==42)
					{
						fprintf(globe,"@@Line %d has syntax error\n",line+1);
						fgets(ignore,1024,f);
						line++;
						return f;
					
					}
					if(in==6 || in==12)
					{
						return f;
					
					}
					continue;
				}
		if(c==',')
				{	
					
					in = data_3[in][9];
					
					if(in==42)
					{
						fprintf(globe,"@@Line %d has syntax error\n",line+1);
						fgets(ignore,1024,f);
						line++;
						return f;
					
					}
					if(in==6 || in==12)
					{
						return f;
					
					}
					continue;
				}
		if(isdigit(c))
				{	
					
					in = data_3[in][8];
					
					if(in==42)
					{
						fprintf(globe,"@@Line %d has syntax error\n",line+1);
						fgets(ignore,1024,f);
						line++;
						return f;
					
					}
					if(in==6 || in==12)
					{
						return f;
					
					}
					continue;
				}
		if(isalnum(c))
				{	
					
					in = data_3[in][4];
					
					if(in==42)
					{
						fprintf(globe,"@@Line %d has syntax error\n",line+1);
						fgets(ignore,1024,f);
						line++;
						return f;
					
					}
					if(in==6 || in==12)
					{
						return f;
					
					}
					continue;
				}
			fprintf(globe,"^*Line %d has syntax error %c\n",line+1,c);
			fgets(ignore,1024,f);
			line++;
			return f;
	}
}


FILE * char_check(FILE *f,int x)
{
	int in=0;
	while(1)
	{
		char c = fgetc(f);
		if(c=='a')
				{	
					
					in = data_2[in][0];
					
					if(in==42)
					{
						fprintf(globe,"@@Line %d has syntax error\n",line+1);
						fgets(ignore,1024,f);
						line++;
						return f;
					
					}
					if(in==6 || in==13)
					{
						return f;
					
					}
					continue;
				}
		if(c=='r')
				{	
					
					in = data_2[in][1];
					
					if(in==42)
					{
						fprintf(globe,"@@Line %d has syntax error\n",line+1);
						fgets(ignore,1024,f);
						line++;
						return f;
				
					}
					if(in==6 || in==13)
					{
						return f;
				
					}
					continue;
				}
		if(c==' ')
				{	
				
					in = data_2[in][2];
					
					if(in==42)
					{
						fprintf(globe,"@@Line %d has syntax error\n",line+1);
						fgets(ignore,1024,f);
						line++;
						return f;
				
					}
					if(in==6 || in==13)
					{
						return f;
				
					}
					continue;
				}
		if(c==';')
				{	
				
					in = data_2[in][3];
					
					if(in==42)
					{
						
						fprintf(globe,"@@Line %d has syntax error\n",line+1);
						fgets(ignore,1024,f);
						line++;
						return f;
						
					}
					if(in==6 || in==13)
					{
						return f;
						
					}
					continue;
				}
		if(c=='\'')
				{	
			
					in = data_2[in][5];
					
					if(in==42)
					{
						fprintf(globe,"@@Line %d has syntax error\n",line+1);
						fgets(ignore,1024,f);
						line++;
						return f;
					
					}
					if(in==6 || in==13)
					{
						return f;
			
					}
					continue;
				}
		if(c=='=')
				{	
				
					in = data_2[in][6];
					
					if(in==42)
					{
						fprintf(globe,"@@Line %d has syntax error\n",line+1);
						fgets(ignore,1024,f);
						line++;
						return f;
				
					}
					if(in==6 || in==13)
					{
						return f;
					
					}
					continue;
				}
		if(c==',')
				{	
				
					in = data_2[in][7];
					
					if(in==42)
					{
						fprintf(globe,"@@Line %d has syntax error\n",line+1);
						fgets(ignore,1024,f);
						line++;
						return f;
					
					}
					if(in==6 || in==13)
					{
						return f;
						
					}
					continue;
				}
		if(isalnum(c))
			{   
		
				in = data_2[in][4];
				
				if(in==42)
				{
					fprintf(globe,"@@Line %d has syntax error\n",line+1);
					fgets(ignore,1024,f);
					line++;
					return f;
				}
				if(in==6 || in==13)
				{
					return f;
				}
				continue;
			}
		fprintf(globe,"^*Line %d has syntax error %c\n",line+1,c);
		fgets(ignore,1024,f);
		line++;
		return f;
	}
	
}

FILE * int_check(FILE *f,int x)
{
		int in = 2;
		int y = 1;
		while(y)
		{
				char c = fgetc(f);
			
				
				if(c=='t')
				{	
					//if(in!=100 && in!=42)
					in = data[in][2];
					
					if(in==42)
					{
						fprintf(globe,"@@Line %d has syntax error\n",line+1);
						fgets(ignore,1024,f);
						line++;
						return f;
						y = 0;
					}
					if(in==12 || in==7)
					{
						return f;
						y = 0;
					}
					continue;
				}
				if(c==' ')
				{	
					
					in = data[in][3];
					
					if(in==42)
					{
						fprintf(globe,"$$Line %d has syntax error\n",line+1);
						fgets(ignore,1024,f);
						line++;
						return f;
						y = 0;
					}
					if(in==12 || in==7)
					{
						return f;
						y = 0;
					}
					continue;
				}
				if(c==';')
				{	
			
					in = data[in][4];
					printf("%d ",in);
					
					if(in==42)
					{
						fprintf(globe,"!!Line %d has syntax error\n",line+1);
						fgets(ignore,1024,f);
						line++;
						return f;
						y = 0;
					}
					if(in==12 || in==7)
					{
						return f;
						y = 0;
					}
					continue;
				}
				if(c=='=')
				{	
					in = data[in][5];
					
					if(in==42)
					{
						fprintf(globe,"*!*Line %d has syntax error\n",line+1);
						fgets(ignore,1024,f);
						line++;
						return f;
						y = 0;
					}
					if(in==12 || in==7)
					{
						return f;
						y = 0;
					}
					continue;
				}
				if(c==',')
				{	
					
					in = data[in][6];
					
					if(in==42)
					{
						fprintf(globe,"*#*Line %d has syntax error\n",line+1);
						fgets(ignore,1024,f);
						line++;
						return f;
						y = 0;
					}
					if(in==12 || in==7)
					{
						return f;
						y = 0;
					}
					continue;
				}
				if(isdigit(c))
				{	
				
					in = data[in][8];
					
					if(in==42)
					{
						fprintf(globe,"*$*Line %d has syntax error\n",line+1);
					
						fgets(ignore,1024,f);
						line++;
						return f;
						y = 0;
					}
					if(in==12 && in==7)
					{
						
						return f;
						y = 0;
					}
					continue;
				}
				if(isalnum(c))
				{	
					
						in = data[in][7];
				
					if(in==42)
					{
						fprintf(globe,"*^*Line %d has syntax error\n",line+1);
						fgets(ignore,1024,f);
						line++;
						return f;
						y = 0;
					}
					if(in==12 && in==7)
					{
					
						return f;
						y = 0;
					}
					continue;
				}
				fprintf(globe,"^*Line %d has syntax error %c\n",line+1,c);
				fgets(ignore,1024,f);
				line++;
				return f;
				
			}
}

FILE * scanf_check(FILE *f,int x)
{
		char c;		
		
		if(fgetc(f)!='a')
		{
			fprintf(globe,"Line %d does not contain a",line+1);
			fgets(ignore,1024,f);
			line++;
			return f; 
		}	
		if(fgetc(f)!='n')
		{
			fprintf(globe,"Line %d does not contain n",line+1);
			fgets(ignore,1024,f);
			line++;
			return f; 
		}	
		if(fgetc(f)!='f')
		{
			fprintf(globe,"Line %d does not contain f",line+1);
			fgets(ignore,1024,f);
			line++;
			return f; 
		}
		if(fgetc(f)!='(')
		{
			fprintf(globe,"Line %d does not contain (",line+1);
			fgets(ignore,1024,f);
			line++;
			return f; 
		}
		if(fgetc(f)!='"')
		{
			fprintf(globe,"Line %d does not contain \" ",line+1);
			fgets(ignore,1024,f);
			line++;
			return f; 
		}
		do
		{
			c = fgetc(f);
		}
		while(c!='"' && c!=')' && c!=';' && c!='\n');

		if(c!='"')
		{
			fprintf(globe,"Line %d does not contain \"",line+1);
			fgets(ignore,1024,f);
			line++;
			return f; 
		}
		do
		{
			c = fgetc(f);
		}
		while(c!='"' && c!=')' && c!=';' && c!='\n');
		if(c!=')')
		{
			fprintf(globe,"Line %d does not contain )",line+1);
			fgets(ignore,1024,f);
			line++;
			return f; 
		}
		do
		{
			c = fgetc(f);
		}
		while(c==' ');
		if(c!=';')
		{
			fprintf(globe,"Line %d does not contain ;",line+1);
			fgets(ignore,1024,f);
			line++;
			return f; 
		}
		return f;
}

int main()
{


	initialize();initialize2();initialize3();
	
	
	//PLEASE GIVE PATH ACCORDING TO YOUR FOLDER HIERARCHY 
	
	
	
	globe = fopen("/home/vivek/Desktop/final/error.txt","w+");
	FILE *fp = fopen("/home/vivek/Desktop/final/testing2.c","r");
	if(fp == NULL) {
        perror("Failed to open the source-sorry");
        return EXIT_FAILURE;
   	 }
	char ch;
	
	
	
	
	while((ch=fgetc(fp))!=EOF)
	{
		if(ch=='\n')
			line++;
		if(ch!='{')
			continue;
		else
		{
		
			while( ch!=EOF && (ch=fgetc(fp))!='}')
			{
				
				char ch2;
				line = (ch=='\n')?line+1:line;
				
				ch2 = fgetc(fp);
				
				if(ch=='/' && ch2=='/')
				{
					
					fgets(ignore,1024,fp);
				
					line++;
				}
				else
				{
					if(ch=='p' && ch2=='r')
					{
						fseek(fp,-2,SEEK_CUR);
						fp = printf_check(fp,0);
					}
					else if(ch=='i' && ch2=='n')
					{
						
						fp =int_check(fp,0);
					}
					else if(ch=='c' && ch2=='h')
					{
						fp = char_check(fp,0);
					}
					else if(ch=='f' && ch2=='l')
					{
						fp = float_check(fp,0);
					}
					else if(ch=='s' && ch2=='c')
					{
						fp = scanf_check(fp,0);
					}
					else
					{
						fseek(fp,-1,SEEK_CUR);	
					}
				}
			}
		}
	}
	
	
	printonconsole();
	return 0;
}

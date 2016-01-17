/****************************************************************************************
 * File name     : lexical_analysis.c
 * Author        : Ravi Kiran Chadalawada
 * Functionality : To parse the whole code and trak whole tokens in program.
 * Compiling     : gcc lexical_analysis.c -o lexical_analysis
 * Executing     : ./lexical_analysis sample.c   (provide run time input with sample program.
 * Input         : Any C language source code file with a sample program.
 *                 For ex : sample.c with following code.
 *
 *  #include<stdio.h>
 *
 *  int main()
 *  {
 *    int a,b,res;
 *    printf("enter the operands");
 *    scanf("%d",&a);
 *    scanf("%d",&b);
 *    res=a+b;
 *    res=a-b;
 *    res=a*b;
 *    res=a/b;
 *   printf("The result is :%d\n",res);
 *  }
 *
 * Output     :  Along with above source code we see following lines.
 *  THE TOTAL NUMBER OF LINES IN THE PROGRAMME ARE :13
 *
 *		         PREPROCESSORS
 *
 * The number of preprocessors are 1
 *
 *                         VARIABLES
 *
 * The total number of variables are 3
 *		The no of integer variables are 3
 *		The no of floating point  variables are 0
 *                                      
 *
 *                        INPUT-OUTPUT
 *
 * The number of formatted input statements are 2
 * The number of formatted output statements are 2
 * The number of formatspecifiers are 3
 *
 *		         OPERATIONS
 * The total number of operations are 8
 *
 *		The number of additions are 1
 *		The number of subtractions are 1
 *		The number of multiplications are 1
 *		The number of divisions are 1
 *		The number of assignments are 4
 *
 *                      SPECIAL CHARACTERS
 *
 * The total number of special characters are  43
 *
 *		The number of Curly Braces are  2
 *		The number of normal braces are 10
 *		The number of anglebraces are 2
 *		The number of commas are 5
 *		The number of percentage characters are 3
 *		The number of semicolons are 9
 *		The number of amphasends are 2
 *		The number of whitespaces are 2
 *		The number of double inverted commas are 8      
 *
*****************************************************************************************/


/**********header files or Preprocessors *******/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**************function prototypes*************/

void prefun();
void variable_count();
void psfunction();
void postfun();

/**************global variables***************/

char c;  //character to hold data from file
int i,j,k; //integers used as array indices
char a[200],b[100];//to hold data temporarily
int no_of_lines=0;//total no of lines in input file
int pre=0;//no of preprocessors

//catogery of input and output
int format=0;//no of format specifiers
int input=0;//no of input statements
int output=0;//noof output statements

//catogery of variables
int inte=0;//no of integer variables
int flot=0;//no of float variables
int vari=0; //total no of variables

//catogery of operations
int oper=0;//total no of operations 
int assign=0;//no of assignments
int add=0;//no of additions
int sub=0;//no of subtractions
int mul=0;//no of multiplications
int divi=0;//no of divisions

//catogery of special characters
int curly_braces=0;//no of curly braces
int normal_braces=0;//no of normal braces
int angle_braces=0;//no of angular braces
int comma=0;//no of commas
int percent=0;//no of  %'s
int semicol=0;//no of semicolons
int white_space=0;//no of white spaces
int spec=0;//total no special characters
int amph=0;//no of amphasands 
int double_inv=0;//no of double inverted commas;

/*************start of main function***********/

int main(int argc, char *argv[])
{
 FILE *fp; //file pointer

 fp=fopen(argv[1],"r");
 
if(fp==NULL)
  {
   printf("file cannot be opened :");
   exit(1);//exits from main block
  }//end of if block
 else
  {
   c=fgetc(fp);
   while(c!=EOF)
  {
   printf("%c",c);
   c=fgetc(fp);
  }
}fclose(fp);


fp=fopen("sample.c","r");

c=fgetc(fp);

    do
      {
	i=0;
        no_of_lines++;
	while(c!='\n')
		{
		 a[i]=c;
		 i++;
                c=fgetc(fp);
                }
		a[i]='\0';
          i=0;
        

    if(a[i]=='#')
         {
          pre++;
          prefun();
         }
       else if (a[i]=='{')
         {
          spec++;
          curly_braces++;
         }
         else if (a[i]=='}')
         {
          curly_braces++;
          spec++;
         }

        else if((a[i]=='i')||(a[i]=='f'))
        {
         variable_count();
        }
        else if ((a[i]=='p')||(a[i]=='s'))
         {
          psfunction();
         }
        else
         { 
          postfun();
         }
         for(k=0;a[k]!='\0';k++)
         {
           a[k]='\0';
         }
        
      c=fgetc(fp);
}while(c!=EOF);

printf("THE TOTAL NO OF LINES IN THE PROGRAMME ARE :%d\n",no_of_lines);

printf("\t\t\t\t\tPREPROCESSORS\n");
printf("The no of preprocessors are %d\n",pre);

printf("\n\t\t\t\t\t\tVARIABLES\n\n");
printf("The total no variables are :%d\n",vari);
printf("\t\tThe no of integer variables are %d\n",inte);
printf("\t\tThe no of floating point  variables are %d\n",flot);

printf("\n\t\t\t\t\t\tINPUT-OUTPUT\n\n");
printf("The no of formatted input statements are %d\n",input);
printf("The no of formatted output statements are %d\n",output);
printf("The no formatspecifiers are %d\n",format);

printf("\n\t\t\t\t\t\tOPERATIONS\n\n");
printf("The total no of operations are %d\n",oper);
printf("\t\tThe number of additions are %d\n",add);
printf("\t\tThe number of subtractions are %d\n",sub);
printf("\t\tThe number of multiplications are %d\n",mul);
printf("\t\tThe number of divisions are %d\n",divi);
printf("\t\tThe number of assignments are %d\n",assign);

printf("\n\t\t\t\t\t\tSPECIAL CHARACTERS\n\n");
printf("The no of special chars are  %d\n",spec);
printf("\t\tThe no of Curly Braces are  %d\n",curly_braces);
printf("\t\tThe no of normal braces are %d\n",normal_braces);
printf("\t\tThe no of anglebraces are %d\n",angle_braces);
printf("\t\tThe no of commas are %d\n",comma);
printf("\t\tThe no of percentage characters are %d\n",percent);
printf("\t\tThe no of semicolons are %d\n",semicol);
printf("\t\tThe no of amphasends are %d\n",amph);
printf("\t\tThe no of whitespaces are %d\n",white_space);
printf("\t\tThe no of double inverted commas are %d\n",double_inv);
 return 0;
} //end of main function

void prefun()//counts no of preprocessors
 { 
  
    while(a[i]!='\0')
     {
	if((a[i]==60)||(a[i]==62)) //ascii values for '<' is 60 and '>'is 62
	{
		angle_braces++;
		spec++;
	}
       i++;
    }
}

void variable_count()//fn definition that counts no of variables in the programme
{
   int local_count=0;//counts special characters in a line; 
   int e,f; //local variables  to check value returned by strcmp() fn 
    j=0;
   b[j]=a[i];
   i++;
   j++;
       
	while((a[i]!=32) && (a[i]!='\0'))  //ascii value of whitespace=32
	 {
	  b[j]=a[i];
	  j++;
	  i++;
	 }
 b[j]='\0';
 if(a[i]==32) 
   {
     white_space++;//incrementing white spaces
     spec++;
      i++;
     e=strcmp("int",b);
     f=strcmp("float",b);
    

 if(e==0)
       {
        for(k=0;b[k]!='\0';k++)
        {
	 b[k]='\0';
        }
         j=0;
     while(a[i]!='\0')
	{
	   b[j]=a[i];

           if (b[j]==61) //assignment ascii is 61
	  {
	   local_count++;
		assign++;
          }
	   else if (b[j]==59)//ascii value for ; is 59
          {
           semicol++;
           local_count++;
	  }
           else if(b[j]==44)//ascii for ,
           {
		comma++;
             local_count++;
           }
           else if(b[j]==40)//ascii for '(' only for main fn
           {
                normal_braces++;
                spec++; 
           }
           else if(b[j]==41)//ascii for '(' only for main fn
           {
                normal_braces++;
               spec++;
           }

          
         i++;
	j++; 
        }//end of while loop
      spec=spec+local_count;//adding to tatal no special characters in file
      inte=inte+local_count;   //adding to no of variables in the programme
      vari=vari+inte;
     }//end of if()
     else if(f==0)
      {
         for(k=0;b[k]!='\0';k++)//clearing  array b[] 
        {
         b[k]='\0';
        }
         j=0;
     while(a[i]!='\0')
        {
           b[j]=a[i];
       if (b[j]==61) //assignment ascii is 61
          {
           local_count++;
	   assign++;
          }
           else if (b[j]==59)//ascii value for ; is 59
          {
           local_count++;
           semicol++;
          }
           else if(b[j]==44)//ascii for ,
           {
             local_count++;
		comma++;
           }
         i++;
        j++;
        }
      spec=spec+local_count;//adding to tatal no special characters in file
      flot=flot+local_count;   //adding to no of variables in the programme
      vari=vari+flot;//counting total no of variables
     }
   }
else if(a[i]=='\0')
    {
        j=0;
	while(b[j]!='\0')
		{
		if(b[j]==61)//checking for assignment
			{
				assign++;
				oper++;
			}
		else if(b[j]==43)//ascii for addition
			{
				add++;
				oper++;
			}
		else if(b[j]==45) //ascii for subtraction
                        {
                                sub++;
		   oper++;
                        }
		else if(b[j]==42)//ascii for multiplication
                        {
                                mul++;
		    oper++;
                        }
		 else if(b[j]==47)//ascii for multiplication
                        {
                                divi++;
		    oper++;
                        }
                   j++;
	           } 
       }//end of while loop

}//end of intcount();

 void psfunction()//counts no of printf and scanf functions
 {  
   int r,v;//to hold the integer retutned by string compare fn
         j=0;
	b[j]=a[i];
	i++;
	j++;
	while((a[i]!=40) && (a[i]!='\0'))//asciii for '('
	{
                          b[j]=a[i];
		j++;
		i++;	
	}
        b[j]='\0';
        if(a[i]==40)
        {
        r=strcmp("printf",b);
        v=strcmp("scanf",b);
	
          if((r==0)||(v==0))
	   {
           if(r==0)
		{
		 output++;
		}
           else
		{
		 input++;
		}

	 for(k=0;b[k]!='\0';k++);
        {
                b[k]='\0';
        }
                 j=0;

		
	
                         while(a[i]!='\0')
		{
			b[j]=a[i];
			if(b[j]==40)//ascii for '('
			{
		                         spec++;//incrementing special characters
                                                      normal_braces++;
			}
                        else if(b[j]==37)//ascii for '%'
			{
                                                         percent++;
				spec++;
				format++;
			}
			else if(b[j]==44)//ascii value of ','
			{             comma++;
				spec++;
			}
			else if(b[j]==34)//ascii value of "
                        		{
                                                          spec++;
				double_inv++;
                       		 }
			else if(b[j]==41)//ascii value of ')'
                       		 {
                                                spec++;
                                                normal_braces++;
                       		 }
			else if(b[j]==59)//ascii value of ';'
                      		  {        
			 semicol++;
                                            spec++;
                       		 }
                                      else if(b[j]==38)//ascii value for '&'
                                   	{
                                                amph++;
                                               spec++;
		       	}
                        i++;
	         j++;
                    }
	}
    }
     else if(a[i]=='\0')
      {
        j=0;
        while(b[j]!='\0')
                {
                if(b[j]==61)//checking for assignment
                        {
                                assign++;
                                oper++;
                        }
                else if(b[j]==43)//ascii for addition
                        {
                                add++;
                                oper++;
                        }
                
       else if(b[j]==45) //ascii for subtraction
                        {
                                sub++;
                                oper++;
                        }
                else if(b[j]==42)//ascii for multiplication
                        {
                                mul++;
                                oper++;
                        }
                 else if(b[j]==47)//ascii for multiplication
                        {
                                divi++;
                                oper++;
                        }
                   j++;
                   }
       }
 }//end of ps function()	
void postfun()//start post function to check for four basic operations
{
  while(a[i]!='\0')
                {
                if(a[i]==61)//checking for assignment
                        {
                                assign++;
                                oper++;
                        }
                else if(a[i]==43)//ascii for addition
                        {
                                add++;
                                oper++;
                        }
                else if(a[i]==45) //ascii for subtraction
                        {
                                sub++;
                                oper++;
                        }
                else if(a[i]==42)//ascii for multiplication
                        {
                                mul++;
                                oper++;
                        }
                 else if(a[i]==47)//ascii for multiplication
                        {
                                divi++;
                                oper++;
                        }
                 else if(a[i]==59)//ascii for ';'
			{
			  semicol++;
                                             spec++;
			}
                           i++;
                   }

 }//end of post function


# lexical_analysis
This code is aimed at identifying and counting all the tokens in a given source code in C.


This source code is developed by using some implementations of C that are specific to gcc(GNU-C) compiler.Please use corresponding compiler specific API's if need to be compiled using any other compilers.
/****************************************************************************************
 * File name     : lexical_analysis.c
 * Author        : Ravi Kiran Chadalawada
 * Functionality : To parse the whole code and trak whole tokens in program.
 * Compiling     : gcc lexical_analysis.c -o lexical_analysis
 * Executing     : ./lexical_analysis sample.c   (provide run time argument as sample source code.
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
*****************************************************************************************/

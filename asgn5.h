#ifndef _asgn5_h
#define _asgn5_h


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


/*
Function: atoi_cs330
Inputs: character array (string)
Outputs: Integer representation of the char arrray 
Description: The function is used to convert a character array (possibly from user input) and convert
it into an integer so that it can be used in functions with integer parameters
*/
int atoi_cs330(const char* inputString) {
/*The variable "myString" is used as array where the input is stored after the memory is allocated to the heap
the number variable is the temp vairable that stores the value of the character array
the isNegative variable acts as a flag to tell the function whether the character arra starts with a '-' which
represents a negative number*/
    char* myString;
    int number = 0;
    bool isNegative = false;
//allocates memory to the heap
    myString = (char*)malloc(strlen(inputString) + 1);
//copies the imputed string into the memory location that was allocated
    strncpy(myString, inputString, strlen(inputString));



    if(*(myString + 0)=='\0'){
        return 0;
    }
//checks the first character of the array to see if its negative or not
    if (*(myString + 0) == '-') {
        isNegative = true;
        myString++; 
    }

    for (int i = 0; *(myString + i) != '\0'; i++) {
        //48 is subtracted from the number that is at the myString[i] location to convert its ascii value to integer value

        number = number * 10 + (*(myString + i) - 48);
    }
//
    if (isNegative) {
        number = number*-1;
    }



    return number;

    free(myString);
    return 0;
}

/*
Function: itoa_cs330
Inputs: integer representation of a number
Outputs: a character array that represents the number that was inputed*/
char* itoa_cs330(int num){
    char* myString;
    int  num1 = num;
    int sizeOfnum = 1;
    int tempnum=0;
//flag that determines a positive or negative number is inputed
    bool isNegative=false;

    if (num==0){
        sizeOfnum=1;
        myString = (char*)malloc(sizeOfnum);
        *(myString+0)='\0';
    }
    if(num<0){
        sizeOfnum++;
        isNegative=true;
        num1=-num;
        
    }
/*uses division to determine how many integers are in the number, this is used to determine the amount of
memory that needs to be allocated to the heap*/
    while (num1!=0){
        num1 = num1/10;
        sizeOfnum++;
    }
    num1 = num;
    myString = (char*)malloc(sizeOfnum+1);
/*the purpose of this for loop is to iterate through the integer and use a modulo divisor to extract numbers
from the int one at a time and then + 48 to the integer to convert it to its ascii character value*/
    for (int i=sizeOfnum-2;i>=0;i--){
        tempnum = num1%10;
        if (tempnum<0){
        *(myString+i)=-tempnum+48;
        }else{
        *(myString+i)=tempnum+48;
        }
        num1 = num1/10;

    }
    if(isNegative){
        *(myString+0)='-';
    }
    *(myString+(sizeOfnum))='\0';

    return myString;

}



#endif
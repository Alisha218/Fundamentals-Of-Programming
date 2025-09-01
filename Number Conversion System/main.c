#include <stdio.h>
 //Provides functions like printf() and scanf() for input and output operations.
#include <stdlib.h>
 //Provides functions for dynamic memory allocation and deallocation.
#include <stdbool.h>
 //Introduces the keywords true and false.
#include <math.h>
 //Includes functions like pow(), sqrt(), and sin()




// Structures
// Definition of a structure named 'ConversionInput' to hold various representations of a number.


typedef struct
{
    int decimal;            // Integer to store decimal representation of the number.
    long long binary;       // Long long integer to store binary representation of the number.
    int octal;              // Integer to store octal representation of the number.
    char hexadecimal[100];  // Character array to store hexadecimal representation of the number.
} ConversionInput;


//decimal to binary
long long decimalToBinary(int decimalNumber) {
    long long binaryNumber=0;
    int remainder,i=1;

    while (decimalNumber != 0) {
        remainder= decimalNumber%2;
        decimalNumber= decimalNumber/2;
        binaryNumber= binaryNumber+(remainder*i);
        i*=10;
    }

    return binaryNumber;
}

//decimal to octal
int decimalToOctal(int decimalNumber) {
    int octalNumber=0,i=1, remainder;

    while (decimalNumber!=0) {
        remainder= decimalNumber%8;
        decimalNumber= decimalNumber/8;
        octalNumber= octalNumber+(remainder*i);
        i*=10;
    }

    return octalNumber;
}

//decimal to hexadecimal
void decimalToHexadecimal(int decimalNumber) {
    int remainder;
    int i=1,j;
    char hexadecimalNumber[100];

    while (decimalNumber!=0)
    {
        remainder = decimalNumber%16;
        if (remainder<10)
        {
            remainder=remainder+48;
        }
        else
        {
            remainder=remainder+55;
        }
        hexadecimalNumber[i++]=remainder;
        decimalNumber=decimalNumber/16;
    }

    printf("Hexadecimal equivalent: ");
    for (j=i-1;j>0;j--)
    {
        printf("%c",hexadecimalNumber[j]);
    }
}

//binary to decimal
int binaryToDecimal(long long binaryNumber) {
    int decimalNumber=0,i=0, remainder;

    while (binaryNumber!=0)
    {
        remainder=binaryNumber%10;
        binaryNumber=binaryNumber/10;
        decimalNumber=decimalNumber+(remainder*pow(2,i));
        ++i;
    }

    return decimalNumber;
}

//octal to decimal
int octalToDecimal(int octalNumber) {
    int decimalNumber=0,i=0,remainder;

    while (octalNumber!=0)
    {
        remainder=octalNumber%10;
        octalNumber/=10;
        decimalNumber+=remainder*pow(8,i);
        ++i;
    }

    return decimalNumber;
}

//hexadecimal to decimal
int hexadecimalToDecimal(char hexadecimalNumber[]) {
    int decimalNumber=0,i=0,val,len;

    len=strlen(hexadecimalNumber);
    len--;

    for (i=0;hexadecimalNumber[i]!='\0';i++) {
        if (hexadecimalNumber[i] >='0'&&hexadecimalNumber[i]<='9')
        {
            val=hexadecimalNumber[i]-48;
        }
        else if (hexadecimalNumber[i]>='a'&&hexadecimalNumber[i]<='f')
        {
            val=hexadecimalNumber[i]-97+10;
        }
        else if (hexadecimalNumber[i]>='A'&&hexadecimalNumber[i]<='F')
        {
            val=hexadecimalNumber[i]-65+10;
        }

        decimalNumber=decimalNumber+(val*pow(16,len));
        len--;
    }

    return decimalNumber;
}

//binary to octal
int binaryToOctal(long long binaryNumber) {
    int octalNumber=0,decimalNumber=0,i=0;

    while (binaryNumber!=0)
    {
        decimalNumber+=(binaryNumber%10)*pow(2,i);
        ++i;
        binaryNumber/=10;
    }
    i=1;

    while (decimalNumber!=0)
    {
        octalNumber+=(decimalNumber%8)*i;
        decimalNumber/=8;
        i*=10;
    }

    return octalNumber;
}

//binary to hexadecimal
void binaryToHexadecimal(long long binaryNumber) {
    int decimalNumber=0,i=0;
    char hexadecimalNumber[100];

    while (binaryNumber!=0)
    {
        decimalNumber+=(binaryNumber%10)*pow(2,i);
        ++i;
        binaryNumber/=10;
    }

    i=1;

    while (decimalNumber!=0)
    {
        int temp=0;
        temp=decimalNumber % 16;

        if(temp<10)
            temp=temp+48;
        else
            temp=temp+55;

        hexadecimalNumber[i++]=temp;
        decimalNumber/=16;
    }

    printf("Hexadecimal equivalent: ");
    for (int j=i-1;j>0;j--)
        printf("%c",hexadecimalNumber[j]);
}

//octal to binary
long long octalToBinary(int octalNumber) {
    int decimalNumber=0,i=0;
    long long binaryNumber=0;

    while (octalNumber!=0)
    {
        decimalNumber+=(octalNumber%10)*pow(8,i);
        ++i;
        octalNumber/=10;
    }
    i=1;

    while (decimalNumber!=0)
    {
        binaryNumber+=(decimalNumber%2)*i;
        decimalNumber/=2;
        i*=10;
    }

    return binaryNumber;
}

//hexadecimal to binary
long long hexadecimalToBinary(char hexadecimalNumber[]) {
    int decimalNumber=hexadecimalToDecimal(hexadecimalNumber);
    long long binaryNumber=decimalToBinary(decimalNumber);

    return binaryNumber;
}

//octal to hexadecimal
void octalToHexadecimal(int octalNumber) {
    int decimalNumber=octalToDecimal(octalNumber);
    decimalToHexadecimal(decimalNumber);
}

//hexadecimal to octal
void hexadecimalToOctal(char hexadecimalNumber[]) {
    int decimalNumber=hexadecimalToDecimal(hexadecimalNumber);
    int octalNumber=decimalToOctal(decimalNumber);

    printf("Octal equivalent: %d",octalNumber);
}

//checking binary(1,0)
bool isValidBinary(long long binaryNumber) {
    while (binaryNumber!=0)
    {
        int digit=binaryNumber%10;
        if (digit!=0&&digit!=1)
        {
            return false;
        }
        binaryNumber/=10;
    }
    return true;
}

//checking octal(1-7)
bool isValidOctal(long long octalNumber) {
    while (octalNumber!=0)
    {
        int digit=octalNumber%10;
        if (digit<0||digit>7)
        {
            return false;
        }
        octalNumber/=10;
    }
    return true;
}

//checking Hexadecimal(1-10 && A-F)
bool isValidHexadecimal(const char *hexString) {
    while (*hexString!='\0')
    {
        char currentChar=*hexString;
        if (!((currentChar>='0'&&currentChar<='9')||
              (currentChar>='A'&&currentChar<='F')||
              (currentChar>='a'&&currentChar<='f')))
        {
            return false;
        }
        hexString++;
    }
    return true;
}
int main()
{
    int option, exit;
    char choice;
    printf("WELCOME TO THE NUMBER COVERSION SYSTEM\n\n");
    do{
    printf("*Number Conversion Menu:\n");
    printf("(1). Decimal to Binary\n");
    printf("(2). Decimal to Octal\n");
    printf("(3). Decimal to Hexadecimal\n");
    printf("(4). Binary to Decimal\n");
    printf("(5). Octal to Decimal\n");
    printf("(6). Hexadecimal to Decimal\n");
    printf("(7). Binary to Octal\n");
    printf("(8). Binary to Hexadecimal\n");
    printf("(9). Octal to Binary\n");
    printf("(10). Hexadecimal to Binary\n");
    printf("(11). Octal to Hexadecimal\n");
    printf("(12). Hexadecimal to Octal\n");
    printf("\nWhat specific conversion do you want to perform?\t");
    scanf("%d", &option);

    if (option>=1&&option<=12)
    {
        int inputDecimal,inputOctal;
        long long inputBinary;
        char inputHexadecimal[100];

        switch (option)
        {
            case 1:
                printf("\nEnter a decimal number: ");
                scanf("%d", &inputDecimal);
                printf("\nBinary equivalent: %lld",decimalToBinary(inputDecimal));
                printf("_{2}");
                break;

            case 2:
                printf("\nEnter a decimal number: ");
                scanf("%d", &inputDecimal);
                printf("\nOctal equivalent: %d",decimalToOctal(inputDecimal));
                printf("_{8}");
                break;

            case 3:
                printf("\nEnter a decimal number: ");
                scanf("%d", &inputDecimal);
                printf("\n");
                decimalToHexadecimal(inputDecimal);
                printf("_{16}");
                break;

            case 4:
                printf("\nEnter a binary number: ");
                scanf("%lld", &inputBinary);
                if(isValidBinary(inputBinary))
                {
                printf("\nDecimal equivalent: %d", binaryToDecimal(inputBinary));
                printf("_{10}");
                }
                else
                {
                    printf("\ninvalid input, give binary numbers (0 and 1)");
                }
                break;

            case 5:
                printf("\nEnter an octal number: ");
                scanf("%d", &inputOctal);
                if (isValidOctal(inputOctal))
                {
                printf("\nDecimal equivalent: %d", octalToDecimal(inputOctal));
                printf("_{10}");
                }
                else
                {
                    printf("\ninvalid input, give octal numbers (0-7)");
                }
                break;

            case 6:
                printf("\nEnter a hexadecimal number: ");
                scanf("%s",inputHexadecimal);
                 if (isValidHexadecimal(inputHexadecimal))
                 {
                    printf("\nDecimal equivalent: %d",hexadecimalToDecimal(inputHexadecimal));
                    printf("_{10}");
                 }
                 else
                {
                    printf("\ninvalid input, give hexadecimal number (0-9)&(A-F)");
                }
                break;

            case 7:
                printf("\nEnter a binary number: ");
                scanf("%lld", &inputBinary);
                if(isValidBinary(inputBinary))
                {
                printf("\nOctal equivalent: %d",binaryToOctal(inputBinary));
                printf("_{8}");
                }
                else
                {
                    printf("\ninvalid input, give binary numbers (0 and 1)");
                }
                break;

            case 8:
                printf("\nEnter a binary number: ");
                scanf("%lld", &inputBinary);
                if(isValidBinary(inputBinary))
                {
                printf("\n");
                binaryToHexadecimal(inputBinary);
                printf("_{16}");
                }
                else
                {
                    printf("\ninvalid input, give binary numbers (0 and 1)");
                }
                break;

            case 9:
                printf("\nEnter an octal number: ");
                scanf("%d", &inputOctal);
                if (isValidOctal(inputOctal))
                {
                printf("\nBinary equivalent: %lld",octalToBinary(inputOctal));
                printf("_{2}");
                }
                else
                {
                    printf("\ninvalid input, give octal numbers (0-7)");
                }
                break;

            case 10:
                printf("\nEnter a hexadecimal number: ");
                scanf("%s", inputHexadecimal);
                if (isValidHexadecimal(inputHexadecimal))
                 {
                printf("\nBinary equivalent: %lld",hexadecimalToBinary(inputHexadecimal));
                printf("_{2}");
                 }
                 else
                {
                    printf("\ninvalid input, give hexadecimal number (0-9)&(A-F)");
                }
                break;

            case 11:
                printf("\nEnter an octal number: ");
                scanf("%d", &inputOctal);
                if(isValidOctal(inputOctal))
                {
                printf("\n");
                octalToHexadecimal(inputOctal);
                printf("_{16}");
                }
                else
                {
                    printf("\ninvalid input, give octal numbers (0-7)");
                }
                break;

            case 12:
                printf("\nEnter a hexadecimal number: ");
                scanf("%s", inputHexadecimal);
                if (isValidHexadecimal(inputHexadecimal))
                 {
                printf("\n");
                hexadecimalToOctal(inputHexadecimal);
                printf("_{8}");
                 }
                 else
                 {
                    printf("\ninvalid input, give hexadecimal number (0-9)&(A-F)");
                 }
                break;
        }
    }
    else
    {
        printf("Wrong input, give input between (1-12)");
    }
    printf("\n\nDo you want to continou?(Y/N)\n");
    scanf(" %c",&choice);
    printf("\n");
    }
    while(choice=='y'||choice=='Y');
    return 0;
}

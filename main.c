#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary
long long decimalToBinary(int decimalNumber)
{
    long long binaryNumber=0;
    int remainder,i=1;
    while (decimalNumber!=0)
    {
        remainder=decimalNumber%2;
        decimalNumber= decimalNumber/2;
        binaryNumber=binaryNumber+(remainder*i);
        i*=10;
    }
    return binaryNumber;
}

// Function to convert decimal to octal
int decimalToOctal(int decimalNumber)
{
    int octalNumber= 0,i=1,remainder;
    while (decimalNumber!=0)
    {
        remainder=decimalNumber% 8;
        decimalNumber=decimalNumber/8;
        octalNumber=octalNumber+(remainder*i);
        i*=10;
    }
    return octalNumber;
}

// Function to convert decimal to hexadecimal
void decimalToHexadecimal(int decimalNumber)
{
    int quotient,remainder;
    int i=1,j;
    char hexadecimalNumber[100];

    while(decimalNumber!=0)
    {
        remainder=decimalNumber%16;
        // To convert remainder into the equivalent hexadecimal character
        if (remainder<10)
        {
            remainder=remainder+48;
        }
        else
        {
            remainder=remainder+55;
        }
        hexadecimalNumber[i++]=remainder;
        decimalNumber = decimalNumber/16;
    }
    //reverse
    printf("Hexadecimal equivalent: ");
    for (j=i-1;j>0;j--)
        printf("%c",hexadecimalNumber[j]);
}

// Function to convert binary to decimal
int binaryToDecimal(long long binaryNumber) {
    int decimalNumber = 0, i = 0, remainder;

    while (binaryNumber != 0) {
        remainder=binaryNumber%10;
        binaryNumber=binaryNumber/10;
        decimalNumber=decimalNumber+(remainder * pow(2,i));
        ++i;
    }

    return decimalNumber;
}

// Function to convert octal to decimal
int octalToDecimal(int octalNumber)
{
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

// Function to convert hexadecimal to decimal
int hexadecimalToDecimal(char hexadecimalNumber[])
{
    int decimalNumber=0,i=0,val,len;

    // Find the length of the hexadecimal number
    len=strlen(hexadecimalNumber);
    len--;

    for (i=0;hexadecimalNumber[i]!='\0';i++)
    {
        // Find the decimal value of each hexadecimal digit
        if (hexadecimalNumber[i]>='0'&&hexadecimalNumber[i]<='9')
        {
            val=hexadecimalNumber[i]-48;
        } else if(hexadecimalNumber[i]>='a'&&hexadecimalNumber[i]<='f')
        {
            val = hexadecimalNumber[i] - 97 + 10;
        } else if(hexadecimalNumber[i]>='A'&&hexadecimalNumber[i]<='F')
        {
            val = hexadecimalNumber[i]-65+10;
        }

        // Decimal equivalent formula
        decimalNumber+=val*pow(16,len);
        len--;
    }

    return decimalNumber;
}

// Function to convert binary to octal
int binaryToOctal(long long binaryNumber)
{
    int octalNumber=0, decimalNumber=0,i=0;

    // Convert binary to decimal
    while (binaryNumber!=0)
    {
        decimalNumber+=(binaryNumber%10)*pow(2,i);
        ++i;
        binaryNumber/=10;
    }

    i=1;

    // Convert decimal to octal
    while (decimalNumber!=0)
    {
        octalNumber+=(decimalNumber%8)*i;
        decimalNumber/=8;
        i*=10;
    }

    return octalNumber;
}

// Function to convert binary to hexadecimal
void binaryToHexadecimal(long long binaryNumber)
{
    int decimalNumber=0,i=0;
    char hexadecimalNumber[100];

    // Convert binary to decimal
    while(binaryNumber!=0)
    {
        decimalNumber+=(binaryNumber%10)*pow(2,i);
        ++i;
        binaryNumber/=10;
    }

    i=1;

    // Convert decimal to hexadecimal
    while (decimalNumber!=0)
    {
        int temp=0;
        temp=decimalNumber%16;

        // To convert remainder into the equivalent hexadecimal character
        if (temp<10)
            temp=temp+48;
        else
            temp=temp+55;

        hexadecimalNumber[i++]=temp;
        decimalNumber/=16;
    }

    printf("Hexadecimal equivalent: ");
    for (int j=i-1;j>0;j--)
        printf("%c", hexadecimalNumber[j]);
}

// Function to convert octal to binary
long long octalToBinary(int octalNumber)
{
    int decimalNumber=0,i=0;
    long long binaryNumber=0;

    // Convert octal to decimal
    while (octalNumber!=0)
    {
        decimalNumber+=(octalNumber%10)*pow(8,i);
        ++i;
        octalNumber/=10;
    }

    i=1;

    // Convert decimal to binary
    while (decimalNumber!=0)
    {
        binaryNumber+=(decimalNumber%2)*i;
        decimalNumber /=2;
        i*=10;
    }

    return binaryNumber;
}

// Function to convert hexadecimal to binary
long long hexadecimalToBinary(char hexadecimalNumber[])
{
    int decimalNumber=hexadecimalToDecimal(hexadecimalNumber);
    long long binaryNumber=decimalToBinary(decimalNumber);

    return binaryNumber;
}

// Function to convert octal to hexadecimal
void octalToHexadecimal(int octalNumber)
{
    int decimalNumber=octalToDecimal(octalNumber);
    decimalToHexadecimal(decimalNumber);
}

// Function to convert hexadecimal to octal
void hexadecimalToOctal(char hexadecimalNumber[])
{
    int decimalNumber=hexadecimalToDecimal(hexadecimalNumber);
    int octalNumber=decimalToOctal(decimalNumber);

    printf("Octal equivalent: %d",octalNumber);
}

int main()
{
    int option, exit;
    char choice;
    printf("WELCOME TO THE NUMBER COVERSION SYSTEM\n\n");
    do{
    printf("Number Conversion Menu:\n");
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

    if (option >= 1 && option <= 12) {
        int inputDecimal, inputOctal;
        long long inputBinary;
        char inputHexadecimal[100];

        switch (option)
        {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &inputDecimal);
                printf("Binary equivalent: %lld", decimalToBinary(inputDecimal));
                break;

            case 2:
                printf("Enter a decimal number: ");
                scanf("%d", &inputDecimal);
                printf("Octal equivalent: %d", decimalToOctal(inputDecimal));
                break;

            case 3:
                printf("Enter a decimal number: ");
                scanf("%d", &inputDecimal);
                decimalToHexadecimal(inputDecimal);
                break;

            case 4:
                printf("Enter a binary number: ");
                scanf("%lld", &inputBinary);
                printf("Decimal equivalent: %d", binaryToDecimal(inputBinary));
                break;

            case 5:
                printf("Enter an octal number: ");
                scanf("%d", &inputOctal);
                printf("Decimal equivalent: %d", octalToDecimal(inputOctal));
                break;

            case 6:
                printf("Enter a hexadecimal number: ");
                scanf("%s", inputHexadecimal);
                printf("Decimal equivalent: %d", hexadecimalToDecimal(inputHexadecimal));
                break;

            case 7:
                printf("Enter a binary number: ");
                scanf("%lld", &inputBinary);
                printf("Octal equivalent: %d", binaryToOctal(inputBinary));
                break;

            case 8:
                printf("Enter a binary number: ");
                scanf("%lld", &inputBinary);
                binaryToHexadecimal(inputBinary);
                break;

            case 9:
                printf("Enter an octal number: ");
                scanf("%d", &inputOctal);
                printf("Binary equivalent: %lld", octalToBinary(inputOctal));
                break;

            case 10:
                printf("Enter a hexadecimal number: ");
                scanf("%s", inputHexadecimal);
                printf("Binary equivalent: %lld", hexadecimalToBinary(inputHexadecimal));
                break;

            case 11:
                printf("Enter an octal number: ");
                scanf("%d", &inputOctal);
                octalToHexadecimal(inputOctal);
                break;

            case 12:
                printf("Enter a hexadecimal number: ");
                scanf("%s", inputHexadecimal);
                hexadecimalToOctal(inputHexadecimal);
                break;
        }
    } else {
        printf("Wrong input, give input between (1-12)");
    }
    printf("\n\nDo you want to continou?(Y/N)\n");
    scanf(" %c",&choice);
    }
    while(choice=='y' || choice=='Y');
    return 0;
}

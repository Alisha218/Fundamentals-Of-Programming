#include <stdio.h>
#include <stdlib.h>
#include<math.h>


int main()
{
    int length,width,height,radius, calc, aOf,pOf;
    length = 23;
    width= 12;
    height = 2;
    radius = 4;
    printf("which calculation is to be performed: \n 1.Area \n 2.Perimeter\n");
    scanf("%d", &calc);
    printf("calc performed is %d", calc);
    switch (calc)
    {
        case '1':
            {
                printf("area of? /n 1.circle\n 2. triangle \n 3.square\n");
                scanf("%d", aOf);

                switch (aOf)
                {
                    case '1':
                    {
                        printf("area is ", (3.14*pow(radius,2)));

                    }
                    case '2':
                    {
                        printf("area is %d", (1/2*length*height));
                    }
                    case '3':
                    {
                        printf("area is %d", (length*length)));
                    }
                    default:(printf("invalid"));

                }
        case '2':
            {
                printf("perimeter of ? \n 1.circle\n 2. triangle \n 3.square\n");
                scanf("%d" , pOf)

                switch (pOf)
                {
                    case 1:
                    {
                        printf("perimeter is ", (3.14*pow(radius,2)));
                        break;

                    }
                    case 2:
                    {
                        printf("perimeter is ", (length+(2*sqrt((length/2)^2+(height/2)^2))/;
                    }
                    case 3:
                    {
                        printf("perimter is ", (4*length)));
                    }
                    default:
                        {
                            printf("invalid")
                            break;
                        }

                }

            }
            }

    }


    return 0;

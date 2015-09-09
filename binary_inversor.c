#include <stdio.h>

int main()
{
    int decimal;
    scanf("%d",&decimal);

    int d[100];
    int i = 0;
    while( decimal>0 )
    {
	d[i] = decimal%2;
	i++;
	decimal = decimal/2;
    }

    for(int j=i-1;j>=0;j--)
	d[j] = !d[j];

    decimal = 0;
    int multiplier = 1;
    for ( int j=0; j<i; j++ )
    {
	decimal += multiplier*d[j];
	multiplier *= 2;
    }

    printf("%d",decimal);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define BIT_SET(i, x)	{ ((x) = (x) | (1 << i)) ;}

void showLED(char *LEDS)
{
	int i, j ;

	printf("LED \t1\t2\t3\t4\t5\t6\t7\t8\n");
	for (i = 0 ; i < 64 ; i++ )
	{
		printf("    ");
		for( j = 0 ; j < 8 ; j++)
		{
			if( LEDS[i] & (1 << j))
			{
				printf("\tON");
			}
			else
			{
				printf("\tOFF");
			}  
		}
		printf("\n");
	}
}

void changeLEDState(char *LEDS, int num)
{
	int div;
	int mod;

	num -= 1;
	div = num / 8;
	mod = num % 8;
	if( LEDS[div] & (1 << mod))
	{
		LEDS[div] = LEDS[div] | ( 0 << mod) ;
	}
	else
	{
		LEDS[div] = LEDS[div] | ( 1 << mod) ;
	}  

}
void showTargetLED(char *LEDS, int num)
{
	int i, j ;
	int div, mod;

	num -= 1;
	div = num / 8;
	mod = num % 8;

	if( LEDS[div] & (1 << mod))
	{
		printf("LED[%d] is ON\n", num + 1);
	}
	else
	{
		printf("LED[%d] is OFF\n", num + 1 );
	}  

}


int main(void){

	char LEDS[64] = {0,};
	int num = 0;

	while(1)
	{
		printf("\nshow all LED : 1 \nchane state N : 2 \ncheck Target LED : 3\ninput : ");  
		scanf("%d", &num);
		switch(num)
		{
		case 1:
			showLED(LEDS);
		break;
		case 2:
			printf("input LED Number : ");
			scanf("%d", &num);
			changeLEDState(LEDS, num);
		break;
		case 3:
			printf("input LED Number : ");
			scanf("%d" ,&num);
			showTargetLED(LEDS, num);
		break;
		default:
			printf("err input\n");
		break;
		}
	}

#if 0
	printf("\n");
	BIT_SET(0, *LEDS);  // LEDS |= (1 << 0) ;
	showTargetLED(&LEDS, 0);
	showTargetLED(&LEDS, 1);
	showTargetLED(&LEDS, 8);
	printf("\n");
	BIT_SET(1, *LEDS);
	showTargetLED(&LEDS, 1);
	showTargetLED(&LEDS, 2);
	printf("\n");
	BIT_SET(7, *LEDS);
	showTargetLED(&LEDS, 7);
	showTargetLED(&LEDS, 8);
	printf("\n");
	BIT_SET(50, *LEDS);
	showTargetLED(&LEDS, 50);
	showTargetLED(&LEDS, 51);
	printf("\n");
	//BIT_SET(80, *LEDS);
	showTargetLED(&LEDS, 80);
	printf("\n");
	BIT_SET(80, *LEDS);

	showTargetLED(&LEDS, 80);
#endif
}


#include<stdio.h>

void Euclid(int num1, int num2);//유클리드 알고리즘
void divisor_multiple(int num1, int num2);//약수와 배수 성립되는지 여부
void get_gcd(int nume1, int num2);// 최대공약수 노가다방법
void Expanded_Euclid(int num1, int num2);
int main()
{
	int num1, num2, temp;
	int menu;
	while (1)
	{
		printf("메뉴를 입력하시오(종료하시려면 -1): \n");
		printf("------------------\n");
		printf("1. 유클리드 알고리즘으로 최대공약수 구하기.\n");
		printf("2. 약수와 배수 성립되는지 판단.\n");
		printf("3. 최대공약수 알고리즘\n");
		printf("4. 확장된 유클리드 알고리즘\n");
		printf("------------------\n");
		scanf("%d", &menu);
		if (menu == -1)
		{
			break;
		}
		if (menu == 1)
		{
			printf("두 정수를 입력하시오:");
			scanf("%d %d", &num1, &num2);
			if (num1 < num2)
			{
				temp = num1;
				num1 = num2;
				num2 = temp;
			}
			Euclid(num1, num2);
		}
		else if (menu == 2)
		{
			printf("두 정수를 입력하시오:");
			scanf("%d %d", &num1, &num2);
			if (num1 < num2)
			{
				temp = num1;
				num1 = num2;
				num2 = temp;
			}
			divisor_multiple(num1, num2);
		}
		else if (menu == 3)
		{
			printf("두 정수를 입력하시오:");
			scanf("%d %d", &num1, &num2);
			if (num1 < num2)
			{
				temp = num1;
				num1 = num2;
				num2 = temp;
			}
			get_gcd(num1, num2);
		}
		else if (menu == 4)
		{
			printf("두 정수를 입력하시오:");
			scanf("%d %d", &num1, &num2);
			if (num1 < num2)
			{
				temp = num1;
				num1 = num2;
				num2 = temp;
			}
			Expanded_Euclid(num1, num2);
		}
	}

	return 0;
}

void Euclid(int num1, int num2)
{
	int modular;


	while (num2 != 0)
	{
		printf("%d = %d * %d + %d\n", num1, num2, num1 / num2, num1 % num2);
		modular = num1 % num2;
		num1 = num2;
		num2 = modular;

	}
	printf("최대 공약수는 %d입니다.\n", num1);
}

void divisor_multiple(int num1, int num2)
{
	if (num1 %num2 == 0)
	{
		printf("약수와 배수의 관계가 성립됩니다.\n", num1, num2);
	}
	else
	{
		printf("약수와 배수의 관계가 성립되지 않습니다.\n");
	}
}

void get_gcd(int num1, int num2)
{
	int temp;
	printf("(%d, %d)\n", num1, num2);
	while (num2 != 0)
	{
		num1 = num1 - num2;
		if (num1 < num2)
		{
			temp = num1;
			num1 = num2;
			num2 = temp;
		}
		printf("(%d, %d)\n", num1, num2);
	}
	printf("최대공약수는 %d입니다.\n", num1);
}

void Expanded_Euclid(int num1, int num2)
{
	int q, r, s1 = 1, s2 = 0, s, t1 = 0, t2 = 1, t;
	int modular;
	int a, b;
	a = num1;
	b = num2;
	printf("    q     a     b     r     s1    s2    s     t1    t2    t\n");
	while (num2 != 0)
	{
		q = num1 / num2;
		r = num1 % num2;
		s = s1 - (s2 * q);
		t = t1 - (t2 * q);
		printf("%5d %5d %5d %5d %5d %5d %5d %5d %5d %5d\n", q, num1, num2, r, s1, s2, s, t1, t2, t);
		modular = num1 %num2;
		num1 = num2;
		num2 = modular;
		s1 = s2;
		s2 = s;
		t1 = t2;
		t2 = t;
		if (num2 == 0)
		{
			break;
		}
	}
	printf("     %5d  %5d       %5d %5d       %5d %5d\n", num1, num2, s1, s2, t1, t2);
	printf("gcd(%d, %d) = %d입니다. s = %d t = %d입니다.\n", a, b, num1, s1, t1);

	return 0;

}
#include<stdio.h>

void Euclid(int num1, int num2);//��Ŭ���� �˰���
void divisor_multiple(int num1, int num2);//����� ��� �����Ǵ��� ����
void get_gcd(int nume1, int num2);// �ִ����� �밡�ٹ��
void Expanded_Euclid(int num1, int num2);
int main()
{
	int num1, num2, temp;
	int menu;
	while (1)
	{
		printf("�޴��� �Է��Ͻÿ�(�����Ͻ÷��� -1): \n");
		printf("------------------\n");
		printf("1. ��Ŭ���� �˰������� �ִ����� ���ϱ�.\n");
		printf("2. ����� ��� �����Ǵ��� �Ǵ�.\n");
		printf("3. �ִ����� �˰���\n");
		printf("4. Ȯ��� ��Ŭ���� �˰���\n");
		printf("------------------\n");
		scanf("%d", &menu);
		if (menu == -1)
		{
			break;
		}
		if (menu == 1)
		{
			printf("�� ������ �Է��Ͻÿ�:");
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
			printf("�� ������ �Է��Ͻÿ�:");
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
			printf("�� ������ �Է��Ͻÿ�:");
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
			printf("�� ������ �Է��Ͻÿ�:");
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
	printf("�ִ� ������� %d�Դϴ�.\n", num1);
}

void divisor_multiple(int num1, int num2)
{
	if (num1 %num2 == 0)
	{
		printf("����� ����� ���谡 �����˴ϴ�.\n", num1, num2);
	}
	else
	{
		printf("����� ����� ���谡 �������� �ʽ��ϴ�.\n");
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
	printf("�ִ������� %d�Դϴ�.\n", num1);
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
	printf("gcd(%d, %d) = %d�Դϴ�. s = %d t = %d�Դϴ�.\n", a, b, num1, s1, t1);

	return 0;

}
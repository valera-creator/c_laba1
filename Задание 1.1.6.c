#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main()
{
	int n, is_fool, summa = 0, count_elems = 0;
	int left = -1, right = -1;
	int *array;
	char buf_string;
	setlocale(LC_ALL, "Russian");

	// ���� � �������� �� ������ ��� ����� n
	while (1)
	{
		printf("������� N:\n");
		is_fool = scanf_s("%d", &n);
		if (is_fool)
		{
			break;
		}
		else
		{
			printf("N ������ ���� ������\n");
			scanf_s("%c", &buf_string); // ���� ����� ������, ��������� �����
		}
	}
	right = n - 1;
	array = malloc(sizeof(int) * n);

	// ���������� �������
	printf("������� �������� �������\n");
	for (int i = 0; i < n; i++)
	{
		// ���� � �������� �� ������ ��� ��������� �������
		while (1)
		{
			printf("������� %d-� ������� �������:\n", i + 1);
			is_fool = scanf_s("%d", &array[i]);
			if (is_fool)
			{
				break;
			}
			else
			{
				printf("������� ������ ���� ������\n");
				scanf_s("%c", &buf_string); // ���� ����� ������, ��������� �����
			}
		}
	}

	// ����� �������
	for (int i = 0; i < n; i++)
	{
		if (-5 >= array[i] || array[i] >= 7)
		{
			left = i;
			break;
		}
	}

	// ���� ��� ����� �������
	if (left == -1)
	{
		printf("����� ������� ���;\n�����: %d\n����������: %d\n", summa, count_elems);
		return 0;
	}

	// ������ �������
	for (int i = left + 1; i < n; i++)
	{
		if (array[i] < i + 1)
		{
			right = i;
		}
	}

	// printf("left: %d\n", left);
	// printf("right: %d\n", right);

	// ���������� �����
	for (int i = left; i <= right; i++)
	{
		summa += array[i];
	}

	count_elems = right - left + 1;

	printf("�����: %d\n����������: %d\n", summa, count_elems);
	return 0;
}
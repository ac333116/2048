#include <iostream>
#include <random>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdio.h>
#include <string>

using namespace std;

//����趨
#define Wide 4

random_device rd;
//��¼���������λ��
int newp[2] = { -1,-1 };
//��Ӯ�ж�
int judge(int arr[Wide][Wide])
{
	int p = 1;
	for (int i = 0; i < Wide; i++)
	{
		for (int j = 0; j < Wide; j++)
		{
			if (arr[i][j] == 0)
			{
				p = 0;
				break;
			}
		}
	}
	return p;
}



//ͼ�����
void load(int arr[Wide][Wide],int newp[2]) {
	system("cls");
	int i,j;
	cout << "\n\n\t";
	for (int n = 0; n < Wide-1; n++)
	{
		cout << "��������";
	}
	cout << "��\n";
	for (i = 0; i < Wide; i++)
	{
		for (j = 0; j < Wide; j++)
		{
			if (arr[i][j] != 0)
				if (i == newp[0] && j == newp[1])
					cout<<"\t\033[32;1m"<<arr[i][j]<<"\033[0m";
				else
					cout << "\t" << arr[i][j];
			else
				cout << "\t" ;
		}
		if(i!=Wide-1||j!=Wide)
		cout << "\n\n\n";
	}
	cout << "\n\t";
	for (int n = 0; n < Wide - 1; n++)
	{
		cout << "��������";
	}
	cout << "��\n";
}

//����¿�
void addNew(int arr[Wide][Wide])
{
	int x_r = rd() % Wide;
	int y_r = rd() % Wide;
	while (arr[x_r][y_r] != 0)
	{
		x_r = rd() % Wide;
		y_r = rd() % Wide;
	}
	if (rd() % 10 + 1 > 2)
		arr[x_r][y_r] = 2;
	else
		arr[x_r][y_r] = 4;
	newp[0] = x_r;
	newp[1] = y_r;
	load(arr,newp);
}

//ֵ�޸�
void modify(int arr[Wide][Wide], int i, int j, int dir)
{
	//����
	if (dir == 0)
	{
		int ie;
		for (ie = i - 1; ie >= 0; ie--)
		{
			if (arr[ie][j] != 0)
			{
				ie--;
				break;
			}
		}
		ie++;

		if (arr[i][j] == arr[ie][j] || arr[ie][j] == 0)
		{
			arr[ie][j] += arr[i][j];
			arr[i][j] = 0;
		}
		else if (arr[ie + 1][j] == 0)
		{
			arr[ie + 1][j] += arr[i][j];
			arr[i][j] = 0;
		}
		else
		{
			cout << "error" << endl;
		}
	}
	//����
	else if (dir == 1)
	{
		int ie;
		for (ie = i + 1; ie < Wide; ie++)
		{
			if (arr[ie][j] != 0)
			{
				ie++;
				break;
			}
		}
		ie--;

		if (arr[i][j] == arr[ie][j] || arr[ie][j] == 0)
		{
			arr[ie][j] += arr[i][j];
			arr[i][j] = 0;
		}
		else if (arr[ie - 1][j] == 0)
		{
			arr[ie - 1][j] += arr[i][j];
			arr[i][j] = 0;
		}
		else
		{
			cout << "error" << endl;
		}
	}
	//����
	if (dir == 2)
	{
		int je;
		for (je = j - 1; je >= 0; je--)
		{
			if (arr[i][je] != 0)
			{
				je--;
				break;
			}
		}
		je++;

		if (arr[i][j] == arr[i][je] || arr[i][je] == 0)
		{
			arr[i][je] += arr[i][j];
			arr[i][j] = 0;
		}
		else if (arr[i][je+1] == 0)
		{
			arr[i][je+1] += arr[i][j];
			arr[i][j] = 0;
		}
		else
		{
			cout << "error" << endl;
		}
	}
	//����
	if (dir == 3)
	{
		int je;
		for (je = j + 1; je < Wide; je++)
		{
			if (arr[i][je] != 0)
			{
				je++;
				break;
			}
		}
		je--;

		if (arr[i][j] == arr[i][je] || arr[i][je] == 0)
		{
			arr[i][je] += arr[i][j];
			arr[i][j] = 0;
		}
		else if (arr[i][je - 1] == 0)
		{
			arr[i][je - 1] += arr[i][j];
			arr[i][j] = 0;
		}
		else
		{
			cout << "error" << endl;
		}
	}
}




int main()
{

	int arr[Wide][Wide] = {};
	addNew(arr);
	load(arr,newp);


	while (1)
	{
		//�ж�ʤ��
		if (judge(arr))
		{
			cout << "��Ϸ����";
			break;
		}

		//�������¿�
		addNew(arr);

		Sleep(100);
		//�õ�����
		char ch1 = _getch();
		char ch2 = _getch();


		//��������
		//load(arr,newp);

		
		//ѡ����
		switch (ch2)
		{
		case(72):
			for (int i = 1; i < Wide; i++)
			{
				for (int j = 0; j < Wide; j++)
				{
					modify(arr, i, j, 0);
				}
			}
			break;
		case(80):
			for (int i = Wide-2; i >= 0; i--)
			{
				for (int j = 0; j < Wide; j++)
				{
					modify(arr, i, j, 1);
				}
			}
			break;
		case(75):
			for (int j = 1; j < Wide; j++)
			{
				for (int i = 0; i < Wide; i++)
				{
					modify(arr, i, j, 2);
				}
			}
			break;
		case(77):
			for (int j = Wide-2; j >= 0; j--)
			{
				for (int i = 0; i < Wide; i++)
				{
					modify(arr, i, j, 3);
				}
			}
			break;
		}
	}



	
	system("pause");
	return 0;
}
#include <iostream>
#include <random>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdio.h>
#include <string>

using namespace std;

//宽度设定
#define Wide 4

random_device rd;
//记录新添加数字位置
int newp[2] = { -1,-1 };
//输赢判定
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



//图像加载
void load(int arr[Wide][Wide],int newp[2]) {
	system("cls");
	int i,j;
	cout << "\n\n\t";
	for (int n = 0; n < Wide-1; n++)
	{
		cout << "————";
	}
	cout << "—\n";
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
		cout << "————";
	}
	cout << "—\n";
}

//添加新块
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

//值修改
void modify(int arr[Wide][Wide], int i, int j, int dir)
{
	//向上
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
	//向下
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
	//向左
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
	//向右
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
		//判定胜负
		if (judge(arr))
		{
			cout << "游戏结束";
			break;
		}

		//随机添加新块
		addNew(arr);

		Sleep(100);
		//得到按键
		char ch1 = _getch();
		char ch2 = _getch();


		//加载数字
		//load(arr,newp);

		
		//选择方向
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
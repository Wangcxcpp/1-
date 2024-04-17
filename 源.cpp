
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;
int ssize = 0;
typedef struct Lnode
{
	char data;
	struct Lnode* next;
}Lnode, * Lstack;
void creat(Lstack& s)
{
	Lnode* p = (Lnode*)malloc(sizeof(Lnode));
	s = NULL;
}
void push(Lstack& s, char d)
{
	Lnode* p = (Lstack)malloc(sizeof(Lnode));
	p->data = d;
	p->next = s;
	s = p;
	ssize++;
}
int pop(Lstack& s, char& e)
{
	if (s == NULL)
		return 0;
	Lnode* p = (Lstack)malloc(sizeof(Lnode));
	p = s;
	e = p->data;
	s = s->next;
	free(p);
	return 1;
}
int empty(Lstack& s)
{
	if (s == NULL)
		return 0;
	else return 1;
}
void detop(Lstack& s)
{
	Lnode* p;
	p = s;
	s = s->next;
	free(p);
	ssize--;
}
void clear(Lstack& s)
{
	s = NULL;
	ssize = 0;
	free(s);
}
int main()
{
	cout << "请用户输入命令：" << endl;
	cout << "    E：行编辑" << endl;
	cout << "    W:写入文件" << endl;
	cout << "    #:退格" << endl;
	cout << "    @:清除整行内容" << endl;
	cout << "    Q:存盘退出" << endl;
	Lstack LT;
	creat(LT);
	char c; char b; char a[10000] = { 0 };
	char temp = 0;
	int flag = 0;
	ofstream ofs; int length2;
	while (1)
	{
		cin >> c;
		b = getchar();
		switch (c)//根据输入不同实现不同操作
		{
		case'E':
			while (1)
			{
				c = getchar();
				if (c == '\n')break;
				else push(LT, c);
			}
			//length2 = ssize;
			break;
		case'#':
			detop(LT);//删除栈顶元素
			break;
		case'@':
			clear(LT);//清除栈中所有内容
			break;

		case'W':
		{
			ofs.open("test.txt", ios::out);//打开文件
			while (empty(LT))
			{
				for (int i = 0; pop(LT, temp) != 0; i++)
				{
					//pop(LT, temp);
					a[i] = temp;//将出栈元素赋值到数组里
				}
			}

			{
				length2 = ssize;
				if (ssize != 0)
				{
					for (int i = length2 - 1; i >= 0; i--)
						ofs << a[i];
				}

			}
			break;

		}
		case'Q':
			ofs.close();//关闭文件
			flag = 1;
		}
		if (flag == 1)break;
	}
}

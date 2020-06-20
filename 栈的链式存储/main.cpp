#include"LinkStack.h"
#include<string.h>

static char* k;
typedef struct MYCHAR{

	LinkNode node;
	char* p;
}MyChar;


typedef struct MYINT{

	LinkNode node;
	int p;
}MyInt;



//创建MyChar
MyChar* CreateMyChar(char* p)
{
	MyChar* mychar = (MyChar*)malloc(sizeof(MyChar));
	mychar->p = p;
	return mychar;
}

void SaveNumber(LinkStack* stack, char *p)
{
	char temp = *p;
	k = (char*)malloc(sizeof(int));
	*k = temp;
	
	Push_LinkStack(stack, (LinkNode*)CreateMyChar(k));
}


//判断是否是数字
int IsNumber(char c)
{
	return c >= '0'&&c <= '9';
}


//数字操作
void NumberOperate(char *p,LinkStack* stack1)
{
	printf("%c", p);
	SaveNumber(stack1,p);
}

//存入右操作数



//左括号操作
void LeftOperator(LinkStack* stack, char* p)
{
	Push_LinkStack(stack,(LinkNode*)CreateMyChar(p));
}
//判断是不是左括号
int IsLeft(char c)
{
	return c == '(';
}
//判断是不是右括号
int IsRight(char c)
{
	return c == ')';
}

//判断是运算符号
int IsOperator(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}

//返回运算符号的优先级
int GetPrioty(char c){
	if (c == '*' || c == '/')
		return 2;
	if (c == '+' || c == '-')
		return 1;
	return 0;
}

//右括号操作
void RightOperate(LinkStack* stack, LinkStack* stack1)
{
	while (Size_LinkStack(stack) > 0)
	{
		MyChar* mychar = (MyChar*)Top_LinkStack(stack);
		//如果匹配到左括号
		if (IsLeft(*(mychar->p)))
		{
			Pop_LinkStack(stack);
			break;
		}
		//如果不是左括号
		printf("%c", *(mychar->p));
		SaveNumber(stack1, mychar->p);
		Pop_LinkStack(stack);
		//释放内存
		free(mychar);
	}
}

void OperatorOperate(LinkStack* stack, char* p, LinkStack* stack1)
{
	//先取出栈顶符号
	MyChar* mychar = (MyChar*)Top_LinkStack(stack);
	if (mychar == NULL)
	{
		Push_LinkStack(stack, (LinkNode*)CreateMyChar(p));
		return;

	}
	if (GetPrioty(*mychar->p) < GetPrioty(*p))
	{
		Push_LinkStack(stack, (LinkNode*)CreateMyChar(p));
		return;
	}
	else
	{
		while (Size_LinkStack(stack)>=0)
		{
			MyChar* mychar2=(MyChar*)Top_LinkStack(stack);
			//如果优先级低 当前符号入栈
			if (GetPrioty(*mychar2->p)< GetPrioty(*p))
			{
				Push_LinkStack(stack, (LinkNode*)CreateMyChar(p));
				break;
			}
			//输出
			printf("%c", *(mychar2->p));
			SaveNumber(stack1, mychar2->p);
			//弹出
			Pop_LinkStack(stack);
			//释放
		}
	}
	free(mychar);

}




int finish(int c1, int c2, char result)
{
	if (result == '+')
	{
		int sum = c1 + c2;
		return sum;
	}
	if (result == '-')
	{
		int sum = c2 - c1;
		return sum;
	}
	if (result == '*')
	{
		int sum = c1 * c2;
		return sum;
	}
	if (result == '/')
	{
		int sum = c2/c1;
		return sum;
	}
}
int main(void)
{

	//创建栈
	LinkStack* stack = Init_LinkStack();

	char* str = "8+(9-1)*5";
	char* p = str;
	LinkStack* stack1 = Init_LinkStack();
	char result[30];
	while (*p != '\0')
	{ 
		//如果是数字
		if (IsNumber(*p))
		{
			NumberOperate(p,stack1);
		}
		//如果是左括号
		if (IsLeft(*p))
		{
			LeftOperator(stack, p);
		}
		//如果是右括号
		if (IsRight(*p))
		{
			RightOperate(stack,stack1);
		}
		//如果是运算符
		if (IsOperator(*p))
		{
			OperatorOperate(stack, p,stack1);
		}
		p++;
	}

    while(Size_LinkStack(stack) > 0)
	{
		printf("%c", *((MyChar*)Top_LinkStack(stack))->p);
		SaveNumber(stack1, ((MyChar*)Top_LinkStack(stack))->p);
		Pop_LinkStack(stack);
	}
	printf("\n");
	int i =Size_LinkStack(stack1)-1;
	int temp = Size_LinkStack(stack1);
	while (Size_LinkStack(stack1) > 0)
	{
		result[i] = *((MyChar*)Top_LinkStack(stack1))->p;
		Pop_LinkStack(stack1);
		i--;
	}
	result[temp] = '\0';
	for (int i = 0; i < temp; i++)
	{
		printf("%c", result[i]);
	}
	printf("\n");
	LinkStack* sum = Init_LinkStack();
	int count1 = 0;
	//MyInt* mi = (MyInt*)malloc(sizeof(MyInt));
	while (result[count1]!='\0')
	{
		///printf("%c",result[count1]);
		 MyInt* mi = (MyInt*)malloc(sizeof(MyInt));
		if (result[count1]>='0'&&result[count1]<='9')
		{
			//MyInt* mi = (MyInt*)malloc(sizeof(MyInt));
			mi->p = int(result[count1] - '0');
			Push_LinkStack(sum, (LinkNode*)mi);
			//printf("%c", *((MyChar*)Top_LinkStack(stack1))->p);
			//free(mi);
		}
		else
		{
			    int c1 = ((MyInt*)Top_LinkStack(sum))->p;
			    Pop_LinkStack(sum);
			    int c2 = ((MyInt*)Top_LinkStack(sum))->p;
			    Pop_LinkStack(sum);
			    int pf = finish(c1, c2,result[count1]);
			    //MyInt* mi = (MyInt*)malloc(sizeof(MyInt));
			    mi->p = pf;
				Push_LinkStack(sum, (LinkNode*)mi);
			    //free(mi);
		}
		if (result[count1+1]=='\0')
		{
			printf("结果为：%d\n", ((MyInt*)Top_LinkStack(sum))->p);
		}
		count1++;
	}
	FreeSpace_LinkStack(stack);
	FreeSpace_LinkStack(stack1);
	FreeSpace_LinkStack(sum);
	//if (Size_LinkStack(stack1)==0)
	//{
	//	printf("true\n");
	//	
	//}
	//else
	//{
	//	printf("false\n");
	//	printf("%c", *((MyChar*)Top_LinkStack(stack1))->p);
	//}

    
}
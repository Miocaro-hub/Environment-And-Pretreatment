#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//预处理(编译)详解

//预定义符号
//__FILE__  进行编译的源文件
//__LINE__  文件当前的行号
//__DATE__  文件被编译的日期
//__TIME__  文件被编译的时间
//__STDC__  如果编译器遵循ANSI C,其值为1,否则未定义
//这些预定义符号都是语言内置的,例如:
//printf("file:%s line:%d\n",__FILE__,__LINE__);
int main()
{
	printf("file:%s line:%d\n", __FILE__, __LINE__); //__FILE__就是代码所在的源文件的名称,__LINE__就是文件当前的行号

	//若要写日志文件
	int i = 0;
	int arr[10] = { 0 };
	FILE* pf = fopen("log.txt", "w");
	for (i = 0; i < 10; i++)
	{
		arr[i] = i;
		fprintf(pf, "file:%s line:%d date:%s time:%s i=%d\n",
			__FILE__, __LINE__, __DATE__, __TIME__, i);
	}
	fclose(pf);
	pf = NULL;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}


//预处理指令
//#define定义标识符
//还有#include,#pragma,#if,#end,#endif,#ifdef等
//语法: #define name stuff

#define MAX 100
#define STR "hello world"
#define reg register  //为register这个关键字,创建一个简短的名字reg
#define do_forever for(;;)  //用更形象的符号来替换一种实现
#define CASE break;case  //在写case语句的时候自动把break写上

//如果定义的stuff过长,可以分成几行写,除了最后一行外,每行的后面都加一个反斜杠(续行符)
#define DEBUG_PRINT printf("file:%s\tline:%d\t"\
                           date:%s\ttime:%s\n",\
                           __FILE__,__LINE__,
__DATE__, __TIME__)
//#define后面不要加;

int main()
{
	int max = MAX;
	printf("%d\n", max);
	printf("%s\n", STR);
	return 0;
}

//#define定义宏
//#define机制包括了一个规定,允许把参数替换到文本中,这种实现通常称为宏(macro)或定义宏(define macro)

//宏的申明方式:
//#define name(parament-list)stuff其中的parament-list是一个由逗号隔开的符号表,它们可能出现在stuff中
//参数列表的左括号必须与name紧邻,如果两者之间有任何空白存在,参数列表就会被解释为stuff的一部分

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//文件包含
//#include指令可以使另外一个文件被编译,就像它实际出现于#include指令的地方一样
//这种替换的方式很简单:预处理器先删除这条指令,并用包含文件的内容替换.这样一个源文件被包含10次,那就实际被编译10次

//头文件被包含的方式:
//本地文件包含 - #include"filename" 用双引号
//库文件包含 - #include<filename.h> 用尖括号(也可以用双引号,只不过走的就是本地文件的查找策略,浪费时间,也不容易区分是本地文件还是库文件了)
//本地文件的查找策略:先在源文件所在目录下查找,如果该头文件未找到,编译器就想查找库函数头文件一样在标准位置查找头文件.如果找不到就提示编译错误
//库文件的查找测率:直接去标准路径下查找,如果找不到就提示编译错误

//头文件时长会出现嵌套文件包含的情况,可能会多次的被引用,会使得头文件冗余,被包含一次就被编译一次
//这时候条件编译就发挥了作用,可以有效避免头文件的重复引入
//例如:
#ifndef __TEST_H__  //若头文件已经被定义过,则中间的代码全部不执行
#define __TEST_H__
int Add(int x, int y);
#endif

//现在还有一种方法:
#pragma once
int Add(int x, int y);

//推荐《高质量C/C++编程指南》中附录的考试试卷

//还有一些其他的预处理指令:
//#error,#pragma,#line等可以去自己了解
//可以参考《C语言深度剖析》进行学习

//百度笔试题:请编写宏,计算结构体中某变量相对于首地址的偏移,并给出说明
#include<stddef.h>

struct S
{
	char c1;
	int a;
	char c2;
};

int main()
{
	//struct S s;
	printf("%d\n", offsetof(struct S, c1)); //offsetof为一个宏,可以计算结构体中某变量相对于首地址的偏移
	printf("%d\n", offsetof(struct S, a));
	printf("%d\n", offsetof(struct S, c2));
	return 0;
}

//下面要自己实现
//假设起始成员的地址偏移量为0
#define OFFSETOF(struct_name,member_name) (int)&(((struct_name*)0)->member_name)

int main()
{
	printf("%d\n", OFFSETOF(struct S, c1));
	printf("%d\n", OFFSETOF(struct S, a));
	printf("%d\n", OFFSETOF(struct S, c2));
	return 0;
}
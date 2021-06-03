#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//命令行定义
//许多C的编译器提供了一种能力,允许在命令行中定义符号.用于启动编译过程.例如:当我们根据同一个源文件要编译出不同的一个程序的不同版本的时候,这个特性有点用处
//(假定某个程序中声明了一个某个长度的数组,如果机器内存有限,我们需要一个很小的数组,但是另外一个机器内存大写,我们需要一个数组能够大写)
int main()
{
	int arr[SZ] = { 0 };
	int i = 0;
	for (i = 0; i < SZ; i++)
	{
		arr[i] = i;
	}
	for (i = 0; i < SZ; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
//编译指令(linux):gcc - D SZ=10 programe.c


//条件编译:在编译一个程序的时候我们如果要将一条语句(一组语句)编译或者放弃是很方便的,因为我们有条件编译指令
//比如说:调试性代码,删除可惜,保留又碍事,所以我们可以选择性的编译
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		arr[i] = 0;
#ifdef DEBUG  //如果DEBUG被定义,下面的语句才会执行(预编译阶段#define任意一个值)
		printf("%d ", arr[i]);  //这句打印是我们要验证arr数组是否全部被置为0,并无其他的作用
#endif
	}
	return 0;
}

//常见的条件编译指令:
/*
1.
#if 常量表达式
           //...
#endif
常量表达式由预处理器求值
*/
#define DEBUG 0
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		arr[i] = 0;
#if DEBUG //(DEBUG的值为真则语句执行,为假则不执行)
		printf("%d ", arr[i]);  //这句打印是我们要验证arr数组是否全部被置为0,并无其他的作用
#endif
	}
	return 0;
}


/*
2.多个分支的条件编译
#if 常量表达式
        //...
#elif 常量表达式
        //...
#else 
        //...
#endif
*/
int main()
{
#if 2==1  //如果第一个的常量表达式为真,则执行下面的语句,其他的不执行,同理,为假的话判断下面的
	printf("hello\n");  
#elif 1==1
	printf("nihao\n");
#else
	printf("bonjour");
#endif
	return 0;
}

/*
3.判断是否被定义
#if defined(symbol)
#ifdef symbol

#if !defined(symbol)
#ifndef symbol
*/
int main()
{
#if defined(DEBUG)  //如果定义过DEBUG,则执行下面的语句
	printf("hello\n");
#endif

#if !defined(DEBUG) //如果没有定义过DEBUG,则执行下面的语句
	printf("bonjour");
#endif

#ifndef DEBUG //如果没有定义过DEBUG,则执行下面的语句
	printf("nihao");
#endif
	return 0;
}

/*
4.嵌套指令
#if defined(OS_UNIX)
        #ifdef OPTION1
		        unix_version_option1();
        #endif
		#ifdef OPTION2
		        unix_version_option2();
		#endif
#elif defined(OS_MSSDOS)
        #ifdef OPTION2
		        msdos_version_option2();
	    #endif
#endif
*/
          
//条件编译指令在头文件中会广泛的使用
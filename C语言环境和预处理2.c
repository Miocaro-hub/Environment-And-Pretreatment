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

#define SQUARE(X) X*X
int main()
{
	int ret = SQUARE(5);
	int ret = 5 * 5;

	int ret = SQUARE(5 + 1);
	printf("%d\n", ret);  //此时打印的结果为11,5+1*5+1 = 11
	//所以在写宏的时候,括号必不可少,不要吝啬括号的使用
	return 0;
}

//又有以下的情形
#define DOUBLE(X) X+X
int main()
{
	int a = 5;
	int ret = 10 * DOUBLE(a);
	//宏的参数并不是传参，而是完全的替换,所以上述的式子等价于
	int ret = 10 * 5 + 5;  //结果为55,这就是没有加上括号的后果
	return 0;
}


//#define替换规则
//在程序中扩展#define定义符号和宏时,需要涉及几个步骤
//1.在调用宏时,首先对参数进行检查,看看是否包括任何由#define定义的符号.如果是,它们首先被替换
//2.替换文本随后被插入到程序中原来文本的位置.对于宏,参数名被他们的值替换
//3.最后,再次对结果文件进行扫描,看看它是否包含任何由#define定义的符号.如果是,就重复上述处理过程
//例如:

#define MAX 100
#define DOUBLE(X) ((X)+(X))
int main()
{
	int a = 5;
	int ret = 10 * DOUBLE(MAX);  //此时MAX先被替换成100
	int ret = 10 * 5 + 5; 
	return 0;
}
//注意:1.宏参数和#define定义中可以出现其他#define定义的变量.但是对于宏,不能出现递归
//     2.当预处理器搜索#define定义的符号的时候,字符串常量的内容并不被搜索


//#和## - 如何把参数插入到字符串中
//使用#,把一个宏参数变成对应的字符串
#define PRINT(X) printf("the value of "#X" is %d\n",X)
int main()
{
	int a = 10;
	int b = 20;
	PRINT(a);
	//等价于printf("the value of""a""is %d\n",a);
	PRINT(b);
	//printf("the value of""b""is %d\n", b);
	//多个字符串放在一起会自然的连接起来
	return 0;
}


//##的作用 - 可以把位于它两边的符号合成一个符号,它允许宏定义从分离的文本片段创建标识符
#define CAT(X,Y) X##Y
int main()
{
	int Helloworld = 2021;
	printf("%d\n", Helloworld);  //结果为2021
	printf("%d\n", CAT(Hello, world)); //结果也为2021,和上式等价
	return 0;
}
//这样的连接必须产生一个合法的标识符,否则其结果就是未定义的


//带副作用的宏参数
//当宏参数在宏的定义中出现超过一次的时候,如果参数带有副作用,那么你在使用这个宏的时候就可能出现不可预测的后果
//副作用就是表达式求值的时候出现的永久性的效果
//例如:
//x+1;不带有副作用   x++;带有副作用

#define MAX(X,Y) (X)>(Y)?(X);(Y)
int mian()
{
	int a = 10;
	int b = 11;

	int max = MAX(a++, b++);
	printf("%d\n", max);//12
	printf("%d\n", a);//11
	printf("%d\n", b);//13
	return 0;
}


//宏和函数的对比
//宏通常被应用于执行简单的运算,比如在两个数中找出较大的一个
#define MAX(a,b)  ((a)>(b)?(a):(b))

//不选择用函数来完成这个任务有两个原因:
//1.用于调用函数和从函数返回的代码可能比实际执行这个小型计算工作所需要的时间更多.所以宏比函数在程序的规模和速度方面更胜一筹
//  函数在调用的时候会有函数调用和返回的开销,而宏在预处理阶段就完成了替换,没有函数嗲用和返回的开销
//2.更为重要的是函数的参数必须声明为特定的类型,所以函数只能在类型适合的表达式上使用.反之这个宏可以适用于整型,长整型,浮点型等可以用于>来比较的类型.宏是类型无关的

//当然和宏和函数相比也有劣势的地方
//1.每次使用宏的时候,一份宏定义的代码将插入到程序中.除非宏比较短,否则可能大幅度增加代码的长度
//2.宏是没法调试的
//3.宏由于类型无关,也不够严谨
//4.宏可能会带来运算符优先级的问题,导致程序容易出错

//宏有时候可以做函数做不到的事情,比如:宏的参数可以出现类型,但是函数做不到
#define SIZEOF(type) sizeof(type)
int main()
{
	int ret = SIZEOF(int);
	//等价于int ret = sizeof(int);
	printf("%d\n", ret);
	return 0;
}

//在动态内存开辟的时候也更加的方便
#define MALLOC(num,type) (type*)malloc(num*sizeof(type))
int main()
{
	int* p = (int*)malloc(10 * sizeof(int)); //传统的写法

	int* p = MALLOC(10, int);
	//int* p = (int*)malloc(10*sizeof(int));
	return 0;
}

//命名约定
//一般来讲函数和宏的使用语法很相似,所以语言本身没法帮我们区分二者,那我们平时的一个习惯就是:
//把宏名全部大写,函数名不要全部大写



//#undef - 这条指令用于移除一个宏定义
#define MAX 100
int main()
{
	printf("MAX = %d\n", MAX);
#undef MAX
	printf("MAX = %d\n", MAX); //此时的MAX被移除,无法再使用了
	return 0;
}
//#undef NAME 如果现存的一个名字需要被重新定义,那么它的旧名字首先要被移除


//命令行定义
//pp255

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//Ԥ����(����)���

//Ԥ�������
//__FILE__  ���б����Դ�ļ�
//__LINE__  �ļ���ǰ���к�
//__DATE__  �ļ������������
//__TIME__  �ļ��������ʱ��
//__STDC__  �����������ѭANSI C,��ֵΪ1,����δ����
//��ЩԤ������Ŷ����������õ�,����:
//printf("file:%s line:%d\n",__FILE__,__LINE__);
int main()
{
	printf("file:%s line:%d\n", __FILE__, __LINE__); //__FILE__���Ǵ������ڵ�Դ�ļ�������,__LINE__�����ļ���ǰ���к�

	//��Ҫд��־�ļ�
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


//Ԥ����ָ��
//#define�����ʶ��
//����#include,#pragma,#if,#end,#endif,#ifdef��
//�﷨: #define name stuff

#define MAX 100
#define STR "hello world"
#define reg register  //Ϊregister����ؼ���,����һ����̵�����reg
#define do_forever for(;;)  //�ø�����ķ������滻һ��ʵ��
#define CASE break;case  //��дcase����ʱ���Զ���breakд��

//��������stuff����,���Էֳɼ���д,�������һ����,ÿ�еĺ��涼��һ����б��(���з�)
#define DEBUG_PRINT printf("file:%s\tline:%d\t"\
                           date:%s\ttime:%s\n",\
                           __FILE__,__LINE__,
__DATE__, __TIME__)
//#define���治Ҫ��;

int main()
{
	int max = MAX;
	printf("%d\n", max);
	printf("%s\n", STR);
	return 0;
}

//#define�����
//#define���ư�����һ���涨,����Ѳ����滻���ı���,����ʵ��ͨ����Ϊ��(macro)�����(define macro)

//���������ʽ:
//#define name(parament-list)stuff���е�parament-list��һ���ɶ��Ÿ����ķ��ű�,���ǿ��ܳ�����stuff��
//�����б�������ű�����name����,�������֮�����κοհ״���,�����б�ͻᱻ����Ϊstuff��һ����
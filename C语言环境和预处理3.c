#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//�����ж���
//���C�ı������ṩ��һ������,�������������ж������.���������������.����:�����Ǹ���ͬһ��Դ�ļ�Ҫ�������ͬ��һ������Ĳ�ͬ�汾��ʱ��,��������е��ô�
//(�ٶ�ĳ��������������һ��ĳ�����ȵ�����,��������ڴ�����,������Ҫһ����С������,��������һ�������ڴ��д,������Ҫһ�������ܹ���д)
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
//����ָ��(linux):gcc - D SZ=10 programe.c


//��������:�ڱ���һ�������ʱ���������Ҫ��һ�����(һ�����)������߷����Ǻܷ����,��Ϊ��������������ָ��
//����˵:�����Դ���,ɾ����ϧ,�����ְ���,�������ǿ���ѡ���Եı���
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		arr[i] = 0;
#ifdef DEBUG  //���DEBUG������,��������Ż�ִ��(Ԥ����׶�#define����һ��ֵ)
		printf("%d ", arr[i]);  //����ӡ������Ҫ��֤arr�����Ƿ�ȫ������Ϊ0,��������������
#endif
	}
	return 0;
}

//��������������ָ��:
/*
1.
#if �������ʽ
           //...
#endif
�������ʽ��Ԥ��������ֵ
*/
#define DEBUG 0
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		arr[i] = 0;
#if DEBUG //(DEBUG��ֵΪ�������ִ��,Ϊ����ִ��)
		printf("%d ", arr[i]);  //����ӡ������Ҫ��֤arr�����Ƿ�ȫ������Ϊ0,��������������
#endif
	}
	return 0;
}


/*
2.�����֧����������
#if �������ʽ
        //...
#elif �������ʽ
        //...
#else 
        //...
#endif
*/
int main()
{
#if 2==1  //�����һ���ĳ������ʽΪ��,��ִ����������,�����Ĳ�ִ��,ͬ��,Ϊ�ٵĻ��ж������
	printf("hello\n");  
#elif 1==1
	printf("nihao\n");
#else
	printf("bonjour");
#endif
	return 0;
}

/*
3.�ж��Ƿ񱻶���
#if defined(symbol)
#ifdef symbol

#if !defined(symbol)
#ifndef symbol
*/
int main()
{
#if defined(DEBUG)  //��������DEBUG,��ִ����������
	printf("hello\n");
#endif

#if !defined(DEBUG) //���û�ж����DEBUG,��ִ����������
	printf("bonjour");
#endif

#ifndef DEBUG //���û�ж����DEBUG,��ִ����������
	printf("nihao");
#endif
	return 0;
}

/*
4.Ƕ��ָ��
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
          
//��������ָ����ͷ�ļ��л�㷺��ʹ��
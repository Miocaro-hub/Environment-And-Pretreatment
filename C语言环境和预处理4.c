#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//�ļ�����
//#includeָ�����ʹ����һ���ļ�������,������ʵ�ʳ�����#includeָ��ĵط�һ��
//�����滻�ķ�ʽ�ܼ�:Ԥ��������ɾ������ָ��,���ð����ļ��������滻.����һ��Դ�ļ�������10��,�Ǿ�ʵ�ʱ�����10��

//ͷ�ļ��������ķ�ʽ:
//�����ļ����� - #include"filename" ��˫����
//���ļ����� - #include<filename.h> �ü�����(Ҳ������˫����,ֻ�����ߵľ��Ǳ����ļ��Ĳ��Ҳ���,�˷�ʱ��,Ҳ�����������Ǳ����ļ����ǿ��ļ���)
//�����ļ��Ĳ��Ҳ���:����Դ�ļ�����Ŀ¼�²���,�����ͷ�ļ�δ�ҵ�,������������ҿ⺯��ͷ�ļ�һ���ڱ�׼λ�ò���ͷ�ļ�.����Ҳ�������ʾ�������
//���ļ��Ĳ��Ҳ���:ֱ��ȥ��׼·���²���,����Ҳ�������ʾ�������

//ͷ�ļ�ʱ�������Ƕ���ļ����������,���ܻ��εı�����,��ʹ��ͷ�ļ�����,������һ�ξͱ�����һ��
//��ʱ����������ͷ���������,������Ч����ͷ�ļ����ظ�����
//����:
#ifndef __TEST_H__  //��ͷ�ļ��Ѿ��������,���м�Ĵ���ȫ����ִ��
#define __TEST_H__
int Add(int x, int y);
#endif

//���ڻ���һ�ַ���:
#pragma once
int Add(int x, int y);

//�Ƽ���������C/C++���ָ�ϡ��и�¼�Ŀ����Ծ�

//����һЩ������Ԥ����ָ��:
//#error,#pragma,#line�ȿ���ȥ�Լ��˽�
//���Բο���C�����������������ѧϰ

//�ٶȱ�����:���д��,����ṹ����ĳ����������׵�ַ��ƫ��,������˵��
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
	printf("%d\n", offsetof(struct S, c1)); //offsetofΪһ����,���Լ���ṹ����ĳ����������׵�ַ��ƫ��
	printf("%d\n", offsetof(struct S, a));
	printf("%d\n", offsetof(struct S, c2));
	return 0;
}

//����Ҫ�Լ�ʵ��
//������ʼ��Ա�ĵ�ַƫ����Ϊ0
#define OFFSETOF(struct_name,member_name) (int)&(((struct_name*)0)->member_name)

int main()
{
	printf("%d\n", OFFSETOF(struct S, c1));
	printf("%d\n", OFFSETOF(struct S, a));
	printf("%d\n", OFFSETOF(struct S, c2));
	return 0;
}
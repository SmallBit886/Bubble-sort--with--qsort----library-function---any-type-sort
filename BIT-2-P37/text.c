#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

////回顾
//int add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	//指针数组
//	int* arr[10];
//	//数组指针
//	int* (*pa)[10] = &arr;
//	//函数指针
//	int(*padd)(int, int) = add;//&add
//	//函数指针的调用方式
//	printf("%d\n",(*padd)(3, 4));//7
//	printf("%d\n", padd(3, 4));//7
//	//函数指针的数组
//	int* (*parr[5])(int, int);
//	//指向函数指针数组的指针
//	int*(*(*pparr)[5])(int,int) = &parr;
//	return 0;
//}

//回调函数
//冒泡函数排序
#include <stdlib.h>
void bubbil_sort(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		//一趟冒泡排序
		int j = 0;
		for (j = 0; j <sz-1-i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
struct stu
{
	char name[20];
	int age;
};
/******************************************************/
int cmp_int(const void* e1, const void* e2)
{
	//比较两个整型值
	return *(int*)e1 - *(int*)e2;
}
void text1()	//使用qsort排序整形数组
{
	int arr[10] = { 4,6,2,1,3,7,9,8,0 ,5 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);//0 1 2 3 4 5 6 7 8 9
	}
}
/*********************************************************/
/******************************************************/
int cmp_float(const void* e1, const void* e2)
{
	//比较两个浮点型值
	//return ((int)(*(float*)e1 - *(float*)e2));
	if (*(float*)e1 == *(float*)e2)
	{
		return 0;
	}
	else if (*(float*)e1 > *(float*)e2)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
void text2()	//使用qsort排序浮点型数组
{
	float f[] = { 1.3,1.3,4.7,7.8,10.0 };
	int sz = sizeof(f) / sizeof(f[0]);
	qsort(f, sz, sizeof(f[0]), cmp_float);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%f ", f[i]);//1.300000 1.300000 4.700000 7.800000 10.000000
	}
}
/*********************************************************/
/*********************************************************/
int cmp_stu_age(const void* e1, const void* e2)
{
	//比较结构体的两个age
	return ((struct stu*)e1)->age - ((struct stu*)e2)->age;
}
#include <string.h>
int cmp_stu_name(const void* e1, const void* e2)
{
	//比较结构体的两个age
	return strcmp(((struct stu*)e1)->name,((struct stu*)e2)->name);
}
void text3()	//使用qsort排序结构体数组
{
	struct stu s[3] = { {"zhangsan",70},{"lisi",30},{"w",10} };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_stu_age);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%s ", s[i]);//name:lisi w zhangsan   //age:w lisi zhangsan
	}
}
int main()
{
	struct stu s[3] = { {"zhangsan",10},{"lisi",20},{"mawu",30} };
	//float f[] = { 1.3,1.3,4.7,7.8,10.0 };
	//bubbil_sort(f, sz);  //只能排序整型
	/*****************************************/
	//int arr[10] = { 4,6,2,1,3,7,9,8,0 ,5 };
	//int sz = sizeof(arr) / sizeof(arr[0]);
	//bubbil_sort(arr, sz);
	
	//int i = 0;
	//for (i = 0; i < 10; i++)
	//{
	//	printf("%d ", arr[i]);//0 1 2 3 4 5 6 7 8 9
	//}

	//text1();
	//text2();
	text3();
	return 0;
}

//【qsort】-- 库函数 -- 排序 --quick sort【快速排序】



////void* --- 可以接收任意类型的地址
//int main()
//{
//	int a = 10;
//	int* p = &a;
//	//char* ch = &a;	//警告
//	void* pa = &a;//不能进行解引用操作
//	//*pa = 0; //不确定访问几个字节  	//非法的间接寻址
//	//pa++;   //不能进行加减整数的操作
//	return 0;
//}


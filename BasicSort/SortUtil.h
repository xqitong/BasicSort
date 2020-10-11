#pragma once
//template<typename T>
//void insertionSort(T arr[], int n)
//{
//    for (size_t i = 1; i < n; i ++)
//    {
//        //Ѱ��Ԫ�� arr[i] ���ʵĲ���λ��
//	for (size_t j = i; j > 0 && arr[j] < arr[j - 1]; j --)
//	{
//	    std::swap(arr[j],arr[j-1]);
//	}
//    }
//}
template<typename T>
void insertionSort(T arr[], size_t n)
{
    for (size_t i = 1; i < n; i++)
    {
	//Ѱ��Ԫ�� arr[i] ���ʵĲ���λ��
	T e = arr[i];
	size_t j = i;
	//for ( j = i; j > 0 && arr[j - 1] > e; j--)
	//{
	//    arr[j] = arr[j-1];
	//}
	while (j > 0 && arr[j - 1] > e)
	{
	    arr[j] = arr[j - 1];
	    j--;
	}
	arr[j] = e;
    }
}
template<typename T>
void selectionSort(T arr[], size_t n)
{
    //Ѱ��[i,n) �����ڵ���Сֵ
    for (size_t i = 0; i < n; i++)
    {
	size_t minIndex = i;
	for (size_t j = i + 1; j < n; j++)
	{
	    if (arr[j] < arr[minIndex])
	    {
		minIndex = j;
	    }
	}
	std::swap(arr[i], arr[minIndex]);
    }
}
//merge sort
template<typename T>
void __mergeSort(T arr[], size_t l, size_t r)
{

}

template<typename T>
void mergeSort(T arr[], size_t n)
{
    __mergeSort(arr,0,n-1);
}

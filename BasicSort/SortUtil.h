#pragma once
//template<typename T>
//void insertionSort(T arr[], int n)
//{
//    for (size_t i = 1; i < n; i ++)
//    {
//        //寻找元素 arr[i] 合适的插入位置
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
	//寻找元素 arr[i] 合适的插入位置
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
    //寻找[i,n) 区间内的最小值
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

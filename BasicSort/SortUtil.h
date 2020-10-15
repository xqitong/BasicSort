#pragma once
#include <algorithm>
#include <time.h>
#include <stdlib.h>
//template<typename T>
//void insertionSort(T arr[], int n)
//{
//    for (int i = 1; i < n; i ++)
//    {
//        //Ѱ��Ԫ�� arr[i] ���ʵĲ���λ��
//    for (int j = i; j > 0 && arr[j] < arr[j - 1]; j --)
//    {
//        std::swap(arr[j],arr[j-1]);
//    }
//    }
//}

#pragma region Insertion  Sort
template<typename T>
void insertionSort(T arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        //Ѱ��Ԫ�� arr[i] ���ʵĲ���λ��
        T e = arr[i];
        int j = i;
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
void insertionSort(T arr[], int l, int r)
{
    for (int i = l + 1; i <= r; i++)
    {
        //Ѱ��Ԫ�� arr[i] ���ʵĲ���λ��
        T e = arr[i];
        int j = i;
        //for ( j = i; j > 0 && arr[j - 1] > e; j--)
        //{
        //    arr[j] = arr[j-1];
        //}
        while (j > l && arr[j - 1] > e)
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = e;
    }
}
#pragma endregion

#pragma region Selection Sort
template<typename T>
void selectionSort(T arr[], int n)
{
    //Ѱ��[i,n) �����ڵ���Сֵ
    for (int i = 0; i < n; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}
#pragma endregion

#pragma region merge sort
//merge sort
template<typename T>
void __merge(T arr[], int l, int mid, int r)
{
    //������������
   // const int cnt = r - l + 1;
    T* aux = new T[r - l + 1];
    // T aux[r - l + 1];
    for (int i = l; i <= r; i++)
    {
        aux[i - l] = arr[i];
    }
    int i = l, j = mid + 1;
    for (int k = l; k <= r; k++)
    {
        // ǰ�����ж��±�ĺϷ���
        if (i > mid)
        {
            arr[k] = aux[j - l];
            j++;
        }
        else if (j > r)
        {
            arr[k] = aux[i - l];
            i++;
        }
        else if (aux[i - l] < aux[j - l])
        {
            arr[k] = aux[i - l];
            i++;
        }
        else
        {
            arr[k] = aux[j - l];
            j++;
        }

    }

    delete[] aux;
}


//// ��arr[l...mid]��arr[mid+1...r]�����ֽ��й鲢
//template<typename  T>
//void __merge(T arr[], int l, int mid, int r) {
//
//    //* VS��֧�ֶ�̬��������, ������ʹ�� T aux[r-l+1]�ķ�ʽ����aux�Ŀռ�
//    //* ʹ��VS��ͬѧ, ��ʹ��new�ķ�ʽ����aux�ռ�
//    //* ʹ��new����ռ�, ��Ҫ������__merge���������, delete������Ŀռ�:)
//    //T aux[r - l + 1];
//    T *aux = new T[r-l+1];
//
//    for (int i = l; i <= r; i++)
//        aux[i - l] = arr[i];
//
//    // ��ʼ����iָ����벿�ֵ���ʼ����λ��l��jָ���Ұ벿����ʼ����λ��mid+1
//    int i = l, j = mid + 1;
//    for (int k = l; k <= r; k++) {
//
//        if (i > mid) {  // �����벿��Ԫ���Ѿ�ȫ���������
//            arr[k] = aux[j - l]; j++;
//        }
//        else if (j > r) {  // ����Ұ벿��Ԫ���Ѿ�ȫ���������
//            arr[k] = aux[i - l]; i++;
//        }
//        else if (aux[i - l] < aux[j - l]) {  // ��벿����ָԪ�� < �Ұ벿����ָԪ��
//            arr[k] = aux[i - l]; i++;
//        }
//        else {  // ��벿����ָԪ�� >= �Ұ벿����ָԪ��
//            arr[k] = aux[j - l]; j++;
//        }
//    }
//
//    delete[] aux;
//}


// �ݹ�ʹ�ù鲢���򣬶� arr[l...r] �ķ�Χ��������
template<typename T>
void __mergeSort(T arr[], int l, int r)
{
    //if ( l >= r )
    //{
    //    return;
    //}
    if (r - l <= 15)
    {
        insertionSort(arr, l, r);
        return;
    }
    int mid = (r - l) / 2 + l;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid + 1, r);
    if (arr[mid] > arr[mid + 1]) // ���ڽ���������������Ż�
    {
        __merge(arr, l, mid, r);
    }
}

template<typename T>
void mergeSort(T arr[], int n)
{
    __mergeSort(arr, 0, n - 1);
}
#pragma endregion

#pragma region Quick Sort
//�� arr[l...r]���ֽ���partition����
//����p�� ʹ�� arr[l...p-1] < arr[p], arr[p+1...r] > arr[p]
template<typename T>
int __partition(T arr[], int l, int r)
{
    // �����arr[l...r]�ķ�Χ��, ѡ��һ����ֵ��Ϊ�궨��

    int ret = rand();
    int index = ret % (r - l + 1) + l;
    swap(arr[l], arr[index]);
    T v = arr[l];
    // arr[l+1...j] < v ; arr[j+1...i] > v
    int j = l;
    for (int i = l + 1; i <= r; i++)
    {
        if (arr[i] < v)
        {
            std::swap(arr[j + 1], arr[i]);
            j++;
        }
    }

    std::swap(arr[l], arr[j]);
    return j;
}
//�� arr[l...r]���ֽ��п�������
template<typename T>
void __quickSort(T arr[], int l, int r)
{
    // �ݹ���ֹ
    if (l >= r)
    {
        return;
    }
    //���ò�����������Ż�
    // if ( r - l <= 15)
    // {
    //     insertionSort(arr,l,r);
    //     return;
    // }


    int p = __partition(arr, l, r);
    __quickSort(arr, l, p - 1);
    __quickSort(arr, p + 1, r);

}
template<typename T>
void quickSort(T arr[], int n)
{
    srand(time(NULL));
    __quickSort(arr, 0, n - 1);
}
#pragma endregion

#pragma region Quick Sort2

#pragma endregion
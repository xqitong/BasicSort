#pragma once
//template<typename T>
//void insertionSort(T arr[], int n)
//{
//    for (int i = 1; i < n; i ++)
//    {
//        //寻找元素 arr[i] 合适的插入位置
//    for (int j = i; j > 0 && arr[j] < arr[j - 1]; j --)
//    {
//        std::swap(arr[j],arr[j-1]);
//    }
//    }
//}
template<typename T>
void insertionSort(T arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        //寻找元素 arr[i] 合适的插入位置
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
void insertionSort(T arr[], int l,int r)
{
    for (int i = l+1; i <= r; i++)
    {
        //寻找元素 arr[i] 合适的插入位置
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
template<typename T>
void selectionSort(T arr[], int n)
{
    //寻找[i,n) 区间内的最小值
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
//merge sort
template<typename T>
void __merge(T arr[], int l, int mid, int r)
{
    //复制排序区段
   // const int cnt = r - l + 1;
    T *aux = new T[r - l + 1];
   // T aux[r - l + 1];
    for (int i = l; i <= r; i++)
    {
        aux[i - l] = arr[i];
    }
    int i = l, j = mid + 1;
    for (int k = l; k <= r; k++)
    {
        // 前边先判断下标的合法性
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
        else if ( aux[i-l] < aux[j-l] )
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


//// 将arr[l...mid]和arr[mid+1...r]两部分进行归并
//template<typename  T>
//void __merge(T arr[], int l, int mid, int r) {
//
//    //* VS不支持动态长度数组, 即不能使用 T aux[r-l+1]的方式申请aux的空间
//    //* 使用VS的同学, 请使用new的方式申请aux空间
//    //* 使用new申请空间, 不要忘了在__merge函数的最后, delete掉申请的空间:)
//    //T aux[r - l + 1];
//    T *aux = new T[r-l+1];
//
//    for (int i = l; i <= r; i++)
//        aux[i - l] = arr[i];
//
//    // 初始化，i指向左半部分的起始索引位置l；j指向右半部分起始索引位置mid+1
//    int i = l, j = mid + 1;
//    for (int k = l; k <= r; k++) {
//
//        if (i > mid) {  // 如果左半部分元素已经全部处理完毕
//            arr[k] = aux[j - l]; j++;
//        }
//        else if (j > r) {  // 如果右半部分元素已经全部处理完毕
//            arr[k] = aux[i - l]; i++;
//        }
//        else if (aux[i - l] < aux[j - l]) {  // 左半部分所指元素 < 右半部分所指元素
//            arr[k] = aux[i - l]; i++;
//        }
//        else {  // 左半部分所指元素 >= 右半部分所指元素
//            arr[k] = aux[j - l]; j++;
//        }
//    }
//
//    delete[] aux;
//}


// 递归使用归并排序，对 arr[l...r] 的范围进行排序
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
    if (arr[mid] > arr[mid +1]) // 对于近乎有序的数组有优化
    {
        __merge(arr, l, mid, r);
    }
}

template<typename T>
void mergeSort(T arr[], int n)
{
    __mergeSort(arr,0,n-1);
}



#pragma once
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
void insertionSort(T arr[], int l,int r)
{
    for (int i = l+1; i <= r; i++)
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
//merge sort
template<typename T>
void __merge(T arr[], int l, int mid, int r)
{
    //������������
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
    if (arr[mid] > arr[mid +1]) // ���ڽ���������������Ż�
    {
        __merge(arr, l, mid, r);
    }
}

template<typename T>
void mergeSort(T arr[], int n)
{
    __mergeSort(arr,0,n-1);
}



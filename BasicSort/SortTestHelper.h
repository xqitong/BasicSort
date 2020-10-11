#pragma once
#include<iostream>
#include<ctime>
#include<time.h>
#include<cassert>

using namespace std;

namespace SortTestHelper {

    //生产有n个元素的随机数组，每个元素的随机范围为 [rangeL,rangeR]
    int* generateRandomArray(size_t n, size_t rangeL, size_t rangeR)
    {
        assert(rangeL <= rangeR);
        int * arr = new int[n];
        srand(time(NULL));
        for (size_t i = 0; i < n; i++)
        {
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        }
        return arr;
    }
    int* generateNearlyOrderedArray(size_t n, size_t swapTimes)
    {
        int* arr = new int[n];
        for (size_t i = 0; i < n; i++)
        {
            arr[i] = i;
        }

        srand(time(NULL));
        for (size_t i = 0; i < swapTimes; i++)
        {
            int posx = rand() % n;
            int posy = rand() % n;
            std::swap(arr[posx], arr[posy]);
        }
        return arr;
    }
    template<typename T>
    void printArray(T arr[], size_t n)
    {
        for (size_t i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    template <typename T>
    bool isSorted(T arr[], size_t n)
    {
        for (size_t i = 0; i < n - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                return false;
            }
        }
        return true;
    }
    template<typename T>
    void testSort(string sortName, void(*sort)(T[], size_t), T arr[], size_t n)
    {
        clock_t startTime = clock();
        sort(arr,n);
        clock_t endTime = clock();
        assert(isSorted(arr,n));
        cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
        return;
    }
    int* copyIntArray(int arr[], size_t n)
    {
        int* arrRet = new int[n];
        std::copy(arr,arr+n,arrRet);
        return arrRet;

    }

}
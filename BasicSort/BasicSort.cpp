#include <iostream>

#include "SortTestHelper.h"
#include "SortUtil.h"

using namespace std;

// https://code.visualstudio.com/docs/cpp/config-mingw
int main()
{
    //编译器没有限制，不过会受到栈大小的限制，windows下栈的默认大小是1M，递归次数太多会造成栈溢出
    //
    //在 Visual Studio 开发环境中设置此链接器选项

    //    打开此项目的“属性页”对话框。有关详细信息，请参见设置 Visual C++ 项目属性。
    //    单击“链接器”文件夹。
    //    单击“系统”属性页。
    //    修改下列任一属性：
    //    堆栈提交大小
    //    堆栈保留大小 ?*1024*1024byte = ?mb
    int n = 1000000;
    int intSize = sizeof(int);
    //int* arr = SortTestHelper::generateNearlyOrderedArray(n,0);
    int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);

    int* arr2 = SortTestHelper::copyIntArray(arr1, n);
    cout << "Test for random array: n = " << n << endl;
    SortTestHelper::testSort("MergeSort", mergeSort, arr1, n);
    SortTestHelper::testSort("QuickSort", quickSort, arr2, n);

    delete[] arr1;
    delete[] arr2;

    int swaptimes = 100;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n, swaptimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    cout << "Test for nearly ordered array: n = " << n << " swaptimes = " << swaptimes << endl;
    SortTestHelper::testSort("MergeSort", mergeSort, arr1, n);
    SortTestHelper::testSort("QuickSort", quickSort, arr2, n);

    delete[] arr1;
    delete[] arr2;
    //
        // 测试3 测试存在包含大量相同元素的数组
    // 但此时, 对于含有大量相同元素的数组, 我们的快速排序算法再次退化成了O(n^2)级别的算法
    // 思考一下为什么在这种情况下, 快排退化成了O(n^2)的算法? :)
    cout << "Test for random array, size = " << n << ", random range [0,10]" << endl;
    arr1 = SortTestHelper::generateRandomArray(n, 0, 10);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);

    delete[] arr1;
    delete[] arr2;

    return 0;
}

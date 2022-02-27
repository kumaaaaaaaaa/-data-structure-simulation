#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <time.h>
#include "UsefulHeap.h"
#include "ListBaseQueue.h"
#define BUCKET_NUM		10001

int DataPriorityComp(char ch1, char ch2)
{
	return ch2-ch1;
//	return ch1-ch2;
}
void RadixSort(int arr[], int num, int maxLen)   // maxLen�� ���� �� �������� ����
{
	Queue buckets[BUCKET_NUM];
	int bi;
	int pos;
	int di;
	int divfac = 1;
	int radix;

	// �� 10���� ��Ŷ �ʱ�ȭ
	for(bi=0; bi<BUCKET_NUM; bi++)
		QueueInit(&buckets[bi]);

	// ���� �� �������� ���̸�ŭ �ݺ�
	for(pos=0; pos<maxLen; pos++)
	{ 
		// ���� ����� ����ŭ �ݺ�
		for(di=0; di<num; di++)
		{
			// N��° �ڸ��� ���� ����
			radix = (arr[di] / divfac) % 10;

			// ������ ���ڸ� �ٰŷ� ������ ��Ŷ�� ����
			Enqueue(&buckets[radix], arr[di]);
		}

		// ��Ŷ ����ŭ �ݺ�
		for(bi=0, di=0; bi<BUCKET_NUM; bi++)
		{
			// ��Ŷ�� ����� �� ������� �� ������ �ٽ� arr�� ����
			while(!QIsEmpty(&buckets[bi]))
				arr[di++] = Dequeue(&buckets[bi]);
		}

		// N��° �ڸ��� ���� ������ ���� �������� ����
		divfac *= 10;
	}	
}
void BubbleSort(int arr[], int n)
{
	int i, j;
	int temp;

	for(i=0; i<n-1; i++) // �������� ���� �ڵ�
	{
		for(j=0; j<(n-i)-1; j++)
		{
			if(arr[j] > arr[j+1])
			{ // �������� ��ȯ
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

void SelSort(int arr[], int n)
{
	int i, j;
	int maxIdx;
	int temp;

	for(i=0; i<n-1; i++)
	{
		maxIdx = i;    // ���� ������ ���� �ռ��� �������� index

		for(j=i+1; j<n; j++)   // �ּҰ� Ž��
		{
			if(arr[j] < arr[maxIdx])
				maxIdx = j;
		}

		/* ��ȯ */
		temp = arr[i];
		arr[i] = arr[maxIdx];
		arr[maxIdx] = temp;
	}
}

void MergeTwoArea(int arr[], int left, int mid, int right)
{
	int fIdx = left;
	int rIdx = mid+1;
	int i;

// ���� �� ����� ���� �迭 sortArr�� �����Ҵ�!
	int * sortArr = (int*)malloc(sizeof(int)*(right+1));
	int sIdx = left;

	while(fIdx<=mid && rIdx<=right) // ���� �� �� ������ ������ �����͵��� ���Ͽ�
	{ // ���� ������� �ϳ��� �Ű� ��´�.
		if(arr[fIdx] <= arr[rIdx])
			sortArr[sIdx] = arr[fIdx++];
		else
			sortArr[sIdx] = arr[rIdx++];

		sIdx++;
	}

	if(fIdx > mid) // �迭�� �պκ��� ��� �Ű����ٸ�
	{
		for(i=rIdx; i<=right; i++, sIdx++) // �迭�� �޺κп� ���� �����͵��� �״�� �ű�.
			sortArr[sIdx] = arr[i];
	}
	else // �迭�� �޺κ��� ��� �Ű����ٸ�
	{
		for(i=fIdx; i<=mid; i++, sIdx++) // �迭�� �պκп� ���� �����͵��� �״�� �ű�
			sortArr[sIdx] = arr[i];
	}

	for(i=left; i<=right; i++)
		arr[i] = sortArr[i];
	
	free(sortArr);
}

void MergeSort(int arr[], int left, int right)
{
	int mid;

	if(left < right) // left�� �۴ٴ� ���� �� ���� �� �ִٴ� ��!
	{
		// �߰� ������ ����Ѵ�.
		mid = (left+right) / 2;

		// �ѷ� ������ ������ �����Ѵ�.
		MergeSort(arr, left, mid);
		MergeSort(arr, mid+1, right);

		// ���ĵ� �� �迭�� �����Ѵ�.
		MergeTwoArea(arr, left, mid, right);
	}
}

void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}	

int PriComp(int n1, int n2)
{
	return n2-n1;
//	return n1-n2;
}

void HeapSort(int arr[], int n, PriorityComp pc)
{
	Heap heap;
	int i;

	HeapInit(&heap, pc);

	// ���� ����� ������ ���� �����Ѵ�.
	for(i=0; i<n; i++)
		HInsert(&heap, arr[i]);

	// ������� �ϳ��� ������ ������ �ϼ��Ѵ�.
	for(i=0; i<n; i++)
		arr[i] = HDelete(&heap);
}
int Partition(int arr[], int left, int right) // �ǹ��� �ε��� �� ��ȯ
{
	int pivot = arr[left];    // �ǹ��� ��ġ�� ���� ����! 
	int low = left+1;
	int high = right;

	while(low <= high)    // �������� ���� ������ �ݺ�
	{	
		// �ǹ����� ū ���� ã�� ����
		while(pivot >= arr[low] && low <= right) // ������ ���� �������� ���� ���� �ڵ�
			low++;

		while(pivot <= arr[high] && high >= (left+1))
			high--;

		if(low <= high)    // �������� ���� ���¶�� Swap ����
			Swap(arr, low, high);    // low�� high�� ����Ű�� ��� ��ȯ
	}

	Swap(arr, left, high);    // �ǹ��� high�� ����Ű�� ��� ��ȯ
	return high;    // �Ű��� �ǹ��� ��ġ ���� ��ȯ
}

void QuickSort(int arr[], int left, int right)
{
	if(left <= right)
	{
		int pivot = Partition(arr, left, right);    // �ѷ� ������ 
		QuickSort(arr, left, pivot-1);    // ���� ������ ����
		QuickSort(arr, pivot+1, right);    // ������ ������ ����
	}
}

int main(){
    int menu, n;
    int arr[10000] = {0,};
    double start, finish;

    printf("num for num plz\n");
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("menu \n1. Bubblesort\n2. Selection Sort\n3. Heap Sort\n4. Merge Sort\n5. Quick Sort\n6. Radix Sort \n7. return\ninput number : ");

    scanf("%d", &menu);

    if(menu == 1)
    {
        start = clock(); 
        BubbleSort(arr, n);
        finish =clock();
    }
    
    else if(menu == 2)
    {
        start = clock(); 
        SelSort(arr, n);
        finish =clock();
    }
    
    else if(menu == 3)
    {
        start = clock(); 
        HeapSort(arr, n, PriComp);
        finish =clock();
    }

    else if(menu == 4)
    {
        start = clock(); 
        MergeSort(arr, 0, n-1);
        finish =clock();
    }

    else if(menu == 5)
    {
        start = clock(); 
        QuickSort(arr, 0, n-1);
        finish =clock();
    }

    else if(menu == 6)
    {
        start = clock(); 
        RadixSort(arr, n, n-1);
        finish =clock();
    }
    else if(menu == 7)
	{
		system("cls");
		system(".\\sim.exe");
		return 0;
	}
	
	for(int i=0; i<n; i++)
	{
		printf("%d ", arr[i]);
	}
    printf("\n%lf sec", (double)(finish-start)/ CLOCKS_PER_SEC);

    return 0;
}
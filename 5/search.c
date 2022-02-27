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
void RadixSort(int arr[], int num, int maxLen)   // maxLen은 가장 긴 데이터의 길이
{
	Queue buckets[BUCKET_NUM];
	int bi;
	int pos;
	int di;
	int divfac = 1;
	int radix;

	// 총 10개의 버킷 초기화
	for(bi=0; bi<BUCKET_NUM; bi++)
		QueueInit(&buckets[bi]);

	// 가장 긴 데이터의 길이만큼 반복
	for(pos=0; pos<maxLen; pos++)
	{ 
		// 정렬 대상의 수만큼 반복
		for(di=0; di<num; di++)
		{
			// N번째 자리의 숫자 추출
			radix = (arr[di] / divfac) % 10;

			// 추출한 숫자를 근거로 데이터 버킷에 저장
			Enqueue(&buckets[radix], arr[di]);
		}

		// 버킷 수만큼 반복
		for(bi=0, di=0; bi<BUCKET_NUM; bi++)
		{
			// 버킷에 저장된 것 순서대로 다 꺼내서 다시 arr에 저장
			while(!QIsEmpty(&buckets[bi]))
				arr[di++] = Dequeue(&buckets[bi]);
		}

		// N번째 자리의 숫자 추출을 위한 피제수의 증가
		divfac *= 10;
	}	
}
void BubbleSort(int arr[], int n)
{
	int i, j;
	int temp;

	for(i=0; i<n-1; i++) // 실질적인 구현 코드
	{
		for(j=0; j<(n-i)-1; j++)
		{
			if(arr[j] > arr[j+1])
			{ // 데이터의 교환
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
		maxIdx = i;    // 정렬 순서상 가장 앞서는 데이터의 index

		for(j=i+1; j<n; j++)   // 최소값 탐색
		{
			if(arr[j] < arr[maxIdx])
				maxIdx = j;
		}

		/* 교환 */
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

// 병합 한 결과를 담을 배열 sortArr의 동적할당!
	int * sortArr = (int*)malloc(sizeof(int)*(right+1));
	int sIdx = left;

	while(fIdx<=mid && rIdx<=right) // 병합 할 두 데이터 영역의 데이터들을 비교하여
	{ // 정렬 순서대로 하나씩 옮겨 담는다.
		if(arr[fIdx] <= arr[rIdx])
			sortArr[sIdx] = arr[fIdx++];
		else
			sortArr[sIdx] = arr[rIdx++];

		sIdx++;
	}

	if(fIdx > mid) // 배열의 앞부분이 모두 옮겨졌다면
	{
		for(i=rIdx; i<=right; i++, sIdx++) // 배열의 뒷부분에 남은 데이터들을 그대로 옮김.
			sortArr[sIdx] = arr[i];
	}
	else // 배열의 뒷부분이 모두 옮겨졌다면
	{
		for(i=fIdx; i<=mid; i++, sIdx++) // 배열의 앞부분에 남은 데이터들을 그대로 옮김
			sortArr[sIdx] = arr[i];
	}

	for(i=left; i<=right; i++)
		arr[i] = sortArr[i];
	
	free(sortArr);
}

void MergeSort(int arr[], int left, int right)
{
	int mid;

	if(left < right) // left가 작다는 것은 더 나눌 수 있다는 뜻!
	{
		// 중간 지점을 계산한다.
		mid = (left+right) / 2;

		// 둘로 나눠서 각각을 정렬한다.
		MergeSort(arr, left, mid);
		MergeSort(arr, mid+1, right);

		// 정렬된 두 배열을 병합한다.
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

	// 정렬 대상을 가지고 힙을 구성한다.
	for(i=0; i<n; i++)
		HInsert(&heap, arr[i]);

	// 순서대로 하나씩 꺼내서 정렬을 완성한다.
	for(i=0; i<n; i++)
		arr[i] = HDelete(&heap);
}
int Partition(int arr[], int left, int right) // 피벗의 인덱스 값 반환
{
	int pivot = arr[left];    // 피벗의 위치는 가장 왼쪽! 
	int low = left+1;
	int high = right;

	while(low <= high)    // 교차되지 않을 때까지 반복
	{	
		// 피벗보다 큰 값을 찾는 과정
		while(pivot >= arr[low] && low <= right) // 동일한 값이 등장했을 때를 위한 코드
			low++;

		while(pivot <= arr[high] && high >= (left+1))
			high--;

		if(low <= high)    // 교차되지 않은 상태라면 Swap 실행
			Swap(arr, low, high);    // low와 high가 가리키는 대상 교환
	}

	Swap(arr, left, high);    // 피벗과 high가 가리키는 대상 교환
	return high;    // 옮겨진 피벗의 위치 정보 반환
}

void QuickSort(int arr[], int left, int right)
{
	if(left <= right)
	{
		int pivot = Partition(arr, left, right);    // 둘로 나눠서 
		QuickSort(arr, left, pivot-1);    // 왼쪽 영역을 정렬
		QuickSort(arr, pivot+1, right);    // 오른쪽 영역을 정렬
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
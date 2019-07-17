#include<stdio.h>
//数组常用算法
//逆序数组
int * Reverse(int arr[], int from, int to) {
	int mid = (to - from) / 2;
	for (int i = 0; i <= mid; i++) {
		//交换元素
		int temp = arr[from + i];
		arr[from + i] = arr[to - i];
		arr[to - i] = temp;
	}
	return arr;
}
void Print(int arr[], int length){
	for (int i = 0; i < length; i++) {
		printf("%d\t",arr[i]);
	}

}
int main() {
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
	Print(arr , 8);
	printf("\n");
	int *array = Reverse(arr, 0 , 7);
	Print(array, 8);
	while (1);
	return 0;
}
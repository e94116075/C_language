#include <stdio.h>
void insertionSortOptimized(int arr[], int n) {
	for(int i=1;i<n;i++){
		int  no;
		int tmp;
		for(i=1;i<n;i++){
			tmp=arr[i];//TMP為要插入的資料
			no=i-1;
			while(no>=0&&tmp>arr[no]){
				arr[no+1]=arr[no];//若新插入的資料比較小，就把已經排序好的原資料向後移
				no--;//繼續向前檢查，直到新插入資料比較大為止
			}
			arr[no+1]=tmp;//最後將空下來的位置讓給新插入的資料
			
			for(int j=0;j<n;j++){
			printf("%d ",arr[j]);
			} 
			printf("\n");
		}
			
	}
}
// 測試程式碼 助教會修改arr[]的內容做測試
int main() {
int arr[] = {16, 25, 39, 27, 12, 8, 45, 63}; // 待排序數列
int n = sizeof(arr) / sizeof(arr[0]);
insertionSortOptimized(arr, n);
return 0;
}

#include <stdio.h>
void insertionSortOptimized(int arr[], int n) {
	for(int i=1;i<n;i++){
		int  no;
		int tmp;
		for(i=1;i<n;i++){
			tmp=arr[i];//TMP���n���J�����
			no=i-1;
			while(no>=0&&tmp>arr[no]){
				arr[no+1]=arr[no];//�Y�s���J����Ƥ���p�A�N��w�g�ƧǦn�����ƦV�Ჾ
				no--;//�~��V�e�ˬd�A����s���J��Ƥ���j����
			}
			arr[no+1]=tmp;//�̫�N�ŤU�Ӫ���m�����s���J�����
			
			for(int j=0;j<n;j++){
			printf("%d ",arr[j]);
			} 
			printf("\n");
		}
			
	}
}
// ���յ{���X �U�з|�ק�arr[]�����e������
int main() {
int arr[] = {16, 25, 39, 27, 12, 8, 45, 63}; // �ݱƧǼƦC
int n = sizeof(arr) / sizeof(arr[0]);
insertionSortOptimized(arr, n);
return 0;
}

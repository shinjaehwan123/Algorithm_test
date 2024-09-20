#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//9장.정렬 sorting
// time complexity는 최악의 경우를 고려하는 것이다
//selection sort - 선택정렬==> n+n-1+n-2+.... 따라서 time complexity는 O(n^2)다
//insertion sort - 삽입정렬===>1+2+3+..+n-1 따라서 time complexity는 O(n^2)다
//bubble sort - 거품정렬===>n+n-1+n-2+...+1 time complexity는 O(n^2)다
//shell sort - 셸정렬
// ==========================================
// 정렬계의 샤넬=====>O(nlogn)
//merge sort - 합병정렬
//quick sort - 퀵 정렬

// ==========================================
//radix sort - 기수정렬
//heap sort - 합정렬


////////////////////////////////////////////////////////////selection sort
int do_selection_sort(int _data[], int _sz) {
	int k=0; //가장 작은 애를 찾으면 데려올 위치
	int temp;
	int i;
	int least = 0; // 가장 작은 값을 갖는 index
	int cnt = 0;

	for (k = 0; k < _sz - 1; k++) {//맨 끝에꺼는 비교해줄 필요가 없음 그래서 _sz-1한거

		least = k;

		for (i = k+1; i < _sz; i++) {
			//현재 알려진 가장 작은 애 //(least)보다 더 작은 애가 나오면//그 위치를 기억
			if (_data[least] > _data[i]) {
				least = i; //새로운 작은 애!!!
				
			}
		}
		//least에는 가장 작은 애의 index가 담겨
		//있으니, 위치를 바꿔준다.
		if (_data[least] != _data[k]) {
			if (_data[least] == 7 | _data[k] == 7) {
				cnt++;
			}
		}
		
		temp = _data[least];
		_data[least] = _data[k];
		_data[k] = temp;
	}
	return cnt;
}

void show_data(int _data[], int _sz) {
	for (int i = 0; i < _sz; i++) {
		printf("%d-> ", _data[i]);
	}
	printf("\n");
}

//////////////////////////////////////////////insertion sort
void do_insertion_sort(int _data[], int _sz) {
	int i, j, temp;

	for (i = 1; i < _sz; i++) {//반복....
		int me = _data[i]; // 일단 자리를 비켜준다 나보다 큰 애가 올 수 있도록
		for (j = i - 1; j >= 0; j--) {
			if (_data[j] > me) {
				_data[j + 1] = _data[j];
			}
			if (_data[j] < me) { //더이상 갈 수 없는 조건
				break;
			}
		}
		//여기까지 오면 .....
		_data[j + 1] = me;
	}
}

/////////////////////////////////////////////////////////////// bubble sort
///한번 돌고나면 자기 자리 찾는 애가 나온다 selection sort도 마찬가지
int do_bubble_sort(int _data[], int _sz) {
	int i, j, temp;
	int cnt = 0;
	for (i = 0; i < _sz - 1; i++) {
		for (j = 0; j < _sz - 1 - i; j++) { // 맨끝가면 초과해서 //한번돌리면 제일 큰것이 맨위에 가있어서 -1씩 계속 해준다 따라서 i 씀
			if (_data[j] > _data[j + 1]) { //앞방울이 뒷방울보다 크다 !! 띄워라!!
				
				temp = _data[j];
				_data[j] = _data[j + 1];
				_data[j + 1] = temp;
				if (_data[j+1] == 87) {
					cnt++;
				}
				if (_data[j] ==87) {
					cnt++;
				}
			
			}
		}

	}
	return cnt;

}


//배열을 버블 sort로 구현하고자한다 10이 움직인 횟수를 구하시오. 다음 퀴즈. 특정 숫자가 움직이는 count횟수를 구하시오
int main(void) {
	int data[] = { 5,7,4,2,10};
	int sz = sizeof(data) / sizeof(data[0]);
	int k = 0;
	//k=do_bubble_sort(data, sz);
	//show_data(data, sz);
	//printf("\n\n%d", k);
	//do_insertion_sort(data, sz);
	//show_data(data, sz);
	k=do_selection_sort(data, sz);
	show_data(data, sz);
	printf("\n\n%d", k);


	return 0;
}

//////////정렬 3문제 BST DEL 나온다
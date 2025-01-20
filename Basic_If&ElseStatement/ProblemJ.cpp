#include <stdio.h>
int main(){
	int x, y, k;
	scanf("%d %d %d", &x, &y, &k);
	
	if(k >= x && y >= k){
		int meetingup = k - x;
		int meetingdown = y - k;
		if (meetingup == meetingdown){
			printf("%d\n", meetingup);
		}
		else{
			printf("-1\n");
		}
	}
	else {
		printf("-1\n");
	}
	return 0;
}

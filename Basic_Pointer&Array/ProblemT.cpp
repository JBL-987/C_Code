#include <stdio.h>

int main()
{
	int T = 0;
	int it = 0; // iterator utk setiap karakter
	int gap = 1;
	int dist_coll[1001]={0};
	char ms[1001];
	char temp;
	scanf("%d", &T);
	getchar();
	for(int t=0; t<T; t++)
	{
		scanf("%[^\n]", ms);
		getchar();
		printf("Case #%d:\n", t+1);
		it = 0;
		while(ms[it] != '\0')
		{
			if(ms[it] == 'A' ||
				ms[it] == 'E' ||
				ms[it] == 'I' ||
				ms[it] == 'O' ||
				ms[it] == 'U')
			{
				// jika huruf yg dicek adalah VOKAL
				printf("%c", ms[it]);	
				dist_coll[it] = 0;
			}
			else
			{
				// jika huruf yg dicek adalah KONSONAN
				//printf(" ");
				
				gap = 1;
				temp = ms[it]-gap;
				while(temp >= 'A')
				{
					temp = ms[it]-gap; // temp = 'L' - 1 = 'K'
					if(temp == 'A'
					|| temp == 'E'
					|| temp == 'I'
					|| temp == 'O'
					|| temp == 'U')
					{
						printf("%c", temp);
						dist_coll[it] = gap;
						temp = 'A'-1;
					}
					gap++;
				}
				
			}
			it++;
		}
		
		// print distance collection nya
		printf("\n");
		for(int i=0; i<it; i++) 
			printf("%d", dist_coll[i]);
		
		printf("\n"); // newline setiap selesai case
	}
	
	
	
	return 0;
}

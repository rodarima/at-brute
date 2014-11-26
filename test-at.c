#include <stdio.h>
#include <unistd.h>

#define MAX	256

void brute(int n)
{
	char buf[MAX];
	char c;
	int i, j, k;

	for(i = 0; i < n; i++)
	{
		for(k = 0; k <= i; k++)
		{
			buf[k] = 'A';
		}

		buf[i+1] = '\0';
		j = i;

		while(1)
		{
			printf("AT+%s=?\n", buf);
			usleep(50000);
			if(buf[j] != 'Z')
			{
				buf[j]++;
				continue;
			}

			if(j == 0)
			{
				break;
			}

			buf[j] = 'A';
			k = j-1;
			while(k >= 0)
			{
				if(buf[k]=='Z') buf[k] = 'A';
				else
				{
					buf[k]++;
					break;
				}
				k--;
			}
			if(k < 0) break;
		}
	}
}

int main(int argc, char *argv[])
{
	brute(4);
	return 0;
}

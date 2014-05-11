#include<cstdio>
#include<cstdlib>
#include<cstring>
int x;
char cmd[1005];
int main(void)
{
	char username[105];
	char passwd[105];
	printf("Username:");
	scanf("%s",username);
	printf("Password:");
	scanf("%s",passwd);
	sprintf(cmd,"node uva-node add uva %s %s",username,passwd);
	system(cmd);
	sprintf(cmd,"node uva-node use uva %s",username);
	system(cmd);

	FILE *fp = fopen("problem.txt","r");
	while(~fscanf(fp,"%d",&x))
	{
		sprintf(cmd,"node uva-node send %d",x);
		system(cmd);
	}



}

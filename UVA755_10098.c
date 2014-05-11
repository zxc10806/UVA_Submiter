#include <stdio.h>
#include <string.h>

int compare(const void *a,const void *b){
    return strcmp((char *)a,(char *)b);
}

char find(char c)
{
    if(c>'Q' && c<'Z'){
        c = 55+(c-81)/3;
    }
    else if(c<'Q'&&c>='A'){
        c = 50+(c-65)/3;
    }  
    else c=0;
    return c;
}

int main()
{
    char c[10000],ans[100100][31];
    int n,N,i,j,l,k=0,count=0,num=0;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&n);
        for(j=0;j<n;j++){
            scanf("%s",c);
            for(l=0;l<strlen(c);l++){
                if(c[l]>='0' && c[l]<='9'){
                    ans[j][k]=c[l];
                    k++;
                }
                else if(c[l]>='A' && c[l]<='Z'){
                    c[l]=find(c[l]);
                    if(c[l]!=0){
                        ans[j][k]=c[l];
                        k++;
                    }
                }
                if(k==3){
                    ans[j][k]='-';
                    k++;
                }
            }
            k=0;
        }
        qsort(ans,n,sizeof(char[31]),compare);
        for(j=1;j<n;j++){
            if(strcmp(ans[j-1],ans[j])==0){
                 count++;
            }
            else if(count!=0){
                printf("%s %d\n",ans[j-1],count+1);
                count=0;
                num++;
            }
            if(j==n-1 && count!=0){
                printf("%s %d\n",ans[j-1],count+1);
                count=0;
                num++;
            }
        }
        if(num==0)printf("No duplicates.\n");
        if(i!=N-1)printf("\n");
        num=0;
    }
    return 0;
}

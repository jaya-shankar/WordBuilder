#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

typedef struct coans
{
    char nex;
    int l;
}coans;



coans against(char ans,ret *tmp,node *tmpc,int level)
{
    srand(time(0));
    int k;
    bool response;
    char nex;
    coans coscore;
    time_t start,stop;
    start=time(NULL);
    element answer;
    repeat:
    do
    {
        k=rand()%level;
        answer=tmp->buckets[(int)ans-97][k];
        stop=time(NULL);
        if(stop-start>2)
            break;
    } while (tmp->buckets[(int)ans-97][k].use!=0 && !strcmp(".",answer.data));
    if(stop-start>2)
    {
        coscore.l=0;
        coscore.nex='?';
        return coscore;
    }

    tmp->buckets[(int)ans-97][k].use=1;
    response=check(answer.data,tmpc);
    if(response==false)
        goto repeat;
    
    printf("\nMy answer is %s\n",answer.data);
    coscore.l=strlen(answer.data);
    coscore.nex=answer.data[coscore.l-1];
    return coscore;
}






#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>



char help(char ans,ret *tmp,node *tmpc)
{
    srand(time(0));
    int k;
    bool response;
    char nex;
    time_t start,stop;
    start=time(NULL);
    element answer;
    repeat:
    do
    {
        k=rand()%50;
        answer=tmp->buckets[(int)ans-97][k];
        stop=time(NULL);
        if(stop-start>2)
            break;
    } while (tmp->buckets[(int)ans-97][k].use!=0 && !strcmp(".",answer.data));
    if(stop-start>2)
    {
        printf("Sorry no word starting with %c exists in our data\n",ans);
        do
        {
            nex=(char)(rand()%26)+97;
        } while (nex==ans);
        printf("Player can start with the following word\n");
        return '|';
    }

    tmp->buckets[(int)ans-97][k].use=1;
    response=check(answer.data,tmpc);
    if(response==false)
        goto repeat;
    
    printf("The answer is %s\n",answer.data);
    int l=strlen(answer.data);
    return answer.data[l-1];
}






#include<stdio.h>
#include<stdbool.h>


bool check(char *s,node *tmp)
{
    convert(s);
    int x;
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]=='_')
            x=26;
        else if(s[i]==',')
            x=27;
        else if(s[i]=='-')
            x=28;
        else
            x=(int)s[i]-97;
        tmp=tmp->memb[x];
        if(tmp==NULL)
            return false;
    }
    if(tmp->use==0)
        tmp->use=1;
    else
    {
        return false;
    }
    int k=strcmp(tmp->data,s);
    if(k==0)
        return true;
    else
        return false;
}


 
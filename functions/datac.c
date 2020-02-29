#include<stdio.h>
#include<stdlib.h>
#include<string.h>



ret datac(char * word,int ch,int level)
{


    char phrase[32];
    int l,k;
    ret root;
    int i[26];
     for(int j =0;j<26;j++)
        i[j]=0;
    FILE *file=fopen(word,"r");
    while (fscanf(file,"%s",phrase)!=EOF)
    {
        convert(phrase);
        l=strlen(phrase);
        if(l==5 || l==6|| l==7|| ch==2)
        {
            k=(int)phrase[0]-97;
            if(i[k]<level)
            {
                printf("%s\n",phrase);
                strcpy(root.buckets[k][i[k]].data,phrase);
                root.buckets[k][i[k]].use=0;
                i[k]++;
            }
        }
    }
    for(int j=0;j<26;j++)
    {
        for(int m=i[j];m<50;m++)
            strcpy(root.buckets[j][m].data,".");
    }
    return root;
}



#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>



typedef struct node
{
    char data[32];
    struct node *memb[29];
    int use;

}node;

void convert(char *);


node* load(char * word)
{
    int x,y=0,z,len;
    node *tmp;
    node *root=(node*)malloc(sizeof(node)*1);
    for(int i=0;i<29;i++)
        root->memb[i]=NULL;
    root->use=0;
    char phrase[32];
    FILE *file=fopen(word,"r");
    while (fscanf(file,"%s",phrase)!=EOF)
    {
        tmp=root;
        convert(phrase);
        for(int i=0;phrase[i]!='\0';i++)
        {
            if(phrase[i]=='_')
                x=26;
            else if(phrase[i]==',')
                x=27;
            else if(phrase[i]=='-')
                x=28;
            else
                x=(int)phrase[i]-97;
            if(tmp->memb[x]==NULL)
            {
                tmp->memb[x]=(node*)(malloc(sizeof(node)*1));
                tmp=tmp->memb[x];
                for(int j=0;j<29;j++)
                    tmp->memb[j]=NULL; 
                root->use=0;
            }
            else
               tmp=tmp->memb[x];

        }
        strcpy(tmp->data,phrase);
    }
    return root;

}

void free_all(node* curs)
{
    int i;

    // recursive case (go to end of trie)
    for (i = 0; i < 29; i++)
    {
        if (curs->memb[i] != NULL)
        {
            free_all(curs->memb[i]);
        }
    }

    // base case
    free(curs);
}

void convert(char * s)
 {
     for(int i=0;s[i]!='\0';i++)
         if(isalpha(s[i]))
             if(isupper(s[i]))
                 s[i]=(int)s[i]-65+97;
 }
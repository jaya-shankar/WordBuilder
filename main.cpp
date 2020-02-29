
#include "functions/playerClass.cpp"
#include "functions/load.c"
#include "functions/loadh.c"
#include "functions/datac.c"
#include "functions/check.c"
#include "functions/help.c"
#include "functions/against.c"
#include "functions/design.cpp"




#include <iostream>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>


#define wordn "words/words_alpha.txt"
#define wordc "words/india.txt"

using namespace std;


int main()
{
     int number,count,len,de,mode,limit,ch,men,level,tp=1;
     char next='a',he;
     bool response;
     coans coscore;
     char hel[]="..";
     player* arr;
     player AI('x');
     ret rooth,comp;
     node *root;
     start:
     title();
     again:
     menu();
     cin>>men;
     if(men==2 || men==1)
     {
         cout<<"1.Classic\t\t\t\t2.Survival"<<endl;
         cout<<"\nEnter Game mode : ";
         cin>>mode;
         cout<<"1.Normal WordBuilder \t\t\t\t\t\t 2.Cities"<<endl;
         cout<<"Select the theme of the game: ";
         cin>>ch;
         while(ch<1 || ch>2)
         {
            cout<<"Please enter correct number: ";
            cin>>ch;
         }

         if(ch==1)
         {
            rooth=loadh(wordn,ch);
            root=load(wordn);
         }
         else if(ch==2)
         {
            root=load(wordc);
            rooth=loadh(wordc,ch);
         }
     }
     if(men==3)
     {
         about();
         goto again;
     }

     if(mode==1)
     {
        cout<<"Enter score limit: ";
        cin>>limit;
     }

      if(men==2)
      {
         cout<<"Enter number of players: ";
         cin>>number;
      }
      if(men==1)
      {
         level=difficulty();
         if(ch==1)
            comp=datac(wordn,ch,level);
         else if(ch==2)
            comp=datac(wordc,ch,level);
         number=1;
      }
     count=number;
     arr=new player[number];
     while(count>1||(men==1 && count>0))
     {
        for(int i=0;i<number;i++)
        {
            char answer[50];
           if(arr[i].errors>=0)
           {
               do
               {
                  repeat:
                  de=0;
                  cout<<"The starting letter is : "<<next<<endl;
                  cout<<"it's "<<arr[i].dispname()<<" turn : ";
                  cin>>answer;

                  if(answer[0]=='.' && answer[1]=='.')
                  {
                     int k=arr[i].dechelp();
                     if(k<=-1)
                        cout<<"Sorry We cannot help you ,You are out of lives"<<endl;
                     else
                     {
                        he=help(next,&rooth,root);
                        if(he=='|')
                        {
                           do
                           {
                              he=(char)(rand()%26)+97;
                           } while (he==next);
                           cout<<"Player can start with the following letter:\n";
                           goto repeat;
                        }
                        else
                           cout<<"You still have "<<k<<" hints left.."<<endl;
                        break;
                     }
                  }
                  else if(answer[0]=='~')
                  {
                     arr[i].errors=-1;
                     cout<<"\n"<<arr[i].dispname()<<" has quit the game"<<endl;
                     count--;
                     break;

                  }
                  else if(!check(answer,root)|| answer[0]!=next)
                  {
                     if( answer[0]!=next )
                        cout<<"You violated the rules of the game"<<endl;
                     
                     else
                     {
                        de=1;
                        if(answer[0]!=next)
                           cout<<"The word doesnot exist!!"<<endl;
                        else
                        {
                           cout<<"The word already used!!"<<endl;
                           cout<<"You violated the rules of the game."<<endl;
                        }
                        
                     }
                     int k=arr[i].decerror();
                     if(k>0)
                        cout<<"You have only "<<k<<" chances left"<<endl;
                     else
                     {
                        cout<<arr[i].dispname()<<" has been elminated"<<endl;
                        arr[i].errors=-1;
                        count--;
                        break;

                     }
                  }
               }while(strlen(answer)<3 || answer[0]!=next ||de==1);
               if(count==1 && men!=1)
                break;

               if(answer[0]=='.' && answer[1]=='.')
                  next=he;
               else if(de==0 && answer[0]==next)
               {
                  int k=strlen(answer);
                  arr[i].addscore(k);
                  next=answer[k-1];
                  if(arr[i].getscore()>=limit && mode==1 )
                  {
                     count=0;
                     break;
                  }
               }
           }
         }
         if(men==1 && number==1)
         {
            coscore=against(next,&comp,root,level);
            AI.addscore(coscore.l);
            if(AI.getscore()>=limit && mode==1 )
            {
               tp=1;
               count=0;
               break;
            }
            next=coscore.nex;
            if(next=='?')
            {
               cout<<"I quit the game"<<endl;
               AI.errors=-1;
               break;
            }
         }
     }
    int x=finalscore(arr,AI,number,men,mode);
    free_all(root);
    if(x==1)
      goto start;
   else
         return 0;
   
}

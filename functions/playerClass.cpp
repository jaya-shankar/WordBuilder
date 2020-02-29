#include<iostream>

using namespace std;

class player
{
 char name[32];
 int helps;
 int score;
 int mul;
 public:
 int errors;
   player()
   {
      cout<<"Enter name of player: ";
      cin>>name;
      errors=3;
      helps=50;
      score=0;
      mul=0;
   }
   player(char a)
   {
     
      strcpy(name,"Computer");
      errors=3;
      helps=5;
      score=0;
      mul=0;
   }
   player(int x)
   {};
   int decerror()
   {
      errors--;
      return errors;
   }
   char *dispname()
   {
      return name;
   }
   int dechelp()
   {
      helps--;
      return helps;
   }
   void addscore(int x)
   {
      mul++;
      score=score+(x*mul);
   }
   int getscore()
   {
    return score;
   }
   void inchelp()
   {
      helps++;
   }

};
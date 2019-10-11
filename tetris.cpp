#include<iostream>
#include  <string>
#include<fstream>
using namespace std;
class metrix{
    public:
    int row;
    int col;
    int** index;
};

char* ch=new char[2];
int place;
int currentstate=1;
int type;
ifstream file("Tetris.data");
ofstream file2("Tetris.output");
void showmet(metrix* met){
  int row=met->row;
  int col=met->col;
   for(int i=2;i<=row+1;i++){
       for(int n=0;n<col;n++){
           file2<<(met->index)[i][n];
       }
       file2<<endl;
   }
}

void newmet(metrix* met,int row, int col){
    int** head = new int*[row+2];
    for(int i=0;i<=row+1;i++){
        head[i]= new int[col+2];
        for(int j=0;j<=col+1;j++){
            head[i][j]=0;
        }
    }
    met->index=head;
}
int detype (char* ch) {
  if(ch[0]=='T'){
    switch(ch[1]){
    case '1': return 1; break;
    case '2': return 2; break;
    case '3': return 3; break;
    case '4': return 4; break;
    }
  }
  if(ch[0]=='L'){
    switch(ch[1]){
    case '1': return 5; break;
    case '2': return 6; break;
    case '3': return 7; break;
    case '4': return 8; break;
    }
  }
  if(ch[0]=='J'){
    switch(ch[1]){
    case '1': return 9;  break;
    case '2': return 10; break;
    case '3': return 11; break;
    case '4': return 12; break;

    }
  }
   if(ch[0]=='S'){
    switch(ch[1]){
    case '1': return 13;  break;
    case '2': return 14; break;

    }
  }
  if(ch[0]=='Z'){
    switch(ch[1]){
    case '1': return 15;  break;
    case '2': return 16; break;

    }
  }
  if(ch[0]=='I'){
    if(ch[1]=='1')return 17;
    else return 18;
  }
  if(ch[0]=='O') return 19;
  if(ch[0]=='E') currentstate=0;
  return 0;
}
void findindex(metrix* met,int type,int x){
   int i,n,find1,find2;
   int find=0;
   switch(type){
   case  1 :
      for(i=2;i<=(met->row)+1&&find!=1;i++){
         if((met->index)[i][x+1]==1){
           find=2;
           break;
          }
        else{
          if(met->index[i][x]==1||met->index[i][x+2]==1){
            find=1;
            break;
          }
         }
      }
        if(find==2)drawblock(met,i-1,x,type);
         else if(find==1)drawblock(met,i,x,type);
            else drawblock(met,i-1,x,type);
      break;

    case 2:
      find1=0;
      find2=0;
      for(i=2;i<=(met->row)+1&&find1!=1;i++){
          if((met->index)[i][x+1]==1){
               find1=1;
               break;
          }
      }
       for (n=2;n<=(met->row)+1&&find2!=1;n++){
          if((met->index)[n][x]==1){
               find2=1;
                break;
          }
      }
     if (find2==0&&find1==0) drawblock(met,(met->row)+1,x,type);
       else if(n+1>i) drawblock(met,i-1,x,type);
         else drawblock(met,n,x,type);
    break;

   case 3 :
     for(i=2;i<=(met->row)+1&&find!=1;i++){
         for(int n=x;n<x+3;n++){
          if((met->index)[i][n]){
            find=1;
            break;
          }
         }
      }
        if(find==1)drawblock(met,i-2,x,type);
         else drawblock(met,i-1,x,type);
     break;

    case 4 :
      find1=0;
      find2=0;
      for(i=2;i<=(met->row)+1&&find1!=1;i++){
          if((met->index)[i][x]==1){
               find1=1;
               break;
          }
      }
       for (n=2;n<=(met->row)+1&&find2!=1;n++){
          if((met->index)[n][x+1]==1){
               find2=1;
                break;
          }
      }
     if (find2==0&&find1==0) drawblock(met,(met->row)+1,x,type);
       else if(n+1>i) drawblock(met,i-1,x,type);
         else drawblock(met,n,x,type);
    break;


   case  5:
      for(i=2;i<=(met->row)+1&&find!=1;i++){
        for(int n=x;n<x+2;n++){
            if(met->index[i][n]==1){
                find=1;
                break;
            }
        }
      }
     if(find==1)drawblock(met,i-2,x,type);
      else drawblock(met,i-1,x,type);
      break;
   case 6:
      for(i=2;i<=(met->row)+1&&find!=1;i++){
         if((met->index)[i][x]==1){
           find=2;
           break;
          }
        else{
         for(int n=x;n<x+3;n++){
          if(met->index[i][n]){
            find=1;
            break;
          }
         }
        }
      }
        if(find==2)drawblock(met,i-1,x,type);
         else if(find==1)drawblock(met,i-1,x,type);
            else drawblock(met,i-1,x,type);
      break;

   case 7:
      find1=0;
      find2=0;
      for(i=2;i<=(met->row)+1&&find1!=1;i++){
          if((met->index)[i][x+1]==1){
               find1=1;
               break;
          }
      }
       for (n=2;n<=(met->row)+1&&find2!=1;n++){
          if((met->index)[n][x]==1){
               find2=1;
                break;
          }
      }
     if (find2==0&&find1==0) drawblock(met,(met->row)+1,x,type);
       else if(n+2>i) drawblock(met,i-1,x,type);
         else drawblock(met,n+1,x,type);
    break;

   case 8:
     for(i=2;i<=(met->row)+1&&find!=1;i++){
         for(int n=x;n<x+3;n++){
          if((met->index)[i][n]){
            find=1;
            break;
          }
         }
      }
        if(find==1)drawblock(met,i-2,x,type);
         else drawblock(met,i-1,x,type);
     break;

   case 9 :
      for(i=2;i<=(met->row)+1&&find!=1;i++){
        for(int n=x;n<x+2;n++){
            if(met->index[i][n]==1){
                find=1;
                break;
            }
        }
      }
     if(find==1)drawblock(met,i-2,x,type);
      else drawblock(met,i-1,x,type);
      break;

   case 10 :
     for(i=2;i<=(met->row)+1&&find!=1;i++){
         for(int n=x;n<x+3;n++){
          if((met->index)[i][n]){
            find=1;
            break;
          }
         }
      }
        if(find==1)drawblock(met,i-2,x,type);
         else drawblock(met,i-1,x,type);
     break;

   case 11 :
      find1=0;
      find2=0;
      for(i=2;i<=(met->row)+1&&find1!=1;i++){
          if((met->index)[i][x]==1){
               find1=1;
               break;
          }
      }
       for (n=2;n<=(met->row)+1&&find2!=1;n++){
          if((met->index)[n][x+1]==1){
               find2=1;
                break;
          }
      }
     if (find2==0&&find1==0) drawblock(met,(met->row)+1,x,type);
       else if(n+2>i) drawblock(met,i-1,x,type);
         else drawblock(met,n-1,x,type);
    break;

   case 12:
      for(i=2;i<=(met->row)+1&&find!=1;i++){
         if((met->index)[i][x+2]==1){
           find=2;
           break;
          }
        else{
          for(int n=x+1;n<x+3;n++){
          if(met->index[i][n])
            find=1;
            break;
          }
         }
      }
        if(find==2)drawblock(met,i-1,x,type);
         else if(find==1)drawblock(met,i-1,x,type);
            else drawblock(met,i-1,x,type);
      break;

   case 13:
      for(i=2;i<=(met->row)+1&&find!=1;i++){
         if((met->index)[i][x]==1||(met->index)[i][x+1]==1){
           find=2;
           break;
          }
        else{
          if(met->index[i][x+2]){
            find=1;
            break;
          }
         }
      }
        if(find==2)drawblock(met,i-1,x,type);
         else if(find==1)drawblock(met,i,x,type);
            else drawblock(met,i-1,x,type);
      break;

    case 14:
      find1=0;
      find2=0;
      for(i=2;i<=(met->row)+1&&find1!=1;i++){
          if((met->index)[i][x+1]==1){
               find1=1;
               break;
          }
      }
       for (n=2;n<=(met->row)+1&&find2!=1;n++){
          if((met->index)[n][x]==1){
               find2=1;
                break;
          }
      }
     if (find2==0&&find1==0) drawblock(met,(met->row)+1,x,type);
       else if(n+1>i) drawblock(met,i-1,x,type);
         else drawblock(met,n,x,type);
    break;


    case 15:
      find1=0;
      find2=0;
      for(i=2;i<=(met->row)+1&&find1!=1;i++){
          if((met->index)[i][x+1]==1||(met->index)[i][x+2]==1){
               find1=1;
               break;
          }
      }
       for (n=2;n<=(met->row)+1&&find2!=1;n++){
          if((met->index)[n][x]==1){
               find2=1;
                break;
          }
      }
     if (find2==0&&find1==0) drawblock(met,(met->row)+1,x,type);
       else if(n+1>i) drawblock(met,i-1,x,type);
         else drawblock(met,n,x,type);
    break;
  case 16 :
      find1=0;
      find2=0;
      for(i=2;i<=(met->row)+1&&find1!=1;i++){
          if((met->index)[i][x]==1){
               find1=1;
               break;
          }
      }
       for (n=2;n<=(met->row)+1&&find2!=1;n++){
          if((met->index)[n][x+1]==1){
               find2=1;
                break;
          }
      }
     if (find2==0&&find1==0) drawblock(met,(met->row)+1,x,type);
       else if(n+1>i) drawblock(met,i-1,x,type);
         else drawblock(met,n,x,type);
    break;

   case 17:
       for(i=2;i<=(met->row)+1&&find!=1;i++){
         if((met->index)[i][x]==1){
             find=1;
             break;
         }
       }
       if(find==1)drawblock(met,i-1,x,type);
       else drawblock(met,i-1,x,type);
   break;

   case 18:
      for(i=2;i<=(met->row)+1&&find!=1;i++){
         for(int n=x;n<x+4;n++){
          if((met->index)[i][n]){
            find=1;
            break;
          }
         }
      }
        if(find==1)drawblock(met,i-2,x,type);
         else drawblock(met,i-1,x,type);
     break;

   case 19:
      for(i=2;i<=(met->row)+1&&find!=1;i++){
        for(int n=x;n<x+2;n++){
            if(met->index[i][n]){
                find=1;
                break;
            }
        }
      }
     if(find==1)drawblock(met,i-2,x,type);
      else drawblock(met,i-1,x,type);
      break;
  }
}
void drawmet(metrix* met){
    file>>ch;
    file>>place;
    type=detype(ch);
    if(type==0){
    file.close();
     return;
    }
    findindex(met,type,place-1);
}

int updatemet(metrix* met){
    do{
    drawmet(met);
    }while(currentstate!=0);
    return 0;
}


int main ()
{
 metrix bg;
 metrix* met=&bg;
if(!file) {
  file2<< "Can't open file!\n";
   }

  else{
 file>>met->row>>met->col;
  }

 newmet(met,met->row,met->col);
 updatemet(met);
 showmet(met);
 return 0;
}

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
ofstream file2("Tetris.final");
void showmet(metrix* met){
  int row=met->row;
  int col=met->col;
   for(int i=4;i<=row+3;i++){
       for(int n=0;n<col;n++){
           file2<<(met->index)[i][n];
       }
       file2<<endl;
   }
}

void newmet(metrix* met,int row, int col){
    int** head = new int*[row+4];
    for(int i=0;i<=row+3;i++){
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
void cleanrow(metrix* met,int row){
  if(row>=4){
    for(int i=row;i>0;i--){
        for(int n=0;n<=(met->col)+1;n++)
       (met->index)[i][n]=(met->index)[i-1][n];
    }
    //file2<<"after clean row:"<<row<<endl;
   // showmet(met);
  //  file2<<endl;
  }
}

void drawblock(metrix* met, int row,int x,int type){
    int clean,i,j,temp;
    if(row<=3||x>=met->col||x<0){
        currentstate=0;
        return;
    }
    switch(type){
     case 1:
       if(x+2>=met->col){
        currentstate= 0;
        return ;
       }

       for(j=x;j<x+3&&j<=met->col;j++){
         (met->index)[row-1][j]=1;
       }
       met->index[row][x+1]=1;
       for(i=row-1;i<=row;i++){
       clean=0;
       for(j=0;j<met->col;j++){
        if(met->index[i][j]==1) clean++;
       }
        if(clean==met->col)cleanrow(met,i);
     }
     if(met->index[3][x]==1) currentstate=0;
     break;


     case 2:
       if(x+1>=met->col) currentstate=0;
       met->index[row-1][x]=1;
       for(i=row;i>row-3&&i>=1;i--){
         met->index[i][x+1]=1;
       }
     for(i=row-2;i<=row;i++){
       clean=0;
       for(j=0;j<met->col;j++){
        if(met->index[i][j]==1) clean++;
       }
        if(clean==met->col)cleanrow(met,i);
     }
     if(met->index[3][x+1]==1) currentstate=0;
     break;

       case 3 :
      if(x+2>=met->col)currentstate=0;
        met->index[row-1][x+1]=1;
      for(j=x;j<=x+2;j++) met->index[row][j]=1;
      for(i=row-1;i<=row;i++){
       clean=0;
       for(j=0;j<met->col;j++){
        if(met->index[i][j]==1) clean++;
       }
        if(clean==met->col)cleanrow(met,i);
     }
     if(met->index[3][x+1]==1) currentstate=0;
     break;

    case 4:
       if(x+1>=met->col) currentstate=0;
       met->index[row-1][x+1]=1;
       for(i=row;i>row-3&&i>=1;i--){
         met->index[i][x]=1;
       }
     for(i=row-2;i<=row;i++){
       clean=0;
       for(j=0;j<met->col;j++){
        if(met->index[i][j]==1) clean++;
       }
        if(clean==met->col)cleanrow(met,i);
     }
     if(met->index[3][x]==1) currentstate=0;
     break;

     case 5:
      if(x+1>=(met->col)){
        currentstate=0;
        return ;
      }
      for(i=row;i>row-3&&i>=1;i--) (met->index)[i][x]=1;
      met->index[row][x+1]=1;
       for(i=row-2;i<=row;i++){
       clean=0;
       for(j=0;j<met->col;j++){
        if(met->index[i][j]==1) clean++;
       }
        if(clean==met->col)cleanrow(met,i);
     }
      if(met->index[3][x]==1) currentstate=0;
     break;

      case 6:
       if(x+2>=met->col){
        currentstate= 0;
        return ;
       }

       for(j=x;j<x+3&&j<=met->col;j++){
         (met->index)[row-1][j]=1;
       }
       met->index[row][x]=1;
       for(i=row-1;i<=row;i++){
       clean=0;
       for(j=0;j<met->col;j++){
        if(met->index[i][j]==1) clean++;
       }
        if(clean==met->col)cleanrow(met,i);
     }
     if(met->index[3][x]==1) currentstate=0;
     break;

     case 7:
       if(x+1>=met->col) currentstate=0;
       met->index[row-2][x]=1;
       //file2<<"row-2="<<row-2<<endl;
       for(i=row;i>row-3&&i>=1;i--){
         met->index[i][x+1]=1;
       }
     for(i=row-2;i<=row;i++){
       clean=0;
       for(j=0;j<met->col;j++){
        if(met->index[i][j]==1) clean++;
       }
        if(clean==met->col)cleanrow(met,i);
     }
     if(met->index[3][x]==1) currentstate=0;
     break;

     case 8:
        if(x+2>=met->col)currentstate=0;
        met->index[row-1][x+2]=1;
        for(j=x;j<=x+2;j++) met->index[row][j]=1;
        for(i=row-1;i<=row;i++){
       clean=0;
       for(j=0;j<met->col;j++){
        if(met->index[i][j]==1) clean++;
       }
        if(clean==met->col)cleanrow(met,i);
     }
     if(met->index[3][x+2]==1) currentstate=0;
     break;

     case 9:
        if(x+1>=(met->col)){
        currentstate=0;
        return ;
      }
      for(i=row;i>row-3&&i>=1;i--) (met->index)[i][x+1]=1;
      met->index[row][x]=1;
      for(i=row-2;i<=row;i++){
       clean=0;
       for(j=0;j<met->col;j++){
        if(met->index[i][j]==1) clean++;
       }
        if(clean==met->col)cleanrow(met,i);
     }
      if(met->index[3][x+1]==1) currentstate=0;
     break;

     case 10 :
      if(x+2>=met->col)currentstate=0;
        met->index[row-1][x]=1;
      for(j=x;j<=x+2;j++) met->index[row][j]=1;
      for(i=row-1;i<=row;i++){
       clean=0;
       for(j=0;j<met->col;j++){
        if(met->index[i][j]==1) clean++;
       }
        if(clean==met->col)cleanrow(met,i);
     }
     if(met->index[3][x]==1) currentstate=0;
     break;

    case 11:
       if(x+1>=met->col) currentstate=0;
       met->index[row-2][x+1]=1;
       for(i=row;i>row-3&&i>=1;i--){
         met->index[i][x]=1;
       }
     for(i=row-2;i<=row;i++){
       clean=0;
       for(j=0;j<met->col;j++){
        if(met->index[i][j]==1) clean++;
       }
        if(clean==met->col)cleanrow(met,i);
     }
     if(met->index[3][x]==1) currentstate=0;
     break;

      case 12:
       if(x+3>met->col){
        currentstate= 0;
        return ;
       }

       for(j=x;j<x+3&&j<=met->col;j++){
         (met->index)[row-1][j]=1;
       }
       met->index[row][x+2]=1;
      // file2<<row<<" "<<"show305"<<endl;
     //  showmet(met);
       for(i=row-1;i<=row;i++){
       clean=0;
       for(j=0;j<met->col;j++){
        if(met->index[i][j]==1) clean++;
       }
      
        if(clean==met->col)cleanrow(met,i);
     } 
     if(met->index[3][x+2]==1) currentstate=0;
     break;

     case 13:
       if(x+2>=met->col){
        currentstate= 0;
        return ;
       }

       for(j=x;j<x+2&&j<=met->col;j++)(met->index)[row][j]=1;
       for(j=x+1;j<x+3&&j<=met->col;j++)(met->index)[row-1][j]=1;
       for(i=row-1;i<=row;i++){
       clean=0;
       for(j=0;j<met->col;j++){
        if(met->index[i][j]==1) clean++;
       }
        if(clean==met->col)cleanrow(met,i);
     }
     if(met->index[3][x+1]==1) currentstate=0;
     break;

    case 14:
       if(x+1>=met->col) currentstate=0;
       for(i=row;i>row-2&&i>=1;i--)met->index[i][x+1]=1;
       for(i=row-1;i>row-3&&i>=1;i--)met->index[i][x]=1;
     for(i=row-2;i<=row;i++){
       clean=0;
       for(j=0;j<met->col;j++){
        if(met->index[i][j]==1) clean++;
       }
        if(clean==met->col)cleanrow(met,i);
     }
     if(met->index[3][x]==1) currentstate=0;
     break;


     case 15:
       if(x+2>=met->col){
        currentstate= 0;
        return ;
       }

       for(j=x;j<x+2&&j<=met->col;j++)(met->index)[row-1][j]=1;
       for(j=x+1;j<x+3&&j<=met->col;j++)(met->index)[row][j]=1;
       for(i=row-1;i<=row;i++){
       clean=0;
       for(j=0;j<met->col;j++){
        if(met->index[i][j]==1) clean++;
       }
        if(clean==met->col)cleanrow(met,i);
     }
     if(met->index[3][x+1]==1) currentstate=0;
     break;

     case 16:
       if(x+1>=met->col) currentstate=0;
       for(i=row;i>row-2&&i>=1;i--)met->index[i][x]=1;
       for(i=row-1;i>row-3&&i>=1;i--)met->index[i][x+1]=1;
     for(i=row-2;i<=row;i++){
       clean=0;
       for(j=0;j<met->col;j++){
        if(met->index[i][j]==1) clean++;
       }
        if(clean==met->col)cleanrow(met,i);
     }
     if(met->index[3][x]==1) currentstate=0;
     break;


    case 17:
        for(i=row;i>row-4&&i>=1;i--){
            (met->index)[i][x]=1;
            temp=i;
        }

        for(i=temp;i<=row;i++){
           clean=0;
           for(int n=0;n<met->col;n++){
            if(met->index[i][n]==1) clean++;
           }
           if(clean==met->col){
                cleanrow(met,i);
           }
        }
     if(met->index[3][x]==1){
            currentstate=0;
            return;
     }
     break;

     case 18:
       if(x+4>met->col){
        currentstate= 0;
        return ;
       }

       for(j=x;j<x+4&&j<=met->col;j++){
         (met->index)[row][j]=1;
       }
       clean=0;
         for(int n=0;n<met->col;n++){
           if(met->index[row][n]==1) clean++;
         }
           if(clean==met->col) cleanrow(met,row);
           if(met->index[3][x]==1) currentstate=0;
     break;
     case 19 :
       if(x+2>met->col){
        currentstate= 0;
        return ;
       }
       for(i=row;i>row-2&&i>=1;i--){
         for(j=x;j<x+2&&j<=met->col;j++){
          (met->index)[i][j]=1;
         }
       }
     for(i=row-1;i<=row;i++){
       clean=0;
       for(j=0;j<met->col;j++){
        if(met->index[i][j]==1) clean++;
       }
        if(clean==met->col)cleanrow(met,i);
     }
     if(met->index[3][x]==1) currentstate=0;
     break;
    }
}

void findindex(metrix* met,int type,int x){
   int i,n,find1,find2;
   int find=0;
   switch(type){
   case 1 :
      for(i=4;i<=(met->row)+3&&find==0;i++){
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
      for(i=4;i<=(met->row)+3&&find1!=1;i++){
          if((met->index)[i][x+1]==1){
               find1=1;
               break;
          }
      }
       for (n=2;n<=(met->row)+3&&find2!=1;n++){
          if((met->index)[n][x]==1){
               find2=1;
                break;
          }
      }
     if (find2==0&&find1==0) drawblock(met,(met->row)+3,x,type);
       else if(n+1>i) drawblock(met,i-1,x,type);
         else drawblock(met,n,x,type);
    break;

   case 3 :
     for(i=4;i<=(met->row)+3&&find!=1;i++){
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
      for(i=4;i<=(met->row)+3&&find1!=1;i++){
          if((met->index)[i][x]==1){
               find1=1;
               break;
          }
      }
       for (n=2;n<=(met->row)+3&&find2!=1;n++){
          if((met->index)[n][x+1]==1){
               find2=1;
                break;
          }
      }
     if (find2==0&&find1==0) drawblock(met,(met->row)+3,x,type);
       else if(n+1>i) drawblock(met,i-1,x,type);
         else drawblock(met,n,x,type);
    break;


   case  5:
      for(i=4;i<=(met->row)+3&&find!=1;i++){
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
      for(i=4;i<=(met->row)+3&&find==0;i++){
         if((met->index)[i][x]==1){
           find=2;
           break;
          }
        else{
         for(int n=x+1;n<x+3;n++){
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
      for(i=4;i<=(met->row)+3&&find1!=1;i++){
          if((met->index)[i][x+1]==1){
               find1=1;
               break;
          }
      }
       for (n=2;n<=(met->row)+3&&find2!=1;n++){
          if((met->index)[n][x]==1){
               find2=1;
                break;
          }
      }
     if (find2==0&&find1==0) drawblock(met,(met->row)+3,x,type);
       else if(n+2>i) drawblock(met,i-1,x,type);
         else drawblock(met,n+1,x,type);
    break;

   case 8:
     for(i=4;i<=(met->row)+3&&find!=1;i++){
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
      for(i=4;i<=(met->row)+3&&find!=1;i++){
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
     for(i=4;i<=(met->row)+3&&find!=1;i++){
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
      for(i=4;i<=(met->row)+3&&find1!=1;i++){
          if((met->index)[i][x]==1){
               find1=1;
               break;
          }
      }
       for (n=2;n<=(met->row)+3&&find2!=1;n++){
          if((met->index)[n][x+1]==1){
               find2=1;
                break;
          }
      }
     if (find2==0&&find1==0) drawblock(met,(met->row)+3,x,type);
       else if(n+2>i) drawblock(met,i-1,x,type);
         else drawblock(met,n+1,x,type);
    break;

   case 12:
      for(i=4;i<=(met->row)+3&&find==0;i++){
         if((met->index)[i][x+2]==1){
           find=2;
           break;
          }
        else{
          for(int n=x;n<x+2;n++){
          if(met->index[i][n]==1){
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

   case 13:
      for(i=4;i<=(met->row)+3&&find==0;i++){
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
      for(i=4;i<=(met->row)+3&&find1!=1;i++){
          if((met->index)[i][x+1]==1){
               find1=1;
               break;
          }
      }
       for (n=2;n<=(met->row)+3&&find2!=1;n++){
          if((met->index)[n][x]==1){
               find2=1;
                break;
          }
      }
     if (find2==0&&find1==0) drawblock(met,(met->row)+3,x,type);
       else if(n+1>i) drawblock(met,i-1,x,type);
         else drawblock(met,n,x,type);
    break;


    case 15:
      find1=0;
      find2=0;
      for(i=4;i<=(met->row)+3&&find1!=1;i++){
          if((met->index)[i][x+1]==1||(met->index)[i][x+2]==1){
               find1=1;
               break;
          }
      }
       for (n=2;n<=(met->row)+3&&find2!=1;n++){
          if((met->index)[n][x]==1){
               find2=1;
                break;
          }
      }
     if (find2==0&&find1==0) drawblock(met,(met->row)+3,x,type);
       else if(n+1>i) drawblock(met,i-1,x,type);
         else drawblock(met,n,x,type);
    break;
  case 16 :
      find1=0;
      find2=0;
      for(i=4;i<=(met->row)+3&&find1!=1;i++){
          if((met->index)[i][x]==1){
               find1=1;
               break;
          }
      }
       for (n=2;n<=(met->row)+3&&find2!=1;n++){
          if((met->index)[n][x+1]==1){
               find2=1;
                break;
          }
      }
     if (find2==0&&find1==0) drawblock(met,(met->row)+3,x,type);
       else if(n+1>i) drawblock(met,i-1,x,type);
         else drawblock(met,n,x,type);
    break;

   case 17:
       for(i=4;i<=(met->row)+3&&find==0;i++){
         if((met->index)[i][x]==1){
             find=1;
             break;
         }
       }
       if(find==1)drawblock(met,i-1,x,type);
       else drawblock(met,i-1,x,type);
   break;

   case 18:
      for(i=4;i<=(met->row)+3&&find!=1;i++){
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
      for(i=4;i<=(met->row)+3&&find!=1;i++){
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
    //file2<<"tetris type is:"<<ch<<" and place is:"<<place<<endl;
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

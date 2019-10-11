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

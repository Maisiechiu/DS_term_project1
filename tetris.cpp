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
 return 0;
}

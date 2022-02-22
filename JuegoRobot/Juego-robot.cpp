#include <iostream>
using namespace std;
void drawMap(int posX,int posY,char gameMap[5][5]){
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      if(posX==j && posY==i)
        {
            cout<<"R";
        }
      else
      {
            cout<<gameMap[i][j];
      }
    }
    cout<<endl;
  }
}
int main(){
  int posX=3;
  int posY=3;
  char map[5][5]={{'1','1','1','1','1'},
                  {'1','0','0','0','1'},
                  {'1','0','0','0','1'},
                  {'1','0','0','0','1'},
                  {'1','1','1','1','1'}};
  char teclado;
  bool gameOver= false;
  drawMap(posX,posY,map);
  while(!gameOver)
  {
    cout << "Bienvenido(a)"  << endl;
    cout << "Controles Teclas --> w(arriba), a(izquierda), d(derecha) y s(abajo)" << endl;
    cout << "Controles Teclas --> p(Salida)" << endl;
    cin >> teclado;


    if (posX !=0 && posY !=0 && posX !=4 && posY !=4){
        switch (teclado)
        {
        case 'a':
            posX-=1;
            break;
        case 'd':
            posX+=1;
            break;
        case 'w':
            posY-=1;
            break;
        case 's':
            posY+=1;
            break;
        case 'p':
            gameOver=true;
        default:
            break;
        }
    }else{
        cout<<"\n---Llego al Limite---\n"<<endl;
        }


  drawMap(posX,posY,map);
  }
 return 0;
}

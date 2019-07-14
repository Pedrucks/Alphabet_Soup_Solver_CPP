#include <iostream>
#include <string.h>

using namespace std;

class Sopa{

  private:

    int fil = 0;
    int col = 0;
    char **tablero;
    string *palabras;
    int cantidad = 0;

  public:

    Sopa(int fila, int columna){

      fil = fila;
      col = columna;

      tablero = new char *[fil];

      for(int i = 0; i < fil; i++){

        tablero[i] = new char [col];

      }

      palabras = new string [0];

    }

    void PedirTab(){

      char letra;

      for(int i = 0; i < fil; i++){

        for(int j = 0; j < col; j++){

          cout << endl << "Introduzca el caracter en la posicion [" << i << "][" << j << "]: ";
          cin >> letra;
          tablero[i][j] = letra;

        }

      }

    }

    void LeerTab(){

      cout << "  ";

      for(int i = 0; i < col; i++){

        cout << i << "   ";

      }

      cout << endl;

      for(int i = 0; i < fil; i++){

        cout << i << " ";

        for(int j = 0; j < col; j++){

          cout << tablero[i][j] << "   ";

        }

        cout << endl << endl;

      }

    }

    void CambiarLetra(int fila, int columna, char nueva){

      if(columna >= 0 && columna < col && fila >= 0 && fila < fil){

        tablero[fila][columna] = nueva;

      }else{

        cout << endl << "No se ha podido cambiar el caracter.";

      }

    }

    void AniadirPalabra(string pal){

      string *v_ampliado = new string [cantidad + 1];

      for(int i = 0; i < cantidad; i++){

        v_ampliado[i] = palabras[i];

      }

      delete [] palabras;

      palabras = v_ampliado;

      palabras[cantidad] = pal;

      cantidad ++;

    }

    void LeerPalab(){

      for(int i = 0; i < cantidad; i++){

        cout << i << ".- " << palabras[i] << endl;

      }

    }

    void EliminarPalab(int num){

      if(num >= 0 && num < cantidad){

        for(int i = 0; i < cantidad - 1; i++){

          if(i >= num){

            palabras[i] = palabras[i + 1];

          }

        }

        cantidad --;

      }else{

        cout << endl << "No se ha podido eliminar";

      }

    }

    int *Resolver(){

      int *solucion = new int [cantidad * 4];
      int aux = 0;
      int contador = 0;
      bool encontrado = false;
      int operacion1 = 0;
      int operacion2 = 0;
      int operacion3 = 0;
      int operacion4 = 0;

      for(int i = 0; i < cantidad; i++){

        for(int j = 0; j < fil; j++){

          for(int k = 0; k < col; k++){

            if(palabras[i][0] == tablero[j][k]){ //Hemos encontrado que la primera letra de la palabra es igual

              operacion1 = palabras[i].length() + k;
              operacion2 = k - palabras[i].length();
              operacion3 = palabras[i].length() + j;
              operacion4 = j - palabras[i].length();

              if(k < col - 1){

                if(palabras[i][1] == tablero[j][k + 1] && encontrado == false && operacion1 <= col){ //Va hacia la derecha

                  for(int m = 0; m < palabras[i].length(); m++){

                    if(palabras[i][m] == tablero[j][k + m]){

                      contador ++;

                    }

                    if(contador == palabras[i].length()){

                      solucion[aux] = j;
                      solucion[aux + 1] = k;
                      solucion[aux + 2] = j;
                      solucion[aux + 3] = k + palabras[i].length() - 1;

                      encontrado = true;
                      aux = aux + 4;

                    }

                  }

                }

              }

              contador = 0;

              if(k > 0){

                if(palabras[i][1] == tablero[j][k - 1] && encontrado == false && operacion2 > -2){ //Va hacia la izquierda

                  for(int m = 0; m < palabras[i].length(); m++){

                    if(palabras[i][m] == tablero[j][k - m]){

                      contador ++;

                    }

                    if(contador == palabras[i].length()){

                      solucion[aux] = j;
                      solucion[aux + 1] = k;
                      solucion[aux + 2] = j;
                      solucion[aux + 3] = k - palabras[i].length() + 1;

                      encontrado = true;
                      aux = aux + 4;

                    }

                  }

                }

              }


              contador = 0;

              if(j < fil - 1){

                if(palabras[i][1] == tablero[j + 1][k] && encontrado == false && operacion3 <= fil){ //Va hacia abajo

                  for(int m = 0; m < palabras[i].length(); m++){

                    if(palabras[i][m] == tablero[j + m][k]){

                      contador ++;

                    }

                    if(contador == palabras[i].length()){

                      solucion[aux] = j;
                      solucion[aux + 1] = k;
                      solucion[aux + 2] = j + palabras[i].length() - 1;
                      solucion[aux + 3] = k;

                      encontrado = true;
                      aux = aux + 4;

                    }

                  }

                }

              }

              contador = 0;

              if(j > 0){

                if(palabras[i][1] == tablero[j - 1][k] && encontrado == false && operacion4 > -2){ //Va hacia arriba

                  for(int m = 0; m < palabras[i].length(); m++){

                    if(palabras[i][m] == tablero[j - m][k]){

                      contador ++;

                    }

                    if(contador == palabras[i].length()){

                      solucion[aux] = j;
                      solucion[aux + 1] = k;
                      solucion[aux + 2] = j - palabras[i].length() + 1;
                      solucion[aux + 3] = k;

                      encontrado = true;
                      aux = aux + 4;

                    }

                  }

                }

              }

              contador = 0;

              if(j < fil - 1 && k < col - 1){

                if(palabras[i][1] == tablero[j + 1][k + 1] && encontrado == false && operacion1 <= col && operacion3 <= fil){ //Diagonal izquierda a derecha y arriba a abajo

                  for(int m = 0; m < palabras[i].length(); m++){

                    if(palabras[i][m] == tablero[j + m][k + m]){

                      contador ++;

                    }

                    if(contador == palabras[i].length()){

                      solucion[aux] = j;
                      solucion[aux + 1] = k;
                      solucion[aux + 2] = j + palabras[i].length() - 1;
                      solucion[aux + 3] = k + palabras[i].length() - 1;

                      encontrado = true;
                      aux = aux + 4;

                    }

                  }

                }

              }


              contador = 0;

              if(j > 0 && k < col - 1){

                if(palabras[i][1] == tablero[j - 1][k + 1] && encontrado == false && operacion1 <= col && operacion4 > -2){ //Diagonal izquierda a derecha y abajo a arriba

                  for(int m = 0; m < palabras[i].length(); m++){

                    if(palabras[i][m] == tablero[j - m][k + m]){

                      contador ++;

                    }

                    if(contador == palabras[i].length()){

                      solucion[aux] = j;
                      solucion[aux + 1] = k;
                      solucion[aux + 2] = j - palabras[i].length() + 1;
                      solucion[aux + 3] = k + palabras[i].length() - 1;

                      encontrado = true;
                      aux = aux + 4;

                    }

                  }

                }

              }

              contador = 0;

              if(j < fil - 1 && k > 0){

                if(palabras[i][1] == tablero[j + 1][k - 1] && encontrado == false && operacion2 > -2 && operacion3 <= fil){ //Diagonal derecha a izquierda y arriba a abajo

                  for(int m = 0; m < palabras[i].length(); m++){

                    if(palabras[i][m] == tablero[j + m][k - m]){

                      contador ++;

                    }

                    if(contador == palabras[i].length()){

                      solucion[aux] = j;
                      solucion[aux + 1] = k;
                      solucion[aux + 2] = j + palabras[i].length() - 1;
                      solucion[aux + 3] = k - palabras[i].length() + 1;

                      encontrado = true;
                      aux = aux + 4;

                    }

                  }

                }


              }

              contador = 0;

              if(j > 0 && k > 0){

                if(palabras[i][1] == tablero[j - 1][k - 1] && encontrado == false && operacion2 > -2 && operacion4 > -2){ //Diagonal derecha a izquierda y abajo a arriba

                  for(int m = 0; m < palabras[i].length(); m++){

                    if(palabras[i][m] == tablero[j - m][k - m]){

                      contador ++;

                    }

                    if(contador == palabras[i].length()){

                      solucion[aux] = j;
                      solucion[aux + 1] = k;
                      solucion[aux + 2] = j - palabras[i].length() + 1;
                      solucion[aux + 3] = k - palabras[i].length() + 1;

                      encontrado = true;
                      aux = aux + 4;

                    }

                  }

                }

              }

              contador = 0;

            }

          }

        }

        if(encontrado == false){

          solucion[aux] = -1;
          solucion[aux + 1] = -1;
          solucion[aux + 2] = -1;
          solucion[aux + 3] = -1;

          aux = aux + 4;

        }

        encontrado = false;

      }

      return solucion;

    }

    void Resultados1(int *res){

      int contador = 0;

      cout << endl << "******************************************SOLUCION******************************************" << endl;

      for(int i = 0; i < cantidad * 4; i = i + 4){

        if(res[i] != -1){

          cout << contador << ".-" << palabras[contador] << "-> Comienzo: [" << res[i] << ", " << res[i + 1] << "] y Final [" << res[i + 2] << ", " << res[i + 3] << "]" << endl;

        }else{

          cout << contador << ".-" << palabras[contador] << "-> PALABRA NO ENCONTRADA" << endl;

        }

        contador ++;

      }

      cout << "******************************************SOLUCION******************************************" << endl << endl;

    }

    ~Sopa(){

      delete [] palabras;
      cantidad = 0;

      for(int i = 0; i < fil; i++){

        delete [] tablero[i];

      }

      delete [] tablero;

      fil = 0;
      col = 0;

    }



};

void Menu(int num, Sopa &sopa);

int main(){

  int fil = 0;
  int col = 0;
  int numero = 0;

  cout << endl << "****************************************************************************************************************************" << endl;
  cout << "RESOLVEDOR DE SOPAS DE LETRAS by Pedrucks." << endl;
  cout << endl << endl << "Consideraciones a tener en cuenta: ";
  cout << endl << "1.- No se detectan simbolos (tildes, ñ)";
  cout << endl << "2.- Si la sopa de letras es grande, la solucion quedara por encima de ella por lo que hay que arrastar hacia arriba" << endl;
  cout << "****************************************************************************************************************************" << endl << endl;


  cout << "Introduzca el tamanio de su tablero, (alto y ancho): ";
  cin >> fil >> col;

  while(fil <= 0 || col <= 0){

    cout << endl << "Datos mal introducidos, introdzuca de nuevo sus valores: ";
    cin >> fil >> col;

  }

  Sopa s1(fil, col);
  s1.PedirTab();

  cout << "\033[2J\033[1;1H";

  cout << "Su tablero ha quedado asi: " << endl << endl;

  while(numero != -1){

    s1.LeerTab();

    cout << endl << endl;

    s1.LeerPalab();

    cout << endl << "**********************************************************************";
    cout << endl << "1.-Pulse 1 para editar una letra. ";
    cout << endl << "2.-Pulse 2 para aniadir una palabra. ";
    cout << endl << "3.-Pulse 3 para eliminar una palabra. ";
    cout << endl << "4.-Pulse 4 para encontrar la solucion. ";
    cout << endl << "5.-Pulse -1 para salir.";
    cout << endl << "**********************************************************************";

    cout << endl << endl << "Numero: ";
    cin >> numero;

    Menu(numero, s1);

    if(numero != 4) {

      cout << "\033[2J\033[1;1H";

    }

  }


}


void Menu(int num, Sopa &sopa){

  int fila = 0;
  int columna = 0;
  char letra;
  string pala;
  int cifra = 0;

  if(num == 1){

    cout << endl << "Introduzca fila, columna y nuevo caracter: ";
    cin >> fila >> columna >> letra;

    sopa.CambiarLetra(fila, columna, letra);

  }else if(num == 2){

    cout << endl << "Introduzca su palabra: ";
    cin >> pala;

    sopa.AniadirPalabra(pala);

  }else if(num == 3){

    cout << endl << "Introduzca el numero de la palabra a eliminar: ";
    cin >> cifra;

    sopa.EliminarPalab(cifra);

  }else if(num == 4){

    sopa.Resultados1(sopa.Resolver());

  }

}

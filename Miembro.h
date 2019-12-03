#ifndef MIEMBRO_H
#define MIEMBRO_H
#include<iostream>

using namespace std;

class Miembro{
  /*
  Atributos de instancia. Estos son accesibles
  a traves de las clases que se hereden de esta
  */
  protected:
      string nombre, matricula;

  //Métodos
  public:
    Miembro(){}
    Miembro(string nom,string mat);

    //Getters
    string getNombre();
    string getMatricula();
};

//Constructor que recibe parámetros
Miembro::Miembro(string nom,string mat){
 nombre=nom;
 matricula=mat;
}

string Miembro::getNombre(){
   return nombre;
}

string Miembro::getMatricula(){
   return matricula;
}



//clase para la Mesa directiva del grupo que hereda a Miembro
class Mesa: public Miembro{
  //Nuevos atributos
  private:
    string cargoMesa;

  //Nuevas funciones
  public:
    Mesa();
    Mesa(string nom, string mat, string charge);

    //Getters
    string getCargoM();

    //Metodos
    string strMesa();
    void NuevoCargo(string);
};

//Por default
Mesa::Mesa(){}

//Constructor de mesa
Mesa::Mesa(string nom, string mat, string charge) : Miembro(nom,mat){
  cargoMesa=charge;
}

string Mesa::getCargoM(){
  return cargoMesa;
}

//Funcion para cambiar el cargo o rol
void Mesa::NuevoCargo(string nc){
  cargoMesa=nc;
}

//Funcion para obtener el nombre, matricula y cargo en un string
string Mesa::strMesa(){
  string strM=nombre+"|"+matricula+"|"+cargoMesa;
  return strM;
}



//clase para el comite tecnico del grupo, que hereda a Miembro
class ComiteTecnico: public Miembro{
  //Nuevos atributos
  private:
    string cargoCT;

  //Nuevas funciones
  public:
    ComiteTecnico();
    ComiteTecnico(string nom,string mat,string charge);

    //Getters
    string getCargoCT();

    //Metodos
    string strComTec();
    void NuevoCargo(string);
};

//por default
ComiteTecnico::ComiteTecnico(){}

//Constructor
ComiteTecnico::ComiteTecnico(string nom,string mat,string charge): Miembro(nom,mat){
    cargoCT=charge;
}

string ComiteTecnico::getCargoCT(){
  return cargoCT;
}

string ComiteTecnico::strComTec(){
  string strCT=nombre+"|"+matricula+"|"+cargoCT;
  return strCT;
}

void ComiteTecnico::NuevoCargo(string nuevo_cargo){
  cargoCT=nuevo_cargo;
}


//clase para los Colaboradores que hereda a miembros
class Colaboradores: public Miembro{
  public:
      Colaboradores();
      Colaboradores(string,string);

      //Constructor
      string strColaborador();
};

//por default
Colaboradores::Colaboradores(){}

//COnstructor
Colaboradores::Colaboradores(string nom,string mat): Miembro(nom,mat){
}

string Colaboradores::strColaborador(){
  string strCol=nombre+"|"+matricula;
  return strCol;
}

#endif // MIEMBRO_H

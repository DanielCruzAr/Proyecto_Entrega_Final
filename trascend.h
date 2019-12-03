#ifndef TRASCEND_H
#define TRASCEND_H
#include <iostream>
#include "Miembro.h"

using namespace std;

const int CUPO=20;

class Trascend{
  private:

    Mesa m[CUPO];
    ComiteTecnico ct[CUPO];
    Colaboradores col[CUPO];

    int nMesa,nCT,nCol;
    float fondos;

  public:
    Trascend(); //por default

    //getters de las variables privadas
    float getFondos();

    void printMesa();
    void printCT();
    void printColaboradores();

    void llenaMesa();
    void llenaCT();

    //Informacion del grupo
    void informacion();
    void mision();
    void vision();
    void infoMesa();
    void infoCT();
    void infoCol();

    //Metodos
    void agregaMesa(string,string,string);
    void agregaCT(string,string,string);
    void agregaColaborador(string,string);
    void agregaFondos(float);
    bool cambiaCargoM(string);
    bool cambiaCargoCT(string);

};

Trascend::Trascend(){
 nMesa=1;
 nCT=0;
 nCol=0;
 /*
 El grupo apenas se esta formando asi que por el momento no contamos con fondos.
 Empezaremos con las vendimias el siguiente semestre para asi tener dinero suficiente.
 */
 fondos=0;

}

void Trascend::llenaMesa(){

  m[0]= Mesa("Carlos Sanchez","A01702188","presidente");
  nMesa++;
  m[1]= Mesa("Rafael Romo","A01701493","vicepresidente");
  nMesa++;
  m[2]= Mesa("Alejandra Lopez","A01702071","tesoreria");
  nMesa++;
  m[3]= Mesa("Romina Gramlich","A01701313","publicidad");
  nMesa++;
  m[4]= Mesa("Daniel Cruz","A01701370","patrocinios");
  nMesa++;

}

void Trascend::llenaCT(){

 ct[0]=ComiteTecnico("Emilio Valdez","A01704832","cursos");
 nCT++;
 ct[1]=ComiteTecnico("Balam Bravo","A01703834","cursos");
 nCT++;

}

float Trascend::getFondos(){
  return fondos;
}

void Trascend::printMesa(){
  for(int i=0;i<nMesa;i++){
    cout << m[i].strMesa() << endl;
  }
}

void Trascend::printCT(){
  for(int i=0;i<nCT;i++){
    cout << ct[i].strComTec() << endl;
  }
}

void Trascend::printColaboradores(){
  for(int i=0;i<nCol;i++){
    cout << col[i].strColaborador() << endl;
  }
}

void Trascend::informacion(){
 cout << "\n Somos un grupo estudiantil con el prop�sito de";
 cout << "\n fomentar el balance en las 7 dimensiones que conforman";
 cout << "\n a la persona (F�sico, Emocional, Social, Espiritual e Intelectual)";
 cout << "\n para as�, alcanzar la autorrealizaci�n y libertad personal.";
 cout << "\n Nuestro objetivo es potencializar las habilidades y facultades";
 cout << "\n de nuestros integrantes mediante pl�ticas, conferencias y actividades en contacto con la naturaleza;";
 cout << "\n para impulsarlos a desarrollar la mejor versi�n de s� mismos." << endl;
}

void Trascend::mision(){
 cout << "\n Inspirar a estudiantes del Tecnol�gico de Monterrey a potencializar sus habilidades de liderazgo,";
 cout << "\n inteligencia emocional y desarrollo integral como personas, mediante actividades que favorezcan";
 cout << "\n el crecimiento personal y profesional en contacto con la  naturaleza, con el fin de alcanzar la plenitud";
 cout << "\n y el bienestar integral." << endl;
}

void Trascend::vision(){
 cout << "\n Lograr ser un grupo estudiantil que est� presente en m�s de un campus y cuente con varios colaboradores.";
 cout << "\n Con el paso del tiempo, poder progresar a actividades de otro nivel con la experiencia adquirida en los cursos b�sicos.";
 cout << "\n A su vez, crear en el grupo una estructura funcional para que las generaciones futuras puedan continuarlo." <<endl;
}

//Informacion sobre la mesa, el comite tecnico y los colaboradores
void Trascend::infoMesa(){
 cout << "\n Encargados de la organizaci�n general del grupo,"
      << "\n administraci�n de recursos, asignaci�n de actividades,"
      << "\n organizaci�n de eventos, publicidad y difusi�n."
      << "\n Encargados de crear m�dulos para temas de inteligencia emocional.\n " << endl;
}

void Trascend::infoCT(){
 cout << "\n Comit� conformado por personas especializadas en diversas"
      << "\n �reas al aire libre. Encargados de dar cursos b�sicos. \n"
      << endl;
}

void Trascend::infoCol(){
 cout << "\n Encargados de participar, contribuir y sumar al grupo de manera efectiva y responsable."
      << "\n Colaborar en vendimias, log�stica y difusi�n del grupo. \n" << endl;
}

void Trascend::agregaMesa(string nom,string mat,string carg){
    Mesa nuevaMesa(nom,mat,carg);
    m[nMesa]=nuevaMesa;
    nMesa++;
}


void Trascend::agregaCT(string nom,string mat,string carg){
    ComiteTecnico nuevoCT(nom,mat,carg);
    ct[nCT]=nuevoCT;
    nCT++;
}

void Trascend::agregaColaborador(string nom,string mat){
    Colaboradores nuevoColaborador(nom,mat);
    col[nCol]=nuevoColaborador;
    nCol++;
}

void Trascend::agregaFondos(float fond){
   fondos=fondos+fond;
}

/*
Las 2 funciones a continuacion primero reciben un string con la matricula del alumno que se
quiera buscar para cambiarle el rango si pretenece a la mesa o al comite tecnico.
Si la funcion encuentra al alumno, pide un input con el nuevo cargo y devuelve verdadero.
Si no lo encuentra devuelve false.
*/
bool Trascend::cambiaCargoM(string mat){
   string nc;
   for(int i=0;i<nMesa;i++){
     if(mat==m[i].getMatricula()){
        cout << "Persona encontrada, introduce nuevo cargo \n";
        cin >> nc;
        m[i].NuevoCargo(nc);
        return true;
     }
   }
   return false;
}

bool Trascend::cambiaCargoCT(string mat){
   string nc;
   for(int i=0;i<nMesa;i++){
     if(mat==ct[i].getMatricula()){
        cout << "Persona encontrada, introduce nuevo cargo \n";
        cin >> nc;
        ct[i].NuevoCargo(nc);
        return true;
     }
   }
   return false;
}

#endif // TRASCEND_H

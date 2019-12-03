/*
Daniel Cruz Arciniega
A01701370

Trascend
Trascend es un grupo estudiantil que estoy planeando junto con otros compa�eros.
Es un grupo enfocado en actividades al aire libre y tematicas como la superacion
personal y la inteligencia emocional.
El grupo est� actualmente activo, sin embargo el TEC no lo reconocer� como tal hasta
febrero del a�o entrante.
Mi programa ense�a toda la estructura del grupo e informacion del mismo.
*/
#include<iostream>
#include<stdio.h>
#include "Miembro.h"
#include "trascend.h"

using namespace std;

void menu(){
 cout <<"\n";
 cout << "Opcion 1: agregar fondos \n";
 cout << "Opcion 2: ver integrantes de mesa \n";
 cout << "Opcion 3: ver integrantes del comite tecnico \n";
 cout << "Opcion 4: ver colaboradores \n";
 cout << "Opcion 5: agregar integrante de mesa \n";
 cout << "Opcion 6: agregar integrante de comite tecnico \n";
 cout << "Opcion 7: agregar colaborador \n";
 cout << "Opcion 8: cambiar el cargo de mesa de una persona \n";
 cout << "Opcion 9: cambiar el cargo de comite tecnico de una persona \n";
 cout << "Opcion 10: ver informacion de mesa, comite tecnico y colaboradores \n";
 cout << "Opcion 11: salir \n";
}

int main(){
   Trascend trascend; //Se construye el objeto trascend con valores por default
   //Ejemplo de miembro de mesa
   cout << "\n �Qui�nes somos?"; trascend.informacion();
   cout << "\n Misi�n del grupo"; trascend.mision();
   cout << "\n Visi�n del grupo"; trascend.vision();
   cout << "\n Fondos: " << trascend.getFondos() << endl;

   /*El grupo ya cuenta con miembros en la mesa directiva y en el comite tecnico
   por lo que la lista se llena automaticamente con los miembros existentes*/
   trascend.llenaMesa();
   trascend.llenaCT();

   int opcion=0;
   float fond;
   string nom,mat,carg;

   while(opcion <11 && opcion >-1){
      menu();
      cin >> opcion;

      switch(opcion){

         case 1:
             cout << "Introduce cantidad que desee agregar " << endl;
             cin >> fond;
             trascend.agregaFondos(fond);
             cout << "Los fondos ahora son $" << trascend.getFondos() << endl;
             break;

         case 2:
             cout << "NOMBRE|MATRICULA|CARGO" << endl;
             trascend.printMesa();
             break;

         case 3:
             cout << "NOMBRE|MATRICULA|CARGO CT" << endl;
             trascend.printCT();
             break;

         case 4:
            cout << "NOMBRE|MATRICULA" << endl;
            trascend.printColaboradores();
            break;

         case 5:
             cout << "Introduce los datos de la persona";
             cout <<"\n Nombre: "; cin >> nom;
             cout << "\n Matricula: "; cin >> mat;
             cout << "\n Cargo de mesa: "; cin >> carg;
             trascend.agregaMesa(nom,mat,carg);
             cout << "Se ha registrado un nuevo miembro de mesa \n";
             break;

        case 6:
             cout << "Introduce los datos de la persona";
             cout <<"\n Nombre: "; cin >> nom;
             cout << "\n Matricula: "; cin >> mat;
             cout << "\n Cargo de comite tecnico: "; cin >> carg;
             trascend.agregaCT(nom,mat,carg);
             cout << "Se ha registrado un nuevo miembro del comite tecnico \n";
             break;

        case 7:
             cout << "Introduce los datos de la persona";
             cout <<"\n Nombre: "; cin >> nom;
             cout << "\n Matricula: "; cin >> mat;
             trascend.agregaColaborador(nom,mat);
             cout << "Se ha registrado un nuevo colaborador \n";
             break;

        case 8:
            cout << "Introduce la matricula de la persona a la que se le quiera cambiar el cargo \n";
            cin >> mat;
            if(trascend.cambiaCargoM(mat)==false){
                cout << "Persona no encontrada \n";
            }
            break;

        case 9:
            cout << "Introduce la matricula de la persona a la que se le quiera cambiar el cargo \n";
            cin >> mat;
            if(trascend.cambiaCargoCT(mat)==false){
                cout << "Persona no encontrada \n";
            }
            break;

        case 10:
            cout << "MESA";
            trascend.infoMesa();
            cout << "COMITE TECNICO";
            trascend.infoCT();
            cout << "COLABORADORES";
            trascend.infoCol();
            break;
      }
   }
return 0;
}

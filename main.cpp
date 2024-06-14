#include <iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
using namespace std;

#include "funciones.h"

int main()
{
  char opp;
  int RPM, carasUtilizables, sectoresPorPista,puntoInicio , peticion, pistasPorCara;
  int sectorIncio, cilindroInicio, sectorDestino, cilindroDestino, rtaCantSecRecorridos;
  int newSectorInicio, sectorHomologoInicio, caraSectorInicio, sectorHomologoDestino, caraSectorDestino;
  float pasoDeCilindro , rtaSeekTime, rtaSeachTime , tiempo_1sectorEnMM;
    while ( true )
    {
      system("cls");
      cout << "***************************" << endl;
      cout << "***************************" << endl;
      cout << "1. CARGAR DATOS:" << endl;
      cout << "2. MOSTRAR DATOS:" << endl;
      cout << "3. PUNTO ACTUAL | PUNTO DISTINO" << endl;
      cout << "4. SEEK TIME: " << endl;
      cout << "5. SECTORES RECORRIDOS DURANTE EL SEEK-TIME" << endl;
      cout << "6. NUEVO PUNTO ACTUAL | NUEVO PUNTO DESTINO: " << endl;
      cout << "7. SEACH TIME: " << endl;
      cout << "8. OTRAS FUNCIONES " << endl;
      cout << "0. PARA SALIR" << endl;
      cout << "***************************" << endl;
      cout << "INGRESE UNA OPCION: ";
      cin >> opp;
      system("cls");
        switch (opp)
        {
          case '1':
              cargarDatos( RPM, carasUtilizables, pistasPorCara, sectoresPorPista, pasoDeCilindro, puntoInicio, peticion );
              carcularCilindroInicio( puntoInicio, carasUtilizables, sectoresPorPista, cilindroInicio, sectorIncio);
              calcularCilindroDestino( peticion, carasUtilizables, sectoresPorPista, cilindroDestino, sectorDestino);
              rtaSeekTime = carlularSeekTime( pasoDeCilindro , cilindroDestino, cilindroInicio);
              // CALCUALO CUANTOS MILISEGUNDO TARDA EN RECORRER 1 SECOR:
                tiempo_1sectorEnMM = calcularSetorEnMilisec( RPM, sectoresPorPista);
              //
              rtaCantSecRecorridos = sectoresRecorridosSeekTime ( rtaSeekTime, tiempo_1sectorEnMM);
              newSectorInicio = rtaCantSecRecorridos + sectorIncio;
              calcularSector_InicioHomologo( newSectorInicio, sectoresPorPista, caraSectorInicio, sectorHomologoInicio);
              calcularSector_DestinoHomologo ( sectorDestino, sectoresPorPista, caraSectorDestino, sectorHomologoDestino);
              //rtaSeachTime = calcular_seachTime ( RPM, sectorHomologoInicio, sectorHomologoDestino, sectoresPorPista);
            break;
          case '2':
              mostrarDatos( RPM, carasUtilizables, pistasPorCara, sectoresPorPista, pasoDeCilindro, puntoInicio, peticion );
            break;
          case '3':
              cout << "CLINDRO EN EL QUE ESTOY: " << cilindroInicio << endl;
              cout << "SECTOR EN EL QUE ESTOY: " << sectorIncio << endl;
              cout << "||-|-||-|-||-|-||-|-||-|-||-|-||-|-||-|-||-|-||-|-||-|-||-|-||" << endl;
              cout << "CILINDRO AL QUE VOY :" << cilindroDestino << endl;
              cout << "SECTO AL QUE VOY: "<< sectorDestino << endl;
            break;
          case '4':
              cout << "SEEK TIME: " << rtaSeekTime << endl;
            break;
          case '5':
              cout << "CANTIDAD DE SECOCORES RECORRIDOS DURANTE EL SEEK: " << rtaCantSecRecorridos << endl;
            break;
          case '6':
              cout << "NUEVO SECTOR INICIO: " << newSectorInicio << endl;
              cout << "SECOR HOMOLOGO INICIO: " << sectorHomologoInicio << endl;
              cout << "CARA EN DONDE ESTA EL SECTOR HOMOLOGO: " << caraSectorInicio << endl;
              cout << "||-|-||-|-||-|-||-|-||-|-||-|-||-|-||-|-||-|-||-|-||-|-||-|-||" << endl;
              cout << "SECOR AL QUE VOY: " << sectorDestino << endl;
              cout << "SECOR HOMOLOGO DESTINO: " << sectorHomologoDestino << endl;
              cout << "CARA EN DONDE ESTA EL SECTOR HOMOLOGO: " << caraSectorDestino << endl;
            break;
          case '7':
              cout << "SEACH TIME: " << rtaSeachTime <<endl;
          case '8':
              cout << "TIEMPO QUE TARDA EN RECORRER 1 SEC"  << tiempo_1sectorEnMM <<endl;
            break;
          case '0': return 0;
              break;
          default: cout << "OPCION INCORRECTA" << endl;
              break;
        }
      system("pause");
    }
    return 0;
}

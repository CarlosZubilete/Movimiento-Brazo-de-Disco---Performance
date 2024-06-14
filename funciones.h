#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void cargarDatos( int &rpm, int &caras, int &pistas, int &secXpista, float &pasoXCil, int &ptoInicio, int &ptoFinal)
{
  cout << "INGRESE R.P.M ";
  cin >> rpm;
  cout << "INGRESE CARAS UTILIZABLES: ";
  cin >> caras;
  cout << "INGRESE PISTAS POR CARA: ";
  cin >> pistas;
  cout << "INGRESE SECTORES POR PISTA: ";
  cin >> secXpista;
  cout << "INGRESE PASO DE CILINDRO: ";
  cin >> pasoXCil;
  cout << "INGRESE PUNTO ACTUAL ";
  cin >> ptoInicio ;
  cout << "INGRESE PETICION ";
  cin >> ptoFinal;
}

void mostrarDatos( int rpm, int caras, int pistas, int secXpista, float pasoXCil, int ptoInicio, int ptoFinal)
{
  cout << "R.P.M: " << rpm << endl;
  cout << "CARAS UTILIZABLES: " << caras << endl;
  cout << "PISTAS POR CARA: " << pistas << endl;
  cout << "SECTORES POR PISTA: " << secXpista << endl;
  cout << "PASO DE CILINDRO: " << pasoXCil << endl;
  cout << "PUNTO ACTUAL " << ptoInicio << endl;
  cout << "PETICION " << ptoFinal << endl;
}

// PASO N°1:
  int calcularSecoresXCilindro ( int caras, int secXpista)
  {
    int rta;
    rta = caras * secXpista;
    return rta;
  }
// FIN PASO N°1.

// PASO N°2:
  void carcularCilindroInicio ( int ptoIncio , int caras, int secXpista, int &cilInicio, int &secInicio)
  {
    int rtaSecXPista = calcularSecoresXCilindro (caras, secXpista);
    cilInicio = ptoIncio / rtaSecXPista;
    secInicio = ptoIncio % rtaSecXPista;
  }

  void calcularCilindroDestino ( int ptoFinal, int caras, int secXpista, int &cilDestino, int &secDestino)
  {
    int rtaSecXPista = calcularSecoresXCilindro (caras, secXpista);
    cilDestino = ptoFinal / rtaSecXPista;
    secDestino = ptoFinal % rtaSecXPista;
  }
// FIN PASO N°2.

// PASO N°3:
  float carlularSeekTime ( float pasoXcil, int cilDestino , int cilInico)
  {
    float seekTime = (float)(cilDestino-cilInico)*pasoXcil;

      if ( seekTime < 0 )
      {
        seekTime = seekTime*(-1);
      }

    return seekTime;
  }
// FIN PASO N°3.

// CACCULOS EXTRAS:
  float calcularSetorEnMilisec ( int rpm, int secXpista )
  {
    float revXMiliSeg, pasajeAMiliSeg;
    revXMiliSeg = (float)60000/rpm;
    pasajeAMiliSeg = (float) revXMiliSeg / secXpista;

    return pasajeAMiliSeg;
  }

  int redondearUp (float valor)
  {
    int partEntera = 0;
    for (int i = 0 ; i <= valor ; i++)
    {
      partEntera++;
    }
     return partEntera++;
  }
///////////////////////////////////////////
int sectoresRecorridosSeekTime (float seekTime , float tiempoRecorrer1Sec)
{
  float secRecorriedos = seekTime / tiempoRecorrer1Sec;
  int redondearSec = redondearUp (secRecorriedos);
  return redondearSec;
}

void calcularSector_InicioHomologo ( int newSec, int secXpista, int &caraHomoIni, int &secHomoIni)
{
  caraHomoIni = newSec / secXpista;
  secHomoIni = newSec % secXpista;
}

void calcularSector_DestinoHomologo ( int secDestino, int secXpista, int &caraHomoDes, int &secHomoDes)
{
  caraHomoDes = secDestino / secXpista;
  secHomoDes = secDestino % secXpista;
}

float calcular_seachTime ( int rpm, int secHomoIni , int secHomoDes , int secXpista)
{
  float tiempoEn1sec = calcularSetorEnMilisec(rpm, secXpista);
  int cantSecAMover ;
  float seachTime;
  if ( secHomoIni > secHomoDes )
  {
    cantSecAMover = ( secXpista - secHomoIni) + secHomoDes;
  }
  else
  {
    cantSecAMover = secHomoDes - secHomoIni;
  }
    seachTime = (float)cantSecAMover*tiempoEn1sec;
    return seachTime;
}


#endif // FUNCIONES_H_INCLUDED

/*
  display7seg.h - Library for display of seven segments
  Created by Ruben Granados, Junio 7, 2022.
  Released into the public domain.
*/
#include "Arduino.h"
#include "display7seg.h"

Display7s::Display7s(byte *pinesdisplay, boolean ano_cato, boolean ptdy) {
  _pinesdisplay = pinesdisplay;
  _ano_cato = ano_cato;
  _ptdy = ptdy;
  boolean selecatanodo;
  if (_ptdy == 1) {
    for ( int i = 0; i < 8; i++) {    //declara los pines como salida
      pinMode(_pinesdisplay[i], OUTPUT);
    }
  } else {
    for ( int i = 0; i < 7; i++) {    //declara los pines como salida
      pinMode(_pinesdisplay[i], OUTPUT);
    }
  }
}
void Display7s::prueba(int retardar) {
  if (_ptdy == 1) {
    for ( int i = 0; i < 8; i++) {
      digitalWrite(_pinesdisplay[i], !_ano_cato);
      delay(retardar);
    }
    for ( int i = 0; i < 8; i++) {
      digitalWrite(_pinesdisplay[i], _ano_cato);
      delay(retardar);
    }
  } else {
    for ( int i = 0; i < 7; i++) {
      digitalWrite(_pinesdisplay[i], !_ano_cato);
      delay(retardar);
    }
    for ( int i = 0; i < 7; i++) {
      digitalWrite(_pinesdisplay[i], _ano_cato);
      delay(retardar);
    }
  }
}
void Display7s::mostrar(int x) {      //muestra los numeros hexadecimales
  if ( _ptdy == 1) {
    for (int i = 0; i < 8; i++) {       //recorre cada segmento del display
      digitalWrite(_pinesdisplay[i], catanodo(_ano_cato, x, i));
    }        // lo imprime en el display
  } else {
    for (int i = 0; i < 7; i++) {       //recorre cada segmento del display
      digitalWrite(_pinesdisplay[i], catanodo(_ano_cato, x, i));
    }
  }
}
boolean Display7s::catanodo(bool control, int columna, int fila) {     // Catodo/Anodo, columna, fila
  if (control == 0) {
    selecatanodo = numeros[columna][fila]; // busca el bit deseado
  }
  else {
    selecatanodo = !numeros[columna][fila]; // busca el bit deseado y lo contradice
  }
  return (selecatanodo);      // retorna un 0 o un 1 dependiendo si es Catodo o Anodo
}
void Display7s::apagado(){
  if (_ptdy == 1) {
    for ( int i = 0; i < 8; i++) {
      digitalWrite(_pinesdisplay[i], _ano_cato);
    }
  } else {
    for ( int i = 0; i < 7; i++) {
      digitalWrite(_pinesdisplay[i], _ano_cato);
    }
  }
}

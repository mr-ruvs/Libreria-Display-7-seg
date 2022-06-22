/*
  display7seg.h - Library for display of seven segments
  Created by Ruben Granados, Junio 7, 2022.
  Released into the public domain.
*/
#ifndef display7seg_h
#define display7seg_h
#include "Arduino.h"
// Made changes according to this post http://arduino.cc/forum/index.php?topic=58337.0
// by Nick Gammon. Thanks for the input Nick. It actually saved 78 bytes for me. :)

class Display7s
{
  public:
    Display7s(byte *pinesdisplay, boolean ano_cato, boolean ptdy);
    void prueba(int retardar);
    void mostrar(int x);
    void apagado();
    boolean catanodo(bool control, int columna, int fila);
  private:
    byte *_pinesdisplay;
    boolean _ano_cato;
    boolean _ptdy;
    boolean selecatanodo;
    boolean numeros[16][8] = {       //columna, fila
      { 1, 1, 1, 1, 1, 1, 0, 1 },       // 0
      { 0, 1, 1, 0, 0, 0, 0, 1 },       // 1
      { 1, 1, 0, 1, 1, 0, 1, 1 },       // 2
      { 1, 1, 1, 1, 0, 0, 1, 1 },       // 3
      { 0, 1, 1, 0, 0, 1, 1, 1 },       // 4
      { 1, 0, 1, 1, 0, 1, 1, 1 },       // 5
      { 1, 0, 1, 1, 1, 1, 1, 1 },       // 6
      { 1, 1, 1, 0, 0, 0, 0, 1 },       // 7
      { 1, 1, 1, 1, 1, 1, 1, 1 },       // 8
      { 1, 1, 1, 1, 0, 1, 1, 1 },       // 9
      { 1, 1, 1, 0, 1, 1, 1, 1 },       //A
      { 0, 0, 1, 1, 1, 1, 1, 1 },       //b
      { 1, 0, 0, 1, 1, 1, 0, 1 },       //C
      { 0, 1, 1, 1, 1, 0, 1, 1 },       //d
      { 1, 0, 0, 1, 1, 1, 1, 1 },       //E
      { 1, 0, 0, 0, 1, 1, 1, 1 }        //F
    };
};

#endif

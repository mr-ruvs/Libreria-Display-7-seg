#include <display7seg.h>
byte pines[] = {6, 11, 9, 8, 7, 5, 3, 10}; // segmentos a, b, c, d, e, f, g, dp
Display7s d1(pines, 0, 1);                 // objeto tipo Display7s; se declaran los pines, 0 para catodo, 1 para activar dp
void setup() {

}

void loop() {
  for (int i = 0; i <= 15; i++) {          // recorre los numeros del 0 al 15
    d1.mostrar(i);                         // muestra los numeros hexadecimal
    delay(500);                            // una espera de 500 ms
  }
}

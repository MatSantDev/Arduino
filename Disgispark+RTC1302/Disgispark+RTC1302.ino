// Código Arduino para Digispark (ATtiny85) com DS1302

#include <DS1302.h>
#include <DigiKeyboard.h>

#ifndef KEY_TAB
#define KEY_TAB     43   // Código HID da tecla Tab
#endif

// Definir os pinos para o DS1302
const int CE_PIN = 0;   // P0 no Digispark
const int IO_PIN = 1;   // P1 no Digispark
const int SCLK_PIN = 2; // P2 no Digispark

// instância do objeto DS1302
DS1302 rtc(CE_PIN, IO_PIN, SCLK_PIN);

void setup() {

  // Configurar o RTC
  rtc.halt(false); // Habilitar o relógio
  rtc.writeProtect(false); // Desabilitar proteção contra escrita
}

void loop() {

  // Ler a hora atual do DS1302
  Time t = rtc.time();
  int hour = t.hr;
  int minute = t.min;
  int second = t.sec;

  // Mude a hora e minuto (24h) para o momento que queira que o digispark ative
  if (hour == 8 && minute == 00) {
    // Escreve na tela
    DigiKeyboard.print("XXXXXXXX");
    // Pressiona Enter, pode colocar outros comandos como Win+R, Alt+f4, veja a tabela
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    //Delay necessario pode alterar se for preciso
    DigiKeyboard.delay(100);
    
    // Delay maior para que ele não execute varias vezes no horario
    DigiKeyboard.delay(50000);
  }

  // Pequeno atraso para não ler o RTC muito rapidamente
  delay(10000);
}

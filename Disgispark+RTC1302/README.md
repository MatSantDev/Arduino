# Digispark ATtiny85 + DS1302 (RTC) Automação de Teclado

Este projeto utiliza o **Digispark ATtiny85** junto com o módulo **RTC DS1302** para executar automaticamente comandos de teclado em um horário programado.  
A ideia é simples: quando o relógio atinge o horário configurado no código, o Digispark envia teclas simulando a digitação no computador.

---

## 🚀 Como funciona
1. O **RTC DS1302** mantém a hora atual mesmo sem energia.
2. O **Digispark ATtiny85** lê o horário do DS1302.
3. Se o horário definido no código for atingido, o dispositivo envia comandos de teclado utilizando a biblioteca `DigiKeyboard`.

Exemplo incluído no código:
- Quando o RTC marca **08:00**, o Digispark digita `"XXXXXXXX"` e pressiona **Enter**. Podendo alterar como prefirir apenas um exemplo

---

## 🔧 Conexões do DS1302 com Digispark

| DS1302  | Digispark |
|---------|-----------|
| CE      | P0        |
| IO      | P1        |
| SCLK    | P2        |
| VCC     | 5V        |
| GND     | GND       |
| BAT     | CR2032    |

---

## ⚙️ Configuração
Indico a usar a versão do arduino Legacy, no momento que fiz estava na versão Legacy IDE (1.8.19)

1. Abra o **Arduino IDE**.
2. Vá em **Arquivo > Preferências**.
3. No campo **URLs adicionais para Gerenciadores de Placas**, adicione: https://raw.githubusercontent.com/digistump/arduino-boards-index/master/package_digistump_index.json
Se já houver outra URL, separe por vírgula.
4. Vá em **Ferramentas > Placa > Gerenciador de Placas**.
5. Procure por **Digistump AVR Boards** e instale.
6. Agora selecione a placa:  
**Ferramentas > Placa > Digispark (Default - 16.5mhz)**.
7. Agora selecione o programador:  
**Ferramentas > Programador > Micronucleos**.
8. Conecte o Digispark **somente quando a IDE pedir durante o upload**.


## ⌨️ Tabela de Códigos DigiKeyboard

Use no formato:
```cpp
DigiKeyboard.sendKeyStroke(KEY_X);
DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); // Exemplo com modificador
🔹 Teclas básicas
Tecla	Código HID
Enter	KEY_ENTER
Tab	KEY_TAB
Espaço	KEY_SPACE
Backspace	KEY_BACKSPACE
Esc	KEY_ESC
Delete	KEY_DELETE
Insert	KEY_INSERT
🔹 Setas
Tecla	Código HID
↑ Cima	KEY_UP
↓ Baixo	KEY_DOWN
← Esquerda	KEY_LEFT
→ Direita	KEY_RIGHT
🔹 Teclas de Função
Tecla	Código HID
F1	KEY_F1
F2	KEY_F2
F3	KEY_F3
F4	KEY_F4
F5	KEY_F5
F6	KEY_F6
F7	KEY_F7
F8	KEY_F8
F9	KEY_F9
F10	KEY_F10
F11	KEY_F11
F12	KEY_F12
🔹 Modificadores (podem ser combinados)
Tecla	Código
Ctrl	MOD_CONTROL_LEFT
Shift	MOD_SHIFT_LEFT
Alt	MOD_ALT_LEFT
Windows (GUI)	MOD_GUI_LEFT

Exemplo de combinação:

DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); // Win + R
DigiKeyboard.sendKeyStroke(KEY_F4, MOD_ALT_LEFT); // Alt + F4

OBS: **Alguns podem não funcionar corretamente se seu teclado estiver em outra linguagem**

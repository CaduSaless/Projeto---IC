// C++ code
// Testes
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

//teclado
  const byte numLinhas = 4;
  const byte numColunas = 3;
  const int PIR = 1;

  byte linhas[numLinhas] = {13, 12, 11, 10};
  byte colunas[numColunas] = {9, 8, 7};

  char teclas[numLinhas][numColunas] =
  {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0','#'}
  };

  Keypad teclado = Keypad(makeKeymap(teclas), linhas, colunas, numLinhas, numColunas);

//Tela
LiquidCrystal_I2C lcd(0x27, 16,2);

//Buzzer
const int frequencia = 1000;
bool Alarme=false;
bool Porta=false;
float seno;
float buzzOutput;

String Senha = "4481";
void setup()
{
  Serial.begin(9600); //teclado
  pinMode(A0, OUTPUT); //Buzzer
  lcd.init(); //Tela
  lcd.clear();
  lcd.backlight();
  lcd.print("   Bem-vindo");
  lcd.setCursor(0,1);
  lcd.print("Alarme desligado"); 
}

void loop()
{   
  delay(10);
  char teste = teclado.getKey();
  Serial.println(teste);
  if (teste == '#'){
     delay(300);
     lcd.clear();
     lcd.print("   Bem-vindo");
     lcd.setCursor(0,1); 
     lcd.print("Senha: ");
     lcd.setCursor(7,1); 
     String texto = ler_do_teclado();
     if(texto==Senha && Alarme==true){
     lcd.clear();
     lcd.print("   Bem-vindo");
     lcd.setCursor(0,1);
     lcd.print("Alarme desligado"); 
     Alarme=false;
     for (int x = 0; x <= 180; x++){
       seno = sin(radians(x));
       buzzOutput = frequencia + frequencia*seno; // De 1000 Hz a 2000 Hz
       tone(A0, buzzOutput);
       delay(2);
     }  
     noTone(A0);
     delay(100);
     for (int x = 0; x <= 180; x++){
       seno = sin(radians(x));
       buzzOutput = frequencia + frequencia*seno; // De 1000 Hz a 2000 Hz
       tone(A0, buzzOutput);
       delay(2);
     }
     noTone(A0);
     } else if(texto==Senha && Alarme==false){
     lcd.clear();
     lcd.print("   Bem-vindo");
     lcd.setCursor(0,1);
     lcd.print("Alarme ligado");
     Alarme=true;
     for (int x = 0; x <= 180; x++){
       seno = sin(radians(x));
       buzzOutput = frequencia + frequencia*seno; // De 1000 Hz a 2000 Hz
       tone(A0, buzzOutput);
       delay(2);
     }  
     noTone(A0);
     delay(100);
     for (int x = 0; x <= 180; x++){
       seno = sin(radians(x));
       buzzOutput = frequencia + frequencia*seno; // De 1000 Hz a 2000 Hz
       tone(A0, buzzOutput);
       delay(2);
     }
     noTone(A0);
     }else if(texto!=Senha){
     lcd.clear();
     lcd.print("   Bem-vindo");
     lcd.setCursor(0,1); 
     lcd.print(" Senha errada!"); 
     delay(1000);
     lcd.clear();
     lcd.print("   Bem-vindo");
     lcd.setCursor(0,1);
     }
}
  int Sensor = analogRead(A3); //Sensor PIR
  delay(10);
  if(Sensor!=0 && Alarme==true){
    Porta=true;
     }
   while(Porta==true){
     tone(A0, 3000); 
     lcd.clear();
     lcd.print("    Perigo!!!");
     lcd.setCursor(0,1);
     lcd.print("Senha:");
     String texto = ler_do_teclado();
     
     if(texto==Senha){
     lcd.clear();
     lcd.print("Alarme desligado");
     noTone(A0);
     delay(1000);
     lcd.clear();
     lcd.print("   Bem-vindo");
     Porta=false;
     Alarme=false;
     } else if(texto!=Senha){
     lcd.clear();
     lcd.print(" Senha errada!");
     delay(1000);
     }
}
}


String ler_do_teclado(){
  String valorRetornado;
  char valorLido = teclado.waitForKey();
  int contador_numeros = 0;
  String senha = "*";
  while (contador_numeros < 3)
  {
    if (contador_numeros == 0){
      valorRetornado += valorLido;
      lcd.print(senha);
    }
    valorLido = teclado.waitForKey();
    valorRetornado += valorLido;
    lcd.print(senha);
    contador_numeros += 1;
    delay(10);
  }
    return valorRetornado;
}

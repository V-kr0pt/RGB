#include <Arduino.h>


#define R 10 //pino conectado ao LED vermelho
#define G 9 //pino conectado ao LED verde
#define B 11 //pino conectado ao LED azul


//Definindo algumas variáveis necessárias para o funcionamento do algoritmo
int state = 0; //variável que define o estado dos leds

void brilho(int R_brilho, int G_brilho, int B_brilho){
  //função que envia o sinal analógico para o pino do arduino
  if(R_brilho < 0){R_brilho = 0;}
  if(G_brilho < 0){G_brilho = 0;}
  if(B_brilho < 0){B_brilho = 0;}
  analogWrite(R, R_brilho);
  analogWrite(G, G_brilho);
  analogWrite(B, B_brilho);
}

void cor(String Cor, int intensidade = 255){
  //função que retorna a cor através dos LEDs RGBs

  bool vermelho = Cor.equalsIgnoreCase("vermelho");
  bool verde = Cor.equalsIgnoreCase("verde");
  bool azul = Cor.equalsIgnoreCase("azul");
  bool amarelo = Cor.equalsIgnoreCase("amarelo");
  bool roxo = Cor.equalsIgnoreCase("roxo");
  bool rosa = Cor.equalsIgnoreCase("rosa");
  bool cinza = Cor.equalsIgnoreCase("cinza");
  bool slateBlue  = Cor.equalsIgnoreCase("slateblue"); 
  bool deepSkyBlue =  Cor.equalsIgnoreCase("deepSkyBlue"); 
  bool skyBlue = Cor.equalsIgnoreCase("skyblue");
  bool aqua = Cor.equalsIgnoreCase("aqua");
  bool lightGreen = Cor.equalsIgnoreCase("lightgreen");
  bool powderBlue = Cor.equalsIgnoreCase("powderblue");
  bool thistle = Cor.equalsIgnoreCase("thistle");
  
  
  if(vermelho){brilho(intensidade,0,0);}
  if(rosa){brilho(intensidade,intensidade-235,intensidade-108);}
  if(thistle){brilho(intensidade-39, intensidade-64, intensidade-39);}

  if(amarelo){brilho(intensidade,intensidade,0);}

  if(verde){brilho(0,intensidade,0);}
  if(lightGreen){brilho(intensidade-111,intensidade-17,intensidade-111);}

  if(azul){brilho(0,0,intensidade);}  
  if(slateBlue){brilho(intensidade-124,intensidade-144,intensidade);}
  if(deepSkyBlue){brilho(intensidade-255,intensidade-64,intensidade);}
  if(skyBlue){brilho(intensidade-120,intensidade-49,intensidade-20);}
  if(aqua){brilho(0, intensidade, intensidade);}
  if(powderBlue){brilho(intensidade-79,intensidade-26,intensidade-20);}

  if(roxo){brilho(intensidade,0,intensidade);}
  if(cinza){brilho(intensidade-201,intensidade-201,intensidade-201);}
 
}

void Efeito(String Efeito, String Cor, int Espera=50, int Repeticao = 10){
  bool fade = Efeito.equalsIgnoreCase("fade");
  bool blink = Efeito.equalsIgnoreCase("blink");

  if(fade){
    //efeito crescente e decrescente da luminosidade dos Leds
    for(int i=0; i<=255; i++){
      cor(Cor, i);
      delay(Espera);
    }
    for(int i=255; i>=0; i--){
      cor(Cor, i);
      delay(Espera);
    }
  }

  if(blink){
    for(int i=0; i<Repeticao; i++){
      cor(Cor, 0);
      delay(Espera);
      cor(Cor);
      delay(Espera);
    }

  }
}


void fade_standart(){

  Efeito("fade","vermelho", 25);
  Efeito("fade", "amarelo", 25);
  Efeito("fade", "verde", 25);
  Efeito("fade", "lightGreen", 25);
  Efeito("fade", "azul", 25);
  Efeito("fade", "slateBlue", 25);
  Efeito("fade", "aqua", 25);
  Efeito("fade", "powderblue", 25);
  Efeito("fade", "deepSkyBlue", 25);
  Efeito("fade", "skyblue", 25);
  Efeito("fade", "roxo", 25);

}

void cor_standart(){
  //Mudança de cor
  for(int i=0; i<5; i++){
    cor("vermelho");
    delay(2000);
    cor("rosa");
    delay(2000);
    cor("thistle");
    delay(2000);
    cor("roxo");
    delay(2000);
    cor("azul");
    delay(2000);
    cor("powderblue");
    delay(2000);
    cor("aqua");
    delay(2000);
    cor("verde");
    delay(2000);
    cor("amarelo");
  }

}


void setup() {
  //define os pinos como saída
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);

  //inicializando a comunicação serial
  Serial.begin(9600);
  while(Serial.read() !='1'){}
  Serial.println("Seja bem vindo!");
  Serial.println("------------------------------------\n");
  cor("azul");
  delay(500);
  cor("vermelho");
  delay(500);
  cor("verde");
  delay(500);
  brilho(0,0,0);
  delay(1000);
  Serial.println("Opções:\n0- fade_standart\n1- cor_standart\n2- azul\n3- vermelho\n4- verde");
  Serial.println("5- amarelo\n6- rosa\n7- aqua\n8- powder blue\n9- verde claro\noutro- desliga");
  
  
}

void loop() {
  //código principal
  //standart();

  if(Serial.available()>0){
    state = Serial.read();
  }

  switch(state){
    case '0':
      fade_standart();      
      break;  
    case '1':
      cor_standart();
      break;
    case '2':
      cor("azul");
      break;
    case '3':
      cor("vermelho");
      break;
    case '4':
      cor("verde");
      break;
    case '5':
      cor("amarelo");
      break;
    case '6':
      cor("rosa");
      break;
    case '7':
      cor("aqua");
      break;
    case '8':
      cor("powderblue");
      break;
    case '9':
      cor("lightgreen");
      break;
    default:
      brilho(0,0,0);         
      break;
  }
}

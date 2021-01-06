#include <Arduino.h>
#include <functions.cpp>

#define R 10 //pino conectado ao LED vermelho
#define G 9 //pino conectado ao LED verde
#define B 11 //pino conectado ao LED azul


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


void standart(){

  Efeito("fade","vermelho", 25);
    delay(200);
    Efeito("fade", "amarelo", 25);
    delay(200);
    Efeito("fade", "verde", 25);
    delay(200);
    Efeito("fade", "lightGreen", 25);
    delay(200);
    Efeito("fade", "azul", 25);
    delay(200); 
    Efeito("fade", "slateBlue", 25);
    delay(200);
    Efeito("fade", "aqua", 25);
    delay(200);
    Efeito("fade", "powderblue", 25);
    delay(200);
    Efeito("fade", "deepSkyBlue", 25);
    delay(200);
    Efeito("fade", "skyblue", 25);
    delay(200);
    Efeito("fade", "roxo", 25);
    delay(1000); 
    
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
      delay(2000);
    }

}


void setup() {
  //define os pinos como saída
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
}

void loop() {
  //código principal
  standart();
  
}


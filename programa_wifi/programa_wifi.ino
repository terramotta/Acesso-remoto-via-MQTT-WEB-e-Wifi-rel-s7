// 180 horizontal MAX
Servo horizontal; // servo horizontal.
int servoh = 90;   // 90;     // posição padrão do servo horizontal.

int servohLimitHigh = 180; // range máximo do servo horizontal .
int servohLimitLow = 65;

// 65 degrees MAX
Servo vertical;   // servo vertical.
int servov = 90;    //   90;     // posição padrão do servo vertical.

int servovLimitHigh = 120; // range máximo do servo vertical.
int servovLimitLow = 15;


// conexão dos pinos do LDR
//  name  = analogpin;
int ldrlt = 2; //LDR top left - BOTTOM LEFT    <--- BDG
int ldrrt = 3; //LDR top rigt - BOTTOM RIGHT 
int ldrld = 0; //LDR down left - TOP LEFT
int ldrrd = 1; //ldr down rigt - TOP RIGHT


void setup() {
  
  Serial.begin(9600);
// servo connections
// name.attacht(pin);
  horizontal.attach(9); // função da biblioteca servo, anexa o servo à um pino.
  vertical.attach(10); 
  horizontal.write(180); // função da biblioteca servo, isso definirá o ângulo do eixo (em graus), movendo o eixo para essa orientação.
  vertical.write(45);
  delay(3000);
}



void loop() {

  int lt = analogRead(ldrlt); // top left
  int rt = analogRead(ldrrt); // top right
  int ld = analogRead(ldrld); // down left
  int rd = analogRead(ldrrd); // down rigt
  
  // int dtime = analogRead(4)/20; // read potentiometers  
  // int tol = analogRead(5)/4;
  int dtime = 10;
  int tol = 50;
  
  int avt = (lt + rt) / 2; // valor médio no topo.
  int avd = (ld + rd) / 2; // valor médio em baixo.
  int avl = (lt + ld) / 2; // valor médio na esquerda.
  int avr = (rt + rd) / 2; // valor médio na direita.

  int dvert = avt - avd; // checa a diferença entre a parte superior e inferior.
  int dhoriz = avl - avr;// checa a diferença entre a parte da esquerda e da direita.
  
  
  Serial.print(avt);
  Serial.print(" ");
  Serial.print(avd);
  Serial.print(" ");
  Serial.print(avl);
  Serial.print(" ");
  Serial.print(avr);
  Serial.print("   ");
  Serial.print(dtime);
  Serial.print("   ");
  Serial.print(tol);
  Serial.println(" ");
  
  if ((avt < 30 && avd < 30) && (avl > 30 && avr > 30)){
  Serial.println("No Sun Detected!") ;
  }else if (-1*tol > dvert || dvert > tol) // checa se a diferença está dentro da tolerância, else-> muda o angulo)
  {
  if (avt > avd)
  {
    servov = ++servov;
     if (servov > servovLimitHigh) 
     { 
      servov = servovLimitHigh;
     }
  }
  else if (avt < avd)
  {
    servov= --servov;
    if (servov < servovLimitLow)
  {
    servov = servovLimitLow;
  }
  }
  vertical.write(servov);
  }

  
  if (-1*tol > dhoriz || dhoriz > tol) // check if the diffirence is in the tolerance else change horizontal angle
  {
  if (avl > avr)
  {
    servoh = --servoh;
    if (servoh < servohLimitLow)
    {
    servoh = servohLimitLow;
    }
  }
  else if (avl < avr)
  {
    servoh = ++servoh;
     if (servoh > servohLimitHigh)
     {
     servoh = servohLimitHigh;
     }
  }
  else if (avl = avr)
  {
    // nothing
  }
  horizontal.write(servoh);
  }
   delay(dtime); // comentário de teste

}

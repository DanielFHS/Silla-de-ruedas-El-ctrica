const int disparo = PA0;
const int eco = PA1;

// MOTOR IZQUIERDO
int IzquierdaA = PB7;
int IzquierdaB = PB8;
// MOTOR DERECHA
int derechaA = PA2;
int derechaB = PA3;

int vel=255;

int adelante = 0;
int izquierda = 0;
int derecha = 0;
//int atras = 0;

void setup()
{

// pinMode(,INPUT);// atras
pinMode(PA6,INPUT);//adelante
pinMode(PA7,INPUT);//derecha
pinMode(PA5,INPUT);//izq
Serial.begin(9600);  
  pinMode(disparo,OUTPUT);
  pinMode(eco,INPUT);
  
  digitalWrite(disparo, LOW);
 
pinMode(derechaA, OUTPUT);
pinMode(derechaB, OUTPUT);
pinMode(IzquierdaA, OUTPUT);
pinMode(IzquierdaB, OUTPUT);
Serial.begin(9600);
analogWrite(derechaA, 0);
analogWrite(derechaB, 0);
analogWrite(IzquierdaA, 0);
analogWrite(IzquierdaB, 0);
      
  
}

void loop()
{
// BLOQUE DE FUNCIONAMIETO DEL SENSOR DE ULTRASONIDO
  long tiempo;
  long distancia;
  digitalWrite(disparo, HIGH);
    delayMicroseconds(10);
  digitalWrite(disparo, LOW);
  
  
  
  tiempo=pulseIn(eco, HIGH);
  
  distancia=tiempo/59;
  
  
  
  // BLOQUE DE FUNCIONAMIENTO DEL MOTOR CON BOTONES//////////////////////////
 
  adelante = digitalRead(PA6);
  //atras = digitalRead(2);
  derecha = digitalRead(PA7);
  izquierda = digitalRead(PA5);
// parar
if (adelante==LOW  && derecha==LOW && izquierda==LOW){
analogWrite(derechaA, 0);
analogWrite(derechaB, 0);
analogWrite(IzquierdaA, 0);
analogWrite(IzquierdaB, 0);
}
//izquierda
if (adelante==LOW && derecha==LOW && izquierda==HIGH){
analogWrite(IzquierdaA, 0);
analogWrite(IzquierdaB, 0);
analogWrite(IzquierdaA, vel);
analogWrite(IzquierdaB, 0);
}
//Reversa hacia izquierda
/*if (adelante==LOW && atras==HIGH && derecha==LOW && izquierda==HIGH){
analogWrite(derechaA, 0);
analogWrite(derechaB, 0);
analogWrite(IzquierdaA, 0);
analogWrite(IzquierdaB, vel);
}*/
//derecha
if (adelante==LOW  && derecha==HIGH && izquierda==LOW){

analogWrite(derechaA, vel);
analogWrite(derechaB, 0);
analogWrite(IzquierdaA, 0);
analogWrite(IzquierdaB, 0);
}
//reversa hacia derecha
if (adelante==LOW  && derecha==HIGH && izquierda==LOW){

analogWrite(derechaA, 0);
analogWrite(derechaB, vel);
analogWrite(IzquierdaA, 0);
analogWrite(IzquierdaB, 0);
}
//adelante
if (adelante==HIGH  && derecha==LOW && izquierda==LOW){

analogWrite(derechaA, vel);
analogWrite(derechaB, 0);
analogWrite(IzquierdaA, vel);
analogWrite(IzquierdaB, 0);
}
//atras
/*if (adelante==LOW && atras==HIGH && derecha==LOW && izquierda==LOW){

analogWrite(derecha, 0);
analogWrite(derechaB, vel);
analogWrite(IzquierdaA, 0);
analogWrite(IzquierdaB, vel);
} */
    
  //bloque de funcionamiento de motor con sensor
 if(distancia<=20){
  
  analogWrite(derechaA, 0); 
  analogWrite(derechaB, 0);
  analogWrite(IzquierdaA, 0);
  analogWrite(IzquierdaB, 0);
   
  delay(1000);
  analogWrite(derechaA, 0);
  analogWrite(derechaB, vel);
  analogWrite(IzquierdaA, 0);
  analogWrite(IzquierdaB, 0);
  
   digitalWrite(disparo, HIGH);
    delayMicroseconds(10);
  digitalWrite(disparo, LOW);
  

  }
  
  else {
    
  analogWrite(derechaA, vel);
  analogWrite(derechaB, 0);
  analogWrite(IzquierdaA, vel);
  analogWrite(IzquierdaB, 0);
     
    }
}

//variaveis da led
const int vermelho = 5; 
const int verde = 6;
const int azul = 7;
//variavel do processo
const int iniciar = 2;
const int finalizar = 3;
unsigned long lastDebounceTime1 = 0;
unsigned long lastDebounceTime2 = 1; //acrescentamento da função “Time”.
const int botaoDelay = 100;

void setup()
{
  pinMode(A0, INPUT); //fotosensor (ideal +15).
  pinMode(A1, INPUT); //termometro (ideal +5).
 
  pinMode(vermelho, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
 
  Serial.begin(9600);

  Serial.println("AC1 - Meu Primeiro Projeto 2021");
  Serial.println("                           V1.0");
  Serial.println("Grupo: GAMG"); //acrescentamento do nome do grupo.
}

void loop()
{
  if((millis() - lastDebounceTime1) > botaoDelay && digitalRead(iniciar)){
  Serial.println("iniciar processo");
    ledVermelho(true);
  lastDebounceTime1 = millis();
  }
  if((millis() - lastDebounceTime1) > botaoDelay && digitalRead(finalizar)){
  Serial.println("finalizar processo");
    ledVermelho(false);
  lastDebounceTime1 = millis();
  }
 
  if(getTemperatura() >15){ //sensor de temperatura ligado/desligado.
    //troca do “> 30” por “> 15”.
    ledAzul(true);
    Serial.println("temperatura ideal");
  }else{
    ledAzul(false);
    Serial.println("temperatura não ideal!!");
  }
  if(getLuminosidade()>5){ //sensor de luminosidade ligado/desligado.
    //montagem dos comandos da LED de cor verde.
    ledVerde(true);
    Serial.println("Iluminção certa");
  }else{
    ledVerde(false);
    Serial.println("Iluminção muito escura!!");
 
  }
 
  delay(10);
}

void ledVermelho(bool estado){
  digitalWrite(vermelho,estado); //indicador vermelho.
}
void ledVerde(bool estado){
 digitalWrite(verde,estado); //indicador verde.
}
void ledAzul(bool estado){
digitalWrite(azul,estado); //indicador azul.
}
//Codigo de Temperatura completo
int getTemperatura(){
  int temperaturaC; //não modificar!
temperaturaC = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
  return temperaturaC;
}
//Codigo de Luminosidade completo
int getLuminosidade(){
  int luminosidade; //não modificar!
luminosidade = map(analogRead(A1), 6, 619, -3, 10);
  return luminosidade;
}

int botao = 4;
int verde_carro = 10;
int amarelo_carro = 11;
int vermelho_carro = 12;

int vermelho_pedestre = 9;
int verde_pedestre = 8;

int time; 

void setup() {
  Serial.begin(9600);
  pinMode(botao, INPUT);

  pinMode(verde_carro, OUTPUT);
  pinMode(amarelo_carro, OUTPUT);
  pinMode(vermelho_carro, OUTPUT);

  pinMode(vermelho_pedestre, OUTPUT);
  pinMode(verde_pedestre, OUTPUT);
  digitalWrite(vermelho_pedestre, HIGH);
  digitalWrite(verde_carro, HIGH);
}

void loop() {
  if(digitalRead(botao) == 1)
  {
    digitalWrite(verde_carro, LOW);
    digitalWrite(amarelo_carro, HIGH);
    delay(1000);

    digitalWrite(amarelo_carro, LOW);
    digitalWrite(vermelho_carro, HIGH);
    delay(1000);

    digitalWrite(vermelho_pedestre, LOW);
    digitalWrite(verde_pedestre, HIGH);
    delay(3000);

    time = millis();

    while(millis() - time < 2000)
    {
      digitalWrite(verde_pedestre, LOW);
      delay(200);
      digitalWrite(verde_pedestre, HIGH);
      delay(200);
    }
    digitalWrite(verde_pedestre, LOW);
    digitalWrite(vermelho_pedestre, HIGH);
    delay(1000);

    digitalWrite(amarelo_carro, LOW);
    digitalWrite(vermelho_carro, LOW);
    digitalWrite(verde_carro, HIGH);
  }
}

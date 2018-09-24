#define rele 2 // pino onde é conectado modulo relé
#define captacao_sensor A5 // pino onde se conecta os sinais vindos do sensor de luminosidade
#define led_vm 5 // pino do led vermelho
#define led_am 6 // pino do led amarelo
#define led_vd 7 // pino do lede verde
void setup() {
  pinMode (rele, OUTPUT); // define o pino 2 como saída
  pinMode (led_vm, OUTPUT); // define o pino 5 como saída
  pinMode (led_am, OUTPUT); // define o pino 6 como saída
  pinMode (led_vd, OUTPUT); // define o pino 7 como saída
  pinMode (captacao_sensor, INPUT);
  Serial.begin(9600); // inicia a comunicaçao serial
} 
void loop() {
  int sensor = analogRead (captacao_sensor); // cria a variavel "sensor" e a condiciona a receber os sinais advindos do sensor de luminosidade
  float valorAnalog_sensor = sensor * (5.0/ 1023.0); // modifica a leitura dos sinais advindos do sensor de luninosidade para forma de tensão
  Serial.println(valorAnalog_sensor); // printa no monitor serial os valores recebidos em "valorAnalog_sensor"
if(valorAnalog_sensor > 2.50) // se o valor de tensão recebido do sensor for maior que 2,5V, é executado o código abaixo
{
  digitalWrite (rele, LOW); // comuta o módulo relé para o acendimento da lâmpada (Obs: o modulo relé atua em nivel baixo LOW)
  digitalWrite(led_vm, HIGH); // Ascende o led vermeho
  digitalWrite(led_am, LOW); // Apaga o Led amarelo
  digitalWrite(led_vd, LOW);} //apaga o led verde
if (valorAnalog_sensor > 1.00 && valorAnalog_sensor < 2.50) // se o valor de tensão recebido do sensor estiver entre 1.01V e 2.49V, é excutado o código abaixo
{
  digitalWrite (rele, HIGH); // mantém o módulo relé inativo
  digitalWrite(led_am, HIGH); // Ascende o led Amarelo
  digitalWrite(led_vm, LOW); // Apaga o led vermelho
  digitalWrite(led_vd, LOW); // Apaga o led verde
  }
if (valorAnalog_sensor < 1.00) // se o valor de tensão recebido do sensor for menor que 1V, é executado o código abaixo
{
  digitalWrite (rele, HIGH);  // mantém o módulo relé inativo
  digitalWrite(led_vd, HIGH); // Ascende o led verde
  digitalWrite(led_vm, LOW); // Apaga o led vermelho
  digitalWrite(led_am, LOW); // Apaga o led amarelo
}
} 
 

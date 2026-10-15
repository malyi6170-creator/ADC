// Определяем пин, к которому подключен датчик или потенциометр
const int SENSOR_PIN = A0;

// Опорное напряжение микроконтроллера (в вольтах)
const float V_REF = 5.0;

// Максимальное значение для 10-битного АЦП (2^10 - 1 = 1023)
const int ADC_MAX = 1023;

void setup() {
  // Инициализируем Serial-порт для вывода информации в монитор
  Serial.begin(9600);
  
  // Небольшая запускная пауза
  delay(1000);
  Serial.println("Система инициализирована. Чтение АЦП запущено...");
}

void loop() {
  // 1. Читаем "сырые" отсчеты АЦП (число от 0 до 1023)
  int adcValue = analogRead(SENSOR_PIN);

  // 2. Переводим отсчеты в напряжение по формуле
  float voltage = (adcValue * V_REF) / ADC_MAX;

  // 3. Выводим результаты в Serial Monitor
  Serial.print("Отсчеты (ADC): ");
  Serial.print(adcValue);
  Serial.print("\t|\tНапряжение: ");
  Serial.print(voltage, 3); // Выводим с тремя знаками после запятой
  Serial.println(" В");

  // Делаем задержку полсекунды для удобства чтения
  delay(500);
}

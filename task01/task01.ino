//Вариант 400 мс 150 мс  100 мс  250 мкс 35 мкс

struct diode
{
  int pin;
  int status;
  unsigned long previousTime;
  unsigned long interval;
};

const int diodeCount = 5;
struct diode diodes[] = {
  2, LOW, 0, 400000,
  3, LOW, 0, 150000,
  4, LOW, 0, 100000,
  5, LOW, 0, 250,
  6, LOW, 0, 35
};


void setup() {
  for (int a = 0; a < diodeCount; a++)
  {
    pinMode(diodes[a].pin, OUTPUT);
  }
}

void loop()
{
  unsigned long time = micros();

  for (int a = 0; a < diodeCount; a++)
  {
    if (time - diodes[a].previousTime > diodes[a].interval)
    {
      diodes[a].previousTime = time;

      if (diodes[a].status == LOW)
        diodes[a].status = HIGH;
      else
        diodes[a].status = LOW;

      digitalWrite(diodes[a].pin, diodes[a].status);
    }
  }
}

// ��������ı䡣��������pin��:
const int ledPin =  LED_BUILTIN;// LED�ܽű��

// ������ı�:
int ledState = LOW;             // ��������led��led״̬

// ͨ�������ڱ���ʱ��ı�����Ӧ��ʹ���޷���long 
// ֵ�ܿ�ͻ���̫���޷��洢int
unsigned long previousMillis = 0;        // ���洢�ϴθ���led��ʱ��

// �������� :
const long interval = 1000;           // ��˸��������룩

void setup() {
  // �����ֹܽ�����Ϊ���:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // ����������Է�����Ҫһֱ���еĴ���.

  // ���led�Ƿ���˸��Ҳ����˵����� 
  // ��ǰʱ�����ϴ���˸ʱ��֮��Ĳ��� 
  // led������ϣ���ļ��
  // ʹLED��˸ .
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // �����ϴ���˸led��ʱ��
    previousMillis = currentMillis;

    // ���LEDϨ������򿪣���֮��Ȼ :
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // �ñ�����ledState����LED:
    digitalWrite(ledPin, ledState);
  }
}
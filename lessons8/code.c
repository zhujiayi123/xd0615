// 常数不会改变。用于设置pin码:
const int ledPin =  LED_BUILTIN;// LED管脚编号

// 变量会改变:
int ledState = LOW;             // 用于设置led的led状态

// 通常，对于保持时间的变量，应该使用无符号long 
// 值很快就会变得太大，无法存储int
unsigned long previousMillis = 0;        // 将存储上次更新led的时间

// 常数不变 :
const long interval = 1000;           // 闪烁间隔（毫秒）

void setup() {
  // 将数字管脚设置为输出:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // 在这里你可以放置需要一直运行的代码.

  // 检查led是否闪烁；也就是说，如果 
  // 当前时间与上次闪烁时间之间的差异 
  // led大于您希望的间隔
  // 使LED闪烁 .
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // 保存上次闪烁led的时间
    previousMillis = currentMillis;

    // 如果LED熄灭，则将其打开，反之亦然 :
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // 用变量的ledState设置LED:
    digitalWrite(ledPin, ledState);
  }
}
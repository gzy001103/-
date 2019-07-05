//定义莫尔斯电码表
char MORSE[][4] = {
  {'.', '-', '*', '*'}, //A
  {'-', '.', '.', '.'}, //B
  {'-', '.', '-', '.'}, //C
  {'-', '.', '.', '*'}, //D
  {'.', '*', '*', '*'}, //E
  {'.', '.', '-', '.'}, //F
  {'-', '-', '.', '*'}, //G
  {'.', '.', '.', '.'}, //H
  {'.', '.', '*', '*'}, //I
  {'.', '-', '-', '-'}, //J
  {'-', '.', '-', '*'}, //K
  {'.', '-', '.', '.'}, //L
  {'-', '-', '*', '*'}, //M
  {'-', '.', '*', '*'}, //N
  {'-', '-', '-', '*'}, //O
  {'.', '-', '-', '.'}, //P
  {'-', '-', '.', '-'}, //Q
  {'.', '-', '.', '*'}, //R
  {'.', '.', '.', '*'}, //S
  {'-', '*', '*', '*'}, //T
  {'.', '.', '-', '*'}, //U
  {'.', '.', '.', '-'}, //V
  {'.', '-', '-', '*'}, //W
  {'-', '.', '.', '-'}, //X
  {'-', '.', '-', '-'}, //Y
  {'-', '-', '.', '.'}  //Z
};

void setup() {
  Serial.begin(9600);//设置通信波特率
}

void morse.dot()
{
  digitalWrite(pin, HIGH);
  delay(250);
  digitalWrite(pin, LOW);
  delay(250);
}
void morse.dash()
{
  digitalWrite(pin, HIGH);
  delay(1000);
  digitalWrite(pin, LOW);
  delay(250);
}
void morse.w_space()
{
  delay(3000)
}

void loop() {
  String str = "";  //定义未转义字符串
  String morse = "";  //定义转义后字符串
  int i, t, temp = 0;
  int n = 0;  //对传入字符个数计数
  while (Serial.available() > 0) {
    temp = 1;  //判断是否有数据传入
    str += char(Serial.read());  //将传入的数据储存在字符串中
    delay(2);  //延迟保证传入正常
    n=n+1;
  }

  if (temp) {
    //查询Morse电码表并进行转换
    for (i = 0; i < n; i++)
    {
      for (t = 0; t < 4; t++)
      {
        //判断是否为小写字母，如果是则转义
        if (str[i] >= 'a' && str[i] <= 'z')
        {
          morse =morse+ char(MORSE[int(str[i] - 97)][t]);
        }
      }
      //每段Morse之后补空格
      morse =morse+ ' ';
    }
    Serial.println(morse_s);  //串口传入
    for (i = 0; morse_s[i] != '\0'; i++)//从头到尾读取莫尔斯电码
    {
      if (morse_s[i] == '.')morse.dot();
      else if (morse_s[i] == '*')morse.dash();
      else if (morse_s[i] == ' ')morse.w_space();
    }   
    delay(2);
  }

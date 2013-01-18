const String numbers[][10] = {
   {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"},
   {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"},
   {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"}
};

const int braille[][6] = {
   {1, 0, 0, 0, 0, 0}, {1, 0, 1, 0, 0, 0},
   {1, 1, 0, 0, 0, 0}, {1, 1, 0, 1, 0, 0},
   {1, 0, 0, 1, 0, 0}, {1, 1, 1, 0, 0, 0},
   {1, 1, 1, 1, 0, 0}, {1, 0, 1, 1, 0, 0},
   {0, 1, 1, 0, 0, 0}, {0, 1, 1, 1, 0, 0},
   {1, 0, 0, 0, 1, 0}, {1, 0, 1, 0, 1, 0},
   {1, 1, 0, 0, 1, 0}, {1, 1, 0, 1, 1, 0},
   {1, 0, 0, 1, 1, 0}, {1, 1, 1, 0, 1, 0},
   {1, 1, 1, 1, 1, 0}, {1, 0, 1, 1, 1, 0},
   {0, 1, 1, 0, 1, 0}, {0, 1, 1, 1, 1, 0},
   {1, 0, 0, 0, 1, 1}, {1, 0, 1, 0, 1, 1},
   {0, 1, 1, 1, 0, 1}, {1, 1, 0, 0, 1, 1},
   {1, 1, 0, 1, 1, 1}, {1, 0, 0, 1, 1, 1},
   {0, 0, 0, 0, 0, 0}
};

void setup(){
  for (int i = 1; i <= 7; i++)
    pinMode(i, INPUT);
  for (int i = 8; i <= 13; i++)
    pinMode(i, OUTPUT);
}

void loop(){
  if (digitalRead(13) == HIGH){
    int d = getDecimalInput();
    String s = toString(d);
    outputBraille(s);
    clean();
  }
}

int getDecimalInput() {
   int decimal = 0;
   for (int i = 0; i < 6; i++){
     if (digitalRead(i + 1) == HIGH)
       decimal += pow(2, 5 - i);
   }
   return decimal;
}

String toString(int d) {
   int ones = d % 10;
   int tens = (d - ones) / 10;
   if (tens < 2)
      return numbers[tens][ones];
   else {
      if (ones == 0)
         return numbers[2][tens];
      else
         return numbers[2][tens] + " " + numbers[0][ones];
   }
}

void outputBraille(String s){
  for (int i = 0; i < s.length(); i++){
    int index = getCharIndex(s[i]);
    for (int j = 0; j < 6; j++){
      if (braille[index][j])
        digitalWrite(j + 8, HIGH);
      else
        digitalWrite(j + 8, LOW);
    }
    delay(2000);
  }
}

void clean(){
  for (int i = 8; i <= 13; i++)
    digitalWrite(i, HIGH);
  delay(50);
  for (int i = 8; i <= 13; i++)
    digitalWrite(i, LOW);
}

int getCharIndex(char c){
   switch(c){
      case 'a': return 0; break;
      case 'b': return 1; break;
      case 'c': return 2; break;
      case 'd': return 3; break;
      case 'e': return 4; break;
      case 'f': return 5; break;
      case 'g': return 6; break;
      case 'h': return 7; break;
      case 'i': return 8; break;
      case 'j': return 9; break;
      case 'k': return 10; break;
      case 'l': return 11; break;
      case 'm': return 12; break;
      case 'n': return 13; break;
      case 'o': return 14; break;
      case 'p': return 15; break;
      case 'q': return 16; break;
      case 'r': return 17; break;
      case 's': return 18; break;
      case 't': return 19; break;
      case 'u': return 20; break;
      case 'v': return 21; break;
      case 'w': return 22; break;
      case 'x': return 23; break;
      case 'y': return 24; break;
      case 'z': return 25; break;
      case ' ': return 26;
   }
}


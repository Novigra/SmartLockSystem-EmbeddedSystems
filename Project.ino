#include <LiquidCrystal.h>
#include <Keypad.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

const int BuzzerPin = 13;

const byte Rows = 4;
const byte Cols = 3;

char Keys[Rows][Cols] = { {'1', '2', '3'},
                          {'4', '5', '6'},
                          {'7', '8', '9'},
                          {'*', '0', '#'} };

char Hit;
char MachinePass[5] = {'1', '2', '3', '4', '\0'};
char UserPass[5];
int i = 0;

byte RowPins[Rows] = {11, 10, 9, 8};
byte ColsPins[Cols] = {12, A1, A0};

Keypad MyKeypad = Keypad(makeKeymap(Keys), RowPins, ColsPins, Rows, Cols);

enum Mode
{
  EnterPass,
  UpdatePass
};

Mode mode;

void setup() {
  lcd.begin(16, 2);

  lcd.setCursor(0, 0);
  lcd.print("CODE:");

  mode = EnterPass;

  pinMode(BuzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Hit = MyKeypad.getKey();

  // Change Input Mode
  if((Hit == '#') && (i == 0))
  {
    ChangeMode();
  }
  
  // Shows the current saved password
  lcd.setCursor(5, 0);
  for(int j = 0; j < strlen(MachinePass); j++)
  {
    lcd.print(MachinePass[j]);

    Serial.print(MachinePass[j]);
  }
  Serial.println(" ");
  
  // Enter Password
  lcd.setCursor(0, 1);
  if(Hit && (Hit != '#') && (i != 4))
  {
    EnterPassword();
  }
  else if (i == 4)
  {
    if(mode == EnterPass)
    {
      CheckResult();
    }
    else
    {
      UpdatePassword();
    }
  }
}

// Change whether the user want to enter the password or update it
void ChangeMode()
{
  if(mode == EnterPass)
  {
    mode = UpdatePass;

    lcd.setCursor(0, 1);
    lcd.print("Update Mode");
    delay(1000);

    lcd.setCursor(0, 1);
    lcd.print("             ");
  }
  else
  {
    mode = EnterPass;

    lcd.setCursor(0, 1);
    lcd.print("Enter Mode");
    delay(1000);

    lcd.setCursor(0, 1);
    lcd.print("             ");
  }
}

void EnterPassword()
{
  UserPass[i] += Hit;
    i++;

    for(int j = 0; j < i; j++)
    {
      lcd.print(UserPass[j]);
    }
}

void CheckResult()
{
  UserPass[i] = '\0';
  if(!strcmp(MachinePass, UserPass))
  {
    lcd.print("Pass Is Right");
    Serial.println("SOMEONE ENTERED THE HOUSE");

    tone(BuzzerPin, 1500);
    delay(100);

    noTone(BuzzerPin);
    delay(50);

    tone(BuzzerPin, 1500);
    delay(100);

    noTone(BuzzerPin);
  }
  else
  {
    lcd.print("Pass Is Wrong");
    Serial.println("SOMEONE ENTERED THE WRONG PASSWORD");

    tone(BuzzerPin, 1500);
    delay(300);

    noTone(BuzzerPin);
    delay(50);

    tone(BuzzerPin, 1500);
    delay(300);

    noTone(BuzzerPin);
  }

  i = 0;
  memset(UserPass, '\0', sizeof(UserPass));

  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print("             ");
}

void UpdatePassword()
{
  memset(MachinePass, '\0', sizeof(MachinePass));

  for(int j = 0; j < strlen(UserPass); j++)
  {
    MachinePass[j] = UserPass[j];
  }

  lcd.setCursor(5, 0);
  lcd.print("    ");

  lcd.setCursor(0, 1);
  lcd.print("PASSWORD UPDATED");

  // notify the owner
  Serial.println("PASSWORD GOT UPDATED");

  i = 0;
  memset(UserPass, '\0', sizeof(UserPass));

  tone(BuzzerPin, 2000);
    delay(300);

    noTone(BuzzerPin);
    delay(50);

    tone(BuzzerPin, 1500);
    delay(300);

    noTone(BuzzerPin);

  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print("                ");
}
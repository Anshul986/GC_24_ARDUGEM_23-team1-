#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>
#include <Adafruit_ILI9341.h>


#define TFT_CS 10
#define TFT_RST 8
#define TFT_DC 9




// Joy stick
#define start_button 7
#define left_button 5
#define right_button 3
#define restart_button 6
#define X_pin A0
#define Y_pin A1




int points = 0;
int highScore = 0;
int height = 0;
int blockhits = 0;

int start = 0;

unsigned long restart_lastButtonPress = 0;
unsigned long left_lastButtonPress = 0;
unsigned long right_lastButtonPress = 0;
unsigned long start_lastButtonPress = 0;

unsigned long prevToggle = 0;


uint16_t color = ST7735_BLUE;
uint16_t ballColor = ST7735_WHITE;


int xPosition = 0;
int yPosition = 0;



bool endGame = false;

int WIDTH = 128;
int HEIGHT = 160;

int ballX = WIDTH / 2;
int ballY = HEIGHT / 2 - 40;

int blockX;
int blockY;

int ballSpeedX = 5;
int ballSpeedY = 7;

int currentPosition;
int prevPos;

int xBar;
int yBar;

int proximityX; // closeness of ball and block calculated
int proximityY;






Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

uint16_t colors[8] = { 0xFFFF, 0xF800, 0x07E0, 0xFFA5, 0x07FF, 0xF81F, 0xFFE0, 0xFC00 };


void setup() {

  pinMode(left_button, INPUT);
  pinMode(right_button, INPUT);
  pinMode(restart_button, INPUT);
  pinMode(start_button, INPUT);

  digitalWrite(left_button, HIGH);
  digitalWrite(right_button, HIGH);
  digitalWrite(restart_button, HIGH);
  digitalWrite(start_button, HIGH);


  tft.initR(INITR_BLACKTAB);
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextWrap(false);






  xBar = (WIDTH / 2) - 20; //initial position
  yBar = 130;



  prevPos = analogRead(X_pin);
}

int absolute(int num1, int num2) {
  int diff = num1 - num2;
  if (diff < 0) {
    diff *= -1;
    return diff;
  } else {
    return diff;
  }
}

void loop() {

  if (start == 0) { // start screen
    tft.setCursor(40, 40);
    tft.setTextSize(3);
    tft.setTextColor(0xFFFF);
    tft.println("HIT");
    tft.setCursor(30, 70);
    tft.println("PONG!");
    tft.setCursor(20, 100);
    tft.setTextSize(1);
    tft.print("Press F to Start");

    int start_btnState = digitalRead(start_button);

    if (start_btnState == LOW) {

      start = 1;
    }
  }


  else if (!endGame) {// main game screen

    tft.fillRect(0, 0, 200, 200, ILI9341_BLACK);

    joyStickControl();
    collisions();
    scoreBoard();
    blockY += blockhits + 1;  // block speed increment for each blockhit
    delay(10);
  } else {
    delay(10);
    textScreen();
    int btnState = digitalRead(restart_button);
    if (btnState == LOW) {
      if (millis() - restart_lastButtonPress > 1) {
        ballX = WIDTH / 2;
        ballY = HEIGHT / 2 - 40;
        xBar = (WIDTH / 2) - 20;
        yBar = 130;
        endGame = false;

        //Falling Block
        blockX = random(0, 113);  // Set block X position
        blockY = 0;               // Set block Y position


        if (points > highScore) {
          highScore = points;
        }
        points = 0;
        blockhits = 0;
      }
      restart_lastButtonPress = millis();
    }
  }
}

void scoreBoard() {
  tft.setCursor(10, 10);
  tft.setTextSize(1.5);
  tft.setTextColor(ST77XX_YELLOW);
  tft.println("Score: ");
  tft.setCursor(60, 10);
  tft.print(points);

  tft.setCursor(10, 20);
  tft.setTextSize(1.5);
  tft.setTextColor(ST77XX_YELLOW);
  tft.println("High Score: ");
  tft.setCursor(80, 20);
  tft.print(highScore);
  delay(100);
}

void textScreen() {
  tft.setCursor(30, 40);
  tft.setTextSize(3);
  tft.setTextColor(0x0000);
  tft.println("GAME");
  tft.setCursor(30, 70);
  tft.print("OVER");
  tft.setCursor(10, 100);
  tft.setTextSize(1);
  tft.print("Press E to Restart");
  delay(500);

  tft.setTextSize(3);
  tft.setCursor(30, 40);
  tft.setTextColor(ST77XX_BLUE);
  tft.println("GAME");
  tft.setCursor(30, 70);
  tft.print("OVER");
  tft.setCursor(10, 100);
  tft.setTextSize(1);
  tft.print("Press E to Restart");
  delay(500);
}

void joyStickControl() {
  int xPosition = analogRead(X_pin);
  int yPosition = analogRead(Y_pin);

  tft.fillCircle(ballX, ballY, 5, ballColor);
  tft.fillRect(blockX, blockY, 14, 14, color);



  if (millis() - prevToggle > 1) {

    currentPosition = xPosition;

    if (currentPosition > 400) {
      xBar += 10;
    }

    if (currentPosition < 200) {
      xBar -= 10;
    }

    if (xBar < 0) {
      xBar = 0;
    }

    if (xBar + 40 > WIDTH) {
      xBar = WIDTH - 40;
    }

    prevPos = currentPosition;
  }

  prevToggle = millis();

  int btnState = digitalRead(restart_button);
  int left_btnState = digitalRead(left_button);
  int right_btnState = digitalRead(right_button);


  if (btnState == LOW) {
    if (millis() - restart_lastButtonPress > 50) {
      int rand = random(8);
      color = colors[rand];
    }

    restart_lastButtonPress = millis();
  }


  if (left_btnState == LOW) {  //  &&

    if (millis() - left_lastButtonPress > 40) {  //
      ballX -= 10;
    }

    left_lastButtonPress = millis();
  }

  if (right_btnState == LOW) {  //&& (ballX >= WIDTH)
    if (millis() - left_lastButtonPress > 40) {
      ballX += 10;
    }

    right_lastButtonPress = millis();
  }

  tft.fillRect(xBar, yBar - 5, 40, 5, color);
}


void collisions() {
  ballX += ballSpeedX;
  ballY += ballSpeedY;

  proximityX = absolute(ballX, (blockX + 7));
  proximityY = absolute(ballY, (blockY + 7));


  if ((proximityX <= 13) && (proximityY <= 13)) {
    blockX = random(0, 113);
    blockY = 0;
    blockhits += 1;
    points += 5;
  }

  if (ballX >= WIDTH || ballX - 10 <= 0) {
    ballSpeedX *= -1;

    if (ballSpeedX > 0) {
      ballX += 3;
    } else {
      ballX -= 3;
    }
  }

  if ((ballY >= HEIGHT - 30) || (blockY > HEIGHT - 20) || (ballX >= WIDTH + 10 || ballX + 10 <= 0)) {
    endGame = true;
  }

  if (ballY <= 10) {
    ballSpeedY *= -1;
    ballY += 3;
  }

  if (ballX >= xBar && ballX <= xBar + 40) {
    if (ballY >= yBar - 14) {

      ballColor = colors[random(8)];
      points++;

      ballSpeedX *= -1;
      ballSpeedY = -7;

      ballSpeedX += 1;
      ballSpeedY += 1;

    } else {
      ballColor = ST7735_WHITE;
    }
  }
}

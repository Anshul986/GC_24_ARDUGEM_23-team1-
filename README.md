# GC_24_ARDUGEM_
GitHub Repository Name: GC_24_ARDUGEM_23(team1)

# BLOCK-PONG
Block-Pong is a dynamic game where players control a Bar at the bottom of the screen to bounce a ball. The objective is to break as many blocks as possible by hitting them with the ball while preventing the ball from falling off the bottom of the screen. Each block broken adds points to the player's score, and the game becomes progressively more challenging as the blocks regenerate or new blocks are introduced.

## Features:

- Control the Bar's right and left movements using Joystick to bounce a ball.
- Break blocks randomly generated in space with the ball.
- Score increases with each block broken.
- Your current score along with the Highest made score will be displayed over the screen.

## Hardware Requirements:

- Arduino Uno or compatible board
- TFT LCD Display
- Joystick or buttons for paddle control
- Wires and breadboard for connections


**Concept:**
 In this game, you control a paddle at the bottom of the screen to bounce a ball and hit the randomly generated blocks in space. Each hit to a block increases your score by +5 while each hit by the paddle increases your score by +1. If the ball fall off the bottom of the screen the game will be over.
Let's dive into the details!


**Mechanics:**
1. **Bar:** The Bar is controlled by the player using a joystick. It moves horizontally along the bottom of the screen to intercept the ball and prevent it from falling.
2. **Ball:** The ball moves in a trajectory determined by its direction of impact with the Bar,side or upper screen. When the ball collides with a block, it breaks the block while following its same trajectory.
3. **Blocks:** Block is randomly generated throughout the game area one by one. When hit by the ball, blocks are destroyed,contributing to the player's score & instantly a new block pop somewhere within the game area. 
4. **Score:** The player's score increases with each block broken by +5. While each bounce by bar increases sccore by +1. Objective is to achieve the highest score possible before losing.
5. **Lives:** The player 1 total life. Losing it, when the ball falls off the bottom of the screen without being intercepted by the Bar. The game ends.
   
**Control Scheme:**(Instructions for setting up the gameplay)
- **Launch:** To start the game, the player launches the ball by pressing           button.
- **Movement:** The Bar is moved horizontally using a joystick . Moving the joystick right or left adjusts the position of the Bar accordingly.
- **Restart:** Once the game is over,players have the option to restart the game by pressing a restart button.

Overall, Block-Pong offers engaging gameplay with intuitive controls, challenging mechanics, and endless opportunities for players to test their skills and achieve high scores.


## Installation:

1. Clone this repository to your local machine:

2. Open the Arduino IDE and navigate to File > Open. Select the `Arduino_Paddle_Breakout_Game.ino` file from the cloned repository.

3. Connect your Arduino board and TFT LCD display to your computer.

4. Upload the provided sketch to the Arduino board.

5. Enjoy playing the game on the TFT LCD display!
   



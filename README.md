# GC_24_ARDUGEM_23(team1)
GitHub Repository Name: GC_24_ARDUGEM_23(team1)


# BLOCK-PONG
Block-Pong is a dynamic game where the player controls a Bar at the bottom of the screen to bounce a ball. The objective is to break as many blocks as possible by hitting them with the ball while preventing the ball or block from falling off the bottom of the screen. Each block broken adds points to the player's score, and the game becomes progressively more challenging as the blocks regenerate or new blocks are introduced.


## Hardware Used:
- 1x Arduino Uno
- 1x 1.44 inch TFT LCD display
- 1x JoyStick Shield Module
- 1x Breadboard and jumper wires
- USB 2.0 Cable Type A/B.


# Concept:
 In this game, you control the Bar at the bottom of the screen to bounce a ball and hit the continuously falling block in space. Each hit to a block increases your score by +5 while each bounce given to the ball by the Bar increases your score by +1. While playing the game take care of following-:
- If the ball falls off the bottom of the screen, the game ends.
- If any of the blocks falls off the bottom of the screen, the game ends.
- If the ball is being forcibly crossed the left or right screen boundary by the player, the game ends.
  
Let's dive into the details!


## Features:
- Control the Bar's right and left movements using Joystick to bounce a ball.
- Control the Ball"s right and left movements using buttons "D" & "B" respectively.
- Break blocks randomly generated in space with the ball.
- Score increases with each block broken.
- Your current score along with the Highest made score will be displayed over the screen.


  
# Mechanics:
1. **Bar:** The Bar is controlled by the player using a joystick. It moves horizontally along the bottom of the screen to intercept the ball and prevent it from falling.
2. **Ball:** The ball moves in a trajectory determined by its direction of impact with the Bar,side screen or upper screen. When the ball collides with a block, it breaks the block later on follows its same trajectory.Also the Ball can shifted a little left & right using "D" & "B" buttons respectively.
3. **Blocks:** Block is randomly falling from the top of the screen one by one. When hit by the ball, blocks are destroyed,contributing to the player's score & instantly a new block appear & start falling from the top of the screen. 
4. **Score:** The player's score increases with each block broken by +5. While each bounce given to ball by bar increases sccore by +1. Objective is to achieve the highest score possible before losing.
5. **Screen boundry:** Generally side & top screen boundry reflects the ball when hited, But if the ball crosses the side screen boundary by the player's intervention through "D" or "E" button, the game ends.
6. **Lives:** The player has 1 total life. Losing it, when the ball falls off the bottom of the screen without being intercepted by the Bar. The game ends.While once the game is over, the player can restart the game by pressing "E" button.

   
# Control Scheme(Instructions for setting up the gameplay):
- **Launch:** To start the game, the player launches the ball by pressing "E"  button.
- **Movement of Bar:** The Bar is moved horizontally using a joystick . Moving the joystick left & right adjusts the position of the Bar accordingly.
- **Movement of Ball:** The Ball is moved horizontally using buttons "D" & "B" moves the ball left & right accordingly.
- **Restart:** Once the game is over, players have the option to restart the game by pressing "E" button.
- **Colour:** During the game the bar's & Block's can be changed by pressing using "E" button.

 
## Installation:
1. Clone this repository to your local machine.
2. Open the Arduino IDE and navigate to File > Open. Select the `GC_24_ARDUGEM_23-team1-.ino` file from the cloned repository.
3. Connect your Arduino board & the provided setup to your computer using a USB 2.0 cable TypeA/B.
4. Upload the provided sketch to the Arduino board.
5. Enjoy playing the game on the TFT LCD display.
   

Overall, Block-Pong offers engaging gameplay with intuitive controls, challenging mechanics, and endless opportunities for players to test their skills and achieve high scores.

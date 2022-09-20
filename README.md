# FINAL PROJECT: Battleship

## Team Members
- Sharon Zou, Period 4
- William Lin, Period 4

## Description of the Project
For our final project, we decided to recreate the game Battleship. Battleship is a strategic guessing game between two players. It is played on two 10 by 10 grids. Each player begins the game by marking the positions they want their fleets to be. These positions are concealed from the other player, who will take a guess and choose a position to shoot at. Depending on whether the player guesses correctly or not, the board will correspondingly display a symbol in the position they shot at. The objective of the game is to destroy all of the opponent's fleet.

## Description of User Interface
Since battleship is a two-player game, the game will begin once both players connect. First, each player will input their names. Then, they will be able to choose the positions at which they would like to store their ships for the game. Once both players have finished placing their ships, the first player to have connected will start off the attack. His/her board will be displayed on the left (with their own ships displayed), while the opponent's board will be displayed on the right (with the ships hidden). The status of each player's ships will be displayed respectively below. For each turn, the game will prompt them to enter the x and y coordinates of the position they choose to attack next.

## Description of Technical Design
- Allocating memory: At the beginning of the game, memory is allocated to remember the names of the players and the position of their ships.
- Signals: When a player makes an error in entering their names or in the placement of their ships, messages are returned accordingly.
- Shared memory: Attempted to use this to share information between the two players, but it was simpler to send all the information through networking
- Networking: The two players rely on networking to communicate about board and ship statuses.
- Files: Attempted to use files and write to them to store information about the status of boards and ships.

## Bugs
These are some errors that are we were not able to fix:
- PlaceShips: At certain locations (mostly when it's close to the outer edge of the board), the game will print that there is another ship in the same position depite there not being any other ship. Additionally, the x-coordinate doesn't seem to be checking for valid inputs. 
- Targeting ships: If no integer is inputted (ex: you just press enter at the prompt), it will take in a 0.
- Undesired input: If it's not the player's turn but they accidentally input something, this will be taken into the next input. (ex: they enter 5; when it's their turn, the game will immediately take in 5 as their x-coord input).
- Ending game: game ends after client goes (player two), even if server (player one) wins.

## Instructions
- Ideally, the game should work by following these instructions:
```
 $ git clone git@github.com:szou00/final_project.git
 $ cd final_project/networking
 $ make
```
- In one terminal, type in `./server` to launch Player One.
- In a second terminal within the same folder, type in `./client` to launch Player Two

# Battleship

## Team Members
- Sharon Zou, Period 4
- William Lin, Period 4

## Description of Project
For our final project, we plan to create the game Battleship. Battleship is a strategic guessing game for two players. It is played on a 10 by 10 grid on which each player’s fleet of ships is marked. These locations are concealed from the other player. Players will then take turns shooting at different spots, and the first to destroy the other fleet is the winner.

## User Interface
<b> START </b>
- Ask players to enter their names
- Store names in a 2-d array with a character limit of 20 for each name

<b> MAP </b>
- Use a matrix to correspond to coordinates

<b> SHIPS </b>
- Each player has 5 ships
- Carrier (5 slots)
- Battleship (4 slots)
- Cruiser (3 slots)
- Submarine (3 slots)
- Destroyer (2 slots)
- Select a ship to place (click or key; will be decided later on)
- Either click (if possible) or enter coordinates to determine the placement of each ship (twice for front and end)
- Extra: add a 90 second timer that randomly places ships if not all ships are placed when 90 seconds are up

<b> GAMEPLAY </b>
- Each player gets 60 seconds to guess a coordinate
- If a player does not guess before 60 seconds, either end turn immediately or a random coordinate is chosen
- Once either player loses all their ships, the game ends

## Technical Design
- Allocating memory: At the beginning of the game, memory will be allocated to remember the names of the players and the position of their ships. These positions will be copied over to two corresponding files.
- Finding information about files (stat and such): The program will use information about the files to check the number of ships that are destroyed/still standing
- Signals: if a player makes an error in entering their names or in the placement of their ships, return messages accordingly
- Not yet sure if these will be used:
- Shared memory: used to store the state of the board state/position of ships <- this will mostly be utilized instead of files to have faster gameplay
- Semaphores: used to control access to the shared memory
- Working with files: Two files will be created at the beginning of the game. One file will contain the locations of Player 1’s ships, and one file will contain the locations of Player 2’s ships. When a ship is struck down, the file will be modified to mark the change. These will be read from at the beginning of each turn, and the grid will be printed out on the screen accordingly.  
Processes (fork, exec, etc.), Pipes (named and unnamed), Networking.

General types of functions we will be implementing:
- welcomeScreen()
- initializeGame()
- printBoard()
- putShip()

## Timeline
<b> January 9th </b>
- <i> William </i>: Figure out how to network/share between computers
- <i> Sharon </i>: Set up the game: create a welcome screen that will print out rules and instructions to the user, create different ships etc.

<b> January 9th </b>
- <i> William </i>: Create the different types of ships and display them on the board.
- <i> Sharon </i>: Figure out how to display the game in SDL or some other visual format. Write the code for players to use the coordinates of the mouse to choose where they want their ships to be. Print out the results.

<b> January 10th </b>
- <i> William </i>: Add in code for random placement of ships if the player exceeds a certain time in choosing manually choosing where to place the ships

<b> January 12th </b>
-  <i> Sharon </i>: Implement switching turns between players? The screen should display the results, and then shift back to the user’s own screen

<b> January 15th </b>
- <i> Sharon </i>: Debug.
- <i> William </i>: End of game screen.

<b> January 17th </b>
- <i> Sharon + William </i>: Debug.

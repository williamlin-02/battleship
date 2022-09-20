#include "networking.h"
#include "game.h"

void process(char *s);
void subserver(int from_client);
void readBoard(Cell Board[ROWS][COLS], char buffer[256], int socket);
void sendBoard(Cell Board[ROWS][COLS], char buffer[256], int socket);
void printGame(Cell me[ROWS][COLS], Cell opp[ROWS][COLS]);

int main() {

  int listen_socket;
  int f;
  listen_socket = server_setup();

  printf("Waiting for Player Two to connect...\n");
  int client_socket = server_connect(listen_socket);
  printf("Player Two has connected! Now starting the game. \n");
  sleep(2);
  system("clear");
  printWelcome();

  /**initialize name for player one**/
  char *playerOneName;
  char *playerTwoName;
  char buf[20];
  printf("Enter your name: ");
  fgets(buf, 20, stdin);
  buf[strcspn(buf, "\n")] = 0;
  playerOneName = (char*)malloc(sizeof(buf));
  playerTwoName = (char*)malloc(sizeof(char));
  playerOneName = buf;
  system("clear");
  printf("Hey %s! Let's get started. Choose where you would like your ships to be: \n\n", playerOneName);
  /**/

  // Create the game boards for both players
  Cell playerOne[ROWS][COLS];       /* Player one game board */
  Cell playerTwo[ROWS][COLS];       /* Player two game board */

  // Create ships
  Ship ship1[NUM_SHIPS] = {{'c', 5},
                         {'b', 4},
                         {'r', 3},
                         {'s', 3},
                         {'d', 2}};

  Ship ship2[NUM_SHIPS] = {{'c', 5}, {'b', 4}, {'r', 3}, {'s', 3}, {'d', 2}};

  // printWelcome();
  initializeBoard(playerOne);
  initializeBoard(playerTwo);

  placeShips(playerOne, ship1);


  char buffer[BUFFER_SIZE];

  Cell temp[ROWS][COLS];
  // readBoard(playerTwo, buffer, client_socket);
  read(client_socket, playerTwo, sizeof(playerTwo));
  write(client_socket, playerOne, sizeof(playerOne));

  read(client_socket, ship2, sizeof(ship2));
  write(client_socket, ship1, sizeof(ship1));

  read(client_socket, playerTwoName, sizeof(playerTwoName));
  write(client_socket, playerOneName, sizeof(playerOneName));
  // printf("You are: %s\n", playerOneName.getName);
  // printf("Your opponent is: %s\n", playerTwoName.getName);

  // printf("TESTING: %c\n\n", playerTwo[2][3].shipSymbol);
  // sendBoard(playerTwo, buffer, client_socket);
  printGame(playerOne, playerTwo);
  printf("Your opponent is %s!\n", playerTwoName);
  printf("Waiting for %s...\n", playerTwoName);

  printf("Both players are ready! Game is starting...\n\n");
  sleep(3);

  while (!PlayerWins(ship1) && !(PlayerWins(ship2))) {

    system("clear");
    printGame(playerOne, playerTwo);
    printShips(ship1, ship2);
    hit(playerTwo, ship2);
    sleep(1);
    system("clear");
    printGame(playerOne, playerTwo);
    printShips(ship1, ship2);
    write(client_socket, playerTwo, sizeof(playerTwo));
    write(client_socket, ship2, sizeof(ship2));
    read(client_socket, playerOne, sizeof(playerOne));
    read(client_socket, ship1, sizeof(ship1));
  }
  if (PlayerWins(ship1)) {
    printGoodbye();
    printf("%s won :( Better luck next time!\n\n\n", playerTwoName);
  }
  else {
    printGoodbye();
    printf("AWESOME, you won!\n\n\n");
  }
  close(client_socket);
  exit(0);
}

// void subserver(int client_socket) {
//   char buffer[BUFFER_SIZE];
//
//   while (read(client_socket, buffer, sizeof(buffer))) {
//
//     printf("[subserver %d] received: [%s]\n", getpid(), buffer);
//     process(buffer);
//     write(client_socket, buffer, sizeof(buffer));
//   }//end read loop
//   close(client_socket);
//   exit(0);
// }

void process(char * s) {
  while (*s) {
    if (*s >= 'a' && *s <= 'z')
      *s = ((*s - 'a') + 13) % 26 + 'a';
    else  if (*s >= 'A' && *s <= 'Z')
      *s = ((*s - 'a') + 13) % 26 + 'a';
    s++;
  }
}

void readBoard(Cell Board[ROWS][COLS], char buffer[256], int socket){
  for (int i = 0; i < 10; i++){
    for (int j = 0; j < 10; j++){
      read(socket, buffer, 256);
      Board[i][j].shipSymbol = buffer[0];
    }
  }
}

void sendBoard(Cell Board[ROWS][COLS], char buffer[256], int socket){
  for (int i = 0; i < 10; i++){
    for (int j = 0; j < 10; j++){
      buffer[0] = Board[i][j].shipSymbol;
      write(socket, buffer, 256);
    }
  }
}

void printGame(Cell me[ROWS][COLS], Cell opp[ROWS][COLS]){
  system("clear");
  printBoards(me, opp);
}

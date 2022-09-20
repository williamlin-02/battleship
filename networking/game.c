#include "game.h"

void printWelcome() {
  system("clear");
  printf("\n\n\n\n\n\n");
  printf("\n");
  sleep(1);
  printf("            ___  ___  ___  ___  _    ___  ___  _ _  _  ___ \n ");
  sleep(1);
  printf("           | . >| . ||_ _||_ _|| |  | __>/ __>| | || || . \\ \n");
  sleep(1);
  printf("            | . \\|   | | |  | | | |_ | _> \\__ \\|   || ||  _/\n");
  sleep(1);
  printf("            |___/|_|_| |_|  |_| |___||___><___/|_|_||_||_| \n");

  sleep(3);
  system("clear");
  printf ("\n");
  printf ("Weclome to Battleship!\n\n");
	printf ("Here are the rules of the game:\n\n");
	printf ("1. This is a two player game.\n\n");
	printf ("2. There are five types of ships to be placed by longest length to the\n");
	printf ("   shortest; [c] Carrier has 5 cells, [b] Battleship has 4 cells, [r] Cruiser\n");
	printf ("   has 3 cells, [s] Submarine has 3 cells, [d] Destroyer has 2 cells.\n\n");
  printf ("3. Place your ships and target other ships by following the prompts displayed \n");
  printf ("   on the screen.\n\n");
  printf ("4. Each turn, you will see your board (with the ships displayed) and the\n");
  printf ("   opponents' board (with ships not displayed) on your screen. You will also\n");
  printf ("   see the status of your ships. The number corresponding to each ship\n");
  printf ("   indicates the number of cells it has been hit.\n\n");
	printf ("5. First player to guess the location of all opponents' ships wins.\n\n");
  printf("  R E A D Y ? ");
  sleep(5);
  printf("L E T ' S  P L A Y\n\n");
  sleep(1);
  // system("clear");
}

void initializeBoard(Cell Board[ROWS][COLS]) {
  int r = 0, c = 0;
	for (r = 0; r < ROWS; r++) {
		for (c = 0; c < COLS; c++) {
			Board[r][c].position.ycoor = r;
			Board[r][c].position.xcoor = c;
      Board[r][c].shipSymbol = ' ';
		}
  }
}

void printBoard(Cell Board[ROWS][COLS]) {
  int nums[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int n = 0;
  printf("  ");
  while (n<10) {
    printf("%d ", nums[n]);
    n++;
  }
  printf("\n");
	for (int r = 0; r < ROWS; r++) {
    printf("%d ", nums[r]);
		for (int c = 0; c < COLS; c++) {
      if (Board[r][c].shipSymbol == ' ') {
        printf("* ");
      }
      else{
        printf("%c ", Board[r][c].shipSymbol);
      }
    }
    printf("\n");
  }
}

void printBoards(Cell Board[ROWS][COLS], Cell opp[ROWS][COLS]) {
  int nums[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int n = 0;

  printf("Your Board\t\t\tPlayer Two's Board\n");
  printf("  ");
  while (n<10) {
    printf("%d ", nums[n]);
    n++;
  }
  //printing board 2
  printf("\t\t");
  n = 0;
  printf("  ");
  while (n<10) {
    printf("%d ", nums[n]);
    n++;
  }

  printf("\n");
	for (int r = 0; r < ROWS; r++) {
    printf("%d ", nums[r]);
		for (int c = 0; c < COLS; c++) {
      if (Board[r][c].shipSymbol == ' ') {
        printf("* ");
      }
      else{
        printf("%c ", Board[r][c].shipSymbol);
      }
    }
    //printing Board 2
    printf("\t\t");
    printf("%d ", nums[r]);
    for (int c = 0; c < COLS; c++) {
      if (opp[r][c].shipSymbol == HIT || opp[r][c].shipSymbol == WATER) {
        printf("%c ", opp[r][c].shipSymbol);
      }
      else {
        printf("* ");
      }
    }
    printf("\n");
  }
}

void printShips(Ship me[NUM_SHIPS], Ship opp[NUM_SHIPS]) {
  int i, n = 0;
  printf("\n");
  printf("Your Ships\t\t\tPlayer Two's Ships\n");
  for (i = 0; i<NUM_SHIPS; i++) {
    printf("%c : %d", me[i].shipName, me[i].hits);
    printf("\t\t\t\t");
    printf("%c : %d\n", opp[i].shipName, opp[i].hits);
  }
}




void placeShips(Cell Board[ROWS][COLS], Ship ships[]){
  // int c;
  // char buf[20];
  printBoard(Board);
  int x1, x2, y1, y2, orientation, valid;
  for (int i = 0; i < NUM_SHIPS; i++){
    int placed = 0;
    while (!placed){
      //to fix a certain bug:
      orientation = 20;
      valid = 20;
      x1 = 20;
      x2 = 20;
      y1 = 20;
      y2 = 20;
      //
      char buf[256];

      printf("This ship is %d cells long.\n", ships[i].length);
      printf("Would you like the ship to be (1) horizontal or (2) vertical?\nType in 1 or 2: ");
      // fflush(stdout);
      // fflush(stdin);
      fgets(buf, sizeof(buf), stdin);
      orientation = atoi(buf);
      fflush(stdout);
      fflush(stdin);
      // scanf("%d", &orientation);

      //in case they put in wrong num
      while ((orientation != 1 && orientation != 2)) {
        printf("Please choose a valid option: ");
        // fflush(stdout);
        // fflush(stdin);
        fgets(buf, sizeof(buf), stdin);
        orientation = atoi(buf);
        fflush(stdout);
        fflush(stdin);
        // scanf("%d", &orientation);
        // cleanBuffer();
      }

      //taking in an x-coordinate
      printf("Enter the x-coordinate of initial position: ");
      fgets(buf, sizeof(buf), stdin);
      x1 = atoi(buf);
      fflush(stdout);
      fflush(stdin);
      // scanf("%d", &x1);
      while (!isValidCoord(x1)) {
        printf("Please choose a valid x-coordinate: ");
        fgets(buf, sizeof(buf), stdin);
        x1 = atoi(buf);
        fflush(stdout);
        fflush(stdin);
        // scanf("%d", &x1);
      }
      //y-coordinate
      printf("Enter the y-coordinate of initial position: ");
      fgets(buf, sizeof(buf), stdin);
      y1 = atoi(buf);
      fflush(stdout);
      fflush(stdin);
      // scanf("%d", &y1);
      while (!isValidCoord(y1)) {
        printf("Please choose a valid y-coordinate: ");
        fgets(buf, sizeof(buf), stdin);
        y1 = atoi(buf);
        fflush(stdout);
        fflush(stdin);
        // scanf("%d", &y1);
      }
    // printf("Would you like to (1) manually place a ship or (2) randomly place one? ");
    // scanf("%d", &c);
    // if (c == 1) {
    if (orientation == 2) {
      x2 = x1;
      // printf("y2: %d\n", y2);
      if (y1+ships[i].length >= ROWS) {
        y2 = y1 - ships[i].length;
      }
      else {
        // printf("y2: %d\n", y2);
        y2 = y1+ships[i].length;
      }
      // printf("ship length: %d\n", ships[i].length);
      // printf("y2: %d\n", y2);

      valid = 1;
      int less, more;
        if (y1 < y2){
          less = y1;
          more = y2;
        }
        else{
          less = y2+1;
          more = y1+1;
        }
        for (int j = less; j <= more; j++){
          if (Board[j][x1].shipSymbol != ' '){
            valid = 0;
          }
        }
        if (valid){
          for (int j = less; j < more; j++){
            Board[j][x1].shipSymbol = ships[i].shipName;
          }
          placed = 1;
          system("clear");
          printBoard(Board);
        }
        else {
          printf("There is already a ship in that position, please choose another.\n");
        }
      }
      else if (orientation == 1){
        y2 = y1;
        x2 = 0;
        // printf("x2: %d\n", x2);
        if (x1+ships[i].length >= COLS) {
          x2 = x1 - ships[i].length;
        }
        else {
          // printf("x2: %d\n", x2);
          x2 = x1+ships[i].length;
        }
        // printf("ship length: %d\n", ships[i].length);
        // printf("x2: %d\n", x2);

        int less, more;
        valid = 1;
        if (x1 < x2){
          less = x1;
          more = x2;
        }
        else{
          less = x2+1;
          more = x1+1;
        }
      // printf("less: %d, more: %d\n", less, more);
        for (int j = less; j <= more; j++){
          if (Board[y1][j].shipSymbol != ' '){
            valid = 0;
          }
        }
        // printf("valid: %d\n", valid);
        if (valid){
          for (int j = less; j < more; j++){
            Board[y1][j].shipSymbol = ships[i].shipName;
          }
          placed = 1;
          system("clear");
          printBoard(Board);
        }
        else {
          printf("There is already a ship in that position, please choose another.\n");
        }
      }
      // }
      // else {
      //   randomlyPlace(Board, ships, i);
      // }
    }
  }
}

int isValidCoord(int coordinate) {
  int nums[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int n = 0;
  for (n = 0; n < 10; n++) {
    if (coordinate == nums[n]) {
      return 1;
    }
  }
  return 0;
}

int hit(Cell Board[ROWS][COLS], Ship ships[]) {
  int r, c, s, success = 0;
  char buf[256];
  printf("Your turn! Which position would you like to hit?\n");

  printf("Enter the x-coordinate: ");
  fgets(buf, sizeof(buf), stdin);
  c = atoi(buf);
  fflush(stdout);
  fflush(stdin);
  while (!isValidCoord(c)) {
    printf("Please choose a valid x-coordinate: ");
    fgets(buf, sizeof(buf), stdin);
    c = atoi(buf);
    fflush(stdout);
    fflush(stdin);
  }
  printf("Enter the y-coordinate: ");
  fgets(buf, sizeof(buf), stdin);
  r = atoi(buf);
  fflush(stdout);
  fflush(stdin);
  while (!isValidCoord(r)) {
    printf("Please choose a valid x-coordinate: ");
    fgets(buf, sizeof(buf), stdin);
    r = atoi(buf);
    fflush(stdout);
    fflush(stdin);
  }
    // scanf("%d", &x1);

  int i = 0;
  while (Board[r][c].shipSymbol == WATER || Board[r][c].shipSymbol == HIT) {

    printf("You already targeted this position once. Choose another.\n");
    printf("Enter the x-coordinate: ");
    fgets(buf, sizeof(buf), stdin);
    c = atoi(buf);
    fflush(stdout);
    fflush(stdin);
    while (!isValidCoord(c)) {
      printf("Please choose a valid x-coordinate: ");
      fgets(buf, sizeof(buf), stdin);
      c = atoi(buf);
      fflush(stdout);
      fflush(stdin);
    }
    //y-coordinate
    printf("Enter the y-coordinate: ");
    fgets(buf, sizeof(buf), stdin);
    r = atoi(buf);
    fflush(stdout);
    fflush(stdin);
    while (!isValidCoord(r)) {
      printf("Please choose a valid y-coordinate: ");
      fgets(buf, sizeof(buf), stdin);
      r = atoi(buf);
      fflush(stdout);
      fflush(stdin);
    }

  }
  if (Board[r][c].shipSymbol != ' ') { //checking there is a ship
    for (s = 0; s<5; s++) {
      if (Board[r][c].shipSymbol == ships[s].shipName) {
        ships[s].hits += 1; //adding hits to the corresponding ship
      }
    }
    printf("You hit a %c ship!\n", Board[r][c].shipSymbol);
    Board[r][c].shipSymbol = HIT;
    success = 1;
  }
  else {
    Board[r][c].shipSymbol = WATER;
    printf("Oops - you didn't hit anything\n");
  }
  return success;
}

int PlayerWins(Ship ships[]) {
  int n, sunk = 0;
  for (n = 0; n < 5; n++) {
    if (ships[n].hits == ships[n].length) {
      sunk++;
    }
  }
  // printf("ships sunk: %d\n", sunk);
  if (sunk == 5) {
    // printf("Player won!\n");
    return 1;
  }
  return 0;
}

void printGoodbye() {
  // system("clear");
  // printf("\n\n\n\n\n\n");
  printf("\n");
  sleep(1);
  printf("       ___   ___  __ __  ___   ___  _ _  ___  ___ \n ");
  sleep(1);
  printf("     /  _> | . ||  \\  \\| __> | . || | || __>| . \\ \n");
  sleep(1);
  printf("      | <_/\\|   ||     || _>  | | || ' || _> |   /\n");
  sleep(1);
  printf("      `____/|_|_||_|_|_||___> `___'|__/ |___>|_\\_\\ \n");

  sleep(3);
  printf ("\n\n");
}


#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#define MAX_SIZE 20

char board[MAX_SIZE * 2 + 1][MAX_SIZE * 2 + 1];
int visit[MAX_SIZE][MAX_SIZE];
int starx1, stary1;
int starx2, stary2;
int width, height, sw;
int wallcount1= 0, wallcount2= 0;
int numberwal;
char playercomputer;
char player1[100];
char player2[100];
int s,w;


void initializeBoard() {
    starx1 = height *2-1;
    stary1;
    if(width % 2 ==0){
        stary1= width +1;
    }
    else{
        stary1= width;
    }
    stary2;
    starx2 = 1;
    if(width % 2 ==0){
        stary2= width +1;
    }
    else{
        stary2= width;
    }
    for (int i = 0; i < height * 2 + 1; ++i) {
        for (int j = 0; j < width * 2 + 1; ++j) {
            if (i % 2 == 0 && j % 2 == 0) {
                board[i][j] = '+';
            } else if (i % 2 == 0) {
                board[i][j] = '-';
            } else if (j % 2 == 0) {
                board[i][j] = '|';
            } else {

                board[i][j] = ' ';
            }
        }
    }
    board[starx1][stary1]= '*';
    board[starx2][stary2]='#';
}


void initializeBoard3() {
    for (int i = 0; i < height * 2 + 1; ++i) {
        for (int j = 0; j < width * 2 + 1; ++j) {
            if (i % 2 == 0 && j % 2 == 0) {
                board[i][j] = '+';
            } else if (i % 2 == 0) {
                board[i][j] = '-';
            } else if (j % 2 == 0) {
                board[i][j] = '|';
            } else {

                board[i][j] = ' ';
            }
        }
    }
    board[starx1][stary1]= '*';
    board[starx2][stary2]='#';
}


void printBoard() {
    for (int i = 0; i < height * 2 + 1; ++i) {
        for (int j = 0; j < width * 2 + 1; ++j) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}
void moveFirstPlayerup() {
    if (starx1 - 2 >= 1 && board[starx1][stary1] == '&') {
        if (board[starx1 - 1][stary1] != ')') {
            board[starx1][stary1] = '#';
            starx1 -= 2;
            board[starx1][stary1] = '*';
            sw = 1;
            s=1;
        }
    }
    else if (starx1 - 2  >= 1 && board[starx1 - 2][stary1] != '#') {
        if (board[starx1 - 1][stary1] != ')') {
            board[starx1][stary1] = ' ';
            starx1 -= 2;
            board[starx1][stary1] = '*';
            sw = 1;
            s=1;
        }
    }

    else if (board[starx1 - 2][stary1] == '#') {
        if (board[starx1 - 1][stary1] != ')') {
            board[starx1][stary1] = ' ';
            starx1 -= 2;
            board[starx1][stary1] = '&';
            sw = 1;
            s=1;
        }
    }
}

void movefirstplayerdown(){
    if (starx1 + 2 <= width*2 && board[starx1][stary1] == '&') {
        if (board[starx1 + 1][stary1] != ')') {
            board[starx1][stary1] = '#';
            starx1 += 2;
            board[starx1][stary1] = '*';
            sw = 1;
            s=1;
        }

    }
    else if (starx1 + 2 <= width*2 && board[starx1 + 2][stary1] != '#') {
        if (board[starx1 + 1][stary1] != ')') {
            board[starx1][stary1] = ' ';
            starx1 += 2;
            board[starx1][stary1] = '*';
            sw = 1;
            s=1;
        }

    }

    else if (board[starx1 + 2][stary1] == '#') {
        if (board[starx1 + 1][stary1] != ')') {
            board[starx1][stary1] = ' ';
            starx1 += 2;
            board[starx1][stary1] = '&';
            sw = 1;
            s=1;
        }
    }
}

void movefirstplayerleft(){
    if (stary1 - 2 >= 0 && board[starx1][stary1] == '&') {
        if (board[starx1][stary1 - 1] != ')') {
            board[starx1][stary1] = '*';
            stary1 -= 2;
            board[starx1][stary1] = '#';
            sw = 1;
            s=1;
        }
    }
    else if (stary1 - 2 >= 0 && board[starx1][stary1 - 2] != '#') {
        if (board[starx1][stary1 - 1] != ')') {
            board[starx1][stary1] = ' ';
            stary1 -= 2;
            board[starx1][stary1] = '*';
            sw = 1;
            s=1;
        }
    }
    else if (board[starx1][stary1 - 2] == '#') {
        if (board[starx1][stary1 - 1] != ')') {
            board[starx1][stary1] = ' ';
            stary1 -= 2;
            board[starx1][stary1] = '&';
            sw = 1;
            s=1;
        }
    }
}

void moveFirstPlayerright() {
    if (stary1 <= height*2-2 && board[starx1][stary1] == '&') {
        if (board[starx1][stary1 + 1] != ')') {
            board[starx1][stary1] = '#';
            stary1 += 2;
            board[starx1][stary1] = '*';
            sw = 1;
            s=1;
        }
    }

    else if (stary1 <= height*2-2 && board[starx1][stary1 + 2] != '#') {
        if (board[starx1][stary1 + 1] != ')') {
            board[starx1][stary1] = ' ';
            stary1 += 2;
            board[starx1][stary1] = '*';
            sw = 1;
            s=1;
        }
    }
    else if (board[starx1][stary1 + 2] == '#') {
        if (board[starx1][stary1 + 1] != ')') {
            board[starx1][stary1] = ' ';
            stary1 += 2;
            board[starx1][stary1] = '&';
            sw = 1;
            s=1;
        }
    }
}


void moveFirstPlayer() {
    char direction;
    direction = getch();
    if (direction == 'u') {
        moveFirstPlayerup();
    } else if (direction == 'd') {
        movefirstplayerdown();
    } else if (direction == 'r') {
        moveFirstPlayerright();
    } else if (direction == 'l') {
        movefirstplayerleft();
    }
}

void movecomputerPlayer() {
    srand(time(0));
    int com =rand() % 4 + 1;
    if (com == 1) {
        moveFirstPlayerup();
    } else if (com == 2 ) {
        movefirstplayerdown();
    } else if (com == 3 ) {
        moveFirstPlayerright();
    } else if (com == 4 ) {
        movefirstplayerleft();
    }
}

void moveSecondPlayerup() {

    if (starx2 - 2 >= 1 && board[starx2][stary2] == '&') {
        if (board[starx2 - 1][stary2] != ')') {
            board[starx2][stary2] = '*';
            starx2 -= 2;
            board[starx2][stary2] = '#';
            sw = 0;
            w=1;
        }
    } else if (starx2 - 2 >= 1 && board[starx2 - 2][stary2] != '*') {
        if (board[starx2 - 1][stary2] != ')') {
            board[starx2][stary2] = ' ';
            starx2 -= 2;
            board[starx2][stary2] = '#';
            sw = 0;
            w=1;
        }
    } else if (board[starx2 - 2][stary2] == '*') {
        if (board[starx2 - 1][stary2] != ')') {
            board[starx2][stary2] = ' ';
            starx2 -= 2;
            board[starx2][stary2] = '&';
            sw = 0;
            w=1;
        }
    }
}

void moveSecondPlayerdown(){
    if (starx2 + 2 <= width *2 +1 && board[starx2][stary2]=='&'){
        if (board[starx2 + 1][stary2] != ')') {
            board[starx2][stary2] = '*';
            starx2 += 2;
            board[starx2][stary2] = '#';
            sw = 0;
            w=1;
        }

    }
    else if (starx2 + 2 <= width*2 +1 && board[starx2+2][stary2]!='*'){
        if (board[starx2 + 1][stary2] != ')') {
            board[starx2][stary2] = ' ';
            starx2 += 2;
            board[starx2][stary2] = '#';
            sw = 0;
            w=1;
        }

    }

    else if(board[starx2+2][stary2]=='*'){
        if (board[starx2 +1][stary2] != ')') {
            board[starx2][stary2] = ' ';
            starx2 += 2;
            board[starx2][stary2] = '&';
            sw = 0;
            w=1;
        }
    }
}

void moveSecondPlayerright(){
    if (stary2 <= height*2 - 2 && board[starx2][stary2]=='&'){
        if (board[starx2][stary2+1] != ')') {
            board[starx2][stary2] = '*';
            stary2 += 2;
            board[starx2][stary2] = '#';
            sw = 0;
            w=1;
        }
    }

else if (stary2 <= height*2 - 2 && board[starx2][stary2+2]!='*'){
        if (board[starx2][stary2+1] != ')') {
            board[starx2][stary2] = ' ';
            stary2 += 2;
            board[starx2][stary2] = '#';
            sw = 0;
            w=1;
        }
    }
    else if(board[starx2][stary2+2]=='*'){
        if (board[starx2][stary2+1] != ')') {
            board[starx2][stary2] = ' ';
            stary2 += 2;
            board[starx2][stary2] = '&';
            sw = 0;
            w=1;
        }
    }
}

void moveSecondPlayerleft(){
    if (stary2 - 2 >= 0 && board[starx2][stary2]=='&'){
        if (board[starx2][stary2-1] != ')') {
            board[starx2][stary2] = '*';

            stary2 -= 2;
            board[starx2][stary2] = '#';
            sw = 0;
            w=1;
        }
    }
    else if (stary2 - 2 >= 0 && board[starx2][stary2-2]!='*'){
        if (board[starx2][stary2-1] != ')') {
            board[starx2][stary2] = ' ';
            stary2 -= 2;
            board[starx2][stary2] = '#';
            sw = 0;
            w=1;
        }
    }
    else if(board[starx2][stary2-2]=='*'){
        if (board[starx2][stary2-1] != ')') {
            board[starx2][stary2] = ' ';
            stary2 -= 2;
            board[starx2][stary2] = '&';
            sw = 0;
            w=1;
        }
    }
}


void moveSecondPlayer(){
    char direction;
    direction = getch();
    if (direction == 'u') {
        moveSecondPlayerup();
    }else if (direction == 'd') {
        moveSecondPlayerdown();
    } else if (direction == 'r') {
       moveSecondPlayerright();
    } else if (direction == 'l') {
        moveSecondPlayerleft();
    }
}



int valid =1;

void dfs(int x, int y) {
    visit[x][y] = 1;
    if(y > 0 && board[2 * x + 1][2 * y] == ')' && y < width - 1 && board[2 * x + 1][2 * y + 2] == ')' &&
       x < height - 1 && board[2 * x + 2][2 * y + 1] == ')'){
        valid =0 ;
    }
    if(y < width - 1 && board[2 * x + 1][2 * y + 2] == ')' && y > 0 && board[2 * x + 1][2 * y] == ')' &&
       x> 0 && board[2 * x][2 * y + 1] == ')'){
        valid =0;
    }
    if( y > 0 && board[2 * x + 1][2 * y] == ')' && x> 0 && board[2 * x][2 * y + 1] == ')' &&
        x < height - 1 && board[2 * x + 2][2 * y + 1] == ')'){
        valid =0;
    }
    if(x> 0 && board[2 * x][2 * y + 1] == ')' && x < height - 1 && board[2 * x + 2][2 * y + 1] == ')' &&
       y < width - 1 && board[2 * x + 1][2 * y + 2] == ')'){
        valid =0;
    }
    if (x > 0) {
        if (!visit[x - 1][y] && board[2 * x][2 * y + 1] != ')')
            dfs(x - 1, y);
    }
    if (x < height - 1 && board[2 * x + 2][2 * y + 1] != ')') {
        if (!visit[x + 1][y])
            dfs(x + 1, y);
    }
    if (y > 0 && board[2 * x + 1][2 * y] != ')') {
        if (!visit[x][y - 1])
            dfs(x, y - 1);
    }
    if (y < width - 1 && board[2 * x + 1][2 * y + 2] != ')') {
        if (!visit[x][y + 1])
            dfs(x, y + 1);
    }
}

void wallup(int x, int y) {
    x = (x - 1) * 2;
    y = 2 * y - 1;
    board[x][y] = ')';
    board[x][y+2] = ')';
    for (int i = 0; i < width; i++)
        for (int j = 0; j < height; j++)
            visit[i][j] = 0;
    int xx = (starx1  - 1) / 2;
    int yy = (stary1 - 1) / 2;
    int yy2 = ((stary2 - 1) / 2)+1;
    dfs(xx, yy);
    dfs(xx, yy2);
    int path = 0;
    for (int i = 0; i < width; i++)
        if (visit[0][i]) path = 1;
    for (int i = 0; i < width; i++)
        for (int j = 0; j < height; j++)
            visit[i][j] = 0;
    xx = (starx2  - 1) / 2;
    yy = (stary2 - 1) / 2;
    yy2 = ((stary2 - 1) / 2)+1;
    dfs(xx, yy);
    dfs(xx, yy2);
    for (int i = 0; i < width; i++)
        if (visit[height - 1][i]) path = 1;
    if (! path) {
        board[x][y] = '-';
        board[x][y+2] = '-';
    }
    else
        sw ^= 1;
        
}

void wallleft(int x, int y){
    x = 2 * x - 1;
    y = (y - 1) * 2;

board[x][y] = ')';
    board[x+2][y] = ')';
    for (int i = 0; i < width; i++)
        for (int j = 0  ; j < height; j++)
            visit[i][j] = 0;
    int xx = (starx1  - 1) / 2;
    int yy = (stary1 - 1) / 2;
    dfs(xx, yy);
    dfs(xx+1, yy);
    int path = 0;
    for (int i = 0; i < width; i++)
        if (visit[0][i]) path = 1;
    for (int i = 0; i < width; i++)
        for (int j = 0; j < height; j++)
            visit[i][j] = 0;
    xx = (starx2  - 1) / 2;
    yy = (stary2 - 1) / 2;
    dfs(xx, yy);
    dfs(xx+1, yy);
    for (int i = 0; i < width; i++)
        if (visit[height - 1][i]) path = 1;
    if (! path) {
        board[x][y] = '-';
        board[x+1][y] = '-';
    }
    else
        sw ^= 1;
}

void wall(int x, int y, char xy) {
    if(valid && board[(x-1)*2][2*y-1] != ')'&& board[(x-1)*2][2*y+1] != ')' && y != width) {
        if (xy == 'u') {
            wallup(x, y);
        }
    }
    if(valid && board[2*x+1][(y-1)*2] != ')'&& board[2*x-1][(y-1)*2] != ')' && x != width) {
        if (xy == 'l') {
            wallleft(x, y);
        }
    }
}
void saveGame(FILE *file) {
    fprintf(file, "%d %d\n", width, height);
    fprintf(file, "%d\n", numberwal);
     fprintf(file, "%d\n", wallcount1);
      fprintf(file, "%d\n", wallcount2);
    fprintf(file, "%d\n", sw);
    fprintf(file, " %c\n", playercomputer);
    if(playercomputer == 'c'){
        fprintf(file, "%s\n", player2);
    }
    if(playercomputer == 'f'){
        fprintf(file, "%s\n", player1);
        fprintf(file, "%s\n", player2);
    }
    fprintf(file, "%d %d\n", starx1, stary1);
    fprintf(file, "%d %d\n", starx2, stary2);
    for (int i = 0; i < height * 2 + 1 ; ++i) {
        for (int j = 0; j < width * 2 + 2; ++j) {
            fprintf(file, "%c", board[i][j]);
        }
    }
}

void loadGame(FILE *file) {
    fscanf(file, "%d %d", &width, &height);
    fscanf(file, "%d", &numberwal);
    fscanf(file, "%d", &wallcount1);
    fscanf(file, "%d", &wallcount2);
     fscanf(file, "%d", &sw);
    fscanf(file, " %c", &playercomputer);
    if(playercomputer == 'c'){
        fscanf(file, "%s", player2);
    }
    if(playercomputer == 'f'){
        fscanf(file, "%s", player1);
        fscanf(file, "%s", player2);
    }
    fscanf(file, "%d %d", &starx1, &stary1);
    fscanf(file, "%d %d", &starx2, &stary2);

    for (int i = -1; i < height * 2 + 1; ++i) {
        for (int j = -1; j < width * 2 + 1; ++j) {
            if(i== -1&& j == -1){
                fscanf(file, " ");
                i ++;
                j ++;
            }
            fscanf(file, "%c", &board[i][j]);
        }
    }
}

int lastrand, lastrand2;
void awardpunishment ()
{
  int z = rand () % 5 + 1;
  srand (time (0));
  if (lastrand == 3 && lastrand2 == 1)
	{
	  sw = 1;
	}
  
	  lastrand = z;
	  if (z == 1)
		{
		  printf ("All the walls were cleared!\n");
		  initializeBoard3 ();
		}
	  else if (z == 2)
		{
		  srand (time (0));
		  int v = rand () % 3 + 1;
		  if (v == 1)
			{
			  printf ("%s: you lost 2 walls!\n", player1);
			  wallcount1 += 2;
			}
		  if (v == 2)
			{
			  printf ("%s: you lost 3 walls!\n", player1);
			  wallcount1 += 3;
			}
		  if (v == 3)
			{
			  printf ("%s: you lost 5 walls!\n", player1);
			  wallcount1 += 5;
			}
		}
	  else if (z == 3)
		{
		  srand (time (0));
		  int q = rand () % 2 + 1;
		  lastrand2 = q;
		  if (q == 2)
			{
			  sw = 1;
			  printf ("%s: You are banned for one time!\n", player1);
			}
		  if (q == 1)
			{
			  printf ("%s: You are banned for two time!\n", player1);
			  sw = 1;
			}
		}
	  else if (z == 4)
		{
		  srand (time (0));
		  int v = rand () % 3 + 1;
		  if (v == 1)
			{
			  printf ("%s: you got 2 walls!\n", player1);
			  wallcount1 -= 2;
			}
		  if (v == 2)
			{
			  printf ("%s: you got 3 walls!\n", player1);
			  wallcount1 -= 3;
			}
		  if (v == 3)
			{
			  printf ("%s: you got 5 walls!\n", player1);
			  wallcount1 -= 5;
			}
		}
	  else if (z == 5)
		{
		  int v = rand () % 2 + 1;
		  if (v == 1)
			{
			  printf ("%s: you got 1 wall, %s you lost 1 wall!\n", player1,player2);
			  wallcount2++;
			  wallcount1--;
			}
		  if (v == 2)
			{
			  printf ("%s: you got 2 walls, %s you lost 2 walls!\n", player1,player2);
			  wallcount2 += 2;
			  wallcount1 -= 2;
			
		}
	}
}

int lastrand3, lastrand4;
void awardpunishment2() {
    int z = rand() % 5 + 1;
    srand(time(0));
    if (lastrand3 == 3 && lastrand4 == 1) {
        sw = 0;
    }

        lastrand3 = z;
        if (z == 1) {
            printf("All the walls were cleared!\n");
            initializeBoard3();
        } else if (z == 2) {
            srand(time(0));
            int v = rand() % 3 + 1;
            if (v == 1) {
                printf("%s: you lost 2 walls!\n", player2);
                wallcount2 += 2;
            }
            if (v == 2) {
                printf("%s: you lost 3 walls!\n", player2);
                wallcount2 += 3;
            }
            if (v == 3) {
                printf("%s: you lost 5 walls!\n", player2);
                wallcount2 += 5;
            }
        } else if (z == 3) {
            srand(time(0));
            int q = rand() % 2 + 1;
            lastrand4 = q;
            if (q == 2) {
                sw = 0;
                printf("%s: You are banned for one time!\n", player2);
            }
            if (q == 1) {
                printf("%s: You are banned for two time!\n", player2);
                sw = 0;
            }
        } else if (z == 4) {
            srand(time(0));
            int v = rand() % 3 + 1;
            if (v == 1) {
                printf("%s: you got 2 walls!\n", player2);
                wallcount2 -= 2;
            }
            if (v == 2) {
                printf("%s: you got 3 walls!\n", player2);
                wallcount2 -= 3;
            }
            if (v == 3) {
                printf("%s: you got 5 walls!\n", player2);
                wallcount2 -= 5;
            }
        } else if (z == 5) {
            int v = rand() % 2 + 1;
            if (v == 1) {
                printf("%s: you got 1 wall, %s: you lost 1 wall!\n", player2, player1);
                wallcount1 ++;
                wallcount2 --;
            }
            if (v == 2) {
                printf("%s: you got 2 walls, %s: you lost 2 walls!\n", player2, player1);
                wallcount1 += 2;
                wallcount2 -= 2;
            }
        }
    }





int main() {
    int game;
    FILE *file;
    do {
        printf("if do you want play last game enter 3 if you want new game enter 4?");
        if (scanf("%d", &game) != 1 || (game != 3 && game != 4)) {
            while (getchar() != '\n');
            printf("Invalid input.\n");
            continue;
        }
    } while (game != 3 && game != 4);
    if (game == 3) {
        file = fopen("saved_game.txt", "rt");
        if (!file) {
            printf("error\n");
            return 0;
        }
        loadGame(file);
        fclose(file);
        if (playercomputer == 'c') {
            strcpy(player1, "computer");
            int choice;
            int isGameRunning = 1;
            printBoard();
            while (isGameRunning) {
                if (sw == 0) {
                	s=0;
                    srand(time(0));
                    int randnum;
                    randnum = rand() % 2 + 1;
					if (randnum == 1) {
                        int x, y;
                        x = rand() % (width - 1) + 1;
                        y = rand() % (width - 1) + 1;
                        int xy1;
                        char xy;
                        xy1 = rand() % 2 + 1;
                        if (xy1 == 1) {
                            xy = 'u';
                        }
                        if (xy1 == 2) {
                            xy = 'l';
                        }
                        if (wallcount1 >= numberwal) {
                        	wallcount1 = numberwal;
                            continue;
                        }
                        wall(x, y, xy);
                        if (xy == 'u' && board[(x - 1) * 2][2 * y - 1] == ')' &&board[(x - 1) * 2][2 * y + 1] == ')') {
                            wallcount1++;
                            s=1;
                        }
                        if (xy == 'l' && board[2 * x + 1][(y - 1) * 2] == ')' &&board[2 * x - 1][(y - 1) * 2] == ')') {
                            wallcount1++;
                            s=1;
							}
						} else if (randnum == 2) {
                        movecomputerPlayer();
                    }
                    if (starx1 == 1 && board[starx1 - 1][stary1] != ')') {
                        printf("%s win!", player1);
                        break;
                    }

                    system("cls");
                    printBoard();
					}
				if(s==1){
					awardpunishment2();
	      			printBoard();
		   			s=0;
				   }
				   if (sw == 1) {
                	w=0;
                    while (1) {
                        printf("%s: If you want a wall, enter 1. If you want to move, enter 2. To save the game, enter 0!\n",
                               player2);
                        if (scanf("%d", &choice) != 1 || (choice != 0 && choice != 1 && choice != 2)) {
                            while (getchar() != '\n');
                            printf("Invalid input. Please enter 0, 1, or 2.\n");
                        } else {
                            break;
                        }
                    }
                    if (choice == 1) {
                        int x, y;
                        char xy;
                        if (wallcount2 >= numberwal) {
                        	wallcount2 = numberwal;
                            printf("You are out of wall.\n");
                            continue;
                        }
                        int numberwall = numberwal - wallcount2;

                        printf("%s : %d walls are left^^\n", player2, numberwall);
                        do {
                            printf("%s :please enter the coordinates\n", player2);

                            if (scanf("%d", &x) != 1) {
                                while (getchar() != '\n');
                                printf("wrong cordination.\n");
                                continue;
                            }
                            if (scanf("%d", &y) != 1) {
                                while (getchar() != '\n');
                                printf("wrong cordination.\n");
                                continue;
                            }
                        } while (x <= 0 || y <= 0);
                        if (x > width+1 || y > width+1) {
                            printf("wrong coordination.\n");
                            continue;
                        }
                        int sw2 = 1;
                        printf("if you want make a wall down or up enter u else enter l\n");
                        while (sw2) {
                            scanf(" %c", &xy);
                            if (xy == 'l' || xy == 'u') {
                                sw2 = 0;
                            }
                        }
                        wall(x, y, xy);
                        if (xy == 'u' && board[(x - 1) * 2][2 * y - 1] == ')' &&board[(x - 1) * 2][2 * y + 1] == ')') {
                            wallcount2++;
                            w=1;
                        }
                        if (xy == 'l' && board[2 * x + 1][(y - 1) * 2] == ')' &&board[2 * x - 1][(y - 1) * 2] == ')') {
                            wallcount2++;
                            w=1;
                        }
                    }
                    if (choice == 2) {
                        printf("%s : If you want move up enter u, down enter d, left enter l and right enter r^^\n",player2);
                        moveSecondPlayer();
                    }
                    if (starx2 == height * 2 - 1 && board[starx2 + 1][stary2] != ')') {
                        printf("%s win!", player2);
                        break;
                    }
                    if (choice == 0) {
                        file = fopen("saved_game.txt", "w");
                        saveGame(file);
                        fclose(file);
                        isGameRunning = 0;
                    }
                    system("cls");
                    printBoard();
                }
            }
			if(w==1){
			awardpunishment();
	      	printBoard();
			w=0;}
        }
if (playercomputer == 'f') {
            int choice;
            printBoard();
            int isGameRunning = 1;
            
            while (isGameRunning) {
        if (sw == 0) {
                s=0;
                    if(sw==0){
                    while (1) {
                        printf("%s: If you want a wall, enter 1. If you want to move, enter 2. To save the game, enter 0!\n",
                               player1);
                        if (scanf("%d", &choice) != 1 || (choice != 0 && choice != 1 && choice != 2)) {
                            while (getchar() != '\n');
                            printf("Invalid input. Please enter 0, 1, or 2.\n");
                        } else {
                            break;
                        }
                    }
                    if (choice == 1) {
                        int x, y;
                        char xy;
                        if (wallcount1 >= numberwal) {
                        	wallcount1 = numberwal;
                            printf("You are out of wall.\n");
                            continue;
                        }
                        int numberwall = numberwal - wallcount1;
                        printf("%s : %d walls are left^^\n", player1, numberwall);
                        do {
                            printf("%s :please enter the coordinates\n", player1);
                            if (scanf("%d", &x) != 1) {
                                while (getchar() != '\n');
                                printf("wrong cordination.\n");
                                continue;
                            }
                            if (scanf("%d", &y) != 1) {
                                while (getchar() != '\n');
                                printf("wrong cordination.\n");
                                continue;
                            }
                        } while (x <= 0 || y <= 0);

                        if (x > width+1 || y > width+1) {
                            printf("wrong cordination.\n");
                            continue;
                        }
                        int sw1 = 1;
                        printf("if you want make a wall down or up enter u else enter l\n");
                        while (sw1) {
                            scanf(" %c", &xy);
                            if (xy == 'l' || xy == 'u') {
                                sw1 = 0;
                            }
                        }
                        wall(x, y, xy);
                        if (xy == 'u' && board[(x - 1) * 2][2 * y - 1] == ')' &&board[(x - 1) * 2][2 * y + 1] == ')') {
							wallcount1++;
							s=1;
                        }
                        if (xy == 'l' && board[2 * x + 1][(y - 1) * 2] == ')' &&board[2 * x - 1][(y - 1) * 2] == ')') {
                            wallcount1++;
                            s=1;
                        }
                    }
                    if (choice == 2) {
                        printf("%s : If you want move up enter u, down enter d, left enter l and right enter r^^\n",player1);
                        moveFirstPlayer();
                    }
                    if (starx1 == 1 && board[starx1 - 1][stary1] != ')') {
                        printf("%s win!", player1);
                        break;
                    }
                    if (choice == 0) {
                        file = fopen("saved_game.txt", "w");
                        saveGame(file);
                        fclose(file);
                        isGameRunning = 0;
                }
                    system("cls");
                    printBoard();
                }
			}
			if(s==1){
			awardpunishment2();
	       	printBoard();
		   	s=0;
			   }
        if (sw == 1) {
                w=0;
                    if(sw==1){
                    while (1) {
                        printf("%s: If you want a wall, enter 1. If you want to move, enter 2. To save the game, enter 0!\n",
                               player2);
                        if (scanf("%d", &choice) != 1 || (choice != 0 && choice != 1 && choice != 2)) {
                            while (getchar() != '\n');
                            printf("Invalid input. Please enter 0, 1, or 2.\n");
                        } else {
                            break;
                        }
                    }
                    if (choice == 1) {
                        int x, y;
                        char xy;
                        if (wallcount2 >= numberwal) {
                        	wallcount2 = numberwal;
                            printf("You are out of wall.\n");
                            continue;
                        }
                        int numberwall = numberwal - wallcount2;

                        printf("%s : %d walls are left^^\n", player2, numberwall);
                        do {
                            printf("%s :please enter the coordinates\n", player2);

                            if (scanf("%d", &x) != 1) {
                                while (getchar() != '\n');
                                printf("wrong cordination.\n");
                                continue;
                            }
                            if (scanf("%d", &y) != 1) {
                                while (getchar() != '\n');
                                printf("wrong cordination.\n");
                                continue;
                            }
                        } while (x <= 0 || y <= 0);
                        if (x > width+1 || y > width+1) {
                            printf("wrong coordination.\n");
                            continue;
                        }
                        int sw2 = 1;
                        printf("if you want make a wall down or up enter u else enter l\n");
                        while (sw2) {
                            scanf(" %c", &xy);
                            if (xy == 'l' || xy == 'u') {
                                sw2 = 0;
                            }
                        }
                        wall(x, y, xy);
                        if (xy == 'u' && board[(x - 1) * 2][2 * y - 1] == ')' &&board[(x - 1) * 2][2 * y + 1] == ')') {
                            wallcount2++;
                            w=1;
                        }
                        if (xy == 'l' && board[2 * x + 1][(y - 1) * 2] == ')' &&board[2 * x - 1][(y - 1) * 2] == ')') {
                            wallcount2++;
                            w=1;
                        }
                    }

if (choice == 2) {
                    printf("%s : If you want move up enter u, down enter d, left enter l and right enter r^^\n",player2);
                    moveSecondPlayer();
                    }
                    if (starx2 == height * 2 - 1 && board[starx2 + 1][stary2] != ')') {
                        printf("%s win!", player2);
                        break;
                    }
                    if (choice == 0) {
                        file = fopen("saved_game.txt", "w");
                        saveGame(file);
                        fclose(file);
                        isGameRunning = 0;
                    }
                    system("cls");
                    printBoard();
                }
            }
			if(w==1){
			awardpunishment();
			printBoard();
			w=0;
			}
        }
    }
}
    if (game == 4) {
        do {
            printf("Enter width and height of the board (max size is %d): ", MAX_SIZE);
            if (scanf("%d", &width) != 1) {
                while (getchar() != '\n');
                printf("wrong .\n");
                continue;
            }
            if (scanf("%d", &height) != 1) {
                while (getchar() != '\n');
                printf("wrong .\n");
                continue;
            }
            if (width > MAX_SIZE || height > MAX_SIZE) {
                printf("Invalid size!\n");
            }
        } while (width > MAX_SIZE  ||height > MAX_SIZE||  width <= 0 || height <= 0);
        do {
            printf("how many wall do you want ?\n");
            if (scanf("%d", &numberwal) != 1) {
                while (getchar() != '\n');
                printf("wrong input.\n");
                continue;
            }
        } while (numberwal <= 0 || numberwal > 2 * width);
        int SW=1;
        while(SW){
        	 printf("If you want to play with computer enter c else enter f.\n");
        	 scanf(" %c", &playercomputer) ;
        	 if(playercomputer=='c'||playercomputer=='f'){
        	 	SW=0;
			 }
		}
       
       
        if (playercomputer == 'c') {
            strcpy(player1, "computer");
            printf("Please enter your name Player 2.\n");
            scanf("%s", &player2);
            int choice;
            initializeBoard();
            printBoard();
            int isGameRunning = 1;
            sw = 0;
            while (isGameRunning) {
                if (sw == 0) {
                s=0;
                    if(sw==0){
                    srand(time(0));
                    int randnum;
                    randnum = rand() % 2 + 1;
                    if (randnum == 1) {
                        int x, y;
                        x = rand() % (width - 1) + 1;
                        y = rand() % (width - 1) + 1;
                        int xy1;
                        char xy;
                        xy1 = rand() % 2 + 1;
                        if (xy1 == 1) {
                            xy = 'u';
                        }
                        if (xy1 == 2) {
                            xy = 'l';
                        }
                        if (wallcount1 >= numberwal) {
                        	wallcount1 = numberwal;
                            continue;
                        }
                        wall(x, y, xy);
                        if (xy == 'u' && board[(x - 1) * 2][2 * y - 1] == ')' &&board[(x - 1) * 2][2 * y + 1] == ')') {
                            wallcount1++;
                            s=1;
                        }
                        if (xy == 'l' && board[2 * x + 1][(y - 1) * 2] == ')' &&board[2 * x - 1][(y - 1) * 2] == ')') {
                            wallcount1++;
                            s=1;
                        }
                    } else if (randnum == 2) {
                        movecomputerPlayer();
                    }
                    if (starx1 == 1 && board[starx1 - 1][stary1] != ')') {
                        printf("%s win!", player1);
                        break;
                    }
					system("cls");
                    printBoard();
					}
				}
				 if(s==1){ 
				 awardpunishment2();
				 printBoard();
				 s=0;
				 }
                if (sw == 1) {
				w=0;
				if(sw==1){
                    while (1) {
                        printf("%s: If you want a wall, enter 1. If you want to move, enter 2. To save the game, enter 0!\n",
                               player2);
                        if (scanf("%d", &choice) != 1 || (choice != 0 && choice != 1 && choice != 2)) {
                            while (getchar() != '\n');
                            printf("Invalid input. Please enter 0, 1, or 2.\n");
                        } else {
                            break;
                        }
                    }
                    if (choice == 1) {
                        int x, y;
                        char xy;
                        if (wallcount2 >= numberwal) {
                        		wallcount2 = numberwal;
                            printf("You are out of wall.\n");
                            continue;
                        }
                        int numberwall = numberwal - wallcount2;

                        printf("%s : %d walls are left^^\n", player2, numberwall);
                        do {
                            printf("%s :please enter the coordinates\n", player2);

                            if (scanf("%d", &x) != 1) {
                                while (getchar() != '\n');
                                printf("wrong cordination.\n");
                                continue;
                            }
                            if (scanf("%d", &y) != 1) {
                                while (getchar() != '\n');
                                printf("wrong cordination.\n");
                                continue;
                            }
                        } while (x <= 0 || y <= 0);
                        if (x > width+1 || y > width+1) {
                            printf("wrong coordination.\n");
                            continue;
                        }
                        int sw2 = 1;
                        printf("if you want make a wall down or up enter u else enter l\n");
                        while (sw2) {
                            scanf(" %c", &xy);
                            if (xy == 'l' || xy == 'u') {
                                sw2 = 0;
                            }
                        }
                        wall(x, y, xy);
                        if (xy == 'u' && board[(x - 1) * 2][2 * y - 1] == ')' &&board[(x - 1) * 2][2 * y + 1] == ')') {
                            wallcount2++;
                            w=1;
                        }
                        if (xy == 'l' && board[2 * x + 1][(y - 1) * 2] == ')' &&board[2 * x - 1][(y - 1) * 2] == ')') {
                            wallcount2++;
                            w=1;
                        }
                    } else if (choice == 2) {
                        printf("%s : If you want move up enter u, down enter d, left enter l and right enter r^^\n",player2);
                        moveSecondPlayer();
                    }
                    if (starx2 == height * 2 - 1 && board[starx2 + 1][stary2] != ')') {
                        printf("%s win!", player2);
                        break;
                    } else if (choice == 0) {
                        file = fopen("saved_game.txt", "w");
                        saveGame(file);
                        fclose(file);
                        isGameRunning = 0;
                    }
                    system("cls");
                    printBoard();
                }
            }
             if(w==1){
				
                  	awardpunishment();
	      			 printBoard();
					   w=0;}
        }
	}
        if (playercomputer == 'f') {
            printf("Please enter your name Player 1.\n");
            scanf("%s", &player1);
            printf("Please enter your name Player 2.\n");
            scanf("%s", &player2);
            int choice;
            initializeBoard();
            printBoard();
			int isGameRunning = 1;
            sw = 0;
            while (isGameRunning) {
            	 
                if (sw == 0) {
             s=0;
			
                    

                    if(sw==0){
                    	
					
                    while (1) {
                        printf("%s: If you want a wall, enter 1. If you want to move, enter 2. To save the game, enter 0!\n",
                               player1);
                        if (scanf("%d", &choice) != 1 || (choice != 0 && choice != 1 && choice != 2)) {
                            while (getchar() != '\n');
                            printf("Invalid input. Please enter 0, 1, or 2.\n");
                        } else {
                            break;
                        }
                    }
                    while (choice != 0 && choice != 1 && choice != 2 && choice < 0);
                    if (choice == 1) {
                        int x, y;
                        char xy;
                      
                        if (wallcount1 >= numberwal) {
                        	wallcount1 = numberwal;
                            printf("You are out of wall.\n");
                            continue;
                        }
                        int numberwall = numberwal - wallcount1;
                        printf("%s : %d walls are left^^\n", player1, numberwall);
                        do {
                            printf("%s :please enter the coordinates\n", player1);
                            if (scanf("%d", &x) != 1) {
                                while (getchar() != '\n');
                                printf("wrong cordination.\n");
                                continue;
                            }
                            if (scanf("%d", &y) != 1) {
                                while (getchar() != '\n');
                                printf("wrong cordination.\n");
                                continue;
                            }
                        } while (x <= 0 || y <= 0);

                        if (x > width+1 || y > width+1) {
                            printf("wrong cordination.\n");
                            continue;
                        }
                        int sw1 = 1;
                        printf("if you want make a wall down or up enter u else enter l\n");
                        while (sw1) {
                            scanf(" %c", &xy);
                            if (xy == 'l' || xy == 'u') {
                                sw1 = 0;
                            }
                        }
                        wall(x, y, xy
                        );
                        if (xy == 'u' && board[(x - 1) * 2][2 * y - 1] == ')' &&board[(x - 1) * 2][2 * y + 1] == ')') {
                            wallcount1++;
                            s=1;
                        }
                        if (xy == 'l' && board[2 * x + 1][(y - 1) * 2] == ')' &&board[2 * x - 1][(y - 1) * 2] == ')') {
                            wallcount1++;
                            s=1;
                        }
                        
                    } else if (choice == 2) {
                        printf("%s : If you want move up enter u, down enter d, left enter l and right enter r^^\n",player1);
                        moveFirstPlayer();
                        
                        
                    }
                    if (starx1 == 1 && board[starx1 - 1][stary1] != ')') {
                        printf("%s win!", player1);
                        break;
                    } else if (choice == 0) {
                        file = fopen("saved_game.txt", "w");
                        saveGame(file);
                        isGameRunning = 0;
                    }
                    system("cls");
                    printBoard();
					}
				}
		 if(s==1){
		awardpunishment2();
	       printBoard();
		   s=0;
		   }
		   if (sw == 1) {
		    w=0;
			if(sw==1){	
                    while (1) {
                        printf("%s: If you want a wall, enter 1. If you want to move, enter 2. To save the game, enter 0!\n",
                               player2);
                        if (scanf("%d", &choice) != 1 || (choice != 0 && choice != 1 && choice != 2)) {
                            while (getchar() != '\n');
                            printf("Invalid input. Please enter 0, 1, or 2.\n");
                        } else {
                            break;
                        }
                    }
                
                    if (choice == 1) {
                        int x, y;
                        char xy;
                        if (wallcount2 >= numberwal) {
                        		wallcount2 = numberwal;
                            printf("You are out of wall.\n");
                            continue;
                        }
                        int numberwall = numberwal - wallcount2;

                        printf("%s : %d walls are left^^\n", player2, numberwall);
                        do {
                            printf("%s :please enter the coordinates\n", player2);

                            if (scanf("%d", &x) != 1) {
                                while (getchar() != '\n');
                                printf("wrong cordination.\n");
                                continue;
                            }
                            if (scanf("%d", &y) != 1) {
                                while (getchar() != '\n');
                                printf("wrong cordination.\n");
                                continue;
                            }
                        } while (x <= 0 || y <= 0);
                        if (x > width+1 || y > width+1) {
                            printf("wrong coordination.\n");
                            continue;
                        }
                        int sw2 = 1;
                        printf("if you want make a wall down or up enter u else enter l\n");
                        while (sw2) {
                            scanf(" %c", &xy);
                            if (xy == 'l' || xy == 'u') {
                                sw2 = 0;
                            }
                        }
                        wall(x, y, xy
                        );
                        if (xy == 'u' && board[(x - 1) * 2][2 * y - 1] == ')' &&board[(x - 1) * 2][2 * y + 1] == ')') {
                            wallcount2++;
                            w=1;
                        }
                        if (xy == 'l' && board[2 * x + 1][(y - 1) * 2] == ')' &&board[2 * x - 1][(y - 1) * 2] == ')') {
                            wallcount2++;
                            w=1;
                        }
                    } else if (choice == 2) {
                        printf("%s : If you want move up enter u, down enter d, left enter l and right enter r^^\n",player2);

                        moveSecondPlayer();

                    }
                    if (starx2 == height * 2 - 1 && board[starx2 + 1][stary2] != ')') {
                        printf("%s win!", player2);
                        break;
                    } else if (choice == 0) {
                        file = fopen("saved_game.txt", "w");
                        saveGame(file);
                        fclose(file);
                        isGameRunning = 0;
                    }
                    system("cls");
                    printBoard();
					}
		
      
                }
                          if(w==1){
				
                  	awardpunishment();
	      			 printBoard();
					   w=0;}
                
				
            }
        }
    }
}

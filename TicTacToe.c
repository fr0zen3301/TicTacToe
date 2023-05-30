#include <stdio.h>
#include <stdlib.h>

char matrix[3][3];


void init_matrix(void)
{
    int j, i;

    for(i=0; i<3; i++)
        for(j=0; j<3; j++) matrix[i][j] =  ' ';
}

// player turn
void Player1(void)
{
    int x, y;
    printf("Enter X's coordinates to move: ");
    scanf("%d%*c%d", &x, &y);

    x--; y--;

    if(matrix[x][y]!= ' ')
    {
        printf("Error, type from 1 to 3: \n");
        Player1();
    }
    else
        matrix[x][y] = 'X';
}
void Player2(void)
{
    int i, j;
    printf("Enter Y's coordinates to move: ");
    scanf("%d%*c%d", &i, &j);

    i--; j--;

    if(matrix[i][j]!=' ')
    {
        printf("Error, type from 1 to 3: \n");
        Player2();
    }

    if(i*j==9)
    {
        printf("Draw! No one won. \n");
        exit(0);
    }
    else
        matrix[i][j] = 'O';

}

void DisplayBoard(void)
{
  int t;

  for(t=0; t<3; t++) {
    printf(" %c | %c | %c ",matrix[t][0],
            matrix[t][1], matrix [t][2]);
    if(t!=2) printf("\n---|---|---\n");
  }
  printf("\n");
}


char check(void)
{
    int i;

    // 컬럼 확인
    for (i=0; i<3; i++)
    {
        if (matrix[0][i]==matrix[1][i] && matrix[0][i]==matrix[2][i])
            return matrix[0][i];
    }

    // 열 확인
    for(i=0; i<3; i++)
    {
        if(matrix[i][0]==matrix[i][1] && matrix[i][0]==matrix[i][2])
            return matrix[i][0];
    }

    // diagonals 확인
    if(matrix[0][0]==matrix[1][1] && matrix[1][1]==matrix[2][2])
       return matrix[0][0];

    if(matrix[0][2]==matrix[1][1] && matrix[1][1]==matrix[2][0])
       return matrix[0][2];

    return ' ';

}

int main()
{
    char end;

    printf("Let's start our Tic-Tac-Toe game!\n");
    end = ' ';
    init_matrix();

    do
    {
        DisplayBoard();
        Player1();
        // 바로 확인
        end = check();
        if (end!= ' ')
            break;
        Player2();
        end = check();
    }
    while (end== ' ');

    if (end=='X')
        printf("You won! Congrats!\n");
    else
        printf("You loose, gg! \n");
    DisplayBoard();

    return 0;
}
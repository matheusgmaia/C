/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements the Game of Fifteen (generalized to d x d).
 *
 * Usage: ./fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [MIN,MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// board's minimal dimension
#define MIN 3

// board's maximal dimension
#define MAX 9

// board, whereby board[i][j] represents row i and column j
int board[MAX][MAX];

// board's dimension
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
void save(void);

int main(int argc, string argv[])
{
    // greet player
    greet();

    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < MIN || d > MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            MIN, MIN, MAX, MAX);
        return 2;
    }

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // saves the current state of the board (for testing)
        save();

        // check for win
        if (won())
        {
            printf("VC GANHOU!!!!!!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep for animation's sake
        usleep(500000);
    }

    // that's all folks
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1,
 * (i.e., fills board with values but does not actually print them),
 * whereby board[i][j] represents row i and column j.
 */
void init(void)
{
    // TODO
    
    int k=0;
    int j=0;
    while(true){
    for (int i=0; i<d; i++) {
    board[i][j]= (d*d - (k+1));
    k++;
    
    }
    j++;
    if (j==(d))
    {
    if (d%2==0 )
    {
    board[d-3][d-1] = 1;
    board[d-2][d-1] = 2;
    } 
    break;
    }
    }
}
    

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    // TODO
   int j=0;
   while(true){
   for (int i=0; i<d; i++)
   {
   if (i==0)
   {
   printf("#");
   }
   if (board[i][j]>0){
   
   if (board[i][j]<10){
   printf (" ");
   }
   printf(" %d", (board[i][j]));
   
   }
   else 
   printf("  _");
   }
   printf(" #\n");
   j++;
   if (j==d)
   {
   break;
   }
   }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    // TODO
    int m = 0;
    int n = -1;
    int j = 0;
    int i = 0;
    while(n==-1){
    for (i=0; i<d; i++) {
    if (board[i][j]==0)
    {
    m = i;
    n = j;
    break;   
    }}
    j++;
    }
    
    int element= board[m][n];
    if(tile==board[m+1][n])
    {
    board[m][n]=board[m+1][n];
    board[m+1][n]= element;
    return true;
    }

    else if(tile==board[m][n+1])
    {
    board[m][n]=board[m][n+1];
    board[m][n+1]= element;
    return true;
    }
    else if(tile==board[m][n-1])
    {
    board[m][n]=board[m][n-1];
    board[m][n-1]= element;
    return true;
    }
    else if(tile==board[m-1][n])
    {
    board[m][n]=board[m-1][n];
    board[m-1][n]= element;
    return true;
    }
    else
    return false;
    
    }
  

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    // TODO
    int i=0;
    int j=0;
    int k=0;
    int l=0;
    while(k != (d*d)){
    for (i=0; i<d; i++)
    {
    l++;
    if (board[i][j]==l)
    {
    k++;
    if (k == (d*d-1))
    {
    return true;
    }
    }
    else
    return false;
    }
    j++;
    }
    return true;
    }
    

/**
 * Saves the current state of the board to disk (for testing).
 */
void save(void)
{
    // log
    const string log = "log.txt";

    // delete existing log, if any, before first save
    static bool saved = false;
    if (!saved)
    {
        unlink(log);
        saved = true;
    }

    // open log
    FILE* p = fopen(log, "a");
    if (p == NULL)
    {
        return;
    }

    // log board
    fprintf(p, "{");
    for (int i = 0; i < d; i++)
    {
        fprintf(p, "{");
        for (int j = 0; j < d; j++)
        {
            fprintf(p, "%i", board[i][j]);
            if (j < d - 1)
            {
                fprintf(p, ",");
            }
        }
        fprintf(p, "}");
        if (i < d - 1)
        {
            fprintf(p, ",");
        }
    }
    fprintf(p, "}\n");

    // close log
    fclose(p);
}

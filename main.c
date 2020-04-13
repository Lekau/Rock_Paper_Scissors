#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
void au_putchar(char c)
{
    write(1, &c, 1);
}

void au_putstr(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        au_putchar(str[i++]);
}

int win_win(char comp, char human)
{
    if ((human == 'R' || human == 'P' || human == 'S') && (comp == 'R' || comp == 'P' || comp == 'S'))
    {
        if ((human == 'S' && comp == 'P') || (human == 'P' && comp == 'R') || (human == 'R' && comp == 'S'))
            return(2);
        else 
            return(1);
    }
    else 
        return (0);
}

int main (void)
{
    int rounds = 0;
    int randy;
    int comp_wins = 0;
    int human_wins = 0;
    char human_play;
    char comp_play;
    while (rounds++ < 3)
    {
        au_putstr("Enter your play: \n'R' for rock \n'P' for paper \n'S' for scissors \n"); 
        human_play = getchar();
        getchar();
        randy = rand() % 3;
        if (randy == 1)
            comp_play = 'R';
        else if (randy == 2)
            comp_play = 'P';
        else
            comp_play = 'S';

        if (comp_play != human_play)
        {
            if (win_win(comp_play, human_play) == 1)
            {
                au_putstr("Computer wins round!!!\n");
                 comp_wins++;
            }
            else if (win_win(comp_play, human_play) == 2)
            {
                au_putstr("Human wins round!!!\n");
                human_wins++;
            }
            else 
            {
                au_putstr("GAME OVER!!! \nHuman you didn't enter the correct character. \nHint: we only work with uppercase \n");
                return (0);
            }
        }
        else 
            au_putstr("round is a Draw!!!\n");     
    }
    
    if (comp_wins > human_wins)
        au_putstr("Computer won the game!!!\n");
    else if (comp_wins < human_wins)
        au_putstr("Human won the game!!!\n");
    else 
        au_putstr("Game ends in a Draw!!!\n");
    
    au_putstr("\n Thank you for Playing!!!\n");
    return (0);
}
#include <time.h>
#include <math.h>
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>

int health = 100;
int ram = 50;
int cheetahealth = 25;
int newhealth;
int attack;
int feedback = 0;
int check;

int losehealth(void)
{
    cheetahealth = cheetahealth - rand() % 10;
    newhealth = cheetahealth;
    check++;
    return 0;
}

int rngbase(void)
{
    srand(time(0));
    for(int i = 0; i < 1; i++)
    losehealth();
    attack = 25 - cheetahealth;
    if (newhealth > 0)
    {
        printf("\nYou began to \033[0;32mcombo\033[0m!\n");
        sleep(1);
        printf("Enemy -{\033[0;34mCHROME CHEETAH\033[0m}- went down to \033[0;33m%d\033[0m health\n", newhealth);
        sleep(2);
        srand(time(0));
        losehealth();
        attack = newhealth - cheetahealth;
        if (newhealth > 0)
        {
            printf("Enemy -{\033[0;34mCHROME CHEETAH\033[0m}- went down to \033[0;33m%d\033[0m health\n\n", newhealth);
            sleep(2);
            printf("Enemy -{\033[0;34mCHROME CHEETAH\033[0m}- ate \033[0;35m10\033[0m of your \033[31;1mRAM\033[0m...");
            ram -= 10;
            sleep(1);
            printf(" \033[0;35m%d\033]0m \033[31;1m RAM\033[0m left\n", ram);
        }
        else if (newhealth == 0 || newhealth < 0)
        {
            sleep(2);
            printf("\n> You \033[0;31mdefeated\033[0m the -{\033[0;34mCHROME CHEETAH\033[0m}-!\n\n");
            sleep(3);
            printf("> You got \033[0;35m10XP\033[0m!\n");
        }
    }
    else if (ram == 0 || ram < 0)
    {
        printf("> You ran out \033[31;1mRAM\033[0m and your computer \033[0;31mcrashed\033[0m.\n");
    }
    else if (newhealth == 0 || newhealth < 0)
    {
        sleep(2);
        printf("\n> You \033[0;31mdefeated\033[0m the -{\033[0;34mCHROME CHEETAH\033[0m}-!\n\n");
        sleep(3);
        printf("> You got \033[0;35m10XP\033[0m!\n");
    }
    return 0;
}

int cheetahbattle(void)
{
    printf("> \033[0;32mbattle...");
    sleep(2);
    printf(" \033[32;7mBEGIN!\n");
    sleep(1);
    printf("\033[0m\n");
    printf("   \033[0;36mPlayer\033[0m:\n     \033[31;1mRAM\033[0m - {\033[0;35m50\033[0m}\n\n");
    printf("\033[0;33m");
    printf("  _,\n");
    printf("<|  `.\n");
    printf("  `.  `_'^----.._           _\n");
    printf("   `. ,     _, `.`-.       ' )\n");
    printf("   , ),'--~'(  / ` .`-.___,-'\n");
    printf("  ( /;       `'|,   `\n");
    printf("  _/'        _//     `.\n");
    printf(" ' ``       ' ``    ' `\033[0m\n\n");
    LOOP1: sleep(1);
    if (ram == 0)
    {
        printf("> You ran out \033[31;1mRAM\033[0m and your computer \033[0;31mcrashed\033[0m.\n");
        if(feedback > 1)
        {
            sleep(2);
            printf("> Guess you forgot you aren't Doc. Doolittle, huh?\n\n");
        }
    }
    else if (ram > 0)
    {
    string menu = get_string("\n'\033[0;31mAttack\033[0m' - Combo, '\033[0;32mRun\033[0m', '\033[0;35mAssess\033[0m', or '\033[0;32mNegotiate\033[0m': ");
    if (strcmp(menu, "attack") == 0 || strcmp(menu, "Attack") == 0 || strcmp(menu, "combo") == 0 || strcmp(menu, "Combo") == 0)
    {
        rngbase();
        if(newhealth > 0)
        {
            goto LOOP1;
        }
    }
    else if (strcmp(menu, "Run") == 0 || strcmp(menu, "run") == 0)
    {
        printf("> The coward ran away...\n");
        sleep(1);
    }
    else if (strcmp(menu, "Negotiate") == 0 || strcmp(menu, "negotiate") == 0)
    {
        if (feedback == 0)
        {
            printf("> It's...");
            sleep(1);
            printf(" uh, ");
            sleep(1);
            printf("a cheetah.");
            sleep(2);
            printf(" It can't understand you.\n\n");
            sleep(1);
            printf("Enemy -{\033[0;34mCHROME CHEETAH\033[0m}- ate \033[0;35m10\033[0m of your \033[31;1mRAM\033[0m...");
            ram -= 10;
            sleep(1);
            printf(" \033[0;35m%d\033]0m \033[31;1m RAM\033[0m left\n", ram);
            feedback++;
            goto LOOP1;
        }
        else if (feedback == 1)
        {
            printf("> You talk to the cheetah.");
            sleep(1);
            printf(" It growls at you\n\n");
            sleep(1);
            printf("Enemy -{\033[0;34mCHROME CHEETAH\033[0m}- ate \033[0;35m10\033[0m of your \033[31;1mRAM\033[0m...");
            ram -= 10;
            sleep(1);
            printf(" \033[0;35m%d\033]0m \033[31;1m RAM\033[0m left\n", ram);
            feedback++;
            goto LOOP1;
        }
        else if (feedback > 1)
        {
            printf("> ???");
            sleep(2);
            printf(" I admire your attempts at \033[0;32mpacifism\033[0m\n\n");
            sleep(1);
            printf("Enemy -{\033[0;34mCHROME CHEETAH\033[0m}- ate \033[0;35m10\033[0m of your \033[31;1mRAM\033[0m...");
            ram -= 10;
            sleep(1);
            printf(" \033[0;35m%d\033]0m \033[31;1m RAM\033[0m left\n", ram);
            feedback++;
            goto LOOP1;
        }
    }
    else if (strcmp(menu, "Assess") == 0 || strcmp(menu, "assess") == 0)
    {
        sleep(1);
        printf("\nEnemy -{\033[0;34mCHROME CHEETAH\033[0m}-\n");
        sleep(1);
        if(check == 0)
        {
            printf("   Health: \033[0;33m25\033[0m\n");
        }
        else if (check > 1)
        {
            printf("   Health: \033[0;33m%d\033[0m\n", newhealth);
        }
        sleep(1);
        printf("   \033[0;36mSpecial Ability\033[0m: Hunger - \n");
        sleep(1);
        printf("     -{\033[0;34mCHROME CHEETAH\033[0m}- Eats \033[0;35m10\033[0m\033[31;1m RAM\033[0m every turn\n\n");
        sleep(2);
        printf("Enemy -{\033[0;34mCHROME CHEETAH\033[0m}- ate \033[0;35m10\033[0m of your \033[31;1mRAM\033[0m...");
        ram -= 10;
        sleep(1);
        printf(" \033[0;35m%d\033]0m \033[31;1m RAM\033[0m left\n", ram);
        printf("\n");
        goto LOOP1;
    }
    else if (menu)
    {
        printf("\n> Hmm...");
        sleep(1);
        printf(" Maybe you misspelled something?\n\n");
        sleep(1);
        goto LOOP1;
    }
        return 0;
    }
return 0;
}

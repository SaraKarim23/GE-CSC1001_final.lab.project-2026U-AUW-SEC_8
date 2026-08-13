#include <stdio.h>

void score(const char answers[], int n)
{
    int a = 0, b = 0, c = 0;

    for (int i = 0; i < n; i++) {
        if (answers[i] == 'A')
            a++;
        else if (answers[i] == 'B')
            b++;
        else if (answers[i] == 'C')
            c++;
    }

    printf("\n\n=====Quiz results=====:\n");
    printf("A answers: %d\nB answers: %d\nC answers: %d\n", a, b, c);

    if (a >= b && a >= c)
        printf(
               "......................................\n"
               "You should try mystery or thriller K-dramas 0_0\n"
               "Some good ones are:\n"
               "1) Strangers From Hell\n"
               "2) Flower Of Evil\n"
               "3) Mouse\n"
               "......................................\n");
    else if (b >= a && b >= c)
        printf(
               "......................................\n"
               "You need to try balanced romance and comedy K-dramas ^_^\n"
               "Fan favorites are:\n"
               "1) Lovely Runner\n"
               "2) Hometown Cha Cha Cha\n"
               "3) True Beauty\n"
               "......................................\n");
    else
        printf(
               "......................................\n"
               "Try adventurous K-dramas! >u<\n"
               "Some fan favorites are:\n"
               "1) Moving\n"
               "2) Twinkling Watermelon\n"
               "3) The Trauma Code\n"
               "......................................\n");
}

char get_answer(void)
{
    char answer;

    do {
        printf("Enter A, B, or C: ");
        scanf(" %c", &answer);

        if (answer >= 'a' && answer <= 'c')
            answer -= 'a' - 'A';

        if (answer != 'A' && answer != 'B' && answer != 'C')
            printf("Invalid answer. Please try again.\n");
    } while (answer != 'A' && answer != 'B' && answer != 'C');

    return answer;
}

int main(void)
{
    char name[30];
    char decisions[5];
    int i = 0;
    char ans;

    printf("==========KDRAMA RECS FOR NEWBIES!==========\n"
        "............................................\n"
        "What's your name?\n");
    scanf("%29s", name);

    printf(
        "Hi %s!\n"
        "Are you a kdrama world newbie?\n"
        "Look no further because you're inthe right place!\n"
        "Take this short and fun quiz to get recommended\n"
        "the top three kdramas for YOU <3\n"
        "(N.B: This quiz uses terms used by Asian millennials and older GenZ)\n\n"
        "............................................\n",
        name);

    printf(
        "............................................\n"
        "1) To start off, let's play around with some familiar names.\n"
        "Would you consider yourself:\n"
        "A) A reserved Rokina\n"
        "B) A calm Kamal\n"
        "C) A brave Babul\n"
        "............................................\n"
        );

    ans = get_answer();
    decisions[i++] = ans;

    if (ans == 'A')
        printf("Ooh! You did seem quite sophisticated!\n");
    else if (ans == 'B')
        printf("Need you ('Kamal') during finals! >_<\n");
    else
        printf("You know what's brave? Me choosing this idea for the project T_T\n");

    printf(
        "............................................\n"
        "\n2) When you see romance on screen, do you:\n"
        "A) Feel your skin crawl and want to throw up.\n"
        "B) Worry that a family member will walk into the room :0\n"
        "C) Feel euphoric like the song 'Life is worth living' by Justin Bieber.\n"
        "............................................\n"
        );
    ans = get_answer();
    decisions[i++] = ans;

    if (ans == 'A')
        printf("So not a fan of romance, got it.\nThis narrowed the options a lot!\n");
    else if (ans == 'B')
        printf("PDA is a no-no in your house then, got it!\n");
    else
        printf("You're a hopeless romantic then, got it!\n");

    printf(
        "...........................................\n"
        "\n3) If you hear a sudden loud noise in your house late at night, would you:\n"
        "A) Become the most religious person in the world\n"
        "B) Head towards the noise to check it out (psycho behaviour)\n"
        "C) Think logically about what could've made the noise.\n"
        "...........................................\n"
        );
    ans = get_answer();
    decisions[i++] = ans;

    if (ans == 'A')
        printf("Absolutely valid reaction.\n");
    else if (ans == 'B')
        printf("If this was a movie you'd be the first character to die -__-\n");
    else
        printf("You're definitely a trusted adult. I'll call you when I get into trouble.\n");

    printf(
        "...........................................\n"
        "\n4) Your friend comes up to you and tells you to join them on an adventure.\n"
        "How would you react?\n"
        "A) Say 'no Diva, I have a curfew'\n"
        "B) Ask them to provide somewhat of a plan\n"
        "C) Start leading the way before them.\n"
        "...........................................\n"
    );
    ans = get_answer();
    decisions[i++] = ans;

    if (ans == 'A')
        printf("Cinderella, it's fine.\n");
    else if (ans == 'B')
        printf("Hey, nothing's wrong with some spontaneity, amirite?\n");
    else
        printf("Adrenaline lover! Got it.\n");

    printf(
        "..........................................\n"
        "\n5) Do you care a lot about the emotional depth of characters,\n"
        "or are you someone who watches fiction just for fun?\n"
        "A) Shallow characters are painful to watch!\n"
        "B) I can enjoy all sorts of characters.\n"
        "C) Who cares about depth? If the show is fun, I'll watch it.\n"
        "..........................................\n"
    );
    ans = get_answer();
    decisions[i++] = ans;

    if (ans == 'A')
        printf("I agree!\n");
    else if (ans == 'B')
        printf("That's an admirable trait, bestie.\n");
    else
        printf("Yeah, sometimes fun matters more to me too.\n");

    score(decisions, i);

    return 0;
}

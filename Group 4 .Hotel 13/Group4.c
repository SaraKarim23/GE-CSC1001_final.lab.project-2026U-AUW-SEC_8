#include<stdio.h>
#include<string.h>

#define NUM_SUSPECTS 6
#define NAME_LEN    30
#define TEXT_LEN    100

char names[NUM_SUSPECTS][NAME_LEN]= {"Rosalind Vance", "Thomas Ferris","Meera Kapoor", "Gideon Marsh", "Priya Nandan", "Callum Reed"};
char roles[NUM_SUSPECTS][10]={"Guest","Guest","Guest","Staff","Staff","Staff"};
char motives[NUM_SUSPECTS][TEXT_LEN]= {
    "An inheritance dispute over a business she shared with the victim",
    "The victim owed him a large, unpaid gambling debt",
    "She was secretly investigating the victim for a scandal",
    "The victim threatened to have him fired after 20 years of service",
    "The victim humiliated her in front of everyone at dinner",
    "The victim caught him stealing from the hotel safe"};

char alibis[NUM_SUSPECTS][TEXT_LEN]= {
         "Says she was reading alone in the lounge all night",
         "Claims he was on a long phone call in his room",
         "Says she was writing notes in the dining hall",
         "Claims he was locking up the front gate before the storm hit",
         "Says she was cleaning the kitchen after dinner",
         "Claims he was patrolling the east wing on his usual rounds"
};
int suspicion[NUM_SUSPECTS]= {0,0,0,0,0,0};
void pause_for_effect(void)
{
    printf("\n-----------------------------------\n\n");
}
void readLine(char *buffer,int size)
 {
    if(fgets(buffer,size,stdin)!=NULL)
     {
        buffer[strcspn(buffer,"\n")]= '\0';
     }
 }
void sceneOne_theBody(void)
{
    printf("SCENE 1- THE BODY IN ROOM 13\n\n");
    printf("The storm knocked out the phone lines an hour ago.Now the\n");
    printf("caretaker is pounding on your door: a guest has been found dead\n");
    printf("in Room 13. No roads in or out until the storm breaks at dawn.\n\n");
    printf("Only six people were on the property tonight--three guests,\n");
    printf("three staff. One of them did this.\n\n");
    printf("Kneeling by the back door,you find a single muddy footprint,\n");
    printf("clearly left by a hotel-issued boot, size 11.\n");
    pause_for_effect();
}
void sceneTwo_interrogateGuests(void)
{
int choice;
printf("SCENE 2 - INTERROGATE THE GUESTS\n\n");
for (int i = 0; i < 3; i++) {
    printf("-- %s (%s) --\n", names[i], roles[i]);
    printf("Motive: %s\n", motives[i]);
    printf("Alibi:  %s\n\n", alibis[i]);
    printf("How do you question them?\n");
    printf("  1) Press hard on the details of their alibi\n");
    printf("  2) Ask gently and let them talk freely\n");
    printf("> ");
    scanf("%d", &choice);
    getchar();

    if (choice == 1) {
        printf("\nThey get flustered under pressure and their story wavers slightly.\n");
        suspicion[i] += 2;
    } else {
        printf("\nThey relax and speak openly, but offer nothing new.\n");
        suspicion[i] += 1;
    }
}
pause_for_effect();
}

void sceneThree_interrogateStaff(void) {
    int choice;
    printf("SCENE 3 - INTERROGATE THE STAFF\n\n");

    for (int i = 3; i < NUM_SUSPECTS; i++) {
        printf("-- %s (%s) --\n", names[i], roles[i]);
        printf("Motive: %s\n", motives[i]);
        printf("Alibi:  %s\n\n", alibis[i]);
        printf("How do you question them?\n");
        printf("  1) Press hard on the details of their alibi\n");
        printf("  2) Ask gently and let them talk freely\n");
        printf("> ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            printf("\nThey get flustered under pressure and their story wavers slightly.\n");
            suspicion[i] += 2;
        } else {
            printf("\nThey relax and speak openly, but offer nothing new.\n");
            suspicion[i] += 1;
        }

        pause_for_effect();
    }
}

void sceneFour_forensics(void) {
    int printSize;
    printf("SCENE 4 - THE FOOTPRINT\n\n");
    printf("You compare the size-11 footprint against the staff boot records:\n");
    printf("  Gideon Marsh (Caretaker): size 9\n");
    printf("  Priya Nandan (Cook):      size 7\n");
    printf("  Callum Reed (Watchman):   size 11\n\n");

    printf("Enter the footprint size to check for a match: ");
    scanf("%d", &printSize);
    getchar();

    /* direct comparisons instead of a search algorithm */
    if (printSize == 9) {
        printf("\nThe print matches Gideon Marsh's boots.\n");
        suspicion[3] += 5;
}
    else if (printSize == 11)
    {
        printf("\nThe print matches Callum Reed's boots.\n");
        printf("But he claimed to be in the EAST wing.\n");
        printf("The footprint was found at the WEST wing back door.\n");
        printf("His alibi does not hold up.\n");

        suspicion[5] += 5;
    }
    else
    {
        printf("\nNo staff boot matches that size.\n");
    }

    pause_for_effect();
}

void sceneFive_summary(void)
{
    printf("SCENE 5 - SUSPICION SUMMARY\n\n");

    for (int i = 0; i < NUM_SUSPECTS; i++)
    {
        printf("%-20s Suspicion: %d\n",
               names[i], suspicion[i]);
    }

    pause_for_effect();
}

void sceneSix_accusation(void)
{
    char accusedName[NAME_LEN];

    printf("SCENE 6 - THE ACCUSATION\n\n");

    printf("Suspects:\n");
    printf("Rosalind Vance\n");
    printf("Thomas Ferris\n");
    printf("Meera Kapoor\n");
    printf("Gideon Marsh\n");
    printf("Priya Nandan\n");
    printf("Callum Reed\n\n");

    printf("Who do you accuse? ");

    readLine(accusedName, NAME_LEN);

    if (strcmp(accusedName, "Callum Reed") == 0 &&
        suspicion[5] >= 6)
    {
        printf("\nYou lay out the footprint, the contradicted alibi,\n");
        printf("and the motive. Callum Reed has no answer.\n");
        printf("ENDING: CASE CLOSED\n");
        printf("YOU WIN! You correctly identified Callum Reed as the killer.\n");
    }
    else if (strcmp(accusedName, "Callum Reed") == 0)
    {
        printf("\nYou accuse Callum Reed -- and you're right.\n");
        printf("But your evidence is thin.\n");
        printf("ENDING: RIGHT SUSPECT, WEAK CASE\n");
    }
    else
    {
        printf("\nYou accuse %s. But you're wrong.\n", accusedName);
        printf("The real killer was Callum Reed.\n");
        printf("ENDING: THE KILLER WALKS FREE\n");
    }
}

int main(void)
{
    printf("====================================\n");
    printf("        MURDER AT HOTEL 13\n");
    printf("====================================\n\n");

    sceneOne_theBody();
    sceneTwo_interrogateGuests();
    sceneThree_interrogateStaff();
    sceneFour_forensics();
    sceneFive_summary();
    sceneSix_accusation();

    printf("\nThank you for playing MURDER AT HOTEL 13.\n");

    return 0;
}

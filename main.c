#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inventoryShow(int inventory[5], int guide[2], int goldenStatue[2]);
void readGuide(int inventory[5], int guide[2]);
void items(int level, int guide[2], int goldenStatue[2]);
void takeAll(int inventory[5], int level, int guide[2], int goldenStatue[2]);
void dropAll(int inventory[5], int level, int guide[2], int goldenStatue[2]);
void takeGuide(int inventory[5], int level ,int guide[2]);
void dropGuide(int inventory[5], int level ,int guide[2]);
void takeGoldenStatue(int inventory[5], int level ,int goldenStatue[2]);
void dropGoldenStatue(int inventory[5], int level ,int goldenStatue[2]);

int main()
{
    // Action
    char *action, *action0, *item, *item0;

    action = (char*)malloc(100);
    action0 = (char*)malloc(100);

    item = (char*)malloc(100);
    item0 = (char*)malloc(100);

    // Intro
    int intro = 0;

    // End and level statuses
    int end = 0, sRoom = 0, sHall = 0, sCellar = 0, sField = 0, sCorridor = 0;

    // Levels
    int level = 0, room = 0, hall = 1, cellar = 2, field = 3, corridor = 4;

    // Inventory and ItemIDs
    int inventory[5] = {0, 0, 0, 0, 0}, guide[2] = {1, 1}, goldenStatue[2] = {2, 2};


    // Intro
    printf("Welcome to Interium, a free program intended to take you to a journey full of adventure.\n"
           "Hope you'll enjoy.\n"
           "\nDo you want an introduction? [Y/N]\n");
    while(intro == 0){
        gets(action0);
        action = strlwr(action0);
        if(strcmp(action, "yes") == 0 || strcmp(action, "y") == 0){
            printf("Intro\n");
            intro = 1;
        }
        else if(strcmp(action, "no") == 0 || strcmp(action, "n") == 0){
            intro = 1;
        }
        else{
            printf("\nI don't recognize this sentence\n");
        }
    }

    /* The Game */
    while(end == 0){

        /* The Room */
        if(level == room){

            /* Entry Dialogue */
            if(sRoom == 0){
                printf("\nYou are in a small dim lit room\n"
                       "There is a large doorway to the north, smaller doors to the west and east, and a broken window of your size to the south\n");
                sRoom = 2;
            }
            else if(sRoom == 1){
                printf("\nYou are in a small dim lit room\n"
                       "There is a large doorway to the north, smaller doors to the west and east, and a broken window of your size to the south\n");
                sRoom = 2;
            }
            else{
                printf("\nThe Room\n");
            }

            /* Items */
            items(level, guide, goldenStatue);

            /* Action */
            gets(action0);
            action = strlwr(action0);

            /* Directions */
            if(strcmp(action, "north") == 0 || strcmp(action, "n") == 0){
                level = hall;
            }
            else if(strcmp(action, "northeast") == 0 || strcmp(action, "ne") == 0){
                printf("\nYou can't go that direction\n");
            }
            else if(strcmp(action, "east") == 0 || strcmp(action, "e") == 0){
                level = cellar;
            }
            else if(strcmp(action, "southeast") == 0 || strcmp(action, "se") == 0){
                printf("\nYou can't go that direction\n");
            }
            else if(strcmp(action, "south") == 0 || strcmp(action, "s") == 0){
                printf("\nYou successfully made it trough the window");
                level = field;
            }
            else if(strcmp(action, "southwest") == 0 || strcmp(action, "sw") == 0){
                printf("\nYou can't go that direction\n");
            }
            else if(strcmp(action, "west") == 0 || strcmp(action, "w") == 0){
                level = corridor;
            }
            else if(strcmp(action, "northwest") == 0 || strcmp(action, "nw") == 0){
                printf("\nYou can't go that direction\n");
            }

            /* Read */
            else if(strcmp(action, "read") == 0){
                printf("\nWhat exactly would you like to read?\n");
                gets(item0);
                item = strlwr(item0);

            }
            else if(strcmp(action, "read guide") == 0){
                readGuide(inventory, guide);
            }

            /* Inventory */
            else if(strcmp(action, "inventory") == 0 || strcmp(action, "inv") == 0){
                inventoryShow(inventory, guide, goldenStatue);
            }

            /* Take */
            else if(strcmp(action, "take") == 0){
                printf("\nYou have to be more specific\n");
            }
            else if(strcmp(action, "take all") == 0){
                takeAll(inventory, level, guide, goldenStatue);
            }
            else if(strcmp(action, "take guide") == 0){
                takeGuide(inventory, level, guide);
            }
            else if(strcmp(action, "take golden statue") == 0){
                takeGoldenStatue(inventory, level , goldenStatue);
            }

            /* Drop */
            else if(strcmp(action, "drop") == 0){
                printf("\nYou have to be more specific\n");
            }
            else if(strcmp(action, "drop all") == 0){
                dropAll(inventory, level, guide, goldenStatue);
            }
            else if(strcmp(action, "drop guide") == 0){
                dropGuide(inventory, level, guide);
            }
            else if(strcmp(action, "drop golden statue") == 0){
                dropGoldenStatue(inventory, level, goldenStatue);
            }

            /* Look Around */
            else if(strcmp(action, "look") == 0){
                sRoom = 1;
            }

            /* Error */
            else{
                printf("\nI don't recognize this sentence\n");
            }
        }


        /* The Hall */
        if(level == hall){

            /* Entry Dialogue */
            if(sHall == 0){
                printf("\nYou entered a large hall, with a wierd looking statues in the corners and red carpet on the floor. At the end of the hall there seems to be some kind of altar\n"
                       "The only exit seems to be the one to the south\n");
                sHall = 2;
            }
            else if(sHall == 1){
                printf("\nYou entered a large hall, with a wierd looking statues in the corners and red carpet on the floor. At the end of the hall there seems to be some kind of altar\n"
                       "The only exit seems to be the one to the south\n");
                sHall = 2;
            }
            else{
                printf("\nThe Hall\n");
            }

            /* Items */
            items(level, guide, goldenStatue);

            /* Action */
            gets(action0);
            action = strlwr(action0);

            /* Directions */
            if(strcmp(action, "north") == 0 || strcmp(action, "n") == 0){
                printf("\nYou can't go that direction\n");
            }
            else if(strcmp(action, "northeast") == 0 || strcmp(action, "ne") == 0){
                printf("\nYou can't go that direction\n");
            }
            else if(strcmp(action, "east") == 0 || strcmp(action, "e") == 0){
                printf("\nYou can't go that direction\n");
            }
            else if(strcmp(action, "southeast") == 0 || strcmp(action, "se") == 0){
                printf("\nYou can't go that direction\n");
            }
            else if(strcmp(action, "south") == 0 || strcmp(action, "s") == 0){
                level = room;
            }
            else if(strcmp(action, "southwest") == 0 || strcmp(action, "sw") == 0){
                printf("\nYou can't go that direction\n");
            }
            else if(strcmp(action, "west") == 0 || strcmp(action, "w") == 0){
                printf("\nYou can't go that direction\n");
            }
            else if(strcmp(action, "northwest") == 0 || strcmp(action, "nw") == 0){
                printf("\nYou can't go that direction\n");
            }

            /* Read */
            else if(strcmp(action, "read") == 0){
                printf("\nYou have to be more specific\n");
            }
            else if(strcmp(action, "read guide") == 0){
                readGuide(inventory, guide);
            }

            /* Inventory */
            else if(strcmp(action, "inventory") == 0 || strcmp(action, "inv") == 0){
                inventoryShow(inventory, guide, goldenStatue);
            }

            /* Take */
            else if(strcmp(action, "take") == 0){
                printf("\nYou have to be more specific\n");
            }
            else if(strcmp(action, "take all") == 0){
                takeAll(inventory, level, guide, goldenStatue);
            }
            else if(strcmp(action, "take guide") == 0){
                takeGuide(inventory, level, guide);
            }
            else if(strcmp(action, "take golden statue") == 0){
                takeGoldenStatue(inventory, level , goldenStatue);
            }

            /* Drop */
            else if(strcmp(action, "drop") == 0){
                printf("\nYou have to be more specific\n");
            }
            else if(strcmp(action, "drop all") == 0){
                dropAll(inventory, level, guide, goldenStatue);
            }
            else if(strcmp(action, "drop guide") == 0){
                dropGuide(inventory, level, guide);
            }
            else if(strcmp(action, "drop golden statue") == 0){
                dropGoldenStatue(inventory, level, goldenStatue);
            }

            /* Look Around */
            else if(strcmp(action, "look") == 0){
                sHall = 1;
            }

            /* Error */
            else{
                printf("\nI don't recognize this sentence\n");
            }
        }

        /* The Cellar */
        if(level == cellar){

            /* Entry Dialogue */
            if(sCellar == 0){
                printf("\nNow you are located in some kind of Cellar. There is a lot of barrels and shelfs filled with wine\n"
                       "The room is kind of small and the only exit that you can see is the one to the west\n");
                sCellar = 2;
            }
            else if(sCellar == 1){
                printf("\nNow you are located in some kind of Cellar. There is a lot of barrels and shelfs filled with wine\n"
                       "The room is kind of small and the only exit that you can see is the one to the west\n");
                sCellar = 2;
            }
            else{
                printf("\nThe Cellar\n");
            }

           /* Items */
            items(level, guide, goldenStatue);

            /* Action */
            gets(action0);
            action = strlwr(action0);

            /* Directions */
            if(strcmp(action, "north") == 0 || strcmp(action, "n") == 0){
                printf("\nYou can't go that direction\n");
            }
            else if(strcmp(action, "northeast") == 0 || strcmp(action, "ne") == 0){
                printf("\nYou can't go that direction\n");
            }
            else if(strcmp(action, "east") == 0 || strcmp(action, "e") == 0){
                printf("\nYou can't go that direction\n");
            }
            else if(strcmp(action, "southeast") == 0 || strcmp(action, "se") == 0){
                printf("\nYou can't go that direction\n");
            }
            else if(strcmp(action, "south") == 0 || strcmp(action, "s") == 0){
                printf("\nYou can't go that direction\n");
            }
            else if(strcmp(action, "southwest") == 0 || strcmp(action, "sw") == 0){
                printf("\nYou can't go that direction\n");
            }
            else if(strcmp(action, "west") == 0 || strcmp(action, "w") == 0){
                level = room;
            }
            else if(strcmp(action, "northwest") == 0 || strcmp(action, "nw") == 0){
                printf("\nYou can't go that direction\n");
            }

            /* Read */
            else if(strcmp(action, "read") == 0){
                printf("\nYou have to be more specific\n");
            }
            else if(strcmp(action, "read guide") == 0){
                readGuide(inventory, guide);
            }

            /* Inventory */
            else if(strcmp(action, "inventory") == 0 || strcmp(action, "inv") == 0){
                inventoryShow(inventory, guide, goldenStatue);
            }

            /* Take */
            else if(strcmp(action, "take") == 0){
                printf("\nYou have to be more specific\n");
            }
            else if(strcmp(action, "take all") == 0){
                takeAll(inventory, level, guide, goldenStatue);
            }
            else if(strcmp(action, "take guide") == 0){
                takeGuide(inventory, level, guide);
            }
            else if(strcmp(action, "take golden statue") == 0){
                takeGoldenStatue(inventory, level , goldenStatue);
            }

            /* Drop */
            else if(strcmp(action, "drop") == 0){
                printf("\nYou have to be more specific\n");
            }
            else if(strcmp(action, "drop all") == 0){
                dropAll(inventory, level, guide, goldenStatue);
            }
            else if(strcmp(action, "drop guide") == 0){
                dropGuide(inventory, level, guide);
            }
            else if(strcmp(action, "drop golden statue") == 0){
                dropGoldenStatue(inventory, level, goldenStatue);
            }

            /* Look Around */
            else if(strcmp(action, "look") == 0){
                sCellar = 1;
            }

            /* Error */
            else{
                printf("\nI don't recognize this sentence\n");
            }
        }

        /* The Field */
        if(level == field){

            /* Entry Dialogue */
            if(sField == 0){
                printf("\nYour feet are touching a light green grass. You are on an open field filled with all kinds of flowers\n"
                       "The field seems to be endless, the only thing you can see that doesn't look like field is a broken window to the north\n");
                sField = 2;
            }
            else if(sField == 1){
                printf("\nYour feet are touching a light green grass. You are on an open field filled with all kinds of flowers\n"
                       "The field seems to be endless, the only thing you can see that doesn't look like field is a broken window to the north\n");
                sField = 2;
            }
            else{
                printf("\nA Field\n");
            }

            /* Items */
            items(level, guide, goldenStatue);

            /* Action */
            gets(action0);
            action = strlwr(action0);

            /* Directions */
            if(strcmp(action, "north") == 0 || strcmp(action, "n") == 0){
                printf("\nYou successfully made it trough the window");
                level = room;
            }
            else if(strcmp(action, "northeast") == 0 || strcmp(action, "ne") == 0){
                sField = 0;
            }
            else if(strcmp(action, "east") == 0 || strcmp(action, "e") == 0){
                sField = 0;
            }
            else if(strcmp(action, "southeast") == 0 || strcmp(action, "se") == 0){
                sField = 0;
            }
            else if(strcmp(action, "south") == 0 || strcmp(action, "s") == 0){
                sField = 0;
            }
            else if(strcmp(action, "southwest") == 0 || strcmp(action, "sw") == 0){
                sField = 0;
            }
            else if(strcmp(action, "west") == 0 || strcmp(action, "w") == 0){
                sField = 0;
            }
            else if(strcmp(action, "northwest") == 0 || strcmp(action, "nw") == 0){
                sField = 0;
            }

            /* Read */
            else if(strcmp(action, "read") == 0){
                printf("\nYou have to be more specific\n");
            }
            else if(strcmp(action, "read guide") == 0){
                readGuide(inventory, guide);
            }

            /* Inventory */
            else if(strcmp(action, "inventory") == 0 || strcmp(action, "inv") == 0){
                inventoryShow(inventory, guide, goldenStatue);
            }

            /* Take */
            else if(strcmp(action, "take") == 0){
                printf("\nYou have to be more specific\n");
            }
            else if(strcmp(action, "take all") == 0){
                takeAll(inventory, level, guide, goldenStatue);
            }
            else if(strcmp(action, "take guide") == 0){
                takeGuide(inventory, level, guide);
            }
            else if(strcmp(action, "take golden statue") == 0){
                takeGoldenStatue(inventory, level , goldenStatue);
            }

            /* Drop */
            else if(strcmp(action, "drop") == 0){
                printf("\nYou have to be more specific\n");
            }
            else if(strcmp(action, "drop all") == 0){
                dropAll(inventory, level, guide, goldenStatue);
            }
            else if(strcmp(action, "drop guide") == 0){
                dropGuide(inventory, level, guide);
            }
            else if(strcmp(action, "drop golden statue") == 0){
                dropGoldenStatue(inventory, level, goldenStatue);
            }

            /* Error */
            else{
                printf("\nI don't recognize this sentence\n");
            }
        }

        /* The Corridor */
        if(level == corridor){

            /* Entry Dialogue */
            if(sCorridor == 0){
                printf("\nYou are in a long straight corridor, but the way seems to be blocked here\n"
                       "The only doors are to the east\n");
                sCorridor = 2;
            }
            else if(sCorridor == 1){
                printf("\nYou are in a long straight corridor, but the way seems to be blocked here\n"
                       "The only doors are to the east\n");
                sCorridor = 2;
            }
            else{
                printf("\nThe Corridor\n");
            }

            /* Items */
            items(level, guide, goldenStatue);

            /* Action */
            gets(action0);
            action = strlwr(action0);

            /* Directions */
            if(strcmp(action, "north") == 0 || strcmp(action, "n") == 0){
                printf("\nYou can't go that direction\n");
            }
            else if(strcmp(action, "northeast") == 0 || strcmp(action, "ne") == 0){
                printf("\nYou can't go that direction\n");
            }
            else if(strcmp(action, "east") == 0 || strcmp(action, "e") == 0){
                level = room;
            }
            else if(strcmp(action, "southeast") == 0 || strcmp(action, "se") == 0){
                printf("\nYou can't go that direction\n");
            }
            else if(strcmp(action, "south") == 0 || strcmp(action, "s") == 0){
                printf("\nYou can't go that direction\n");
            }
            else if(strcmp(action, "southwest") == 0 || strcmp(action, "sw") == 0){
                printf("\nYou can't go that direction\n");
            }
            else if(strcmp(action, "west") == 0 || strcmp(action, "w") == 0){
                printf("\nThe way is blocked\n");
            }
            else if(strcmp(action, "northwest") == 0 || strcmp(action, "nw") == 0){
                printf("\nYou can't go that direction\n");
            }

            /* Read */
            else if(strcmp(action, "read") == 0){
                printf("\nYou have to be more specific\n");
            }
            else if(strcmp(action, "read guide") == 0){
                readGuide(inventory, guide);
            }

            /* Inventory */
            else if(strcmp(action, "inventory") == 0 || strcmp(action, "inv") == 0){
                inventoryShow(inventory, guide, goldenStatue);
            }

            /* Take */
            else if(strcmp(action, "take") == 0){
                printf("\nYou have to be more specific\n");
            }
            else if(strcmp(action, "take all") == 0){
                takeAll(inventory, level, guide, goldenStatue);
            }
            else if(strcmp(action, "take guide") == 0){
                takeGuide(inventory, level, guide);
            }
            else if(strcmp(action, "take golden statue") == 0){
                takeGoldenStatue(inventory, level , goldenStatue);
            }

            /* Drop */
            else if(strcmp(action, "drop") == 0){
                printf("\nYou have to be more specific\n");
            }
            else if(strcmp(action, "drop all") == 0){
                dropAll(inventory, level, guide, goldenStatue);
            }
            else if(strcmp(action, "drop guide") == 0){
                dropGuide(inventory, level, guide);
            }
            else if(strcmp(action, "drop golden statue") == 0){
                dropGoldenStatue(inventory, level, goldenStatue);
            }

            /* Look Around */
            else if(strcmp(action, "look") == 0){
                sCorridor = 1;
            }

            /* Error */
            else{
                printf("\nI don't recognize this sentence\n");
            }
        }
    }

    return 0;
}
/* Inventory */
void inventoryShow(int inventory[5], int guide[2], int goldenStatue[2])
{
    int i;

    printf("\nINVENTORY:\n");
    for(i=0; i<=4; i++){
        if(inventory[i] == guide[0]){
            printf("Guide\n");
        }
    }
    for(i=0; i<=4; i++){
        if(inventory[i] == goldenStatue[0]){
            printf("Golden Statue\n");
        }
    }
}
/* Read */
void read(char item, int inventory[5], int guide[2])
{
    if(strcmp(item, "guide") == 0){
        readGuide(inventory, guide);
    }
    else{
        printf("\nYou can't read %s", item);
    }
}
/* Read Guide */
void readGuide(int inventory[5], int guide[2])
{
    int i, c = 0;

    for(i=0; i<=4; i++){
        if(inventory[i] == guide[0]){
            c = 1;
            break;
        }else{
            c = 0;
        }
    }
    if(c == 1){
        printf("\n*** Basic Commands ***\n"
            "DIRECTIONS such as - north, northeast, east, southeast, south, southwest, west, northwest\n"
            "You can type either a full word, or just for example \"n\" for north\n"
            "INVENTORY - You can access your inventory by typing \"inventory\" or just simply \"inv\"\n"
            "Although inventory is still in progress so cant manage it, YET\n"
            "LOOK - If you think you missed something in your location, you can simply type \"look\" to look around\n"
            "READ - If you are holding some item or see some writing on the wall you can read it by typing \"read\" + what you want to read\n");
    }else{
        printf("\nThere is no Guide in your inventory\n");
    }
}
/* Items */
void items(int level, int guide[2], int goldenStatue[2])
{
    int i;

    for(i=0; i<=4; i++){
        if(level == i){
            if(guide[1] == i+1){
                printf("There is a Guide book on the floor\n");
            }
            if(goldenStatue[1] == i+1){
                printf("There is a Golden Statue on the floor\n");
            }
        }
    }
}

/* Take All */
void takeAll(int inventory[5], int level, int guide[2], int goldenStatue[2])
{
    int i, j, c = 0;

    for(i=0; i<=4; i++){
        if(level == i && guide[1] == i+1){
            guide[1] = 0;
            for(j=0; j<=4; j++){
                if(inventory[j] == 0){
                    inventory[j] = guide[0];
                    c = 1;
                    break;
                }
            }
        }
        if(level == i && goldenStatue[1] == i+1){
            goldenStatue[1] = 0;
            for(j=0; j<=4; j++){
                if(inventory[j] == 0){
                    inventory[j] = goldenStatue[0];
                    c = 1;
                    break;
                }
            }
        }
    }
    if(c == 1){
        printf("Done\n");
    }else{
        printf("There is nothing on the floor\n");
    }
}
/* Drop All */
void dropAll(int inventory[5], int level, int guide[2], int goldenStatue[2])
{
    int i, j, c = 0;

    for(i=0; i<=4; i++){
        if(inventory[i] == guide[0]){
            inventory[i] = 0;
            for(j=0; j<=4; j++){
                if(level == j){
                    guide[1] = j+1;
                    printf("Done\n");
                    c = 1;
                    break;
                }
            }
        }
        if(inventory[i] == goldenStatue[0]){
            inventory[i] = 0;
            for(j=0; j<=4; j++){
                if(level == j){
                    goldenStatue[1] = j+1;
                    printf("Done\n");
                    c = 1;
                    break;
                }
            }
        }
    }
    if(c == 1){
        printf("Done\n");
    }else{
        printf("There is nothing in your inventory\n");
    }
}
/* Take Guide*/
void takeGuide(int inventory[5], int level, int guide[2])
{
    int i, j;

    for(i=0; i<=4; i++){
        if(level == i && guide[1] == i+1){
            guide[1] = 0;
            for(j=0; j<=4; j++){
                if(inventory[j] == 0){
                    inventory[j] = guide[0];
                    break;
                }
            }
            printf("Done\n");
        }
        else if(level == i && guide[1] != i+1){
            printf("There is no guide here\n");
        }
    }
}
/* Drop Guide */
void dropGuide(int inventory[5], int level, int guide[2])
{
    int i, j, c = 0;

    for(i=0; i<=4; i++){
        if(inventory[i] == guide[0]){
            inventory[i] = 0;
            for(j=0; j<=4; j++){
                if(level == j){
                    guide[1] = j+1;
                    printf("Done\n");
                    c = 1;
                    break;
                }
            }
        }
        if(c == 0 && i == 4){
            printf("There is no guide in your inventory\n");
        }
    }
}
/* Take Golden Statue */
void takeGoldenStatue(int inventory[5], int level, int goldenStatue[2])
{
    int i, j;

    for(i=0; i<=4; i++){
        if(level == i && goldenStatue[1] == i+1){
            goldenStatue[1] = 0;
            for(j=0; j<=4; j++){
                if(inventory[j] == 0){
                    inventory[j] = goldenStatue[0];
                    break;
                }
            }
            printf("Done\n");
        }
        else if(level == i && goldenStatue[1] != i+1){
            printf("There is no golden statue here\n");
        }
    }
}
/* Drop Golden Statue */
void dropGoldenStatue(int inventory[5], int level, int goldenStatue[2])
{
    int i, j, c = 0;

    for(i=0; i<=4; i++){
        if(inventory[i] == goldenStatue[0]){
            inventory[i] = 0;
            for(j=0; j<=4; j++){
                if(level == j){
                    goldenStatue[1] = j+1;
                    printf("Done\n");
                    c = 1;
                    break;
                }
            }
        }
        if(c == 0 && i == 4){
            printf("There is no golden statue in your inventory\n");
        }
    }
}
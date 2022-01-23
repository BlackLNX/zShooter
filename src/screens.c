void welcome_screen() {
    prints("Welcome to zShooter 0.01a");
    prints("(c)2022 LNX, Artasy.org");
    prints("");
    prints("[No game data found - starting a new game]");
    prints("");
    prints("It was a cold summer night when you woke up in your home hearing some crushing glass from outside. You look out of the window and see burning buildings and running citizens over the street. Some helicopters passing over you. You hear some noise from nearby gun shots.");
    prints("");
    achieve(fACH_CHAPTER1);
}

void print_screen() {
    
}

void print_achievement(uint achievement) {
    switch(achievement) {
        case fACH_CHAPTER1:
            prints("CHAPTER 1: \"Going Equipped\"");
            prints("Maybe I should look whats going up outside... Should I take my gun?");
            prints("(Open your inventory to pick up the pistol and leave the building)");
            break;
        case fACH_CHAPTER2:
            prints("CHAPTER 2: \"What is this?!\"");
            prints("He's covered with blood and I can see his heart ripped out of his body... He just can't be alive, or is he?!");
            break;
        case fACH_CHAPTER3:
            prints("CHAPTER 3: \"Back to normality\"");
            prints("I'm rid of this place, maybe we should produce our own goods and settle down here.");
            break;
        case fACH_CHAPTER4:
            prints("CHAPTER 4: \"Final solution\"");
            prints("Maybe the rumors are true there is a laboratory researching a vaccine...");
            prints("(Seek the laboratory)");
            break;
        case fACH_MELEE:
            prints("MELEE:");
            prints("I guess this won't make noise, but I've to get to my target first...");
            break;
        case fACH_ARCHERY:
            prints("ARCHERY:");
            prints("This is ranged, but I doubt I can hit my target in the distance...");
            break;
        case fACH_FIREARM:
            prints("FIREARMS:");
            prints("As long as I don't run out of ammo no one will probably mess with me...");
            break;
        case fACH_ZOMBIES:
            prints("ZOMBIES:");
            prints("This looks like those zombies from my comics. Maybe I should aim the head...");
            break;
        case fACH_SURVIVOR:
            prints("SURVIVOR:");
            prints("Finally someone who lives... Maybe we can work together?");
            break;
        case fACH_BASE:
            prints("BASE:");
            prints("It's not the safest place, but at least I can get some sleep...");
            break;
        case fACH_OPONENT:
            prints("OPONENT:");
            prints("Well, who would judge me now?!");
            break;
        case fACH_RESEARCH:
            prints("RESEARCH:");
            prints("Maybe we could look how to increase our life at this place?!");
            prints("(Go to research in your base)");
            break;
        case fACH_WALLS:
            prints("WALLS:");
            prints("This will hold back the Zombies, at least I hope so...");
            break;
        case fACH_GROWFOOD:
            prints("GROWING FOOD:");
            prints("There are so many people here, I wonder if this is enough?!");
            break;
        case fACH_ARMORY:
            prints("ARMORY");
            prints("Finally, one problem less to solve...");
            break;
        default:
            prints("??????");
            prints("Description missing...");
            break;
    }
    prints("");
}

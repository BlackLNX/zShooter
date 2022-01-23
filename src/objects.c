int add_character(uchar flags, int x, int y) {
    // PICK RANDOM NAME EITHER FEMALE OR MALE FROM GIVEN FLAG:
    int n = number(0, NAMES - 1);
    const char* name = (flags & fCHAR_FEMALE)?NAMES_F[n]:NAMES_M[n];
    // SEEK FREE MEMORY AND PUT NEW CHARACTER IN:
    for (int i=0; i<CHARACTERS; i++) {
        if (character[i].name[0] == 0) {
            memcpy(character[i].name, name, 16);
            character[i].name[15] = 0;            // ENDS NAME THAT DOESN'T FIT
            character[i].flags = flags;
            character[i].x = x;
            character[i].y = y;
            character[i].team = 0;
            character[i].profession = profession[number(0, PROFESSIONS - 1)];
            character[i].age = number(14, 80);   //14 - 80, avg 47
            character[i].wounds = 0;
            character[i].weapon = 0;
            character[i].melee = 0;
            character[i].guns = 0;
            character[i].evade = 0;
            character[i].crafting = 0;
            return i;
        }
    }
    // (NAME CANNOT BE UNSET, THIS IS RESERVED FOR UNSET)
    // RETURN OVERFLOW VALUE IF NONE COULD BE SET:
    return CHARACTERS;
}

void give_profession(int profession) {
    
}

void remove_character(int id) {
    
}

int add_item(const char* name, uchar flags, uchar value, ushort weight) {
    // SEEK FREE MEMORY AND PUT NEW CHARACTER IN:
    for (int i=0; i<ITEMS; i++) {
        if (item[i].name[0] == 0) {
            memcpy(item[i].name, name, 16);
            item[i].name[15] = 0;               // ENDS NAME THAT DOESN'T FIT
            item[i].flags = flags;
            item[i].value = value;
            item[i].weight = weight;
            return i;
        }
    }
    // (NAME CANNOT BE UNSET, THIS IS RESERVED FOR UNSET)
    // RETURN OVERFLOW VALUE IF NONE COULD BE SET:
    return ITEMS;
}


void setup() {
    //                          name        flags       chance  weight (10g)
                       add_item("Knife",    fITEM_MELEE,  60,    20);
                       add_item("Machete",  fITEM_MELEE,  80,    80);
    const int _SWORD = add_item("Sword",    fITEM_MELEE,  95,   145);
                       add_item("Axt",      fITEM_MELEE, 100,   220);
    //                          ammo            flags                        (id)     weapon          flags,      chance  weights (10g)
    const int _BOW =                                                         add_item("Bow",          fITEM_BOW,    25,    65);
    const int _ARROW = add_item("Arrow",        fITEM_AMMO,                  _BOW,                                               5);
    const int _BOLT =  add_item("Bolt",         fITEM_AMMO,                  add_item("Crossbow",     fITEM_BOW,    50,   280),  2);
                       add_item("Pistol Round", fITEM_AMMO,                  add_item("Pistol",       fITEM_GUN,    60,    80),  1);
                       add_item("Rifle Round",  fITEM_AMMO,                  add_item("Assault Rifle",fITEM_GUN,    80,   340),  2);
    const int _SHOTS = add_item("Shots",        fITEM_AMMO,                  add_item("Shotgun",      fITEM_GUN,    90,   270),  5);
                       add_item("Sniper Round", fITEM_AMMO,                  add_item("Sniper Rifle", fITEM_GUN,   100,  1300),  2);
    //       name        flags         unused  weight (10g)
    add_item("Bandage",  fITEM_MEDICS,   0,      1);
    //                           name        flags         proteins (g)  weight (10g)
                        add_item("Onion",    fITEM_FOOD,      2,           20);
    const int _EGG =    add_item("Egg",      fITEM_FOOD,      8 ,           6);
                        add_item("Peas",     fITEM_FOOD,     13,           25);
    const int _CHEESE = add_item("Cheese",   fITEM_FOOD,     25,           10);
    const int _FLOUR =  add_item("Flour",    fITEM_FOOD,     50,           50);
    const int _RABBIT = add_item("Rabbit",   fITEM_FOOD,     66,           50);    //1 Rabbit => 6-12
    //                         name        flags          type   weight (10g)
                      add_item("Wood",     fITEM_MATERIAL,  1,          200);
                      add_item("Stone",    fITEM_MATERIAL,  2,          500);
                      add_item("Steel",    fITEM_MATERIAL,  3,          100);
    const int _COAL = add_item("Coal",     fITEM_MATERIAL,  4,           50);
    // -- count 27 --

    //                                flags  x  y  
    const int _PLAYER = add_character(0,     0, 0);
}

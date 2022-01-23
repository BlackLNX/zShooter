int number(int min, int max) {
    return (min + rand() % (1 + max - min));
}


void achieve(uint achievement) {
    if (achievements & achievement) return;
    achievements = achievements | achievement;
    print_achievement(achievement);
}

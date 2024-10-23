using TerminalGame_v0;



Player player = new Player("Player", 10, 10, 2, 0, false, 10);
Food apple = new Food("Apple", 1, 1, 8);
Food pear = new Food("Pear", 1, 1, 8);

player.AddItemToBackpack(apple);
player.AddItemToBackpack(pear);

while (true)
{
    player.PickItemFromBackpack();
    player.PrintInfo();
}

// TODO create menu class
// TODO create event class
// TODO create generator class
// TODO create populate class
// TODO create logic class

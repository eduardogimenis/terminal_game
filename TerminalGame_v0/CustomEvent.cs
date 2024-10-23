namespace TerminalGame_v0;

public class FoodItemUsedArgs : EventArgs
{
    //public int WatchWeight;
    public int HungerRestore;
    public FoodItemUsedArgs(/*int watchWeight*/string itemName, int hungerRestore)
    {
        Console.WriteLine($"Consuming {itemName} for {hungerRestore} hunger!");
        HungerRestore = hungerRestore;
    }
}
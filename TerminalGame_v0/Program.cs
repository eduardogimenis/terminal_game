using TerminalGame_v0;

/*
Player player = new Player("Player", 10, 10, 2, 0, false, 10);
Food apple = new Food("Apple", 1, 1, 8);
Food pear = new Food("Pear", 1, 1, 8);
player.AddItemToBackpack(apple);
player.AddItemToBackpack(pear);
player.PickItemFromBackpack();
*/
// TODO create menu class
// TODO create event class
// TODO create generator class
// TODO create populate class
// TODO create logic class


Watch casio = new Watch(59, 8);
Expensive rolex = new Expensive(2000, 14);
Person swagger = new Person(180);
swagger.PrintInfo();
swagger.AddWatch(casio);
swagger.WearWatch(casio);
swagger.PrintInfo();
swagger.AddWatch(rolex);
swagger.PrintInfo();
swagger.WearWatch(rolex);
swagger.PrintInfo();


class Watch
{
    protected int Cost { get; set; }
    protected int Weight { get; set; }
    public event EventHandler<WatchWoreArgs> WatchWore;

    protected virtual void onWatchWore(WatchWoreArgs e)
    {
        WatchWore?.Invoke(this, e);
    }
    public Watch(int cost, int weight)
    {
        Cost = cost;
        Weight = weight;
    }

    public virtual void Wear()
    {
        Console.Write("Casual wear...");
        onWatchWore(new WatchWoreArgs(Weight));
    }
}

class Expensive : Watch
{
    public Expensive(int cost, int weight) : base(cost, weight)
    {
        Cost = cost;
        Weight = weight;
    }
    public override void Wear()
    {
        Console.Write("Swag blinging...");
        onWatchWore(new WatchWoreArgs(Weight));
    }
}

class Person
{
    private int Weight { get; set; }
    private List<Watch> Watches = new List<Watch>();
    public Person(int personWeight)
    {
        Weight = personWeight;
        foreach (Watch watch in Watches)
        {
            if (watch is Expensive expensiveWatch)
            {
                watch.WatchWore += HandleWatchWore;
            }
        }
    }

    public void AddWatch(Watch watch)
    {
        Watches.Add(watch);
        watch.WatchWore += HandleWatchWore;
    }
    private void HandleWatchWore(object sender, WatchWoreArgs e)
    {
        Weight += e.WatchWeight; // Update the player's hunger
        Console.WriteLine($"Your weight is now: {Weight}");
    }

    public void WearWatch(Watch watch)
    {
        watch.Wear();
    }

    public void PrintInfo()
    {
        Console.WriteLine($"This mofo weighs {Weight}");
    }
}

// Custom EventArgs class to hold the watch weight
public class WatchWoreArgs : EventArgs
{
    public int WatchWeight;
    public WatchWoreArgs(int watchWeight)
    {
        Console.WriteLine("Putting it on...");
        WatchWeight = watchWeight;
    }
}
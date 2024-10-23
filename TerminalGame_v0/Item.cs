namespace TerminalGame_v0;
public class Item
{
    protected string Name { get; set; }
    protected int Weight { get; set; }
    protected int SoundLevel { get; set; }
    public event EventHandler<FoodItemUsedArgs> ItemUsed;
    protected virtual void onItemUsed(FoodItemUsedArgs args) => ItemUsed?.Invoke(this, args);

    public Item(string name, int weight, int soundLevel)
    {
        Name = name;
        Weight = weight;
        SoundLevel = soundLevel;
    }

    public void GetInfo() => Console.WriteLine($"Name: {Name}, Weight: {Weight}, Sound Level: {SoundLevel}");

    public virtual void Use()
    {
        onItemUsed(new FoodItemUsedArgs(Name, 0));
        Console.WriteLine($"Using {Name}...");
    }

    public virtual void Choice()
    {
    }

}

public class Backpack : Item
{
    private List<Item> items = new List<Item>();

    public Backpack(string name, int weight, int soundLevel) : base(name, weight, soundLevel)
    {
        Name = name;
        Weight = weight;
        SoundLevel = soundLevel;
    }

    public void AddItem(Item item) => items.Add(item);

    public void RemoveItem(Item item) => items.Remove(item);

    public void ClearBackpack() => items.Clear();

    public void LookInside()
    {
        foreach (Item item in items)
        {
            item.GetInfo();
        }
    }

    public void GrabItem()
    {
        // TODO
        // fix ChooseItem()
        // return Item reference?
        ListItems();
        Item item = ChooseItem();
        item.Choice();
        RemoveItem(item);
    }

    private void ListItems()
    {
        // just lists items based on List<>
        if (items.Count <= 0)
        {
            Console.WriteLine("Nothing to look inside...");
            return;
        }
        for (int i = 0; i < items.Count; i++)
        {
            Console.Write($"{i}. ");
            items[i].GetInfo();
        }
    }

    private Item ChooseItem()
    {
        // TODO
        // make this actually choose an item, instead of just printing info
        int choice;
        Console.Write("Input item number: ");
        while (!(int.TryParse(Console.ReadLine(), out choice) && choice >= 0 && choice < items.Count))
        {
            Console.WriteLine("Invalid choice. Try Again");
        }
        return items[choice];
    }

    public override void Use()
    {
        onItemUsed(new FoodItemUsedArgs(Name, 0));
    }
}

public class Food : Item
{
    private int RestoreHunger { get; set; }
    

    public Food(string name, int weight, int soundLevel, int restoreHunger) : base(name, weight, soundLevel)
    {
        Name = name;
        Weight = weight;
        SoundLevel = soundLevel;
        RestoreHunger = restoreHunger;
    }

    public override void Use()
    {
        onItemUsed(new FoodItemUsedArgs(Name, RestoreHunger));
    }

    public override void Choice()
    {
        int choice;
        Console.WriteLine($"What would you like to do with {Name}?");
        ListActions();
        choice = HandleVarNumber(3);
        switch (choice)
        {
            // TODO
            case 1:
                Use();
                break;
            case 2:
                Console.WriteLine("Throw it");
                break;
            case 3:
                Console.WriteLine("Remove it");
                break;
        }
    }
    private void ListActions() => Console.WriteLine($"1. Eat {Name}\n2. Throw it\n3. Remove it");

    private int HandleVarNumber(int varNumber)
    {
        // TODO
        // make this actually choose an item, instead of just printing info
        int choice;
        Console.Write("Input choice: ");
        while (!(int.TryParse(Console.ReadLine(), out choice) && choice >= 1 && choice < varNumber+1))
        {
            Console.WriteLine("Invalid choice. Try Again");
        }

        return choice;
    }
}

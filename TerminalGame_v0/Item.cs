namespace TerminalGame_v0;
public class Item
{
    protected string Name { get; set; }
    protected int Weight { get; set; }
    protected int SoundLevel { get; set; }

    public Item()
    {
        
    }
    public Item(string name, int weight, int soundLevel)
    {
        Name = name;
        Weight = weight;
        SoundLevel = soundLevel;
    }

    public void GetInfo()
    {
        Console.WriteLine($"Name: {Name}, Weight: {Weight}, Sound Level: {SoundLevel}");
    }

    public virtual void Use()
    {
        Console.WriteLine($"Using {Name}...");
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

    public void AddItem(Item item)
    {
        items.Add(item);
    }

    public void RemoveItem(Item item)
    {
        items.Remove(item);
    }

    public void ClearBackpack()
    {
        items.Clear();
    }

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
        ChooseItem().Use();
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
        // TODO
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
        Console.WriteLine($"What would you like to do with {Name}?");
    }

    private void ListActions()
    {
        int choice;
        Console.WriteLine($"Eat {Name}\nThrow it\nRemove it");
        choice = HandleVarNumber(3);
        switch (choice)
        {
            // TODO
            case 1:
                break;
        }

    }

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
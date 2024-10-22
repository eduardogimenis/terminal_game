namespace TerminalGame_v0;
// this is where player's and enemy's actions and stats will be defined
// separate player class enheriting from the entity class
public class Entity
{
    protected string Name { get; set; }
    protected int CurrentHealth { get; set; }
    protected int MaxHealth { get; set; }
    protected int Strength { get; set; }
    protected int Hunger { get; set; }
    protected bool Dead { get; set; }

    public Entity()
    {
        
    }
    public Entity(string name, int currentHealth, int maxHealth, int strength, int hunger, bool dead)
    {
        Name = name;
        CurrentHealth = currentHealth;
        MaxHealth = maxHealth;
        Strength = strength;
        Hunger = hunger;
        Dead = dead;
    }

    public void TakeDamage(int damage)
    {
        CurrentHealth -= damage;
    }

    public void Heal(int heal)
    {
        CurrentHealth += heal;
    }

    public void Die()
    {
        Dead = true;
        CurrentHealth = 0;
    }

    public void Revive()
    {
        Dead = false;
        CurrentHealth = MaxHealth/3;
    }

    public bool IsAlive()
    {
        return !Dead;
    }

    public void GetHungry(int hunger)
    {
        Hunger += hunger;
    }

    public virtual void PrintInfo()
    {
        Console.WriteLine($"Current Health: {CurrentHealth}, Max Health: {MaxHealth}," +
                          $" Strength: {Strength}, Hunger: {Hunger}");
    }
}

public class Player : Entity
{
    private int Sanity { get; set; }
    private Backpack PlayerBackpack = new Backpack("Player Backpack", 6, 2);
    public Player(string name, int currentHealth, int maxHealth, int strength, int hunger, bool dead, int sanity) 
        : base(name, currentHealth, maxHealth, strength, hunger, dead)
    {
        Name = name;
        CurrentHealth = currentHealth;
        MaxHealth = maxHealth;
        Strength = strength;
        Hunger = hunger;
        Dead = dead;
        Sanity = sanity;
    }

    public void AddItemToBackpack(Item item)
    {
        // TODO
        // make it based on player choice
        // using GrabItem?
        PlayerBackpack.AddItem(item);
    }

    public void RemoveItemFromBackpack(Item item)
    {
        // TODO
        // make it based on player choice
        // using GrabItem?
        PlayerBackpack.RemoveItem(item);
    }

    public void EmptyBackpack()
    {
        PlayerBackpack.ClearBackpack();
    }

    public void PickItemFromBackpack()
    {
        // TODO
        // return item to player usage
        // creates options based on item type
        PlayerBackpack.GrabItem();
    }


    public override void PrintInfo()
    {
        Console.WriteLine($"Current Health: {CurrentHealth}, Max Health: {MaxHealth}," +
                          $" Strength: {Strength}," + $" Hunger: {Hunger}, Sanity: {Sanity}");
    }
    
}
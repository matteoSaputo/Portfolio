public class Weapon
{
    private String name;
    private int str;
    private int weight;
    private int attacks;
    private int exp;
    
    public Weapon(int num)
    {
        if(num == 1)
        {
            name = "Sword";
            str = Randomizer.nextInt(2, 3);
            weight = Randomizer.nextInt(1, 2);
            attacks = Randomizer.nextInt(2, 3);
        }
        if(num == 2)
        {
            name = "Bow";
            str = Randomizer.nextInt(1, 2);
            weight = 1;
            attacks = Randomizer.nextInt(3, 7);
        }
        if(num == 3)
        {
            name = "Staff";
            str = Randomizer.nextInt(2, 3);
            weight = Randomizer.nextInt(1, 3);
            attacks = Randomizer.nextInt(3, 5);
        }
        if(num == 4)
        {
            name = "Spear";
            str = Randomizer.nextInt(3, 8);
            weight = Randomizer.nextInt(4, 5);
            attacks = Randomizer.nextInt(2, 3);
        }
        exp = Randomizer.nextInt(5, 15);
    }
    public int getExp()
    {
        return exp;
    }
    public void increaseAllStats()
    {
        str += Randomizer.nextInt(1, attacks);
        weight += Randomizer.nextInt(1, attacks);
        attacks += Randomizer.nextInt(1, attacks);
    }
    public String getName()
    {
        return name;
    }
    public void setName(String n)
    {
        name = n;
    }
    public int getStr()
    {
        return str;
    }
    public void setStr(int s)
    {
        str = s;
    }
    public int getWeight()
    {
        return weight;
    }
    public void setWeight(int w)
    {
        weight = w;
    }
    public int getAttacks()
    {
        return attacks;
    }
    public void setAttacks(int a)
    {
        attacks = a;
    }
    public String toString()
    {
        return "a " + name + " with " + str + " strength, " + weight + " weight, and can attack " + attacks + " times";                       
    }
}
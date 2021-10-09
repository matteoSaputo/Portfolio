import java.util.*;

public class CustomCharacter
{
    private String name;
    private Power power;
    private Weapon weapon;
    private int str; 
    private int spd; 
    private int def;
    private int dex; 
    private int intel; 
    private int hel; 
    private int maxHealth;
    private int nextLvl;
    private int exp;
    private int lvl;
    Scanner scanner = new Scanner(System.in);
    
    public CustomCharacter(String name, Power power, Weapon weapon)
    {
        this.name = name; 
        this.power = power;
        this.weapon = weapon;
        str = Randomizer.nextInt(1, 5);
        spd = Randomizer.nextInt(1, 5);
        def = Randomizer.nextInt(1, 5);
        dex = Randomizer.nextInt(1, 5);
        intel = Randomizer.nextInt(1, 5);
        hel = Randomizer.nextInt(60, 100);
        maxHealth = hel;
        exp = 0;
        lvl = 1;
        nextLvl = 10;
        System.out.println("You are " + name + ", a level " + lvl + " " + power.getName() + " powered hero!");
        System.out.println("You weild " + weapon);
        System.out.println("Strength: " + str);
        System.out.println("Speed: " + spd);
        System.out.println("Defense: " + def);
        System.out.println("Dexterity: " + dex);
        System.out.println("Intelligence: " + intel);
        System.out.println("Health: " + maxHealth);
    }
    public boolean hasEnoughExp()
    {
        return exp > nextLvl;
    }
    public int nxtLvl()
    {
        return nextLvl;
    }
    public void setNextLvl(int num)
    {
        nextLvl *= 2;
    }
    public void statusAction(Monster mon)
    {
        power.statusAction(mon);
    }
    public int getExp()
    {
        return exp;
    }
    public void gainExp(int num)
    {
        exp += num;
        System.out.println("You got " + num + " experience!");
        scanner.nextLine();
    }
    public void lvlUp()
    {
        lvl++;
        System.out.println("You leveled up to level " + lvl);
        int plus = Randomizer.nextInt(1, 3);
        System.out.println("+" + plus + " Strength " + "(" + (str+plus) + ")");
        str += plus;
        plus = Randomizer.nextInt(1, 3);
        System.out.println("+" + plus + " Speed " + "(" + (spd+plus) + ")");
        spd += plus;
        plus = Randomizer.nextInt(1, 3);
        System.out.println("+" + plus + " Defense " + "(" + (def+plus) + ")");
        def += plus;
        plus = Randomizer.nextInt(1, 3);
        System.out.println("+" + plus + " Dexterity " + "(" + (dex+plus) + ")");
        dex += plus;
        plus = Randomizer.nextInt(1, 3);
        System.out.println("+" + plus + " Intelligence " + "(" + (intel+plus) + ")");
        intel += plus;
        plus = Randomizer.nextInt(1, 3);
        System.out.println("+" + plus + " Health " + "(" + (maxHealth+plus) + ")");
        scanner.nextLine();
        maxHealth += plus;
        hel = maxHealth;
    }
    public String getName()
    {
        return name;
    }
    public Power getPower()
    {
        return power;
    }
    public Weapon getWeapon()
    {
        return weapon;
    }
    public void setWeapon(Weapon w)
    {
        weapon = w;
    }
    public int getStr()
    {
        return str;
    }
    public void setStr(int s)
    {
        str = s;
    }
    public int getSpd()
    {
        return spd;
    }
    public void setSpd(int s)
    {
        spd = s;
    }
    public int getDef()
    {
        return def;
    }
    public void setDef(int d)
    {
        def = d;
    }
    public int getDex()
    {
        return dex;
    }
    public void setDex(int d)
    {
        def = d;
    }
    public int getIntel()
    {
        return hel;
    }
    public void setIntel(int i)
    {
        intel = i;
    }
    public int getHel()
    {
        return hel;
    }
    public void setHel(int h)
    {
        hel = h;
    }
    public int getMaxHealth()
    {
        return maxHealth;
    }
    public void heal(int h)
    {
        hel += h;
    }
    public void takeDamage(int d)
    {
        hel -= d;
    }
}
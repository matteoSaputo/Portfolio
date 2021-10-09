public class Monster
{
    private Weapon weapon;
    private int str; 
    private int spd; 
    private int def;
    private int dex; 
    private int hel;
    private int exp;
    
    public Monster()
    {
        weapon = new Weapon(Randomizer.nextInt(1, 4));
        str = Randomizer.nextInt(3, 5);
        spd = Randomizer.nextInt(3, 5);
        def = Randomizer.nextInt(3, 5);
        dex = Randomizer.nextInt(3, 5);
        hel = Randomizer.nextInt(10, 15);
        exp = Randomizer.nextInt(5, 15);
    }
    public int getExp()
    {
        return exp;
    }
    public Weapon getWeapon()
    {
        return weapon;
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
    public int getHel()
    {
        return hel;
    }
    public void takeDamage(int d)
    {
        hel -= d;
    }
}
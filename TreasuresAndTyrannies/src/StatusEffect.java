public class StatusEffect
{
    private String name;
    private int bonus;
    
    public StatusEffect(String name, int bonus)
    {
        this.name = name;
        this.bonus = bonus;
    }
    
    public String getName()
    {
        return name;
    }
    
    public int getBonus()
    {
        return bonus;
    }
}
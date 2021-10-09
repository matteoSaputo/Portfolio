import java.util.*;

public class Power
{
    private String name;
    private PowerAttack attack;
    private StatusEffect effect;
    private HealingSpell heal;
    
    Scanner scanner = new Scanner(System.in);
    
    public Power(int num)
    {
        if(num == 1)
        {
            name = "Fire";
            attack = new PowerAttack("Fireball", 10);
            effect = new StatusEffect("Burn", 2);
            heal = new HealingSpell("Cool Off", 4);
        }
        if(num == 2)
        {
            name = "Ice";
            attack = new PowerAttack("Blizzard", 6);
            effect = new StatusEffect("Freeze", 5);
            heal = new HealingSpell("Ice Repair", 4);
        }
        if(num == 3)
        {
            name = "Electricity";
            attack = new PowerAttack("Lightning Strike", 5);
            effect = new StatusEffect("Shock", 4);
            heal = new HealingSpell("Energy Jolt", 8);
        }
        if(num == 4)
        {
            name = "Psychic";
            attack = new PowerAttack("PSI Wave", 6);
            effect = new StatusEffect("Hypnosis", 3);
            heal = new HealingSpell("Meditate", 6);
        }
    }
    
    public String getName()
    {
        return name;
    }
    public PowerAttack getPowerAttack()
    {
        return attack;
    }
    public StatusEffect getStatusEffect()
    {
        return effect;
    }
    public HealingSpell getHealingSpell()
    {
        return heal;
    }
    
    
    
    public void statusAction(Monster mon)
    {
        if(name == "Fire")
        {
             mon.setDef(mon.getDef() - effect.getBonus());
             System.out.println("You have inflicted -" + effect.getBonus() + " defense to a monster");
             mon.setStr(mon.getStr() - effect.getBonus());
             System.out.println("You have inflicted -" + effect.getBonus() + " strength to a monster");
             scanner.nextLine();
        }
        if(name == "Ice")
        {
            System.out.println("You have taken away a monsters speed");
            mon.setSpd(0);
            System.out.println("You have taken away a monsters dexterity");
            mon.setDex(0);
            System.out.println("You have taken away a monsters strength");
            mon.setStr(0);
        }
        if(name == "Electricity")
        {
            mon.setSpd(mon.getSpd() - effect.getBonus());
            System.out.println("You have inflicted -" + effect.getBonus() + " speed to a monster");
            mon.setDex(mon.getDex() - effect.getBonus());
            System.out.println("You have inflicted -" + effect.getBonus() + " dexterity to a monster");
            scanner.nextLine();
        }
        if(name == "Psychic")
        {
            
            mon.setDef(mon.getDef() - effect.getBonus());
            System.out.println("You have inflicted -" + effect.getBonus() + " defense to a monster");
            mon.setStr(mon.getStr() - effect.getBonus());
            System.out.println("You have inflicted -" + effect.getBonus() + " strength to a monster");
            mon.setSpd(mon.getSpd() - effect.getBonus());
            System.out.println("You have inflicted -" + effect.getBonus() + " speed to a monster");
            scanner.nextLine();
        }
    }
}
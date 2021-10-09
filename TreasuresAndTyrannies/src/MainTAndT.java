import java.util.ArrayList;
import java.util.Scanner;

public class MainTAndT{
    public static void main(String args[]){
    	Scanner scanner = new Scanner(System.in);
    	
    	System.out.println("Customize Your Character!");
    	System.out.println("What is your Characters name? ");
        String name = scanner.nextLine();
        System.out.println("Choose your Superpower!");
        System.out.println("1 = Fire, 2 = Ice, 3 = Electricity, 4 = Psychic: ");
        Power power = new Power(scanner.nextInt());
        System.out.println("Choose your weapon!");
        System.out.println("1 = Sword, 2 = Bow, 3 = Staff, 4 = Spear: ");
        Weapon weapon = new Weapon(scanner.nextInt());
        System.out.println();
        CustomCharacter player = new CustomCharacter(name, power, weapon);
        
        boolean playing = true;
        System.out.println("Press enter to continue");
        scanner.nextLine();
        while(playing)
        {
            if(player.getHel() <= 0)
            {
            	System.out.println("Customize Your Character!");
            	System.out.println("What is your Characters name? ");
                name = scanner.nextLine();
                System.out.println("Choose your Superpower!");
                System.out.println("1 = Fire, 2 = Ice, 3 = Electricity, 4 = Psychic: ");
                power = new Power(scanner.nextInt());
                System.out.println("Choose your weapon!");
                System.out.println("1 = Sword, 2 = Bow, 3 = Staff, 4 = Spear: ");
                weapon = new Weapon(scanner.nextInt());
                System.out.println();
                player = new CustomCharacter(name, power, weapon);
                
                playing = true;
                System.out.println("Press enter to continue");
            }
            System.out.println();
            scanner.nextLine();
         
            int numRooms = Randomizer.nextInt(4, 7);
            System.out.println("Entering new Dungeon...");
            scanner.nextLine();
            
            for(int i = 1; i <= numRooms; i++)
            {
                if(i == numRooms)
                {
                	System.out.println("FINAL ROOM");
                	scanner.nextLine();
                }
                else
                {
                	System.out.println("ROOM " + i);
                	scanner.nextLine();
                }
                System.out.println();
                int random = Randomizer.nextInt(1, 3);
                
                //Nothing in the room
                if(random == 1)
                {
                    System.out.println("There is nothing Here...");
                    scanner.nextLine();
                    System.out.println();
                }
                
                //monsters in the room
                else if(random == 2)
                {
                    Monster[] mons = new Monster[Randomizer.nextInt(1, 10)];
                    ArrayList<Monster> monsters = new ArrayList<Monster>();
                    int aveMonSpd = 0;
                    for(int j = 0; j < mons.length; j++)
                    {    
                        mons[j] = new Monster();
                        monsters.add(mons[j]);
                        aveMonSpd += mons[j].getSpd();
                    }
                    aveMonSpd /= mons.length;
                    
                    System.out.println("Wild Monsters Appeared!");
                    scanner.nextLine();
                    System.out.println("There are " + monsters.size() + " monsters!");
                    scanner.nextLine();
                    
                    System.out.println("Will you fight? (true or false)");
                    boolean will = scanner.nextBoolean();
                    
                    //escape attempt
                    if(will == false)
                    {
                        if(player.getSpd() > aveMonSpd) {
                            System.out.println("You have escaped! ");
                        	scanner.nextLine();
                        }
                        else if (player.getSpd() == aveMonSpd)
                        {
                            int tie = Randomizer.nextInt(1, 2);
                            if(tie == 1) {
                                System.out.println("You have escaped! ");
                            	scanner.nextLine();
                            }
                            else
                            {
                                System.out.println("You were unable to escape! You must fight ");
                                scanner.nextLine();
                                will = true;
                            }
                        }
                        else
                        {
                            System.out.println("You were unable to escape! You must fight ");
                            scanner.nextLine();
                            will = true;
                        }
                    }
                    
                    if(will)
                    {
                        
                        System.out.println("\n How will u attack? 1 = Weapon, 2 = Power. ");
                        int action1 = scanner.nextInt();
                        
                        while(!isAllNull(monsters))
                        {
                        
                            //weapon || power
                            if(action1 == 1)
                            {
                                System.out.println("You attacked with ur weapon!");
                                scanner.nextLine();
                                int ranMon2 = Randomizer.nextInt(0, monsters.size()-1);
                                while(monsters.get(ranMon2) == null)
                                {
                                    ranMon2 = Randomizer.nextInt(0, monsters.size()-1);
                                }
                                Monster currentMon = monsters.get(ranMon2);
                                //System.out.println(currentMon == null);
                                for(int x = 0; x < player.getWeapon().getAttacks(); x++)
                                {
                                    System.out.println();
                                    System.out.println("You attacked monster " + (ranMon2+1));
                                    
                                    int playerDam = player.getStr() + player.getWeapon().getStr() - currentMon.getDef();
                                    if(playerDam <= 0)
                                    {
                                        playerDam = 0;
                                    }
                                    int playerHit = Randomizer.nextInt(1, player.getSpd()) + Randomizer.nextInt(1, player.getDex()) - player.getWeapon().getWeight();
                                    int monDodge = Randomizer.nextInt(1, currentMon.getSpd()) + Randomizer.nextInt(1, currentMon.getDex()) - currentMon.getWeapon().getWeight();
                                    if(playerHit >= monDodge)
                                    {
                                        currentMon.takeDamage(playerDam);
                                        System.out.println("You did " + playerDam + " damage to monster " + (ranMon2+1));
                                        scanner.nextLine();
                                    }
                                    else
                                    {
                                        System.out.println("You missed");
                                        scanner.nextLine();
                                    }
                                    if(currentMon.getHel() <= 0)
                                    {
                                        System.out.println("Monster " + (ranMon2+1) + " has been defeated");
                                        scanner.nextLine();
                                        player.gainExp(currentMon.getExp());
                                        if(player.hasEnoughExp())
                                        {
                                            player.lvlUp();
                                            player.setNextLvl(player.nxtLvl()*2);
                                        }
                                        monsters.set(ranMon2, null);
                                        ranMon2 = Randomizer.nextInt(0, monsters.size()-1);
                                        currentMon = monsters.get(ranMon2);
                                    }
                                }
                            }    
                            else
                            {
                                System.out.println("You attacked with your powers!");
                                System.out.println("Type 1 for " + player.getPower().getPowerAttack().getName() + 
                                		" (damage attack), 2 for " + player.getPower().getStatusEffect().getName() + 
                                		" (status effect), or 3 for " + player.getPower().getHealingSpell().getName() + " (healing). ");
                                scanner.nextLine();
                                System.out.println();
                                int pow = scanner.nextInt();
                                if(pow == 1)
                                {
                                    System.out.println();
                                    System.out.println("You used " + player.getPower().getPowerAttack().getName());
                                    scanner.nextLine();
                                    
                                    int powerDam = player.getPower().getPowerAttack().getStr() + player.getIntel();
                                    for(int k = 0; k < monsters.size(); k++)
                                    {
                                        if(monsters.get(k) != null)
                                        {
                                            int d = powerDam - monsters.get(k).getDef();
                                            if(player.getIntel() > monsters.get(k).getDex());
                                            {
                                                monsters.get(k).takeDamage(d);
                                                System.out.println("You did " + d + " " + player.getPower().getName() + " damage to monster " + (k + 1));
                                                scanner.nextLine();
                                            }
                                            if(player.getIntel() <= Randomizer.nextInt(monsters.get(k).getDex(), monsters.get(k).getDex()*2))
                                            {
                                            	System.out.println("You missed monster " + (k+1));
                                                scanner.nextLine();
                                            }
                                            if(monsters.get(k).getHel() <= 0)
                                            {
                                            	System.out.println("Monster " + (k+1) + " has been defeated");
                                                scanner.nextLine();
                                                player.gainExp(monsters.get(k).getExp());
                                                if(player.hasEnoughExp())
                                                {
                                                    player.lvlUp();
                                                    player.setNextLvl(player.nxtLvl()*2);
                                                }
                                                monsters.set(k, null);
                                            }    
                                        }
                                    }
                                }
                                else if(pow == 2)
                                {
                                    System.out.println();
                                    System.out.println("You used " + player.getPower().getStatusEffect().getName());
                                    scanner.nextLine();
                                    for(int k = 0; k < player.getPower().getStatusEffect().getBonus(); k++)
                                    {
                                        int ranMon2 = Randomizer.nextInt(0, monsters.size()-1);
                                        while(monsters.get(ranMon2) == null)
                                        {   
                                            ranMon2 = Randomizer.nextInt(0, monsters.size()-1);
                                        }
                                        //Monster currentMon = monsters.get(ranMon2);                    
                                        player.statusAction(monsters.get(Randomizer.nextInt(0, monsters.size()-1)));
                                    }
                                }
                                else
                                {
                                    System.out.println();
                                    System.out.println("You used " + player.getPower().getHealingSpell().getName());
                                    scanner.nextLine();
                                    int numHealed = player.getPower().getHealingSpell().getHealth() + player.getIntel();
                                    player.heal(numHealed);
                                    if(player.getMaxHealth() < player.getHel())
                                    {
                                        player.setHel(player.getMaxHealth());
                                        System.out.println("You are back to max health!");
                                        scanner.nextLine();
                                    }
                                    else
                                    {
                                    	System.out.println("You healed " + numHealed + " health!");
                                        scanner.nextLine();
                                    }
                                }
                            }   
                            
                            
                            if(!isAllNull(monsters))
                            {
                                System.out.println();
                                System.out.println("The monsters attack!");
                                scanner.nextLine();
                                for(int j = 1; j <= monsters.size()/2 + 1; j++)
                                {
                                    int ranMon1 = Randomizer.nextInt(0, monsters.size()-1);
                                    while(monsters.get(ranMon1) == null)
                                    {
                                        ranMon1 = Randomizer.nextInt(0, monsters.size()-1);
                                    }
                                    Monster currentMon = monsters.get(ranMon1);
                                    System.out.println();
                                    System.out.println("Monster " + (ranMon1+1) + " attacked!");
                                    int monDam = currentMon.getStr() + currentMon.getWeapon().getStr() - player.getDef();
                                    if(monDam < 0)
                                    {
                                        monDam = 0;
                                    }
                                    int monHit = Randomizer.nextInt(1, currentMon.getSpd()) + Randomizer.nextInt(1, currentMon.getDex());
                                    int playerDodge = Randomizer.nextInt(1, player.getSpd()) + Randomizer.nextInt(1, currentMon.getDex()) - player.getWeapon().getWeight();
                                    if(monHit >= playerDodge)
                                    {
                                        player.takeDamage(monDam);
                                        System.out.println(name + " took " + monDam + " damage from monster " + (ranMon1+1));
                                        scanner.nextLine();
                                    }
                                    else
                                    {
                                    	System.out.println("Monster " + (ranMon1+1) + " missed!");
                                        scanner.nextLine();
                                    }
                                    if(player.getHel() <= 0)
                                    {
                                    	System.out.println("Your Character has died!");
                                        scanner.nextLine();
                                        System.out.println("GAME OVER!");
                                        scanner.nextLine();
                                        break;
                                    }
                                }
                                if(player.getHel() <= 0)
                                {
                                    playing = false;
                                    break;
                                }
                            }
                            if(!isAllNull(monsters))
                            {
                            	System.out.println("How will u attack? 1 = Weapon, 2 = Power");
                            	action1 = scanner.nextInt();
                            }
                            else
                            {
                                System.out.println("You have defeated the monsters!");
                            }
                        }    
                        if(player.getHel() <= 0)
                        {
                            playing = false;
                            break;
                        }
                    }
                }
                else if(random == 3)
                {
                	System.out.println("There is Treasure here!");
                    scanner.nextLine();
                    ArrayList<Weapon> prizes = new ArrayList<Weapon>();
                    for(int k = 0; k < Randomizer.nextInt(2, 5); k++)
                    {
                        Weapon currentWeapon = new Weapon(Randomizer.nextInt(1, 4));
                        prizes.add(currentWeapon);
                        System.out.println("" + (k+1) + ". There is " + currentWeapon);
                    }
                    System.out.println("Pick the number of the weapon u want or 0 if u want to keep your current weapon. ");
                    int choice = scanner.nextInt();
                    if(choice != 0)
                    {
                        Weapon chosenWeapon = prizes.get(choice-1);
                        player.setWeapon(chosenWeapon);
                        System.out.println("Your new weapon is now " + chosenWeapon);
                        scanner.nextLine();
                        player.getWeapon().increaseAllStats();
                        System.out.println();
                        player.gainExp(chosenWeapon.getExp());
                    }
                    else
                    {
                        player.gainExp(prizes.size());
                    }
                    if(player.hasEnoughExp())
                    {
                        player.lvlUp();
                        player.setNextLvl(player.nxtLvl()*2);
                    }
                }
            }
            if(player.getHel() > 0)
            {
                System.out.println();
                System.out.println("You have finished the dungeon! ");
                scanner.nextLine();
                player.gainExp(numRooms*numRooms);
            }
            if(player.hasEnoughExp())
            {
                player.lvlUp();
                player.setNextLvl(player.nxtLvl()*2);
            }
            System.out.println();
            System.out.println("Continue playing? (true or false)");
            if(scanner.nextBoolean() == false)
            {
                playing = false;
            }
            else
            {
                playing = true;
            }
        }
        scanner.close();
    }
    
    public static boolean isAllNull(ArrayList<Monster> list)
    {
        for(int i = 0; i < list.size(); i++)
            if(list.get(i) != null)
                return false;
        return true;
    }
}

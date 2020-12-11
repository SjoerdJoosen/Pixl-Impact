using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class HealthManager : MonoBehaviour
{
    //fields
    private int maxHealth;
    private int currentHealth;

    //properties
    public int CurrentHealth
    {
        get { return this.currentHealth; }
    }

    //constructor
    public HealthManager(int MaxHealth)
    {
        this.maxHealth = MaxHealth;
        this.currentHealth = MaxHealth;
    }

    //class methods
    public void heal(int howMuchToHeal)
    {
        if (currentHealth + howMuchToHeal <= maxHealth)
        {
            currentHealth += howMuchToHeal;
        }
        else
        {
            currentHealth = maxHealth;
        }
    }

    public void damage(int howMuchToDamage)
    {
        currentHealth -= howMuchToDamage;
    }
}

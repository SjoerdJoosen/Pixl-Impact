using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class HealthManager : MonoBehaviour
{
    //fields
    public int maxHealth;
    private int currentHealth;


    //properties
    public int MaxHealth
    {
        get { return maxHealth; }
        set { maxHealth = value; }
    }

    public int CurrentHealth
    {
        get { return this.currentHealth; }
    }

    // Start is called before the first frame update
    void Start()
    {
        currentHealth = maxHealth;
    }

    void heal(int howMuchToHeal)
    {
        currentHealth += howMuchToHeal;
    }

    void damage(int howMuchToDamage)
    {
        currentHealth -= howMuchToDamage;
    }
}

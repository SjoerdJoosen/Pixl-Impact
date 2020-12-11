using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ArduinoManger : MonoBehaviour
{
    ArduinoMessageHandler messageHandler = new ArduinoMessageHandler();
    HealthManager PlayerManager;
    private int currentHealth;
    private int oldHealth;
    // Start is called before the first frame update
    void Start()
    {
        PlayerManager = GameObject.FindGameObjectWithTag("PlayerPropertyManager").GetComponent<HealthManager>();
        currentHealth = PlayerManager.CurrentHealth;
        oldHealth = currentHealth;
    }

    // Update is called once per frame
    void Update()
    {
        checkHealth();
    }

    private void checkHealth()
    {
        currentHealth = PlayerManager.CurrentHealth;
        if (currentHealth != oldHealth)
        {
            messageHandler.sendMessage("HEALTH:" + currentHealth);
            oldHealth = currentHealth;
        }
    }
}

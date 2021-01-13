using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ArduinoManger : MonoBehaviour
{
    //these fields are used so i can reopen the port 1 second after starting the program
    private bool portHasOpened = false;
    private float timeLeft = 0.1f;

    ArduinoMessageHandler messageHandler;

    public void Start()
    {
        messageHandler = GameObject.FindGameObjectWithTag("Arduino").GetComponent<ArduinoMessageHandler>();
    }

    public void Update()
    {
        if (portHasOpened == false)
        {
            timeLeft -= Time.deltaTime;
            if (timeLeft < 0)
            {
                messageHandler.reopen();
                sendStartValues();
                portHasOpened = true;
            }
        }
    }

    public void updateHealth(int healthToSend)
    {
        messageHandler.sendMessage("HEALTH:" + healthToSend);
    }
    public void updateAmmo (int ammoToSend)
    {
        messageHandler.sendMessage("AMMO:" + ammoToSend);
    }
    public void updateCoins (int coinsToSend)
    {
        messageHandler.sendMessage("COINS:" + coinsToSend);
    }

    private void sendStartValues()
    {
        updateHealth(6);
        updateAmmo(10);
        updateCoins(0);
    }
}

using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ArduinoManger : MonoBehaviour
{
    ArduinoMessageHandler messageHandler;

    public void Start()
    {
        messageHandler = GameObject.FindGameObjectWithTag("Arduino").GetComponent<ArduinoMessageHandler>();
        updateHealth(6);
        updateAmmo(10);
        updateCoins(0);
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
}

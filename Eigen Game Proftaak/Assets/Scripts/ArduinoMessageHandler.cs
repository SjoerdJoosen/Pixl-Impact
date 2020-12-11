using System.Collections;
using System.Collections.Generic;
using System.IO.Ports;
using System;
using UnityEngine;

public class ArduinoMessageHandler : MonoBehaviour
{
    //port fields
    private SerialPort myPort;
    private string portName = "COM4";
    private char startChar = '#';
    private char endChar = '%';


    //Constructor
    private ArduinoMessageHandler()
    {
        startPortCommunication();
    }

    //sends message to serial output
    public void sendMessage(string message)
    {
        if (myPort.IsOpen)
        {
            myPort.Write(startChar + message + endChar); //"#AN_EXAMPLE_MESSAGE%"
        }
    }

    private void startPortCommunication()
    {
        try
        {
            myPort = new SerialPort();
            myPort.BaudRate = 9600;
            myPort.PortName = this.portName;
            myPort.Open();
        }
        catch (Exception)
        {
            UnityEngine.Debug.Log("could not connect to arduino port");
        }
    }
}

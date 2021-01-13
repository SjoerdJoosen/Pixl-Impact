using System.Collections;
using System.Collections.Generic;
using System.IO.Ports;
using System;
using UnityEngine;

public class ArduinoMessageHandler : MonoBehaviour
{
    //port fields
    static private SerialPort myPort;
    private string portName = "COM7";
    private char startChar = '#';
    private char endChar = '%';

    

    //Constructor
    public ArduinoMessageHandler()
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
        UnityEngine.Debug.Log(startChar + message + endChar);
    }

    private void startPortCommunication()
    {
        myPort = new SerialPort();
        myPort.BaudRate = 9600;
        myPort.PortName = this.portName;
        
        myPort.Close();
        myPort.Open();
    }

    public void reopen()
    {
        myPort.Close();
        myPort.Open();
        UnityEngine.Debug.Log("port reopened");
    }
}

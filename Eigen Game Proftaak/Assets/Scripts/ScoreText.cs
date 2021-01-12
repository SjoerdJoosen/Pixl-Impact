using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;

public class ScoreText : MonoBehaviour
{
    private ArduinoManger arduino;
    public static ScoreText instance;
    public TextMeshProUGUI text;
    int score = 0;

    void Start()
    {
        arduino = GameObject.FindGameObjectWithTag("Arduino").GetComponent<ArduinoManger>();
        if (instance == null)
        {
            instance = this;
        }
    }

    public void ChangeCoinAmount(int coinValue)
    {
        score += coinValue;
        text.text = score.ToString();
        arduino.updateCoins(score);
    }
}

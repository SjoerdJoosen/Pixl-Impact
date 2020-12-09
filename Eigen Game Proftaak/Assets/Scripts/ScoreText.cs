using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;

public class ScoreText : MonoBehaviour
{
    public static ScoreText instance;
    public TextMeshProUGUI text;
    int score;

    void Start()
    {
        if (instance == null)
        {
            instance = this;
        }
    }

    public void ChangeCoinAmount(int coinValue)
    {
        score += coinValue;
        text.text = score.ToString();
    }
}

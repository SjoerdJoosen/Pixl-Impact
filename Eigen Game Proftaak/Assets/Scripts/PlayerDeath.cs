using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Tilemaps;
using Cinemachine;

public class PlayerDeath : MonoBehaviour
{
    public Tilemap DeathTiles;
    public ContactPoint2D[] contacts = new ContactPoint2D[1];
    public Vector3 respawnPoint;
    private ArduinoManger arduino;

    private int health = 6;

    private void Start()
    {
        respawnPoint = transform.position;
        arduino = GameObject.FindGameObjectWithTag("Arduino").GetComponent<ArduinoManger>();
    }
    private void OnTriggerEnter2D(Collider2D collision)
    {

        if (collision.gameObject.name == "FallDetector")
        {
            transform.position = respawnPoint;
            health--;
            arduino.updateHealth(health);
        }

        if (collision.gameObject.tag == "Checkpoint")
        {
            respawnPoint = collision.transform.position;
        }
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.gameObject.CompareTag("Enemy"))
        {
            transform.position = respawnPoint;
            health--;
            arduino.updateHealth(health);
        }
    }
}

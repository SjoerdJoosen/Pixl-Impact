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
    public HealthManger playerHealth;


    private void Start()
    {
        respawnPoint = transform.position;
    }
    private void OnTriggerEnter2D(Collider2D collision)
    {

        if (collision.gameObject.name == "FallDetector")
        {
           // Destroy(gameObject);
            // LevelManager.instance.Respawn();
            transform.position = respawnPoint;
        }

        if (collision.gameObject.tag == "Checkpoint")
        {
           // LevelManager.instance.Respawn(); 
            respawnPoint = collision.transform.position;
        }
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.gameObject.CompareTag("Enemy")|| collision.gameObject.tag == "Checkpoint")
        {
            // Destroy(gameObject);
            transform.position = respawnPoint;
            //playerHealth.damage(1);
        }
        //if (collision.gameObject.tag == "Checkpoint")
        //{
        //    // LevelManager.instance.Respawn(); 
        //    respawnPoint = collision.transform.position;
        //}
    }
}

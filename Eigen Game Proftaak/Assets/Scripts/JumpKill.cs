using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class JumpKill : MonoBehaviour
{
    public Vector3 respawnPoint;
    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.gameObject.CompareTag("Enemy") && collision.gameObject.CompareTag("Feet"))
        {
            Destroy(gameObject);
        }

        else if (collision.gameObject.CompareTag("Enemy")) 
        {
            transform.position = respawnPoint;
        }
    }
}

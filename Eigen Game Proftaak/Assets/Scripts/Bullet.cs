using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bullet : MonoBehaviour {
    public float bulletSpeed = 15f;
    public float bulletDamage = 10f;
    public float bulletTime = 2f;
    public Rigidbody2D rb;

    private void Start()
    {
            Destroy(gameObject, bulletTime);
    }

    private void FixedUpdate()
    {
        rb.velocity = transform.right * bulletSpeed;
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        Destroy(gameObject);

        if (collision.gameObject.tag == "Enemy")
        {
            Destroy(collision.gameObject);
        }
    }

}

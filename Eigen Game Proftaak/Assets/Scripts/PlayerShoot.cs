using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerShoot : MonoBehaviour {
    public float fireRate = 0.2f;
    public Transform firingPoint;
    public GameObject bulletPrefab;

    private ArduinoManger arduino;
    private int ammo = 10;

    float timeUntilFire;
    PlayerMovement pm;

    private void Start()
    {
        pm = gameObject.GetComponent<PlayerMovement>();
        arduino = GameObject.FindGameObjectWithTag("Arduino").GetComponent<ArduinoManger>();
    }

    private void Update()
    {
        if((Input.GetMouseButtonDown(0) || Input.GetKeyDown(KeyCode.L)) && timeUntilFire < Time.time)
        {
            Shoot();
            timeUntilFire = Time.time + fireRate;
        }
        if (Input.GetKeyDown(KeyCode.K))
        {
            ammo = 10;
            updateAmmo();
        }
    }

    private void Shoot()
    {
        if (ammo != 0)
        {
            float angle = pm.isFacingRight ? 0f : 180f;
            Instantiate(bulletPrefab, firingPoint.position, Quaternion.Euler(new Vector3(0f, 0f, angle)));
            ammo--;
            updateAmmo();
        }
    }

    private void updateAmmo()
    {
        arduino.updateAmmo(ammo);
    }
}

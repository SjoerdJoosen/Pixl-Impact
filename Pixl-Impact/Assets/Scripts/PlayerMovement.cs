using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMovement : MonoBehaviour {
    public float movementSpeed;
    public Rigidbody2D rb;

    public Animator Anim;

    public float jumpForce = 20f;

    float mx;
    public Transform feet;
    public LayerMask groundLayers;

    private void Update() {
        mx = Input.GetAxis("Horizontal");

        if (Input.GetButtonDown("Jump") && isGrounded()) {
            Jump();
        }

        if (Mathf.Abs(mx) > 0.05f) {
            Anim.SetBool("isRunning", true);
        } else {
            Anim.SetBool("isRunning", false);
        }

        if (mx > 0f) {
            transform.localScale = new Vector3(-1.75f, 1.75f, 1.75f);
        } else if (mx < 0f) {
            transform.localScale = new Vector3(1.75f, 1.75f, 1.75f);
        }
    }

    private void FixedUpdate()
    {
        Vector2 movement = new Vector2(mx * movementSpeed, rb.velocity.y);

        rb.velocity = movement;
    }

    void Jump() {
        Vector2 movement = new Vector2(rb.velocity.x, jumpForce);

        rb.velocity = movement;
    }

    public bool isGrounded() {
        Collider2D groundCheck = Physics2D.OverlapCircle(feet.position, 0.5f, groundLayers);

        if (groundCheck != null) {
            return true;
        }

        return false;
    }

}

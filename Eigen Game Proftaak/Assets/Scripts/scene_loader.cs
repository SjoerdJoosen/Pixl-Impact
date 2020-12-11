using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;


public class scene_loader : MonoBehaviour
{
    public Animator transition;

    // Update is called once per frame
    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.gameObject.CompareTag("LevelEnding"))
        {
            LoadNextLevel();
        }
    }

    public void LoadNextLevel()
    {
        StartCoroutine(Loadlevel(SceneManager.GetActiveScene().buildIndex + 1));
        
    }

    IEnumerator Loadlevel(int levelIndex)
    {
        transition.SetTrigger("StartFade");

        yield return new WaitForSeconds(3);

        SceneManager.LoadScene(levelIndex);
    }
}

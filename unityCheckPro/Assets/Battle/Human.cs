using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Human : MonoBehaviour
{
    Animator anim;
    Rigidbody rb;
    Vector3 _move,_moveZero,_moveRight;
    bool flag=false;
    int timer=0;

    // Start is called before the first frame update
    void Start()
    {
        anim = this.GetComponent<Animator>();
        rb = this.GetComponent<Rigidbody>();
        flag = false;
        _move = new Vector3(0,0,0);
        _moveRight = new Vector3(10.0f,0,0);
        _moveZero = new Vector3(0,0,0);
    }

    void FixedUpdate()
    {
        rb.velocity = _move;

        if(timer > 40 && flag ==false)
        {
            Walk();
            flag = true;
        }
        else if(timer < 80 && flag == true)
        {
            //何もしない
        }
        else if(flag == true)
        {
            timer =0;
            _move = _moveZero;
            flag=false;
        }

        //timer
        timer++;

    }

    void Walk()
    {
        anim.SetTrigger("walk");
        _move = _moveRight;
    }
}

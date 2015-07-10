
/*** SEGUIR UN OBJETO ***/

//El sensor que vamos a usar es el ultrasonido HC-SR04
//Autor: German Souto Fernandez
//Empresa: Asociacion Start-Robot
//---------------------------------------------------------------------

//Cargamos la librerias
#include <Servo.h>
#include <Ultrasonic.h>

Servo servo_6; //Creamos el objeto del servo izquierdo
Servo servo_9; //Creamos el objeto del servo derecho

Ultrasonic ultrasonic(11,10); // (Trig PIN, Echo PIN) 

void setup() {
  // put your setup code here, to run once:
  servo_6.attach(6); //Conexion servo izquierdo
  servo_9.attach(9); //Conexion servo derecha
}

void loop() {
  // put your main code here, to run repeatedly:
  if (ultrasonic.Ranging(CM) <25){
    //Evitar chocar con el objetivo
    servo_6.write(90);// el servo izquierdo para
    servo_9.write(90);// el servo derecho para
    delay(1000);
  } else if (ultrasonic.Ranging(CM) > 35) {
  //Cuando el robo se encuentra a la distancia de 20 lo sigue
    servo_6.write(0);// el servo izquierdo va hacia delante
    servo_9.write(180);//el servo derecho va hacia delante
    delay(1000);
  }else{
    //Busacar objetivo
    servo_6.write(0); // el servo izqwuierdo va hacia delante
    servo_9.write(90); // el servo derecho se para
    delay(1000);
  }
}

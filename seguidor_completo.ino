#include <GuaraTeca_OBR.h>
//motor 1: portas 2,3 | velocidade: 9
//motor 2: portas 4,5 | velocidade: 10
HRobot robo(2,3,9,4,5,10,100);//define o robo nas portas e define a velocidade em 100%
Sensor refesq(6); //sensor de refletância do lado esquerdo
Sensor refdir(7); //sensor de refletância do lado direito
Sensor ultrassonico(22,24);
void setup() {
 
  robo.DefineVelocidade(100,100); //define a velocidade nos motores 1 e 2
}

void loop() {

  if((refesq.luz() == LOW) and (refdir.luz() == LOW)){ //se os dois sensores detectar branco ele anda pra frente
    
    robo.frente();
    }
    else if((refesq.luz() == HIGH) and (refdir.luz() == HIGH) and (ultrassonico.distancia() < 12)){ //se os sensores detectarem branco, mas tiver um obstaculo na frente ele faz o desvio
      robo.para(0.3);
      robo.direita(0.5);
      robo.para(0.3);
      robo.esquerda(0.5); 
      robo.frente(0.5);
      }
      else if((refesq.luz() == LOW) and (refdir.luz() == HIGH)){ //faz curva para a direita
        robo.direita(0.5);
        }
        else if((refesq.luz() == HIGH) and (refdir.luz() == LOW)){ //faz curva para a esquerda
          robo.esquerda(0.5);
          }
          else((refesq.luz() == HIGH) and (refdir.luz() == HIGH)){ //caso os 2 sensores detecte a faixa preta ele faz uma curva para a direita 
            robo.direita(0.5);
            }

//  robo.frente(0.5);//Robo ira para frente por 500ms
//  robo.tras(0.5);//Robo ira para tras por 500ms
//  robo.direita(0.5);//Robo ira para direita por 500ms
//  robo.esquerda(0.5);//Robo ira para esquerda por 500ms
//  robo.para(0.5);//Robo ira parar por 500ms

}

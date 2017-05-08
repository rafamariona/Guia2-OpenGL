#include <GL/gl.h>
#include <GL/glut.h>

void init(){
    // Limpia la ventana con el color azul
    glClearColor(0.0, 0.0, 0.5, 0);
    // El tipo de proyección
    glMatrixMode(GL_PROJECTION);
    // Define el tamaño del ortho
    glOrtho(-70,70,-70,70,-70,70);
    //vista
    //gluLookAt(0.0, 10.0, -10.0, 0.0, 0.0, 0.0, 0, 1, 1);

}

//EjesDeReferencia
void ejes(){
    glBegin (GL_LINES);
    glColor3f(1.0,0.0,0.0);//rojo para el eje x
    glVertex3f (-800.0, 0.0, 0.0);
    glVertex3f (800.0, 0.0, 0.0);
    glColor3f(0.0,1.0,0.0);// verde para el eje y
    glVertex3f ( 0.0, -600.0, 0.0);
    glVertex3f ( 0.0,600.0, 0.0);
    glColor3f(1.0,1.0,1.0);//blanco para el eje z
    glVertex3f ( 0.0, 0.0, -800.0);
    glVertex3f ( 0.0, 0.0,800.0);
    glEnd();
    glFlush();
}
//se dibuja todo
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);//limpia la ventana
  	int counter = 0; //contador para los cuadros
    //ejes();//llama la función ejes(comentada porque ya no se ocupan)
    //Rota el tablero en x y y para que se vea "acostado"
    glRotatef(55, 0.0, 1.0, 0.0 );
    glRotatef(15, 1.0, 0.0, 0.0 );
    glPushMatrix();//Guarda la matriz de coordenadas
    glTranslatef(-60,-60,0);//para mostrar el tablero con centro en (0,0,0)

    //Acá pasa la magia (se dibuja el tablero)
    for (GLint x = 0; x < 120; x += 15)
  	{
  		for (GLint y = 0; y < 120; y += 15)
  		{
  			if (((x + y) / 15) & 1){
  				glColor3f(0.0, 0.0, 0.0);//los negros
  			}
  			else{
  				glColor3f(1.0, 1.0, 1.0);//los blancos
  			}
  			glRecti(x, y, (x + 15), (y + 15));//dibuja un rectangulo
  		}//final del for para y
  	}//final del for para x
  	glFlush();

    glPopMatrix();//Reestablece la matriz de coordenadas
    glutSwapBuffers();
}
int main(int agrc, char ** argv){
    glutInit(&agrc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow ("Guia #2 Ejercicio 1 by MT14002");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

}

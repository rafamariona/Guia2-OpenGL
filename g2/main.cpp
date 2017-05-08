#include <GL/gl.h>
#include <GL/glut.h>

void init(){
    // Limpia la ventana con el color azul
    glClearColor(0.0, 0.0, 0.502, 0);

}

//se dibuja todo
void display(void)
{
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		//Transformaciones para el tablero
		glScalef(0.9,0.5,0.1);
    glRotatef(185,0,1,0);
    glTranslatef(-1.0,-0.5,0.0);
    glRotatef(20,1,0,0);
		glFlush ();

		//Paredes
		glColor3f(1,1,1);
		//derecha
		glBegin(GL_POLYGON);
		glVertex3f(.25,0.5,0);
		glVertex3f(.25,1.5,0);
		glVertex3f(.25,1.5,3);
		glVertex3f(.25,0.5,3);
		glEnd();
		//atras
		glBegin(GL_POLYGON);
		glVertex3f(0,0.5,0);
		glVertex3f(1.25,0.5,0);
		glVertex3f(1.25,1.5,0);
		glVertex3f(0,1.5,0);
		glEnd();
		//izquierda
		glBegin(GL_POLYGON);
		glVertex3f(1.25,0.5,0);
		glVertex3f(1.25,1.5,0);
		glVertex3f(1.25,1.5,3);
		glVertex3f(1.25,0.5,3);
		glEnd();

		glFlush();

		//Acá pasa la magia (se dibuja el tablero)
		GLfloat ejey=-0.0f,ejex=-0.855f,cons=0.25f;//las variables que ocupa
		int col=0;
		for(int y=0; y<=11;y++){//inicia for para y
				ejex=0;
				for(int x=0; x<=4;x++){//inici for para x
			 	if(col==0){
					glColor3f(0,0,0);//color negro
					col=1;
				}
				else{
					glColor3f( 1.0, 1.0, 1.0 );//color blanco
					col=0;
				}
			 		glBegin(GL_QUADS);//dibuja los cuadrados
					glVertex3f(ejex,0.5,ejey);
					glVertex3f(ejex+cons,0.5,ejey);
				 	glVertex3f(ejex+cons,0.5,ejey+cons);
					glVertex3f(ejex,0.5,ejey+cons);

				glEnd();
				glFlush();
				ejex=ejex+cons;
		}
				ejey=ejey+cons;
		}

		glutSwapBuffers();


}
//función principal
int main(int agrc, char ** argv){
    glutInit(&agrc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow ("Guia #2 Ejercicio 2 by MT14002");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

}

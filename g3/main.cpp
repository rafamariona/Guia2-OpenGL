#include <GL/gl.h>
#include <GL/glut.h>


void paredes(double ancho)  //función para las paredes
{
    glPushMatrix();//guarda la matriz de coordenadas
    glTranslated(0.5,0.5*ancho,0.5);
    glScaled(1.0,ancho,1.0);
    glutSolidCube(1.0);
    glPopMatrix();  //resetea la matriz
}

void patas(double ancho,double largo)  //función para las patas
{
    glPushMatrix();  //guarda la matriz de coordenadas
    glTranslated(0,largo/2,0);
    glScaled(ancho,largo,ancho);
    glutSolidCube(1.0);
    glPopMatrix();  //resetea la matriz
}

void mesa(double a, double b,double c,double d)
{    glPushMatrix();
    glTranslated(0,d,0);
    glScaled(a, b,a);
    glutSolidCube(1.0);  //dibuja la tabla
    glPopMatrix();
    double dist =0.95* a/2.0 - c/2.0; //calcula la distancia
    glPushMatrix();
    glTranslated(dist,0,dist);
    patas(c,d);  //dibuja una pata
    glTranslated(0.0,0.0,-2*dist);
    patas(c,d);  //dibuja una pata
    glTranslated(-2*dist,0,2*dist);
    patas(c,d);  //dibuja una pata
    glTranslated(0,0,-2*dist);
    patas(c,d);  //dibuja una pata
    glPopMatrix();
}

void display(void)
{
    //materiales
    GLfloat mat_ambient[] =  {0.0f,  0.0f,  0.0f,  1.0f};// rojo plastico
    GLfloat mat_diffuse[] =  {1.0f,  0.0f,  0.0f,  1.0f};
    GLfloat mat_specular[] = {0.60f, 0.60f,	0.50f, 1.0f};
    GLfloat mat_shininess[]={50.0f};

    glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
    glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
    glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);

    // Define las luces
    GLfloat lightIntensity[] ={ 1.0f,1.0f,1.0f,1.0f};
    GLfloat light_position[] ={ 2.0f,6.0f,3.0f,0.0f};
    glLightfv(GL_LIGHT0 ,GL_POSITION,light_position);
    glLightfv(GL_LIGHT0 ,GL_DIFFUSE,lightIntensity);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.33,1.33, -1,1,0.1,100.0); //espacio
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(2.3,1.3,2.0,0.0,0.25,0.0,0.0,1.0,0.0); //vista
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glTranslated(0.4,0,0.4);
    //materiales para la mesa
    mat_diffuse[0] =  1.0f;
    mat_diffuse[1] =  0.0f;
    glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
    mesa(0.6,0.02,0.02,0.3); //llama la funcion mesa
    glPopMatrix();
    glPushMatrix();
    glTranslated(0.4,0.38,0.5);
    glRotated(45,0,1,0);
    glutSolidTeapot(0.1);  //muestra una tetera
    glPopMatrix();
    //materiales para las paredes
    mat_diffuse[0] =  1.0f;
    mat_diffuse[1] =  0.829f;
    mat_diffuse[2] =  0.829f;
    glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
    paredes(0.02); //dibuja la pared de abajo
    glPushMatrix();
    glRotated(90.0,0.0,0.0,1.0);
    paredes(0.02); //dibuja la pared de la izquierda
    glPopMatrix();
    glPushMatrix();
    glRotated(-90.0,1.0,0.0,0.0);
    paredes(0.02); //dibuja la pared de la derecha
    glPopMatrix();
    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(100,100);
    glutCreateWindow ("Guia #2 Ejercicio 3 by MT14002");
    glutDisplayFunc(display);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_NORMALIZE);
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0,0.0,0.502,0.0);
    glViewport(0,0,640,480);
    glutMainLoop();

return 0;

}

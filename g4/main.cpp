#include <GL/gl.h>
#include <GL/glut.h>

//variables para dibujar los cuadrados
float px =21.87, a=0, pz=31.25;
void pared(){
    GLfloat ejey=0.0f,ejex=-150,px1=23.214f,pz1=31.25,espacio=0;;
    int col=0, a=0,b=10;
    for(int y=0; y<=3;y++){
        ejex=-150;b=10;
        for(int x=0; x<=12;x++){
           glBegin(GL_QUADS);
           glVertex3f(ejex+espacio,ejey+espacio,-150+a);
           glVertex3f(ejex+px1,ejey+espacio,-150+b);
           glVertex3f(ejex+px1,ejey+pz1,-150+b);
           glVertex3f(ejex+espacio,ejey+pz1,-150+a);
           if (b==10){
                    a=10;
                    b=0; /* code */
                      }
                else{
                    b=10;
                    a=0;
                }
            glEnd();
            glFlush();
            espacio=2;
            ejex=ejex+px1;
        }
        ejey=ejey+pz1;
    }
}

void pared2(){
    GLfloat ejey=-150.0f,ejex=-150,px1=23.214f,pz1=31.25,espacio=0;;
    for(int y=0; y<=8;y++){
        ejex=-150,a=0;
        for(int x=0; x<=12;x++){
           glBegin(GL_QUADS);
           glVertex3f(ejex+espacio,0,ejey+espacio);
           glVertex3f(ejex+px1,0,ejey+espacio);
           glVertex3f(ejex+px1,0,ejey+pz1);
           glVertex3f(ejex+espacio,0,ejey+pz1);
           glEnd();
           glFlush();
           espacio=2;
           ejex=ejex+px1;
        }
        ejey=ejey+pz1;
    }
}
void init(void)
{
	  glShadeModel(GL_SMOOTH);
    // Ubicamos la fuente de luz en el punto
    GLfloat light_position[] = { -220, 80.0, 170.0, 1.0 };
    GLfloat luz_ambiental[] = { 0.2, 0.2, 0.2, 1.0 };
    // Activamos la fuente de luz
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);
    glLightfv(GL_LIGHT0,GL_POSITION,light_position);
    // Queremos que se dibujen las caras frontales
    // y con un color solido de relleno.
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

}


void display(void)
{
    // Propiedades del material
    GLfloat mat_ambient[] = { 0.0215f, 0.1745f, 0.0215f,1.0f };
    GLfloat mat_diffuse[] = { 0.07568f, 0.61424f, 0.07568f, 1.0f };
    GLfloat mat_specular[] = { 0.633f, 0.727811f, 0.633f, 1.0f };
    GLfloat shine[] = {40};
    // "Limpiamos" el frame buffer con el color de "Clear", en este
    // caso negro.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode( GL_MODELVIEW_MATRIX );
    glLoadIdentity();
    //setMaterial
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shine);
    glTranslatef(-20,-20,0);
    glRotatef(20,1,0,0);
    glRotatef(-15,0,1,0);
    //dibujamos las paredes
    pared();
    pared2();
    // dibujamos las figuras
    glTranslatef(0,75,110);
    glPushMatrix();
    GLfloat light_position[] = { -100, 100.0, 125.0, 1}; //agregamos luz
    glLightfv(GL_LIGHT0,GL_POSITION,light_position);

    //color de la esfera .329412	0.223529	0.027451	0.780392	0.568627	0.113725
    mat_ambient[0]= 0.329412f, mat_ambient[1]=0.225f, mat_ambient[2]= 0.027451f;
    mat_diffuse[0]= 0.780392, mat_diffuse[1]=0.568627f, mat_diffuse[2]= 0.113725f;
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glTranslatef(-100,0,0);
    glutSolidSphere(40,50,50);  //dibujamos la esfera
    glPopMatrix();
    glPushMatrix();

    glRotatef(-15,0,1,0);
    glRotatef(10,1,0,0);
    //color del cubo 0.135	0.2225	0.1575
    mat_ambient[0]= 0.135f, mat_ambient[1]=0.225f, mat_ambient[2]= 0.1575f;
    mat_diffuse[0]= 0.135f, mat_diffuse[1]=0.225f, mat_diffuse[2]= 0.1575f;
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glutSolidCube(50); //dibujamos el cubo
    glPopMatrix();
    glPushMatrix();

    //color del cono 0.1745	0.01175	0.01175	0.61424	0.04136	0.04136	0.727811
    mat_ambient[0]= 0.1745f, mat_ambient[1]=0.01175f, mat_ambient[2]= 0.001175;
    mat_diffuse[0]= 0.61424f, mat_diffuse[1]=0.04136f, mat_diffuse[2]= 0.727811;
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glTranslatef(100,-25,0);
    glRotatef(-90,1,0,0);
    glutSolidCone(50,70,10,25); //dibujamos el cono
    glPopMatrix();
    glFlush();
}

void reshape(int w, int h)
{
    glViewport(0, 0,  (GLsizei) w, (GLsizei) h);
    // Activamos la matriz de proyeccion.
    glMatrixMode(GL_PROJECTION);
    // "limpiamos" esta con la matriz identidad.
    glLoadIdentity();
    // Usamos proyeccion ortogonal
    glOrtho(-200, 200, -200, 200, -200, 200);
    // Activamos la matriz de modelado/visionado.
    glMatrixMode(GL_MODELVIEW);
    // "Limpiamos" la matriz
    glLoadIdentity();
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(100,100);
    glutCreateWindow ("Guia #2 Ejercicio 4 by MT14002");
    glClearColor(0,0,0,0.0);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_NORMALIZE);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();

return 0;

}

#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>

int x_x, y_y;
int ve_x, ve_y;
int rex, rey;
int ne_x, ne_y;
int stado;

//definimos las funciones para el cambio de material 

float mate_ambient[] ={ 0.329412f,0.223529f,0.027451f ,1.0f};
float mate_diffuse[] ={ 0.780392f,0.568627f,0.113725f,1.0f};
float mate_specular[] ={0.992157f,0.807843f,0.04f,1.0f };
float shine[] ={27.8974f};
          

void init(void)
{
	glClearColor(5.0,5.0,0.0,0.0); //definimos el color de la ventana 

// Activamos la fuente de luz
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);
}

void reshape(int w, int h)
{
    glViewport(0, 0,  (GLsizei) w, (GLsizei) h);
// Activamos la matriz de proyeccion.
    glMatrixMode(GL_PROJECTION);
// "limpiamos" esta con la matriz identidad.
    glLoadIdentity();
// Usamos proyeccion ortogonal
    glOrtho(-300, 300, -300, 300, -300, 300);
// Activamos la matriz de modelado/visionado.
    glMatrixMode(GL_MODELVIEW);
// "Limpiamos" la matriz
    glLoadIdentity();

}

// Aqui ponemos lo que queremos dibujar.
void display(void)
{
// Propiedades del material
// "Limpiamos" el frame buffer con el color de "Clear", en este
// caso negro.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	    GLfloat light_position[] = { (int)((0.03076923076923076923076923076923 * (ne_x + ve_x)) - 10), (int)((0.03076923076923076923076923076923 * (ne_y + ve_y)) - 10) * -1, 1.0, 0.0 };

	glLightfv(GL_LIGHT0,GL_POSITION,light_position);

    glMatrixMode( GL_MODELVIEW_MATRIX );
    glLoadIdentity();


    glPushMatrix();
//setMaterial
    glMaterialfv(GL_FRONT, GL_AMBIENT, mate_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mate_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mate_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shine);
//dibujamos la esferas.
    glutSolidSphere(100.0,150.0,150.0);
    glFlush();
}
//clase de material brass
void brass ()
{
	mate_ambient[0] = 0.329412f;
    mate_ambient[1] =0.223529f;
    mate_ambient[2] =0.027451f,1.0f ; 
    mate_diffuse[0] =  0.780392f ;
    mate_diffuse[1] = 0.568627f;
    mate_diffuse[2] = 0.113725f, 1.0f ;
    mate_specular[0] =  0.992157f;
    mate_specular[1] = 0.941176f;
    mate_specular[2] = 0.807843f, 1.0f ;
    shine[0] = 27.8f;
    
    /*definimos los parametros que necesitamos para nuestro material*/
	}

//clase de material glod
void gold()
{
	mate_ambient[0] = 0.24725;
    mate_ambient[1] =0.1995;
    mate_ambient[2] =0.0745,1.0f ;
    mate_diffuse[0] = 0.75164;
    mate_diffuse[1] = 0.60648;
    mate_diffuse[2] = 0.22648, 1.0f ;
    mate_specular[0] =0.628281;
    mate_specular[1] = 0.555802;
    mate_specular[2] = 0.366065, 1.0f ;
    shine[0] = 20.0f;
	}
	//clase de material copper
	void copper()
	{
		mate_ambient[0] = 0.19125;
    mate_ambient[1] =0.0735;
    mate_ambient[2] =0.0225,1.0f ;
    mate_diffuse[0] =0.7038;
    mate_diffuse[1] =0.27048;
    mate_diffuse[2] =0.0828, 1.0f ;
    mate_specular[0] =0.256777;
    mate_specular[1] =0.137622;
    mate_specular[2] =0.086014, 1.0f ;
    shine[0] = 15.0f;
		}

//clase de material red plastic
void red_plastic()
{
	mate_ambient[0] = 0.0;
    mate_ambient[1] =0.0;
    mate_ambient[2] =0.0,1.0f ;
    mate_diffuse[0] =0.5;
    mate_diffuse[1] =0.0;
    mate_diffuse[2] =0.0, 1.0f ;
    mate_specular[0] =0.7;
    mate_specular[1] =0.6;
    mate_specular[2] =0.6, 1.0f ;
    shine[0] = 10.0f;
	}
	//clase de material silver
	void silver()
	{
	mate_ambient[0] = 0.19225;
    mate_ambient[1] =0.19225;
    mate_ambient[2] =0.19225,1.0f ;
    mate_diffuse[0] =0.50754;
    mate_diffuse[1] =0.50754;
    mate_diffuse[2] =0.50754, 1.0f ;
    mate_specular[0] =0.508273;
    mate_specular[1] =0.508273;
    mate_specular[2] =0.508273, 1.0f ;
    shine[0] = 8.0f;
		}
// Termina la ejecucion del programa cuando se presiona ESC
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    //definimos la letra para el material brass
    case 'b':
    brass();
    break;
    
    //definimos la letra para el material gold
    case 'g':
    gold();
	break;
	
    //definimos la letra para el material copper
    case 'c':
    copper();
	break;
	
    //definimos la letra para el material red plastic
    case 'r':
    red_plastic();
	break;
	
    //definimos la letra para el material silver
    case 's':
    silver();
    
	break;
    }
    glutPostRedisplay();
}
void mouse_move(int button, int state, int x, int y)
    {
        int rx, ry;
        if(button == 0)
        {
            if(state == GLUT_UP)
            {
                ne_x = ne_x + ve_x;
                ne_y = ne_y + ve_y;
            }
        }
        
        //definicion de los parametros de movimiento de mouse
        
    }	
void move(int x, int y)
    {
        if(stado == 0)
        {
            stado = 1;
            rex = x;
            rey = y;
        }
        ve_x = x - rex;
        ve_y = y - rey;
        glutPostRedisplay();
        
        //definicion de coordenadas de movimiento de foco de luz
    }
void nomove(int x, int y)
    {
        x_x = x;
        y_y = y;
        stado = 0;
        ve_x = 0;
        ve_y = 0;
        
        //definicion de coordenadas cuando el no se esta moviendo el foco de luz
    }
// Main del programa.
int main(int argc, char **argv)
{
// Inicializo OpenGL
    glutInit(&argc, argv);

// Activamos buffer simple y colores del tipo RGB
    glutInitDisplayMode (GLUT_RGB | GLUT_DEPTH);

// Definimos una ventana de medidas 800 x 600 como ventana
// de visualizacion en pixels
    glutInitWindowSize (800, 600);

// Posicionamos la ventana en la esquina superior izquierda de
// la pantalla.
    glutInitWindowPosition (0, 0);

// Creamos literalmente la ventana y le adjudicamos el nombre que se
// observara en su barra de titulo.
    glutCreateWindow ("Esfera con iluminacion");

// Inicializamos el sistema
    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse_move);
    glutPassiveMotionFunc(nomove);
    glutMotionFunc(move);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}

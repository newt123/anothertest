#ifdef WIN32
	#include <windows.h>
#endif //WIN32
#include <stdio.h>
#include <GL/glut.h>

#include "gvector.h"
#include "gparticle.h"
#include "gworld.h"

GWorld* w;
GParticle* p;
double mx, my;

void getpos( int x, int y )
{
	double modelm[16];
	glGetDoublev( GL_MODELVIEW_MATRIX, modelm );
	double projm[16];
	glGetDoublev( GL_PROJECTION_MATRIX, projm );
	double z;
	int viewport[4];
	glGetIntegerv( GL_VIEWPORT, viewport );

	gluUnProject( x, glutGet( GLUT_WINDOW_HEIGHT ) - y, 0,
		modelm, projm, viewport,
		&mx, &my, &z );
}

void key( unsigned char key, int x, int y )
{
	getpos( x, y );
	switch( key )
	{
	case 'z':
	case 'Z':
		w->autoscale = false;
		glTranslatef( mx * -0.1, my * -0.1, 0 );
		w->scale *= 1.1;
		glScalef( 1.1, 1.1, 1.1 );
		break;
	case 'x':
	case 'X':
		w->autoscale = false;
		glTranslatef( mx * 0.1, my * 0.1, 0 );
		w->scale *= 0.9;
		glScalef( 0.9, 0.9, 0.9 );
		break;
	case ' ':
		w->autoscale = true;
		break;
	}
}

void click( int button, int state, int x, int y )
{
	getpos( x, y );

	if ( state == GLUT_DOWN )
	{
		p = w->ParticleAt( mx, my );
		if ( !p ) return;
		if ( button == GLUT_LEFT )
		{
			if ( p->init ) p->Init( w );
			p = 0;
		}
		else
		{
			w->greased = true;
		}
	}
	else // state == GLUT_UP
	{
		p = 0;
		w->greased = false;
	}
}

void move( int x, int y )
{
	if ( !p ) return;

	getpos( x, y );

	p->pos = GVector( mx, my );
	glutPostRedisplay();
}

void timer( int val )
{
	w->Render();
	w->ComputeForce();
	w->Step();
	glutPostRedisplay();
	glutTimerFunc( 1, timer, 0 );
}

void display()
{
	glutSwapBuffers();
	glFlush();
}

int main ( int argc, char** argv )
{
	w = new GWorld();
	w->Init();

	p = 0;

	glutInit( &argc, argv );
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_ALPHA );
	glutCreateWindow( "Jamgraph" );
	glutReshapeWindow( 600, 600 );

	//Antialiasing
	glEnable( GL_BLEND );
	glEnable( GL_POLYGON_SMOOTH );
	glEnable( GL_LINE_SMOOTH );
	glBlendFunc (GL_SRC_ALPHA, GL_ONE);
	glHint( GL_POLYGON_SMOOTH_HINT, GL_DONT_CARE );

	glutMouseFunc( click );
	glutMotionFunc( move );
	glutKeyboardFunc( key );
	glutDisplayFunc( display );
	glutTimerFunc( 1, timer, 0 );
	glutMainLoop();

	return 0;
}

#ifdef WIN32
int WINAPI WinMain(HINSTANCE h,HINSTANCE,LPSTR s,int)
{
	char* wargs[] = { "jamgraph", "foo" };
	return main( 1, wargs );
}
#endif //WIN32
#include <math.h>
#include <time.h>
#include <windows.h>
#include <GL/glut.h>

#include "gvector.h"
#include "gparticle.h"

#include "gworld.h"

GWorld::GWorld(void)
{
	parts = 0;
	mass = 100.0;
	scale = 1.0;
	greased = false;
	autoscale = true;
}

GWorld::~GWorld(void)
{
}

void GWorld::Init()
{
	srand( time( 0 ) );

	parts = new GParticle( 0, 0 );
	parts->name = "all";
	parts->initn = 5;
	parts->Init( this );
}

void GWorld::ComputeForce()
{
	//Forces get cleared in the ReScale() function.

	GParticle* p;
	for ( p = parts ; p ; p = p->next )
	{
		p->ComputeForce( this );
	}
}

void GWorld::Step()
{
	GParticle* p;
	for ( p = parts ; p ; p = p->next )
	{
		p->Step( this );
		if ( p->init && ~(p->v) < V_INIT && ~(p->F) < F_INIT  ) 
			p->Init( this );
	}
	ReScale();
}

void GWorld::Render()
{
	glClear( GL_COLOR_BUFFER_BIT );

	if ( autoscale )
	{
		glLoadIdentity();
		glScalef( scale, scale, scale );
	}

	GParticle* p;
	for ( p = parts ; p ; p = p->next )
	{
		p->Render();
	}
}

GParticle* GWorld::ParticleAt( double x, double y )
{
	GVector m( x, y );
	for ( GParticle* p = parts ; p ; p = p->next )
	{
		if ( ~( p->pos - m ) < p->r ) return p;
	}
	return 0;
}

void GWorld::ReScale()
{
	double outer = 0.0;
	double edge;
	GParticle* p, *q;
	for ( p = parts ; p ; p = p->next )
	{
		edge = ~(p->pos) + p->r;
		if ( edge > outer )
		{
			outer = edge;
			q = p;
		}
		p->F = GVector( 0, 0 );
	}
	
	//Re-scale to include all particles.
	scale = ( scale + ( 3.0 / outer ) ) / 4.0 ;

	//Nudge outermost particle toward center.
	q->F = ( q->pos / ~(q->pos) ) * -0.0001;
}
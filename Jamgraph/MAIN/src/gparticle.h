class GParticle;
class GWorld;

class GSpring
{
public:
	GSpring() { next = 0 ;};

	GParticle* part;
	double K;
	GSpring* next;
};

class GParticle
{
public:
	GParticle( double x, double y );
	~GParticle(void);

	void Init( GWorld* );
	
	double Q;	//charge
	double m;	//mass
	double r;   //radius
	GVector F;	//net force
	GVector a;	//acceleration
	GVector v;	//velocity
	GVector pos;	//position

	bool init;
	int initn;

	char* name;

	void ComputeForce( GWorld* w );
	void Step( GWorld* w );
	void Render();

	GParticle* next;
	GSpring* springs; //connected springs
};
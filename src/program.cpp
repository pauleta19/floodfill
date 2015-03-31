#include "program.h"
#include <piksel.h>
#include <QtGui\qpainter.h>
#include <QtGui\qpushbutton.h>
#include <QtGui\qevent.h>
#include <QtGui\qlabel.h>
#include <QtGui\qbrush.h>

program::program(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{	
	b_AlaniSec			= 	new QPushButton("&Alani Sec",this);
	b_SecileniDoldur	= 	new QPushButton("&Doldur",this);
	m_X					=	new piksel[400];
	m_Y					=	new piksel[400];
	nesne1				=  	new piksel;
	k					= 0;
	t					= 0;
	k1					= 0;
	t1					= 0;
	m_temp				= false;
	KutuRengi			= Qt::gray; 
	DisRenk 			= Qt::black;
	
	
	odevyazisi 		= new QLabel		(this);
	ogrismi			= new QLabel		(this);
	ogrno			= new QLabel		(this);
	odevyazisi  ->setText("VERI YAPILARI - QT - ÖDEV 2");
	ogrismi	    ->setText("Mert TASÇI & Fatih AKÇA");
	ogrno	    ->setText("G1112.10061 & G1112.10041");
	odevyazisi  ->setGeometry   	(168,550,250,50);
	ogrismi		->setGeometry		(168,20,250,20);
	ogrno		->setGeometry		(168,50,250,20);
	odevyazisi	->setAlignment(Qt::AlignCenter);
	ogrismi		->setAlignment(Qt::AlignCenter);
	ogrno		->setAlignment(Qt::AlignCenter);
	odevyazisi	->setFrameStyle(QFrame::Panel | QFrame::Sunken);
	ogrismi		->setFrameStyle(QFrame::Panel | QFrame::Sunken);
	ogrno		->setFrameStyle(QFrame::Panel | QFrame::Sunken);
	
	
	
	for(int i=0;i<20;i++)
	for(int j=0;j<20;j++)
		m_DY[i][j]=false;      //bool dizinin hepsine false ilk deger atariz...
	 
		
	QObject::connect(b_AlaniSec,SIGNAL(clicked()),this,SLOT(f_AlaniSec()));
	QObject::connect(b_SecileniDoldur,SIGNAL(clicked()),this,SLOT(f_SecileniDoldur()));
	b_AlaniSec		->setGeometry(30,100,70,400);
	b_SecileniDoldur->setGeometry(500,100,70,400);
	
}



void program::paintEvent(QPaintEvent* pe)
{	
	QPainter cizici(this);
	QPen kalem2((Qt::GlobalColor)DisRenk);
	cizici.setPen(kalem2);
		
		for(int i=0; i<400; i+=20)
	{
			for(int j=0; j<400; j+=20)
		{
		
			cizici.drawRect(100+j,100+i,20,20);

				if(m_DY[i/20][j/20])
			{
			
					int x = 100+i;
					int y = 100+j;
			
						if(x>=y)
					cizici.fillRect(x+1,y+1,19,19,(Qt::GlobalColor)KutuRengi);      //cizimde kosegenin ust tarafinda kalan bir sorundan dolayi yapildi...
						else
					cizici.fillRect(x,y,20,20,(Qt::GlobalColor)KutuRengi);
			
			}
		}
	}
}	

void program::mousePressEvent(QMouseEvent* me)
{

	k = me -> x();
	t = me -> y();
	
	if(k>500 || k<100)		//eger tiklanilan yer pencerenin disinda ise yani 
		return;				//x ve y kordinatlari 500den buyuk veya 100den kucuk ise
	if(t>500 || t<100)		//return yaptik...
		return;
					
				k = (k-100 - k%20)/20;      //alinan kordinatin 20'ye modu alinarak kendisinden cikarildi ve 
				t = (t-100 - t%20)/20;		//tam kordinat "20'nin kati seklinde olan" bulundu...
					
	if(m_temp)
	{
			k1=k;
			t1=t;
	}
		
	if(!m_temp)
	{		
		if(m_DY[k][t])
			m_DY[k][t]=false;
		else
			m_DY[k][t]=true;
	}			
			
	
	QString son = "X indisi:"+son.number(k)+"   Y indisi:"+son.number(t);		//tiklanilan indisi pencerenin basligi seklinde yaziyor...
	setWindowTitle(son);
	
	repaint();
}
void program::f_AlaniSec()
{
	m_temp=true;
} 
void program::f_SecileniDoldur()
{
	f_SimdiDoldur(k1,t1);
	m_temp=false;
}
void program::f_SimdiDoldur(int a,int b)
{

	if(m_temp)
{ 
		if(!m_DY[a][b])
	{
			m_DY[a][b]=true;
	    
			repaint();

		if(a<0 || a>19)	return;		
		if(b<0 || b>19)	return;
	
	
	    f_SimdiDoldur(a-1,b);   //ozyineleme kullanildi...
		f_SimdiDoldur(a+1,b);	//false olan piksele gelene kadar kendini cagiracak olan dongu...
		f_SimdiDoldur(a,b-1);
		f_SimdiDoldur(a,b+1);
		
	}
}


}


program::~program()
{
	 delete nesne1;
	 delete	m_X;					
	 delete m_Y;
}
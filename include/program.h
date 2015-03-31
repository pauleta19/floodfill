#ifndef PROGRAM_H
#define PROGRAM_H

#include <QtGui/QMainWindow>

class QPaintEvent;
class piksel;
class QPushButton;
class QLabel;
class QPainter;
class program : public QMainWindow
{
	Q_OBJECT

public:
	
	QPushButton* b_AlaniSec;
	QPushButton* b_SecileniDoldur;
	QLabel		*ogrismi;
	QLabel 		*ogrno;
	QLabel  	*odevyazisi;
	
	piksel* nesne1;
	piksel* m_X;
	piksel* m_Y;
	bool 		m_DY[20][20];
	int 		k;
	int			k1;
	int 		t;
	int 		t1;
	bool 		m_temp;
	int 		KutuRengi;
	int 		DisRenk;
	void f_SimdiDoldur(int x,int y);
	
	void paintEvent(QPaintEvent* pe);
	
	program(QWidget *parent = 0, Qt::WFlags flags = 0);
	~program();

private:
	void mousePressEvent(QMouseEvent* me);
	
private slots :

	void f_AlaniSec();
	void f_SecileniDoldur();
	
	

};

#endif

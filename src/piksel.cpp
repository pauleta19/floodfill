#include "piksel.h"
#include "program.h"
#include <QtGui\qpainter.h>
#include <QtGui\qlabel.h>
#include <Qt\qstring.h>



piksel::piksel()
{
}

void piksel::f_DurumunuDegistir()
{
		if(m_DYDolumu)
			m_DYDolumu=false;
		else
			m_DYDolumu=true;
}

piksel::~piksel()
{
}
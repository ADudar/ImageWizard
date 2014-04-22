#include "searchpage.h"

SearchPage::SearchPage(QWidget* parent)
	: QWidget(parent), m_boxIndx( 0 ), total(0)
{
	ui.setupUi(this);

	Init();

	show();
}

SearchPage::~SearchPage()
{
}

void SearchPage::Init()
{
	m_mainLayout = new QGridLayout( this );
	this->setLayout( m_mainLayout );

	m_comboBox = new QComboBox( this );
	m_comboBox->setFixedWidth( 40 );
	connect(m_comboBox, SIGNAL(currentIndexChanged(int)), SLOT(BoxIndxChanged(int)) );
	m_mainLayout->addWidget( m_comboBox, 0, 0 );

	AddDisks();

	m_pushButton = new QPushButton( "Searh" );
	m_pushButton->setFixedWidth( 50 );
	m_mainLayout->addWidget( m_pushButton, 0, 1 );
	connect( m_pushButton, SIGNAL(clicked()), SLOT(Searching()) );

	m_scrollArea = new QScrollArea;
	m_mainLayout->addWidget( m_scrollArea, 1, 0, 1, 5 );

	m_listWidget = new QListWidget;
	m_scrollArea->setWidget( m_listWidget );
	m_scrollArea->setWidgetResizable( true );
    m_scrollArea->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
}

void SearchPage::AddDisks()
{
	char buf[26];
    GetLogicalDriveStringsA( sizeof(buf), buf );

    // { "Unknown" , "Invalid path", "Removable", "Fixed" , "Network drive","CD-ROM", "RAM disk" };

    for (char* s = buf; *s; s += strlen(s) + 1)
	{
		unsigned int type = GetDriveTypeA(s);

		if (type == 2 || type == 3 || type == 3 || type == 5)
			m_comboBox->addItem( s );
	}
}

void SearchPage::BoxIndxChanged( int indx )
{
	m_boxIndx = indx;
}

void SearchPage::Searching()
{
	char dir[10];
	char mask[] = "*.txt";

	sprintf( dir, "%s", m_comboBox->itemText( m_boxIndx ).toStdString().c_str(), dir );

	FindFile( dir, mask );
}

void SearchPage::FindFile( char *path, char *mask )
{
	WIN32_FIND_DATAA finddata;
	HANDLE hFind;
	char _path[MAX_PATH], name[MAX_PATH];

	sprintf(_path, "%s\\%s", path, mask);
	hFind = FindFirstFileA(_path, &finddata);

	if (hFind != INVALID_HANDLE_VALUE)
	{
		do
		{
			sprintf(name, "%s\\%s", path, finddata.cFileName);

			m_listWidget->addItem( QString(name) );
			m_listWidget->update();
			
			total++;
		} while (FindNextFileA(hFind, &finddata));
	}
	FindClose(hFind);

	sprintf( _path, "%s\\*", path );
	hFind = FindFirstFileA(_path, &finddata);

	if (hFind != INVALID_HANDLE_VALUE) 
	{
		do
		{
			if (!strcmp(finddata.cFileName, "..") || !strcmp(finddata.cFileName, ".")) continue;
			if ((finddata.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))	
			{
				sprintf(_path, "%s\\%s", path, finddata.cFileName);
				FindFile(_path, mask);
			}
		}
		while (FindNextFileA(hFind, &finddata));
	}
	FindClose(hFind);
}
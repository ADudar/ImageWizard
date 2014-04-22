#include "imagewizard.h"

ImageWizard::ImageWizard(QWidget* parent)
	: QMainWindow(parent),
	  m_height( 300 ),
	  m_width( 500 )
{
	ui.setupUi(this);

	Init();

	show();
}

ImageWizard::~ImageWizard()
{
}

void ImageWizard::Init()
{
	m_stactk = new QStackedWidget( this );
	m_searchPage = new SearchPage( this );
	m_nativeSearchPage = new NativeSearchPage( this );

	this->setFixedSize( m_width, m_height );

	this->setCentralWidget( m_stactk );

	m_stactk->addWidget( m_searchPage );
	m_stactk->addWidget( m_nativeSearchPage );

  // MenuBar and toolBar init
	m_menuBar = new QMenuBar( this );
	m_menuBar->setObjectName( QString::fromUtf8("m_menuBar") );
    m_menuBar->setGeometry( QRect(0, 0, 535, 19) );
    this->setMenuBar( m_menuBar );

	QMenu* menu = new QMenu( "Search" );
	m_menuBar->addMenu( menu );

	m_toolBar = new QToolBar( "Linker ToolBar", this );
	m_toolBar->setObjectName( QString::fromUtf8("m_toolBar") );
	m_toolBar->setMovable( false );
	this->addToolBar( Qt::TopToolBarArea, m_toolBar );
	

	QAction* action_1 = new QAction( "Search images action", 0 );
	action_1->setText("Search images");
	action_1->setShortcut(QKeySequence("CTRL+S"));
	action_1->setToolTip("Search images");
	action_1->setStatusTip("Search images on disk");
	action_1->setWhatsThis("Search images on disk");
	action_1->setIcon(QPixmap(":\\Resources\\mag.jpg"));
	connect( action_1, SIGNAL(triggered()), SLOT(SetPageSearch()) );

	QAction* action_2 = new QAction( "Search native search images action", 0 );
	action_2->setText("Native images");
	action_2->setShortcut(QKeySequence("CTRL+D"));
	action_2->setToolTip("Search native images");
	action_2->setStatusTip("Search native images on disk");
	action_2->setWhatsThis("Search native images on disk");
	action_2->setIcon(QPixmap(":\\Resources\\tilda.png"));
	connect( action_2, SIGNAL(triggered()), SLOT(SetPageNativeSearch()) );


	menu->addAction( action_1 );
	menu->addAction( action_2 );
	m_toolBar->addAction( action_1 );
	m_toolBar->addAction( action_2 );
}

void ImageWizard::SetPageSearch()
{
	m_stactk->setCurrentWidget( m_searchPage );
}

void ImageWizard::SetPageNativeSearch()
{
	m_stactk->setCurrentWidget( m_nativeSearchPage );
}

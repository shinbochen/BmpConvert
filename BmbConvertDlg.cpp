// BmbConvertDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BmbConvert.h"
#include "BmbConvertDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBmbConvertDlg dialog

CBmbConvertDlg::CBmbConvertDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBmbConvertDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBmbConvertDlg)
	m_strPath = _T("");
	m_strResult = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBmbConvertDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBmbConvertDlg)
	DDX_Text(pDX, IDC_FILE, m_strPath);
	DDX_Text(pDX, IDC_RESULT, m_strResult);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBmbConvertDlg, CDialog)
	//{{AFX_MSG_MAP(CBmbConvertDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OPEN, OnOpen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBmbConvertDlg message handlers

BOOL CBmbConvertDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBmbConvertDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CBmbConvertDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CBmbConvertDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

/*
设置COLOR显示区哉的某一点
*/
unsigned char BIT[8]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
unsigned char nVirtualLED[24*3][12];
void SetCPoint( unsigned char *p, int x, int y, char nColor ){
	
	int						xbyte,ybyte;
	unsigned char	xbit;

	xbyte = x/8;
	xbit = x%8;
	ybyte = y*3;
	
	if( nColor&BIT[0] ){
		*(p+ybyte*12+xbyte)	|= BIT[xbit];
	}
	else{
		*(p+ybyte*12+xbyte)	&= (~BIT[xbit])&0xFF;
		
	}
	if( nColor&BIT[1] ){
		*(p+(ybyte+1)*12+xbyte)	|= BIT[xbit];
	}
	else{
		*(p+(ybyte+1)*12+xbyte)	&= (~BIT[xbit])&0xFF;
		
	}
	if( nColor&BIT[2] ){
		*(p+(ybyte+2)*12+xbyte)	|= BIT[xbit];
	}
	else{
		*(p+(ybyte+2)*12+xbyte)	&= (~BIT[xbit])&0xFF;
		
	}
	return;	
}


CString CBmbConvertDlg::ConvertBmbFile(  CString strFilePath ){

	CFile		file;
	CString		strResult;

	strResult.Empty();

	if( file.Open( strFilePath, CFile::modeRead ) == TRUE ){

		BITMAPFILEHEADER		bmfh;
		BITMAPINFOHEADER		bmih;
		unsigned char			*lpPaint = NULL;
		unsigned char			*lpBit = NULL;
		int						nLen,x,y;

		file.Read( &bmfh, sizeof(BITMAPFILEHEADER) );
		file.Read( &bmih, sizeof(BITMAPINFOHEADER) ); 
		
		if( bmfh.bfType == 0x4D42){

			if( (bmih.biBitCount ==1) ||  (bmih.biBitCount == 4) || (bmih.biBitCount == 16) || (bmih.biBitCount == 8) ){
				MessageBox("Can't support this type");
			}
			else{
				// 要建索引色
				if( bmih.biBitCount == 8 ){
					lpPaint = (unsigned char*)malloc( bmih.biClrUsed*4 );
					file.Read( lpPaint, bmih.biClrUsed*4 );
				}

				nLen = bmfh.bfSize-bmfh.bfOffBits+1;

				lpBit = (unsigned char*)malloc(nLen);

				file.Seek(bmfh.bfOffBits,CFile::begin);
				file.Read( lpBit, nLen );
				
				if( bmih.biBitCount == 8 ){

				}
				else if(bmih.biBitCount == 24 ) {						
					x = 0;
					// 正向
					if( bmih.biHeight > 0 ){
						y = bmih.biHeight-1;
					}
					else{
						y = 0;
					}							
					for( int i = 0; i < nLen; ){
						int	nColor = 0;
						nColor = 0;
						// B
						if( (*(lpBit+i++)) >= 0x7F ){
							nColor |= 0x04;
						}
						// G
						if( (*(lpBit+i++)) >= 0x7F ){
							nColor |= 0x02;
						}
						if( (*(lpBit+i++)) >= 0x7F ){
							nColor |= 0x01;
						}

						SetCPoint(&nVirtualLED[0][0], x, y, nColor );
						x++;
						// 每一行是四字节的取整
						if( x>= bmih.biWidth ){									
							x = i%4;
							i = i+(4-x);
							x=0;
							if( bmih.biHeight > 0 ){
								y--;
							}
							else{
								y++;
							}
						}
					}
				}
				else{

					x = 0;
					// 正向
					if( bmih.biHeight > 0 ){
						y = bmih.biHeight-1;
					}
					else{
						y = 0;
					}							
					for( int i = 0; i < nLen; ){
						int	nColor = 0;
						nColor = 0;
						// B
						if( (*(lpBit+i++)) >= 0x7F ){
							nColor |= 0x04;
						}
						// G
						if( (*(lpBit+i++)) >= 0x7F ){
							nColor |= 0x02;
						}
						if( (*(lpBit+i++)) >= 0x7F ){
							nColor |= 0x01;
						}
						i++;

						SetCPoint(&nVirtualLED[0][0], x, y, nColor );
						x++;
						if( x>= bmih.biWidth ){	
							x=0;
							if( bmih.biHeight > 0 ){
								y--;
							}
							else{
								y++;
							}
						}
					}

				}

			}
		}
		if( lpPaint != NULL ){
			free(lpPaint);
			lpPaint = NULL;
		}

		if( lpBit != NULL ){
			
			CString		strTmp;

			free( lpBit );
			lpBit = NULL;

			for( y = 0; y < 24*3; y++ ){
				for( x = 0; x < 12; x++ ){
					strTmp.Format( "0X%02x,", nVirtualLED[y][x] );
					strResult += strTmp;					
				}
				strResult += "\r\n";
			}
			UpdateData( FALSE );

		}
		file.Close();
	}
	return strResult;
}
void CBmbConvertDlg::OnOpen() 
{
	CString		strPath;
	int			i = 0;
	CFileDialog dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT|OFN_ALLOWMULTISELECT,"All Files (*.bmp)|*.bmp||");///TRUE为OPEN对话框，FALSE为SAVE AS对话框 　　
	if(dlg.DoModal()==IDOK){

		POSITION		pos;

		pos = dlg.GetStartPosition( );

		m_strResult.Empty();

		while( pos != NULL ){
			strPath = dlg.GetNextPathName( pos );
			strPath = ConvertBmbFile( strPath );
			if( strPath.IsEmpty() == FALSE ){
				if( m_strResult.IsEmpty() == FALSE ){
					m_strResult += "\r\n\r\n";
				}
				m_strResult += strPath;
				i++;
			}

		}
		m_strPath.Format("%d",i);
		UpdateData( FALSE );
	}


} 

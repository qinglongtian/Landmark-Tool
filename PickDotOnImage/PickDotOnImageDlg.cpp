
// PickDotOnImageDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PickDotOnImage.h"
#include "PickDotOnImageDlg.h"
#include "afxdialogex.h"
#include "LandmarkDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPickDotOnImageDlg dialog



CPickDotOnImageDlg::CPickDotOnImageDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PICKDOTONIMAGE_DIALOG, pParent)
	, m_strFolderName(_T(""))
	, m_strResultFileName(_T(""))
	, m_strStartIndex(_T(""))
	, m_strLastIndex(_T(""))
	, m_strLastFileName(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPickDotOnImageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDITFOLDER, m_strFolderName);
	DDX_Text(pDX, IDC_EDITLMFILE, m_strResultFileName);
	DDX_Text(pDX, IDC_EDITSTARTINDEX, m_strStartIndex);
	DDX_Text(pDX, IDC_STATICLASTINDEX, m_strLastIndex);
	DDX_Text(pDX, IDC_STATICLASTFILENAME, m_strLastFileName);
}

BEGIN_MESSAGE_MAP(CPickDotOnImageDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BROWSERFOLDER, &CPickDotOnImageDlg::OnBnClickedBrowserfolder)
	ON_BN_CLICKED(IDC_BUTTONLMFILE, &CPickDotOnImageDlg::OnBnClickedButtonlmfile)
	ON_BN_CLICKED(IDOK, &CPickDotOnImageDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CPickDotOnImageDlg message handlers

BOOL CPickDotOnImageDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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
	//m_strLastFileName = "";
	//m_strLastIndex = "";
	m_strStartIndex = "0";
	UpdateData(FALSE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPickDotOnImageDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CPickDotOnImageDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPickDotOnImageDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// browser folder for annotation, landmark
void CPickDotOnImageDlg::OnBnClickedBrowserfolder()
{
	// select folder
	CFolderPickerDialog folderSelectDlg;
	if (folderSelectDlg.DoModal() == IDOK)
	{
		m_strFolderName = folderSelectDlg.GetPathName();
		UpdateData(FALSE);
	}
}


void CPickDotOnImageDlg::OnBnClickedButtonlmfile()
{
	// select landmark result file
	CFileDialog fileDlg(TRUE);
	if (fileDlg.DoModal() == IDOK)
	{
		m_strResultFileName = fileDlg.GetPathName();
		UpdateData(FALSE);
	}
}


void CPickDotOnImageDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (m_strStartIndex.GetLength() == 0 || _wtoi(m_strStartIndex) < 0)
	{
		AfxMessageBox(_T("Please input correct Start Index"));
		return;
	}
	if (m_strFolderName.GetLength() == 0)
	{
		AfxMessageBox(_T("Please select image folder"));
		return;
	}
	if (m_strResultFileName.GetLength() == 0)
	{
		AfxMessageBox(_T("Please select Result File"));
		return;
	}
	//CDialogEx::OnOK();
	CLandmarkDlg landmarkDlg;
	landmarkDlg.DoModal();
}

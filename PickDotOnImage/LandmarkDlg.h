#pragma once


// CLandmarkDlg dialog

class CLandmarkDlg : public CDialog
{
	DECLARE_DYNAMIC(CLandmarkDlg)

public:
	CLandmarkDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CLandmarkDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};

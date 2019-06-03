
// PickDotOnImageDlg.h : header file
//

#pragma once


// CPickDotOnImageDlg dialog
class CPickDotOnImageDlg : public CDialogEx
{
// Construction
public:
	CPickDotOnImageDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PICKDOTONIMAGE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBrowserfolder();
	// Folder Name
	CString m_strFolderName;
	CString m_strResultFileName;
	CString m_strStartIndex;
	CString m_strLastIndex;
	CString m_strLastFileName;
	afx_msg void OnBnClickedButtonlmfile();
	afx_msg void OnBnClickedOk();
};

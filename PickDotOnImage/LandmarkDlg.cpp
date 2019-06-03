// LandmarkDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PickDotOnImage.h"
#include "LandmarkDlg.h"
#include "afxdialogex.h"
#include "SlideShowCtrl.h"

// CLandmarkDlg dialog

IMPLEMENT_DYNAMIC(CLandmarkDlg, CDialog)

CLandmarkDlg::CLandmarkDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG1, pParent)
{

}

CLandmarkDlg::~CLandmarkDlg()
{
}

void CLandmarkDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLandmarkDlg, CDialog)
END_MESSAGE_MAP()


// CLandmarkDlg message handlers


BOOL CLandmarkDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	CSlideShowCtrl slideShowCtrl;
	add(slideShowCtrl);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

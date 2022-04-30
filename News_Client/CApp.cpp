#include "CApp.h"

wxIMPLEMENT_APP(CApp);

bool CApp::OnInit()
{
	CustomClient::get_instance()->Connect("127.0.0.1", 60000);

    m_frame1 = new CMainWindow();

    m_frame1->Show();

    return true;
}








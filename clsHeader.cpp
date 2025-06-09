#include "clsHeader.h"
#include "clsSession.h"

void clsHeader::DrawHeader(const std::string& Title) {
	std::cout << "\t\t\t\t\t==================================" << endl;
	std::cout << "\t\t\t\t        " << Title << endl;
	std::cout << "\t\t\t\t\tUser : " << clsSession::CurrentUser.GetUsername()
		<< "\t Date : " << _getCurrentDate() << endl;
	std::cout << "\t\t\t\t\t==================================" << endl;
}

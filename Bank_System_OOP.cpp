#include"Core.h"
#include"clsShowLoginScreen.h"
using namespace std;
int main() {
	while (true){
		if (!clsLoginScreen::ShowLoginScreen())
			break;
	}
}
#include "point.h"

int main(int argc, char const *argv[])
{
	Cartesien p1 = creer_cartesien(10.0, 1.0);
	Cartesien p2 = creer_cartesien(-0.1, -30.0);
	Polaire p3 = cartesien_vers_polaire(p1);
	Polaire p4 = cartesien_vers_polaire(p2);
	char* p1_string = toStringCartesien(p1);
	printf("%s \tdevient\t%s\n", p1_string, toStringPolaire(p3));
	printf("%s \tdevient\t%s\n", toStringCartesien(p2), toStringPolaire(p4));
	detruire_cartesien(p1);
	detruire_cartesien(p2);
	detruire_polaire(p3);
	detruire_polaire(p4);

	p3 = creer_polaire(12, 14);
	p4 = creer_polaire(3.14, -10.1);
	p1 = polaire_vers_cartesien(p3);
	p2 = polaire_vers_cartesien(p4);
	printf("%s \t\tdevient\t%s\n", toStringPolaire(p3), toStringCartesien(p1));
	printf("%s \t\tdevient\t%s\n", toStringPolaire(p4), toStringCartesien(p2));
	detruire_cartesien(p1);
	detruire_cartesien(p2);
	detruire_polaire(p3);
	detruire_polaire(p4);

	return EXIT_SUCCESS;
}

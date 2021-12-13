#include <string>
std::string lenCeaser2encrypt(std::string text)
{
	char ch;
	int i, key;
	key = text.size();
	for (i = 0; text[i] != '\0'; ++i) {
		ch = text[i];
		if (ch >= 'a' && ch <= 'z') {
			ch = ch + key;
			if (ch > 'z') {
				ch = ch - 'z' + 'a' - 1;
			}
			text[i] = ch;
		}
		else if (ch >= 'A' && ch <= 'Z') {
			ch = ch + key;
			if (ch > 'Z') {
				ch = ch - 'Z' + 'A' - 1;
			}
			text[i] = ch;
		}
	}
	return text;
}
std::string lenCeaser2decrypt(std::string text)
{

	char ch;
	int i, key;
	key = text.size();
	for (i = 0; text[i] != '\0'; ++i) {
		ch = text[i];
		if (ch >= 'a' && ch <= 'z') {
			ch = ch - key;
			if (ch < 'a') {
				ch = ch + 'z' - 'a' + 1;
			}
			text[i] = ch;
		}
		else if (ch >= 'A' && ch <= 'Z') {
			ch = ch - key;
			if (ch < 'A') {
				ch = ch + 'Z' - 'A' + 1;
			}
			text[i] = ch;
		}
	}
	return text;
}
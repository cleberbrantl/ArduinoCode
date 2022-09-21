// BiblioCBS.h
#ifndef BIBLIOCBS_H
#define BIBLIOCBS_H

#include <Arduino.h>

class BiblioCBS{
  private:
	String mensagem;
	
	
  public:
    String Crypto(String msg);
    String Decrypto(String msg);
};
char nibble2c(char c);
char hex2c(char c1, char c2);
String hex2str(char *data);
#endif
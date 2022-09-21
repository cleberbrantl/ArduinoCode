// BiblioCBS.cpp
#include <BiblioCBS.h>

String BiblioCBS::Str_2_StrHex(String msg){
	
	String msg_rec = "";
	int tam = msg.length();
	char c;
	
	for(int cont=0; cont<tam; cont++){
		c = msg[cont];

		msg_rec.concat(String(c, HEX));	//Char to HEX
		//Serial.println(String(c, HEX));
	}
  return msg_rec;
}
String BiblioCBS::StrHex_2_Str(String msg){
	
	String msg_rec = "";
	String msgx = msg;
	msgx.toUpperCase();
	int tam = msg.length();
	
	for(int cont=0; cont<tam; cont+=2){
		char aux1 = (char)msgx[cont];
		char aux2 = (char)msgx[cont+1];
		
		char c = hex2c(aux1, aux2);
			
		msg_rec.concat(String(c));
		//Serial.println(String(c));
	}
	return msg_rec;
}
String BiblioCBS::Crypto(String msg){
	
	String msg_rec = "";
	int tam = msg.length();
	char c;
	
	for(int cont=0; cont<tam; cont++){
		c = msg[cont];				//Get Char
		
		c = c+(5+cont);//My Crypto
		
		msg_rec.concat(String(c, HEX));	//Char to HEX -> send String
		//Serial.print(String(c, HEX));
	}
	//Serial.println();
  return msg_rec;
}
String BiblioCBS::Decrypto(String msg){
	
	String msg_rec = "";
	String msgx = msg;
	msgx.toUpperCase();
	int tam = msg.length();
	char c;
	
	int xs = 0;
	for(int cont=0; cont<tam; cont+=2){
		char aux1 = (char)msgx[cont];	//Get StrHex(Decimal)
		char aux2 = (char)msgx[cont+1]; //Get StrHex(Unit)
		
		c = hex2c(aux1, aux2);			//Union Hex to Char
			
		c = c - (5+(xs++));				//Reverse Crypto
		
		msg_rec.concat(String(c));		//Char Send String
		//Serial.print(String(c));
	}
	//Serial.println();
	return msg_rec;
}
char nibble2c(char c){
	
   if ((c>='0') && (c<='9'))
      return c-'0' ;
   if ((c>='A') && (c<='F'))
      return c+10-'A' ;
   return -1 ;
}
char hex2c(char c1, char c2){
	
   if(nibble2c(c2) >= 0)
     return nibble2c(c1)*16+nibble2c(c2) ;
   return nibble2c(c1) ;
}
String hex2str(char *data){
	
   String result = "" ;
   for (int i=0 ; nibble2c(data[i])>=0 ; i++)
   {
      result += hex2c(data[i],data[i+1]) ;
      if(nibble2c(data[i+1])>=0)
        i++ ;
   }
   return result;
}
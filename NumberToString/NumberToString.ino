/*
* NumberToString
 * Creates a string from a given number
 */
void setup()
{
  Serial.begin(9600);
}
char buffer[12];
// long data type has 11 characters (including the
// minus sign) and a terminating null
void loop()
{
  long a = 16;
    ltoa(a,buffer,2);   // here 2 means binary
    Serial.println(buffer);
 
    ltoa(a,buffer,10);   // here 10 means decimal
    Serial.println(buffer);
 
    ltoa(a,buffer,16);   // here 16 means Hexadecimal
    Serial.println(buffer);
  delay(1000);
}


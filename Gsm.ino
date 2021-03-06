bool isGsmReady()
{
  SIM800L.println("AT");
  return _readSerial(2000).indexOf("OK") != -1 ? true : false;
};

String _readSerial(uint32_t timeout)
{
  uint64_t timeOld = millis();
  while (!SIM800L.available() && !(millis() > timeOld + timeout))
  {
    delay(13);
  }
  String str = "";
  while (SIM800L.available())
  {
    if (SIM800L.available())
    {
      str += (char)SIM800L.read();
    }
  }
  return str;
};
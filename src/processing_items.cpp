/* Y U put functions in a header file??? */
/*              :face_palm:              */

#include <Arduino.h>

#if defined(ESP8266)
#include "ESP8266WiFi.h"
#elif defined(ESP32)
#include "WiFi.h"
#endif

extern int darkState;
extern const char *htmlcolor;
extern const char *htmlhover;
extern const char *host;

String DeviceID();
String ip3string(IPAddress ip);
String processor(const String &var);

#include "CSS.h"
#include "SCRIPTS.h"
#include "Standard_Page_Parts.h"

/* Convert a #defined value to a string */
#define ST(A) #A
#define STR(A) ST(A)

String DeviceID() // This code compiles to 16 bytes
{
#if defined(DeviceName)
  String id = STR(DeviceName);
#else
  String id = host;
#endif
  return id;
}

String ip3string(IPAddress ip) // This code compiles to 608 bytes
{
  String ret = String(ip[0]) + "." + String(ip[1]) + "." + String(ip[2]) + "." + String(ip[3]);
  return ret;
}

String processor(const String &var) // This code compiles to 7488 bytes
{                                   // Change placeholders on webpage

  if (var == "The_CSS")
  {
    return CSS_STYLE;
  }

  if (var == "The_SCRIPTS")
  {
    return CSS_SCRIPTS;
  }

  if (var == "Page_Header")
  {
    return Page_Header;
  }

  if (var == "Page_Footer")
  {
    return Page_Footer;
  }

  if (var == "title")
  {
#if defined(htmltitle)
    return String(htmltitle);
#elif defined(DeviceName)
    return DeviceID();
#endif
  }

  if (var == "dark")
  {
    if (darkState == false)
    {
      return "body { background-color: white; color: black; }";
    }
    else
    {
      return "body { background-color: black; color: white; }";
    }
  }

  if (var == "color")
  {
    return htmlcolor;
  }

  if (var == "hover")
  {
    return htmlhover;
  }

  if (var == "ipplaceholder")
  {
    return ip3string(WiFi.localIP());
  }

  if (var == "macplaceholder")
  {
    return WiFi.macAddress();
  }

  /////////////////////////////////////////////
  if (var == "binplaceholder")
  {
    return String(ESP.getSketchSize());
  }
  /////////////////////////////////////////////

  if (var == "IDplaceholder")
  {
    return DeviceID();
  }

  if (var == "processorplaceholder")
  {
#if defined(ESP8266)
    return "ESP8266";
#elif defined(ESP32)
    return "ESP32";
#endif
  }

  if (var == "type")
  {
#if defined(typetitle)
    return STR(typetitle);
#else
    return "WHAT AM I?";
#endif
  }

  return String();
}

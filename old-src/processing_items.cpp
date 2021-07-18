/* Y U put functions in a header file??? */
/*              :face_palm:              */

#include <Arduino.h>

#if defined(ESP8266)
    #include "ESP8266WiFi.h"
#elif defined(ESP32)
    #include "WiFi.h"
#endif

extern int darkState;
extern const char* htmlcolor;
extern const char* htmlhover;
extern const char* host;

String DeviceID();
String ip3string(IPAddress ip);
String processor(const String &var);

#include "CSS.h"
#include "SCRIPTS.h"
#include "Standard_Page_Parts.h"

/* Convert a #defined value to a string */
#define ST(A) #A
#define STR(A) ST(A)

String DeviceID()
{
#if defined(DeviceName)
  String id = STR(DeviceName);
#else
  String id = host;
#endif
  return id;
}

String ip3string(IPAddress ip)
{
  String ret = String(ip[0]) + "." + String(ip[1]) + "." + String(ip[2]) + "." + String(ip[3]);
  return ret;
}

String processor(const String &var)
{ // Change placeholders on webpage
// This code compiles to 7616 bytes

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
    String titleing = "";
#if defined(htmltitle)
    titleing += htmltitle;
#elif defined(DeviceName)
    titleing += DeviceID();
#endif
    return titleing;
  }
  if (var == "dark")
  {
    String dark = "";
    if (darkState == false)
    {
      dark += "body { background-color: white; color: black; }";
    }
    else
    {
      dark += "body { background-color: black; color: white; }";
    }
    return dark;
  }
  if (var == "color")
  {
    String coloring = "";
    coloring += htmlcolor;
    return coloring;
  }
  if (var == "hover")
  {
    String hovering = "";
    hovering += htmlhover;
    return hovering;
  }
  if (var == "ipplaceholder")
  {
    String iping = "";
    iping += ip3string(WiFi.localIP());
    return iping;
  }
  if (var == "macplaceholder")
  {
    String macing = "";
    macing += WiFi.macAddress();
    return macing;
  }
  /////////////////////////////////////////////
  if (var == "binplaceholder")
  {
    String macing = "";
    macing += ESP.getSketchSize();
    return macing;
  }
  /////////////////////////////////////////////
  if (var == "IDplaceholder")
  {
    String IDing = "";
    IDing += DeviceID();
    return IDing;
  }
  if (var == "processorplaceholder")
  {
    String PROing = "";
#if defined(ESP8266)
    PROing += "ESP8266";
#elif defined(ESP32)
    PROing += "ESP32";
#endif
    return PROing;
  }
  if (var == "type")
  {
    String typeing = "";
#if defined(typetitle)
    typeing += STR(typetitle);
#else
    typeing += "WHAT AM I?";
#endif
    return typeing;
  }

  return String();
}
